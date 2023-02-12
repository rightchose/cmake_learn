#### 检查环境
这里用到了cmake提供的`CheckFunctionExists.cmake`，同时涉及了`include`用法。
```
# 检查系统是否支持 pow 函数
# CheckFunctionExists.cmake是cmake提供的，可以去其安装目录下寻找
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
# 将结果存放到HAVE_POW
check_function_exists (pow HAVE_POW)
```

#### 打包
TODO

