# change-value-anydata
 本目录用来练习各种数据类型修改内部数据的方式，结合其他仓all-datatype-sort和 use-pointer-anywhere 来规划这个项目 

a-1.c
 1.将各种数据类型的数据初始化为0 或 '\0' , NULL等
 2.使用函数传参，将原始数据的值或者（数组）其中的某一个值修改成目的值
 3.在主函数中输出修改后的数据

#参考连接
#一种整行修改数据的方式
#https://zhidao.baidu.com/question/431980329092880404.html
#一种通过??数组指针的方式 ？？很可惜为给出实现.
#https://www.zybang.com/question/9d724ab9f2204c5865924689f0da7a2a.html
--------------------------------------------------
 b-1.c
 不使用函数传参，直接在主函数中完成a-1的事情。


 思考:
 1. 字符串数组， 整形二维数组 在处理上面是不是有一些共同点呢，不急，想明白此事后，大致上对指针便有了较深刻的理解
 2. 记得优化代码，比如第5点就可以不使用q指针，仅仅用一个p指针就可以了。
