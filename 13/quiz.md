# 1. 
答案：8/3/10/11/4/9/16/7/6/19/21/23/25
a. 名为abc的函数，返回值int
```c
int abc();
//返回值为int的函数
```
b. 名为abc的int数组
```c
int abc[3];
//int型数组
```
c. 名为abc的函数，返回值**int
```c
int **abc();
//返回值为“int型指针的指针”的函数。
```
d. 名为abc的函数指针，返回值为int
```c
int (*abc)();
//返回值为int的函数指针
```
e. 指向一个数组的指针
```c
int (*abc)[6];
//指向int型数组的指针
```
f. 名为abc的函数，返回值*int
```c
int *abc();
//返回值为“int型指针”的函数。
```
g. 函数指针数组（6个），每个函数的返回值是**int
```c
int **(*abc[6])();
//指向“返回值为int型指针的指针的函数”的指针的数组。
```
h. 指针数组，**int
```c
int **abc[6];
//int型指针的指针数组
```
i. 指向一个数组的指针的数组，这个数组每个元素是*int (你吖眼花了，这题简单)
```c
int *(*abc)[6];
//指向“int型指针数组”的指针
```
j. 函数名，返回另一个函数指针，()=> *int
```c
int *(*abc())();
//返回值为“返回值为int型指针的函数指针”的函数。
```
k. 函数指针，返回值是 ()=>int 函数指针的指针
```c
int (**(*abc)())();
//返回值为“返回值为int的函数指针的指针”的函数指针。
```
l. 函数指针，返回值是指向一个int数组的指针
```c
int (*(*abc)())[6];
//返回值为“指向int型数组的指针”的函数指针
```
m. 函数指针，返回值是指向 “一个函数指针数组，每个函数返回值是*int”的指针

最后检查意见：不对！
函数指针，返回值是指向“函数指针数组”的指针，每个函数的返回值是*int
好像一回事哈
```c
int *(*(*(*abc)())[6])();
//before
int *(*xx[6])();
//after
int *(*(*xx)[6])();
```

# 4.
```c
Product *product = trans->product;
product -> orders += 1;
int quantity = trans -> quantity;
product -> quantity_on_hand -= quantity;
product -> supplier -> reorder_quantity += quantity;
if (product->export_restricted) {
    ...
}

/*
答案：register Product *product = trans->product; 
"把指针放入寄存器好处相当突出"
*/
```


# 7.
优点：现成的函数，不用费心
缺点没想好，可能不能灵活的解析参数了吧。

answer： 你缺了一句很厉害的话：程序的可移植性！！！

# 11.
可能有很多其他指针也使用了这个常量，会影响他们。

answer：这是第二点。
第一点是： 有的编译器压根儿不让你修改这个区域内的常量。