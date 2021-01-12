# Recursive File System Serializer

De-serialize in an easy way your content. You will get a pretty result with your folder like:

```
[0] myFolder
 | [1] .vs
 |  | [2] prueba
 |  |  | [3] v16
 |  |  |  | [4] ipch
 |  |  |  |  | [5] AutoPCH
 |  |  |  |  |  | [6] 430d2f5712ec0c7f
 |  |  |  |  |  |  \_ [0] TEST.ipch
 |  |  |  |  |  | [7] 9c2cde98a8d27a9d
 |  |  |  |  |  |  \_ [0] TEST.ipch
 |  |  |  \_ [0] .suo
 |  |  |  \_ [1] Browse.VC.db
 |  \_ [0] CMake Overview
 |  \_ [1] cmake.db
 |  \_ [2] ProjectSettings.json
 |  \_ [3] slnx.sqlite
 |  \_ [4] VSWorkspaceState.json
 | [2] .vscode
 |  \_ [0] settings.json
 | [3] build
 |  | [4] .cmake
 |  |  | [5] api
 |  |  |  | [6] v1
 |  |  |  |  | [7] query
 |  |  |  |  |  | [8] client-vscode
 |  |  |  |  |  |  \_ [0] query.json
 |  |  |  |  | [8] reply
 |  |  |  |  |  \_ [0] cache-v2-da55e3b5ed1c92e3af41.json
 |  |  |  |  |  \_ [1] codemodel-v2-3e0f6eb4425ef4fbbb79.json
 |  |  |  |  |  \_ [2] index-2020-10-28T22-04-12-0560.json
 |  |  |  |  |  \_ [3] target-ALL_BUILD-Debug-634e4de4e7033371ff06.json
 |  |  |  |  |  \_ [4] target-ALL_BUILD-MinSizeRel-634e4de4e7033371ff06.json
 |  |  |  |  |  \_ [5] target-ALL_BUILD-Release-634e4de4e7033371ff06.json
 |  |  |  |  |  \_ [6] target-ALL_BUILD-RelWithDebInfo-634e4de4e7033371ff06.json
 |  |  |  |  |  \_ [7] target-test-Debug-5feda838a32b6256e630.json
 |  |  |  |  |  \_ [8] target-test-MinSizeRel-a2f931c0ff3cb1ab6be0.json
 |  |  |  |  |  \_ [9] target-test-Release-85674056157d63ab5306.json
 |  |  |  |  |  \_ [10] target-test-RelWithDebInfo-bfe51efeee9ce22088ff.json
 |  |  |  |  |  \_ [11] target-ZERO_CHECK-Debug-9b77995f92fd9b6bff06.json
 |  |  |  |  |  \_ [12] target-ZERO_CHECK-MinSizeRel-9b77995f92fd9b6bff06.json
 |  |  |  |  |  \_ [13] target-ZERO_CHECK-Release-9b77995f92fd9b6bff06.json
 |  |  |  |  |  \_ [14] target-ZERO_CHECK-RelWithDebInfo-9b77995f92fd9b6bff06.json
 |  | [5] CMakeFiles
 |  |  | [6] 1cb4f4ff7b4d76a14ecfc6ba21618d89
 |  |  |  \_ [0] generate.stamp.rule
 |  |  | [7] 3.15.3
 |  |  |  | [8] CompilerIdC
 |  |  |  |  | [9] Debug
 |  |  |  |  |  | [10] CompilerIdC.tlog
 |  |  |  |  |  |  \_ [0] CL.command.1.tlog
 |  |  |  |  |  |  \_ [1] CL.read.1.tlog
 |  |  |  |  |  |  \_ [2] CL.write.1.tlog
 |  |  |  |  |  |  \_ [3] CompilerIdC.lastbuildstate
 |  |  |  |  |  |  \_ [4] link.command.1.tlog
 |  |  |  |  |  |  \_ [5] link.read.1.tlog
 |  |  |  |  |  |  \_ [6] link.write.1.tlog
 |  |  |  |  |  \_ [0] CMakeCCompilerId.obj
 |  |  |  |  |  \_ [1] CompilerIdC.exe.recipe
 |  |  |  |  | [10] tmp
 |  |  |  |  \_ [0] CMakeCCompilerId.c
 |  |  |  |  \_ [1] CompilerIdC.exe
 |  |  |  |  \_ [2] CompilerIdC.vcxproj
 |  |  |  | [9] CompilerIdCXX
 |  |  |  |  | [10] Debug
 |  |  |  |  |  | [11] CompilerIdCXX.tlog
 |  |  |  |  |  |  \_ [0] CL.command.1.tlog
 |  |  |  |  |  |  \_ [1] CL.read.1.tlog
 |  |  |  |  |  |  \_ [2] CL.write.1.tlog
 |  |  |  |  |  |  \_ [3] CompilerIdCXX.lastbuildstate
 |  |  |  |  |  |  \_ [4] link.command.1.tlog
 |  |  |  |  |  |  \_ [5] link.read.1.tlog
 |  |  |  |  |  |  \_ [6] link.write.1.tlog
 |  |  |  |  |  \_ [0] CMakeCXXCompilerId.obj
 |  |  |  |  |  \_ [1] CompilerIdCXX.exe.recipe
 |  |  |  |  | [11] tmp
 |  |  |  |  \_ [0] CMakeCXXCompilerId.cpp
 |  |  |  |  \_ [1] CompilerIdCXX.exe
 |  |  |  |  \_ [2] CompilerIdCXX.vcxproj
 |  |  |  | [10] x64
 |  |  |  |  | [11] Debug
 |  |  |  |  |  | [12] VCTargetsPath.tlog
 |  |  |  |  |  |  \_ [0] VCTargetsPath.lastbuildstate
 |  |  |  |  |  \_ [0] VCTargetsPath.recipe
 |  |  |  \_ [0] CMakeCCompiler.cmake
 |  |  |  \_ [1] CMakeCXXCompiler.cmake
 |  |  |  \_ [2] CMakeDetermineCompilerABI_C.bin
 |  |  |  \_ [3] CMakeDetermineCompilerABI_CXX.bin
 |  |  |  \_ [4] CMakeRCCompiler.cmake
 |  |  |  \_ [5] CMakeSystem.cmake
 |  |  |  \_ [6] VCTargetsPath.txt
 |  |  |  \_ [7] VCTargetsPath.vcxproj
 |  |  | [8] CMakeTmp
 |  |  \_ [0] cmake.check_cache
 |  |  \_ [1] CMakeOutput.log
 |  |  \_ [2] generate.stamp
 |  |  \_ [3] generate.stamp.depend
 |  |  \_ [4] generate.stamp.list
 |  |  \_ [5] TargetDirectories.txt
 |  | [6] Release
 |  |  \_ [0] test.exe
 |  | [7] test.dir
 |  |  | [8] Release
 |  |  |  | [9] test.tlog
 |  |  |  |  \_ [0] CL.command.1.tlog
 |  |  |  |  \_ [1] CL.read.1.tlog
 |  |  |  |  \_ [2] CL.write.1.tlog
 |  |  |  |  \_ [3] CustomBuild.command.1.tlog
 |  |  |  |  \_ [4] CustomBuild.read.1.tlog
 |  |  |  |  \_ [5] CustomBuild.write.1.tlog
 |  |  |  |  \_ [6] link.command.1.tlog
 |  |  |  |  \_ [7] link.read.1.tlog
 |  |  |  |  \_ [8] link.write.1.tlog
 |  |  |  |  \_ [9] test.lastbuildstate
 |  |  |  \_ [0] test.exe.recipe
 |  |  |  \_ [1] test.obj
 |  | [8] x64
 |  |  | [9] Release
 |  |  |  | [10] ALL_BUILD
 |  |  |  |  | [11] ALL_BUILD.tlog
 |  |  |  |  |  \_ [0] ALL_BUILD.lastbuildstate
 |  |  |  |  |  \_ [1] CustomBuild.command.1.tlog
 |  |  |  |  |  \_ [2] CustomBuild.read.1.tlog
 |  |  |  |  |  \_ [3] CustomBuild.write.1.tlog
 |  |  |  |  \_ [0] ALL_BUILD.recipe
 |  |  |  | [11] ZERO_CHECK
 |  |  |  |  | [12] ZERO_CHECK.tlog
 |  |  |  |  |  \_ [0] CustomBuild.command.1.tlog
 |  |  |  |  |  \_ [1] CustomBuild.read.1.tlog
 |  |  |  |  |  \_ [2] CustomBuild.write.1.tlog
 |  |  |  |  |  \_ [3] ZERO_CHECK.lastbuildstate
 |  |  |  |  \_ [0] ZERO_CHECK.recipe
 |  \_ [0] ALL_BUILD.vcxproj
 |  \_ [1] ALL_BUILD.vcxproj.filters
 |  \_ [2] CMakeCache.txt
 |  \_ [3] cmake_install.cmake
 |  \_ [4] test.sln
 |  \_ [5] test.vcxproj
 |  \_ [6] test.vcxproj.filters
 |  \_ [7] ZERO_CHECK.vcxproj
 |  \_ [8] ZERO_CHECK.vcxproj.filters
 | [4] out
 |  | [5] build
 |  |  | [6] x64-Debug
 |  |  |  | [7] .cmake
 |  |  |  |  | [8] api
 |  |  |  |  |  | [9] v1
 |  |  |  |  |  |  | [10] query
 |  |  |  |  |  |  |  | [11] client-MicrosoftVS
 |  |  |  |  |  |  |  |  \_ [0] query.json
 |  |  |  |  |  |  | [11] reply
 |  |  |  |  |  |  |  \_ [0] cache-v2-d75ff71bd9583bad9f48.json
 |  |  |  |  |  |  |  \_ [1] cmakeFiles-v1-9dad94293dc863f17844.json
 |  |  |  |  |  |  |  \_ [2] codemodel-v2-42a74e9e900b9e40954d.json
 |  |  |  |  |  |  |  \_ [3] index-2020-10-27T15-39-47-0716.json
 |  |  |  |  |  |  |  \_ [4] target-test-Debug-e2c31380241346bb4d52.json
 |  |  |  | [8] CMakeFiles
 |  |  |  |  | [9] 3.17.20032601-MSVC_2
 |  |  |  |  |  | [10] CompilerIdC
 |  |  |  |  |  |  | [11] tmp
 |  |  |  |  |  |  \_ [0] CMakeCCompilerId.c
 |  |  |  |  |  |  \_ [1] CMakeCCompilerId.exe
 |  |  |  |  |  |  \_ [2] CMakeCCompilerId.obj
 |  |  |  |  |  | [11] CompilerIdCXX
 |  |  |  |  |  |  | [12] tmp
 |  |  |  |  |  |  \_ [0] CMakeCXXCompilerId.cpp
 |  |  |  |  |  |  \_ [1] CMakeCXXCompilerId.exe
 |  |  |  |  |  |  \_ [2] CMakeCXXCompilerId.obj
 |  |  |  |  |  \_ [0] CMakeCCompiler.cmake
 |  |  |  |  |  \_ [1] CMakeCXXCompiler.cmake
 |  |  |  |  |  \_ [2] CMakeDetermineCompilerABI_C.bin
 |  |  |  |  |  \_ [3] CMakeDetermineCompilerABI_CXX.bin
 |  |  |  |  |  \_ [4] CMakeRCCompiler.cmake
 |  |  |  |  |  \_ [5] CMakeSystem.cmake
 |  |  |  |  | [10] CMakeTmp
 |  |  |  |  | [11] ShowIncludes
 |  |  |  |  |  \_ [0] foo.h
 |  |  |  |  |  \_ [1] main.c
 |  |  |  |  |  \_ [2] main.obj
 |  |  |  |  | [12] test.dir
 |  |  |  |  |  \_ [0] embed.manifest
 |  |  |  |  |  \_ [1] intermediate.manifest
 |  |  |  |  |  \_ [2] manifest.rc
 |  |  |  |  |  \_ [3] manifest.res
 |  |  |  |  |  \_ [4] test.cpp.obj
 |  |  |  |  |  \_ [5] vc140.pdb
 |  |  |  |  \_ [0] cmake.check_cache
 |  |  |  |  \_ [1] CMakeOutput.log
 |  |  |  |  \_ [2] TargetDirectories.txt
 |  |  |  | [9] Testing
 |  |  |  |  | [10] Temporary
 |  |  |  |  |  \_ [0] LastTest.log
 |  |  |  \_ [0] .ninja_deps
 |  |  |  \_ [1] .ninja_log
 |  |  |  \_ [2] build.ninja
 |  |  |  \_ [3] CMakeCache.txt
 |  |  |  \_ [4] cmake_install.cmake
 |  |  |  \_ [5] rules.ninja
 |  |  |  \_ [6] test.exe
 |  |  |  \_ [7] test.ilk
 |  |  |  \_ [8] test.obj
 |  |  |  \_ [9] test.pdb
 |  |  |  \_ [10] vc140.pdb
 |  |  |  \_ [11] VSInheritEnvironments.txt
 |  |  | [7] x64-Debug (predeterminado)
 |  |  |  | [8] .cmake
 |  |  |  |  | [9] api
 |  |  |  |  |  | [10] v1
 |  |  |  |  |  |  | [11] query
 |  |  |  |  |  |  |  | [12] client-MicrosoftVS
 |  |  |  |  |  |  |  |  \_ [0] query.json
 |  |  |  |  |  |  | [12] reply
 |  |  |  |  |  |  |  \_ [0] cache-v2-a724835a31b681b4f721.json
 |  |  |  |  |  |  |  \_ [1] cmakeFiles-v1-d8e3c91601c21a873970.json
 |  |  |  |  |  |  |  \_ [2] codemodel-v2-63d21b92c3988b719964.json
 |  |  |  |  |  |  |  \_ [3] index-2020-10-27T15-39-11-0668.json
 |  |  |  |  |  |  |  \_ [4] target-test-Debug-e2c31380241346bb4d52.json
 |  |  |  | [9] CMakeFiles
 |  |  |  |  | [10] 3.17.20032601-MSVC_2
 |  |  |  |  |  | [11] CompilerIdC
 |  |  |  |  |  |  | [12] tmp
 |  |  |  |  |  |  \_ [0] CMakeCCompilerId.c
 |  |  |  |  |  |  \_ [1] CMakeCCompilerId.exe
 |  |  |  |  |  |  \_ [2] CMakeCCompilerId.obj
 |  |  |  |  |  | [12] CompilerIdCXX
 |  |  |  |  |  |  | [13] tmp
 |  |  |  |  |  |  \_ [0] CMakeCXXCompilerId.cpp
 |  |  |  |  |  |  \_ [1] CMakeCXXCompilerId.exe
 |  |  |  |  |  |  \_ [2] CMakeCXXCompilerId.obj
 |  |  |  |  |  \_ [0] CMakeCCompiler.cmake
 |  |  |  |  |  \_ [1] CMakeCXXCompiler.cmake
 |  |  |  |  |  \_ [2] CMakeDetermineCompilerABI_C.bin
 |  |  |  |  |  \_ [3] CMakeDetermineCompilerABI_CXX.bin
 |  |  |  |  |  \_ [4] CMakeRCCompiler.cmake
 |  |  |  |  |  \_ [5] CMakeSystem.cmake
 |  |  |  |  | [11] CMakeTmp
 |  |  |  |  | [12] ShowIncludes
 |  |  |  |  |  \_ [0] foo.h
 |  |  |  |  |  \_ [1] main.c
 |  |  |  |  |  \_ [2] main.obj
 |  |  |  |  | [13] test.dir
 |  |  |  |  \_ [0] cmake.check_cache
 |  |  |  |  \_ [1] CMakeOutput.log
 |  |  |  |  \_ [2] TargetDirectories.txt
 |  |  |  | [10] Testing
 |  |  |  |  | [11] Temporary
 |  |  |  |  |  \_ [0] LastTest.log
 |  |  |  \_ [0] build.ninja
 |  |  |  \_ [1] CMakeCache.txt
 |  |  |  \_ [2] cmake_install.cmake
 |  |  |  \_ [3] rules.ninja
 |  |  |  \_ [4] VSInheritEnvironments.txt
 |  |  | [8] x64-Release
 |  |  |  | [9] .cmake
 |  |  |  |  | [10] api
 |  |  |  |  |  | [11] v1
 |  |  |  |  |  |  | [12] query
 |  |  |  |  |  |  |  | [13] client-MicrosoftVS
 |  |  |  |  |  |  |  |  \_ [0] query.json
 |  |  |  |  |  |  | [13] reply
 |  |  |  |  |  |  |  \_ [0] cache-v2-d88ddc0362b0bb492c59.json
 |  |  |  |  |  |  |  \_ [1] cmakeFiles-v1-a947d04201e740a7e60e.json
 |  |  |  |  |  |  |  \_ [2] codemodel-v2-5c5ae29cd242373451f1.json
 |  |  |  |  |  |  |  \_ [3] index-2020-10-27T15-47-33-0441.json
 |  |  |  |  |  |  |  \_ [4] target-test-Release-bc444c6aa3c5dd162646.json
 |  |  |  | [10] CMakeFiles
 |  |  |  |  | [11] 3.17.20032601-MSVC_2
 |  |  |  |  |  | [12] CompilerIdC
 |  |  |  |  |  |  | [13] tmp
 |  |  |  |  |  |  \_ [0] CMakeCCompilerId.c
 |  |  |  |  |  |  \_ [1] CMakeCCompilerId.exe
 |  |  |  |  |  |  \_ [2] CMakeCCompilerId.obj
 |  |  |  |  |  | [13] CompilerIdCXX
 |  |  |  |  |  |  | [14] tmp
 |  |  |  |  |  |  \_ [0] CMakeCXXCompilerId.cpp
 |  |  |  |  |  |  \_ [1] CMakeCXXCompilerId.exe
 |  |  |  |  |  |  \_ [2] CMakeCXXCompilerId.obj
 |  |  |  |  |  \_ [0] CMakeCCompiler.cmake
 |  |  |  |  |  \_ [1] CMakeCXXCompiler.cmake
 |  |  |  |  |  \_ [2] CMakeDetermineCompilerABI_C.bin
 |  |  |  |  |  \_ [3] CMakeDetermineCompilerABI_CXX.bin
 |  |  |  |  |  \_ [4] CMakeRCCompiler.cmake
 |  |  |  |  |  \_ [5] CMakeSystem.cmake
 |  |  |  |  | [12] CMakeTmp
 |  |  |  |  | [13] ShowIncludes
 |  |  |  |  |  \_ [0] foo.h
 |  |  |  |  |  \_ [1] main.c
 |  |  |  |  |  \_ [2] main.obj
 |  |  |  |  | [14] test.dir
 |  |  |  |  |  \_ [0] test.cpp.obj
 |  |  |  |  \_ [0] cmake.check_cache
 |  |  |  |  \_ [1] CMakeOutput.log
 |  |  |  |  \_ [2] TargetDirectories.txt
 |  |  |  | [11] Testing
 |  |  |  |  | [12] Temporary
 |  |  |  |  |  \_ [0] LastTest.log
 |  |  |  \_ [0] .ninja_deps
 |  |  |  \_ [1] .ninja_log
 |  |  |  \_ [2] build.ninja
 |  |  |  \_ [3] CMakeCache.txt
 |  |  |  \_ [4] cmake_install.cmake
 |  |  |  \_ [5] rules.ninja
 |  |  |  \_ [6] test.exe
 |  |  |  \_ [7] test.exe.manifest
 |  |  |  \_ [8] VSInheritEnvironments.txt
 \_ [0] CMakeLists.txt
 \_ [1] CMakeSettings.json
 \_ [2] test.cpp
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
