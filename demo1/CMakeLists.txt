# CMake版本要求
cmake_minimum_required(VERSION 2.8)

# 生成的可执行文件和共享库的存放位置 
# PROJECT_SOURCE_DIR表示项目的顶级目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/obj)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/obj)

# 头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 共享库位置
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

# 添加构建子目录
ADD_SUBDIRECTORY(cmake_dir1)
ADD_SUBDIRECTORY(cmake_dir2)
