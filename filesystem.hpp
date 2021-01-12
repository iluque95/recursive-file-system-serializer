#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstring>

class myfilesystem
{
public:
    myfilesystem();
    myfilesystem(const std::string& p);
    myfilesystem(const myfilesystem& f) = delete;
    ~myfilesystem();


    uint64_t raw_size = 0;

public:
    void read();
    void write();
    void print(std::ostream& os);

    uint64_t count();

public:
    uint16_t directories();
    uint32_t files();

public:
    friend std::ostream& operator<<(std::ostream& os, const myfilesystem& f);

private:

    struct file
    {
        std::string filename;
        uint64_t filesize;
        uint32_t offset;
        uint64_t position;
        file() : filesize(0), offset(0), position(0) {}
    };

    struct directory
    {
        std::string name;
        uint16_t n_dirs;
        directory** subdirectory;
        uint32_t n_files;
        file** files;
        directory() : n_dirs(0), n_files(0), subdirectory(nullptr), files(nullptr) {}
    };

    directory* root = nullptr;
    uint16_t m_directories = 0;
    uint32_t m_files = 0;


    void recursive_deletion(directory* d);
    directory* read(directory* d, std::ifstream& ifs);
    void write(directory* d, std::ofstream& ofs);
    void print(std::ostream& os, directory* d, uint32_t inode, uint32_t spaces);
    template <typename T>
    bool reallocate(T*& mem, uint32_t oldSize, uint32_t newSize);
    directory* create_struct(const std::filesystem::path& p);

    uint64_t count(directory* d);
};

myfilesystem::myfilesystem() : root(nullptr), m_directories(0), m_files(0)
{}

myfilesystem::myfilesystem(const std::string& p)
{
    root = create_struct(std::filesystem::path(p));
}

myfilesystem::~myfilesystem()
{
    recursive_deletion(root);
}

void myfilesystem::recursive_deletion(directory* d)
{
    if (d != nullptr)
    {
        if (d->subdirectory != nullptr)
        {
            for (auto i = 0u; i < d->n_dirs; ++i)
            {
                recursive_deletion(d->subdirectory[i]);
            }
            delete[] d->subdirectory;
        }

        if (d->files != nullptr)
        {
            delete[] d->files;
        }

        delete d;
    }
}

myfilesystem::directory* myfilesystem::read(directory* d, std::ifstream& ifs)
{

    d = new directory;
    d->subdirectory = nullptr;
    d->files = nullptr;
    d->n_dirs = 0;
    d->n_files = 0;

    char buff[0xFF];

    uint8_t size = 0;

    ifs.read((char*)&size, sizeof(size));

    ifs.read(&buff[0], size);

    d->name.append(&buff[0], size);

    ifs.read((char*)&d->n_dirs, sizeof(directory::n_dirs));

    if (d->n_dirs > 0) d->subdirectory = new directory * [d->n_dirs];

    for (auto i = 0u; i < d->n_dirs; ++i)
    {
        d->subdirectory[i] = read(d->subdirectory[i], ifs);
    }

    ifs.read((char*)&d->n_files, sizeof(directory::n_files));

    if (d->n_files > 0) d->files = new file * [d->n_files];

    for (auto i = 0u; i < d->n_files; ++i)
    {
        d->files[i] = new file;

        size = 0;

        ifs.read((char*)&size, sizeof(size));

        ifs.read(&buff[0], size);

        d->files[i]->filename.append(&buff[0], size);

        ifs.read((char*)&d->files[i]->filesize, sizeof(file::filesize));
        ifs.read((char*)&d->files[i]->offset, sizeof(file::offset));
        ifs.read((char*)&d->files[i]->position, sizeof(file::position));
    }

    return d;

}

void myfilesystem::read()
{
    std::ifstream ifs("file.bin", std::ios::binary);

    root = read(root, ifs);

    ifs.close();

}

void myfilesystem::write(directory* d, std::ofstream& ofs)
{

    uint8_t size = 0;

    size = d->name.size();

    ofs.write((char*)&size, sizeof(size));
    ofs.write(d->name.c_str(), size);
    ofs.write((char*)&d->n_dirs, sizeof(directory::n_dirs));

    for (auto i = 0u; i < d->n_dirs; ++i)
    {
        write(d->subdirectory[i], ofs);
    }

    ofs.write((char*)&d->n_files, sizeof(directory::n_files));

    for (auto i = 0u; i < d->n_files; ++i)
    {
        size = d->files[i]->filename.size();

        ofs.write((char*)&size, sizeof(size));
        ofs.write(d->files[i]->filename.c_str(), size);
        ofs.write((char*)&d->files[i]->filesize, sizeof(file::filesize));
        ofs.write((char*)&d->files[i]->offset, sizeof(file::offset));
        ofs.write((char*)&d->files[i]->position, sizeof(file::position));
    }
}

