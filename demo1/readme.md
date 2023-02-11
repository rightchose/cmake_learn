##### 项目目录结构
```
    .
    |-- CMakeLists.txt
    |-- build
    |-- cmake_dir1
    |   |-- CMakeLists.txt
    |   `-- main.cpp
    |-- cmake_dir2
    |   |-- CMakeLists.txt
    |   `-- main.cpp
    |-- include
    |-- lib
    |-- obj
    `-- readme.md
```
**目录说明**
- `build`目录存放CMake构建项目时生成的文件，**cmake命令也是在build目录下执行的**。
- `cmake_dirxx`目录表示两个功能独立的代码模块，目录内的`CMakeLists.txt`为各自模块的配置文件。
- `CMakeLists.txt`是此项目顶级的CMake配置文件，包括了构建项目时的一些总体设置。
- `inlcude`文件夹存放用于构建项目时的头文件。例如，`cmake_dirxx`目录中的cpp文件使用到了一些头文件，可以放在此处。
- `lib`目录存放用于构建项目时需要的共享库。
- `obj`目录存放项目生成温计，如可执行二进制文件或共享库等。这里会生成我们的结果。
**注意**
上面的目录说明和`CMakeLists.txt`中的配置相关，不同配置使用不同的。


##### 步骤
1、生成`lib`文件下需要使用的共享库
```
cd lib
g++  -I../include --shared -fPIC -o libfileA.so fileA.cpp
g++  -I../include --shared -fPIC -o libfileB.so fileB.cpp
```
2、构建
```
cd build
cmake .. # 生成makefile文件
make
```
3、测试
```
cd obj
./cmake_test1
./cmake_test2
```
