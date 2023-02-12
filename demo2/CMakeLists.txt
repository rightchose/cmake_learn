# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

# 版本号
set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)


# https://stackoverflow.com/questions/566785/cmake-add-build-directory-to-include-path
# 将build目录加入到cmake的include目录
# 这里因为cmake使用在构建时，会在构建目录生成一个config.h文件
# 需要将该目录加入进来
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH
	   "Use provided math implementation" OFF)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})


# 安装
install(TARGETS Demo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)

# 测试
enable_testing()
# 基础的测试
add_test(test_5_2_demo Demo 5 2)

# 添加信息的测试
add_test(test_5_2_info Demo 5 2)
set_tests_properties(test_5_2_info
      PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

# 测试帮助信息是否可以正常提示
add_test(test_usage Demo)
set_tests_properties(test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")


# 定义宏用来简化测试工作
macro(do_test arg1 arg2 result)
  add_test(test_${arg1}_${arg2} Demo ${arg1} ${arg2})
  set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

do_test(5 2 "is 25")
do_test(10 2 "is 100")


# CMake支持gdb，指定Debug模式开启-g选项
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")




