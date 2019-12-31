# 1.
```c
int *ints[20] = {10, 20, 30, 40,....200};
int *ip = ints + 3;
```

| 表达式 | 值 | 表达式 | 值 |
| - | - | - |- |
| ints | ints首元素的地址值 |  ip | 第4个元素（40）的地址 |
| ints[4] | 50  | ip[4]  | 80 |  
| ints + 4 | 50的地址  | ip + 4 | 80的地址 |
|  *ints + 4  |  14 | *ip + 4  | 44 |
| *(ints + 4) |  50 | *(ip + 4)  | 80|
| ints[-2] |  illegal | ip[-2] | 20 |
| &ints | “ints首元素的地址值”的地址值   | &ip | “第4个元素（40）的地址”的地址值 |
| &ints[4] | 50的地址 | &ip[4]  | 80的地址 |
| &ints + 4 | illegal  | &ip + 4  | illegal |
| &ints[-2]| illegal  |  &ip[-2] |20的地址 |

answer：
- &ints	100 同int	
- &ip	unknown

- &ints + 4 | 50的地址 同int + 4  
- &ip + 4  | unknown

？？？why？

# 5. 
性能损失/要求不太高，但是可读性、维护成本要求高的

# 8.
？？？隐式转换？
？全部legal？

answer 隐式转换不存在。
问题在b，本来是指针，结果声明为数组。“提取一些任意内存位置的内容”

# 12.
遍历顺序

# 17.
```c
//do you mean?
void function( int const *a, int const b[]);
```
a指向的内容不可变，a本身可以变
b都不可变，因为数组名是指针常量。 （X）

answer：
按原题：
```c
void function( int const a, int const b[]);
```
a是标量，值传递，const并不是防止值被修改。
b也是值传递，但是可以通过间接访问修改值，const是防止此类修改

