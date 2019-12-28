# 2. 程序结果

```c
int tmp;
/* 
左边func第一次调用时，返回值是 2， counter为2
右边调用时，返回值是3， counter 为 3
tmp 则为6
*/
tmp = func() * func(); 
/* 
左边func第一次调用时，返回值是 4， counter为 4
tmp 则为6
4 - 6 = -2 对吗？
*/
answer = func() - tmp；
```

答案：

为什么？不慌看答案，自己用gdb调试先（算了，一行内咋调试。。。）
```c
    int a = func(); 
    int b = a * func();
    answer = func() - b;
    printf("%d\n", answer);
```

才是 -2. 编译器干了一些别的事情。

2 - 3 * 4??? = -10

# 4. 条件操作符和if谁快谁慢？
复习一下。
好像差不多把。。。

# 6. 副作用的操作符
后置 ++ ？
&& ||? 

anyway, WTF is 副作用？

answer：
1. ++ -- 前后置
2. = 和复合操作符

副作用，大概就是能改变它们作用的值
