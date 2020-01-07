#include <stdio.h>
#include "singly_linked_list_node.h"

int 
count_nodes_in_sll(Node* node)
{
    /*
        answer: 灰常简单的函数！
        但是还说了一句意味深长的话：
        虽然只能用于它被声明的那种类型的节点，你必须知道节点的内部结构。
        nani？难道不知道内部的内部结构也能搞起？下一章讨论解决这个问题的技巧，那就期待吧。
    */
    //给定单链表任意节点node，计数从它到末尾的节点数
    // if (node == NULL) return 0;
    // int count = 1;
    // while((node = node->link) != NULL) count++;
    // return count;
    int count = 0;
    for (; node != NULL; node = node->link, count++)
    ;
    return count;
}