void myfilesystem::write()
{
    std::ofstream ofs("file.bin", std::ios::binary);

    write(root, ofs);

    ofs.close();
}

uint64_t myfilesystem::count(directory* d)
{

    uint64_t ret = 0;

    uint8_t size = 0;

    size = d->name.size();

    ret += sizeof(size);
    ret += size;

    ret += sizeof(directory::n_dirs);

    for (auto i = 0u; i < d->n_dirs; ++i)
    {
        ret += count(d->subdirectory[i]);
    }

    ret += sizeof(directory::n_files);

    for (auto i = 0u; i < d->n_files; ++i)
    {
        size = d->files[i]->filename.size();

        ret += sizeof(size);
        ret += size;

        ret += sizeof(file::filesize);
        ret += sizeof(file::offset);
        ret += sizeof(file::position);
    }

    return ret;
}

void myfilesystem::print(std::ostream& os, directory* d, uint32_t inode, uint32_t spaces)
{
    if (d != nullptr)
    {
        for (auto i = 0u; i < spaces; ++i) { if (i % 2 == 0) os << " |"; else os << " "; }

        os << "[" << inode << "] " << d->name << "\n";

        spaces += 2;

        for (auto i = 0u; i < d->n_dirs; ++i)
        {
            print(os, d->subdirectory[i], ++inode, spaces);
        }

        for (auto j = 0u; j < d->n_files; ++j)
        {
            for (auto k = 0u; k < spaces - 2; ++k) { if (k % 2 == 0) os << " |"; else os << " "; }
            os << " \\_ [" << j << "] " << d->files[j]->filename << "\n";
        }
    }
}

void myfilesystem::print(std::ostream& os)
{
    print(os, root, 0, 0);
}

inline uint64_t myfilesystem::count()
{
    return count(root);
}

inline uint16_t myfilesystem::directories()
{
    return m_directories;
}

inline uint32_t myfilesystem::files()
{
    return m_files;
}

template <typename T>
bool myfilesystem::reallocate(T*& mem, uint32_t oldSize, uint32_t newSize)
{
    if (newSize == oldSize)
        return true;

    T* newRegion = nullptr;

    try
    {
        newRegion = new T[newSize];
        if (oldSize > 0)
        {
            std::copy(&mem[0], &mem[0] + oldSize, &newRegion[0]);
            newRegion[oldSize] = nullptr;
            delete[] mem;
        }
        mem = newRegion;
        return true;
    }
    catch (...)
    {
        delete[] newRegion;
        return false;
    }
}

myfilesystem::directory* myfilesystem::create_struct(const std::filesystem::path& p)
{
    directory* d = nullptr;

    try {

        d = new directory;

        d->name = p.filename().string();
        d->n_dirs = 0;
        d->subdirectory = nullptr;
        d->n_files = 0;
        d->files = nullptr;

        // Recursive list
        for (auto& p : std::filesystem::directory_iterator(p))
        {
            if (p.is_directory())
            {

                ++d->n_dirs;

                reallocate(d->subdirectory, d->n_dirs - 1, d->n_dirs);

                d->subdirectory[d->n_dirs - 1] = create_struct(p);

            }
            else if (p.is_regular_file())
            {
                file* f;
                try
                {
                    f = new file;

                    f->filename = p.path().filename().string();

                    f->filesize = p.file_size();
                    f->offset = 0;
                    f->position = 0;

                    ++d->n_files;

                    if (reallocate(d->files, d->n_files - 1, d->n_files))
                        d->files[d->n_files - 1] = f;
                    else
                    {
                        std::cout << "Error reallocating.\n";
                        return nullptr;
                    }
                }
                catch (std::exception& e)
                {
                    std::cout << "Error creating file struct. Reason: " << e.what() << "\n";
                    delete f;
                    recursive_deletion(d);
                    return nullptr;
                }
                catch (...)
                {
                    std::cout << "Error creating dynamic memory\n";
                    recursive_deletion(d);
                    return nullptr;
                }


            }
            else
                continue;
        }
    }
    catch (std::filesystem::filesystem_error& fe)
    {
        std::cout << "Filesystem error. Reason: " << fe.what() << "\n";
        recursive_deletion(d);
        return nullptr;
    }
    catch (...)
    {
        std::cout << "Error iterating path.\n";
        recursive_deletion(d);
        return nullptr;
    }

    m_directories += d->n_dirs;
    m_files += d->n_files;

    raw_size += count(d);


    return d;
}

std::ostream& operator<<(std::ostream& os, myfilesystem& f)
{
    f.print(os);
    return os;
}