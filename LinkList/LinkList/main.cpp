//
//  main.cpp
//  LinkList
//
//  Created by kidd on 2018/9/12.
//  Copyright © 2018年 Kidd. All rights reserved.
//  2015年计算机联考真题  将链表中绝对值相同的元素只保留第一个,其他重复的删除

#include <iostream>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(LinkList &L, int* list, int len){
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = NULL;
    for (int i = len-1; i >= 0; i--) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = list[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

void Print(LinkList L){
    LNode *s = L->next;
    while (s != NULL) {
        printf("%d ",s->data);
        s = s->next;
    }
    printf("\n");
}

void func(LinkList &L, int len){
    LNode *p=L, *r;
    int *q,m;
    q=(int *)malloc(sizeof(int)*(len+1));
    for (int i=0; i<len+1; i++) {
        *(q+i) = 0;
    }
    while (p->next!=NULL) {
        m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (*(q+m)==0) {
            *(q+m)=1;
            p=p->next;
        }else{
            r=p->next;
            p->next=r->next;
            free(r);
        }
    }
    free(q);
}


int main(int argc, const char * argv[]) {
    
    int data[] = {1,-2,2,-1,3};
    int len = sizeof(data)/sizeof(int);
    LinkList list;
    CreateList(list, data, len);
    Print(list);
    
    func(list,len);
    Print(list);
    return 0;
}
