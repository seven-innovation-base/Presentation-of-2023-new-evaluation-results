#include "stdio.h"
#include "malloc.h"   /*包含动态分配内存函数*/
#define TRUE 1
#define FALSE 0

typedef int elemtype;
typedef struct node   /*链表结点类型定义*/
 {elemtype data;      /*结点数据域*/
  struct node *next;  /*结点的指针域*/
 }linklist;

 linklist *creatlist() 
 {			            
  int x;
  linklist *head,*r,*p;
  p=(linklist*)malloc(sizeof(linklist));
  head=p;
  p->next=NULL;
  r=p;
  scanf("%d",&x);
  while(x!=-1)
   {
    p=(linklist*)malloc(sizeof(linklist));
    p->data=x;
    p->next=NULL;
    r->next=p;
    r=r->next;
    scanf("%d",&x);
   }
  return (head);
  }

 /*请补充下方的函数，功能是实现有序表中的插入运算*/
   void order_insert(linklist *head,elemtype x)
   {
   linklist *p,*q,*s;
   q=head;
   p=head->next;
   while(p!=NULL)
   if(p->data<x)
   {q=p;
   p=p->next;}
   else break;
   
   s=(linklist*)malloc(sizeof(linklist));
   s->data=x;
  q->next=s;
  s->next=p;
   }

  void print(linklist *head)  /*打印出链表head中各个结点的值*/
  {linklist *p;
  p=head->next;
  while(p!=NULL)
  {printf("%d ",p->data);
   p=p->next;
  }
  printf("\n");
  }

 int main() /*主函数*/
 {linklist *head;  /*定义指向链表的指针head*/
  int x;
  printf("please input the linklist and end by -1:\n");
  head=creatlist();
  print(head);
  printf("now start insert,please input the insert value:\n");
  scanf("%d",&x);
  
  order_insert(head,x);
  print(head);
  return 0;
  }

