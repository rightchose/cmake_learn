/*
    编译生成共享库，这里的头文件放在了上一级的include目录下，编译共享库时需要用下面的命令,
    绝对路径
    g++  -I/home/mr/code/github/cmake_learn/demo1/include --shared -fPIC -o libfileA.so fileA.cpp
    相对路径
    g++  -I../include --shared -fPIC -o libfileA.so fileA.cpp

    注意：生成的共享库开头要以lib开头
 */

#include "fileA.h"

int funA()
{
    cout << "This is funA in fileA print out!" << endl;

    return 0;
}
