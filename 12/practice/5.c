#include <stdio.h>
#include "singly_linked_list_node.h"

#define TRUE 1
#define FALSE 0

/*
    answer： 接受指针：
    对不同的链表包含不同的头文件，一套代码可以作用域任何类型的值！！！
    骚气！

    编程部分：
    1. assert头文件； assert(delete != NULL);
    2. 少声明一些变量，并且把while循环写的更紧凑
*/
int
sll_remove( struct NODE **rootp, struct NODE *node)
{
    register struct NODE **cur = rootp;
    register struct NODE *this = *rootp;
    while(this != NULL){
        if (this != node){
            *cur = (*cur) -> link;
            this = this->link;
        }else{
            //remove "this"
            *cur = this -> link;
            free(this);//TODO this on heap???
            this = NULL;
            return TRUE;
        }
    }
    return FALSE;

}

int
sll_remove2( struct NODE **rootp, struct NODE *node)
{
    register struct NODE **cur = rootp;
    register struct NODE *this = *rootp;
    
    while(this != NULL && this != node){
        *cur = (*cur) -> link;
         this = this->link;
    }
    /*
        这段while循环answer的写法：
        while((this = *rootp) != NULL && this != node)
            rootp = &current -> link;
        一回事，更紧凑。
    */
    if (this == NULL) return FALSE;
    //remove "this"
    *cur = this -> link;
    free(this);//TODO this on heap???
    this = NULL; //answer中没有它
    return TRUE;
}
