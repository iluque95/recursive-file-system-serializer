#include "filesystem.hpp"

int main()
{
    
    std::string folder("myFolder");

    std::cout << "Folder: " << folder << "\n";

    myfilesystem f(folder);

    std::cout << f;

    std::cout << "\n\n";

    std::cout << f.files() << " files and " << f.directories() << " and directories\n";


    std::ofstream ofs("output.txt");
    ofs << f;
    ofs.close();


    f.write();

    myfilesystem mfs;

    mfs.read();

    std::cout << mfs;

    std::ofstream ofs2("output2.txt");
    ofs2 << f;
    ofs2.close();


    auto fsize = std::filesystem::file_size("file.bin");

    std::cout << "Real: " << fsize << ", Struct: " << f.raw_size << ", f(): " << f.count() << "\n";

    std::cin.get();
}