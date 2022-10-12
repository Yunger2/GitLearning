project(Knocker)
set(CMAKE_CXX_COMPILER "g++")
#默认路径位cmakelist.txt文件所在路径,即${CMAKE_CURRENT_SOURCE_DIR}/
include_directories(./include)        #头文件目录路径
aux_source_directory(./src SrcFiles)  #路径 文件变量  将所有cpp源文件列表写在变量SrcFiles中

#[[
set(DLLSRC ./src/my_print.cpp)
set(LIBRARY_OUTPUT_PATH ./lib)
add_library(print SHARED ${DLLSRC})      #库名称 命令（SHARED为动态库，对应生成.dll和.dll.a(同lib)） cpp文件名
add_library(printlib STATIC ${DLLSRC})   #库名称 命令（STATIC为静态库，对应生成.a,即.lib）           cpp文件名
#注：库名称需要不同，否则无法同时生成
]]

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)            #动态库、静态库目录

message("进入cmake")
#条件判断debug or release 便于自动区分运行和调试
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("进入Release")
    set(CMAKE_BUILD_TYPE Release)
    set(EXECUTABLE_OUTPUT_PATH ../bin/release)   # 默认当前文件路径为起始，将生成的二进制文件放在对应目录下
    add_executable(my_cmake_Release ${SrcFiles})
    #target_link_libraries(my_cmake_Release libprintlib.a)  #调用静态库
    file(COPY lib/libprint.dll DESTINATION ../bin/release) #调用动态库时需要将dll复制到exe同一目录下，否则无法运行。
    target_link_libraries(my_cmake_Release libprint.dll) #调用动态库
else()
    message("进入Debug")
    set(CMAKE_BUILD_TYPE Debug)
    set(EXECUTABLE_OUTPUT_PATH ../bin/debug)   # 默认当前文件路径为起始，将生成的二进制文件放在对应目录下
    add_executable(my_cmake_debug ${SrcFiles})
    #target_link_libraries(my_cmake_debug libprintlib.a)   #调用静态库
    file(COPY lib/libprint.dll DESTINATION ../bin/debug)  #调用动态库时需要将dll复制到exe同一目录下，否则无法运行。
    target_link_libraries(my_cmake_debug libprint.dll)  #调用动态库
endif()

#终端查看带中文的txt命令： cat .\CMakeLists.txt -Encoding UTF8
