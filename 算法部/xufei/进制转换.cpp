#include "stdio.h"
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
typedef int datatype;
typedef struct {  
	datatype stack[MAXSIZE];
	int top;
} seqstack;

void setnull(seqstack *s) { 
	s->top=-1;
}
int empty(seqstack *s) {
	if(s->top<0)
		return TRUE;
	else
		return FALSE;
}

int push(seqstack *s,datatype x) { 
	if(s->top>=MAXSIZE-1) {
		printf("stack overflow!\n"); 
		return FALSE;
	} else {
		s->stack[++s->top]=x;
		return TRUE;
	}
}

datatype pop(seqstack *s) { 
	if(s->top<0) {
		printf("stack empty!\n"); 
		return NULL;
	} else {
		s->top--;
		return(s->stack[s->top+1]);
	}
}
void transform(seqstack *s,int x,int y) {
	int z;
	while(x!=0) {
		push(s,x%y);
		x=x/y;
	}
	while(empty(s)!=TRUE	) {
		z=pop(s);
		printf("%d",z);
	}
}



main() {
	int x,y;
	seqstack q;
	setnull(&q);
	printf("请输入想要转换的数值：\n");
	scanf("%d",&x); 
	printf("请输入想要转换的进制：\n");
    scanf("%d",&y); 
    printf("已转换：\n");
    transform(&q,x,y);
}



