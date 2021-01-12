cmake_minimum_required (VERSION 2.8.11)

# This logic needs to be considered before project()
set(_change_MSVC_flags FALSE)
if(WIN32)
  if(CMAKE_VERSION VERSION_LESS 3.15.0)
    set(_change_MSVC_flags TRUE)
  else()
    # Set MSVC runtime to MultiThreaded (/MT)
    cmake_policy(SET CMP0091 NEW)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  endif()
endif()

project (executable LANGUAGES CXX)

add_executable (executable test.cpp)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

set_property(TARGET executable PROPERTY CXX_STANDARD 17)
set_property(TARGET executable PROPERTY CXX_STANDARD_REQUIRED ON)

# Modify compile flags to change optimization level from O3 to O2
string(REGEX REPLACE "([\\/\\-]O)3" "\\12"
  CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "([\\/\\-]O)3" "\\12"
  CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
string(REGEX REPLACE "([\\/\\-]O)3" "\\12"
  CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
string(REGEX REPLACE "([\\/\\-]O)3" "\\12"
  CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

if (UNIX)
  target_link_libraries(executable stdc++fs)
endif()

if(_change_MSVC_flags)
  # Modify compile flags to change MSVC runtime from /MD to /MT
  set(_re_match "([\\/\\-]M)D")
  set(_re_replace "\\1T")
  string(REGEX REPLACE ${_re_match} ${_re_replace}
    CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  string(REGEX REPLACE ${_re_match} ${_re_replace}
    CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
  string(REGEX REPLACE ${_re_match} ${_re_replace}
    CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
  string(REGEX REPLACE ${_re_match} ${_re_replace}
    CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
  string(REGEX REPLACE ${_re_match} ${_re_replace}
    CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
endif()