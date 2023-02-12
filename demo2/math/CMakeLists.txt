# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 指定生成 MathFunctions 链接库
add_library (MathFunctions ${DIR_LIB_SRCS})


# 安装
# 指定MathFunctions库的安装路径
# 会将生成的libMathFunctions.so复制到/usr/local/bin下
# 同时头文件也会被复制到/usr/local/include下
install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.h DESTINATION include)

