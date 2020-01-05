# 2.
结构名：标量
数组名：指针（常量）

# 7.
node[5]
*np: nodes + 2
**npp = &nodes[1].b
画出图会比较好理解。
nodes起始于200
| 表达式 | 值 | 
| - | - | 
| nodes |  200 |
| nodes.a|  illegal |
| nodes[3].a|  12 |
| nodes[3].c |  200 |
| nodes[3].c->a |  5 |
| *nodes |  {5, nodes + 3, null} |
| *nodes.a | illegal, 优先级.高  | 
|  (*nodes).a |  5 |
| nodes -> a | 5  |
| nodes[3].b -> b | 248  |
| \*nodes[3].b -> b| illegal 优先级问题 *错误:答案是整个nodes[4] 那个结构体， \* 是最后作用的  -> 的优先级高于\* * |
| &nodes | 200 |
| &nodes[3].a | 236 同样面临优先级问题|
| &nodes[3].c | 244 优先级|
|&nodes[3].c -> a | 200 ?假设*&优先级一致  |
| &nodes -> a| 200 |
| np |  224 |
| np -> a| 22 |
| np -> c -> c -> a| 15 |
| npp| 216 |
| npp -> a| illegal |
| *npp| 248 |
| **npp| {18, nodes + 2, nodes + 1} |
| *npp -> a| illegal |
| (*npp) -> a| 18 |
| &np|  224 ??????? *答案： 未知 不知道编译器在什么位置存储np*|
| &np -> a| 224 |
| &np -> c -> c -> a|  212 |


# 11.
不使用位段
从左向右分配内存 
16位机器
```c
    int struct_replace;
    struct_replace ||= (aaa<<12 || bbb << 4 || ccc << 1 || ddd);
```
