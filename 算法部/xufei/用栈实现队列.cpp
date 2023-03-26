#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
#define ElemType int
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;
void InitStack(SeqStack *s){
    s->top=-1;
}
bool StackEmpty(SeqStack &s){
    if(s.top==-1)
        return true;
    return false;
}
bool Push(SeqStack &s,ElemType e){
    if(s.top==MAXSIZE-1)
        return false;
    s.data[++(s.top)]=e;
    return true;
}
bool Pop(SeqStack &s,ElemType &e){
    if(s.top==-1)
        return false;
    e=s.data[(s.top)--];
    return true;
}
bool GetTop(SeqStack &s,ElemType &e){
    if(s.top==-1)
        return false;
    e=s.data[s.top];
    return true;
}
void check(bool flag){
    if(flag)
        printf("操作成功!\n");
    else
        printf("操作失败！\n");
}
void display(SeqStack &s){
    int index=s.top;
    while(index>-1){
        printf("%d ",s.data[index--]);
    }
    printf("\n");
    if(index==s.top)
        printf("队列元素为空！");
}
int main(){
    int n;
    //栈的初始化
    SeqStack s,s2;
    printf("顺序栈的基本操作\n");
    printf("栈1的初始化\n");
    InitStack(&s);
    printf("栈1的初始化\n");
    InitStack(&s2);
    printf("模拟队列\n");
    while(1){
        int op;
        int e;
        bool flag;
        printf("请选择操作\n1.进队列\n2.出队列\n3.判空\n4.获取队列头部元素\n5.打印队列中所有元素\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("入队列元素：");
            scanf("%d",&e);
            flag=Push(s,e);
            check(flag);
            if(!StackEmpty(s)&&!StackEmpty(s2)){
                //如果栈2元素还没弹出时，再栈1加入新元素时，
                //为了保证队列的连贯性，必须让前面所有元素出栈2
                printf("清除栈2所有元素！\n");
                while(!StackEmpty(s2)){
                    flag=Pop(s2,e);
                    if(flag)
                        printf("队列头部元素出队列，出队列元素为：%d\n",e);
                }
            }
            break;
        case 2:
            while(!StackEmpty(s)){
                Pop(s,e);
                Push(s2,e);
            }
            flag=Pop(s2,e);
            check(flag);
            if(flag)
                printf("队列头部元素出队列，出队列元素为：%d\n",e);
            break;
        case 3:
            flag=StackEmpty(s2);
            if(StackEmpty(s)&&StackEmpty(s2))
                printf("队列为空！\n");
            else
                printf("队列非空！\n");
            break;
        case 4:
            while(!StackEmpty(s)){
                Pop(s,e);
                Push(s2,e);
            }
            flag=GetTop(s2,e);
            check(flag);
            if(flag)
                printf("队列头部元素为：%d\n",e);
            break;
        case 5:
            while(!StackEmpty(s)){
                Pop(s,e);
                Push(s2,e);
            }
            display(s2);
        default:
            break;
        }
    }

    return 0;
}


