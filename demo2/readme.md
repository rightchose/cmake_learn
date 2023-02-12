#### 自定义编译选项以及安装测试

[参考](https://www.hahack.com/codes/cmake/)

#### 目录介绍
```
    .
    |-- CMakeLists.txt
    |-- config.h.in
    |-- main.cc
    |-- math
    `-- readme.md
```
- `math`目录下存放`power`函数的实现以及对应的`CMakeList.txt`。
- `config.h.in`文件，cmake使用其生成`config.h`文件。
- `main.cc`代码依据`USE_MYMATH`来选择是否调用标准库还是`math`下的实现。

#### CMake执行过程
```
mkdir build
cd build
cmake
```
这里的自定义编译选项通过`CMakeLists.txt`控制，首先会依据`config.h.in`在`build`目录生成一个`config.h`文件。注意下这里的的`set(CMAKE_INCLUDE_CURRENT_DIR PN)`，使用该语句后，后面的`make`才能“看到”`config.h`文件。
这里稍微复杂点的是，cmake通过配置生成`config.h`，进而控制`main.cc`的行为。

一个思路，CMake通过这种技术可以修改配置，改变程序的行为。例如为程序添加版本号，可以按照下面的方法修改
`CMakeLists.txt`:
```
# 版本号
set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)
```
`config.h.in`
```
// the configured options and settings for Tutorial
#define Demo_VERSION_MAJOR @Demo_VERSION_MAJOR @
#define Demo_VERSION_MINOR @Demo_VERSION_MINOR @
```

#### 安装和测试
安装测试的核心代码就在根目录的`CMakeLists.txt`
```

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
```


#### 对GDB的支持
```
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

```