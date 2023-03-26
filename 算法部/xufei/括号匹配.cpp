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
int judge(seqstack *s) { 
	datatype symb,ch,store;
	push(s,'#');
	symb=getchar();
	while(symb!='#') {
		switch(symb) {
			case '(':
			case '[':
			case '{':
				push(s,symb);
				break;
			case ')':
				ch=pop(s);
				if(ch!='(') return FALSE;
				break;
			case ']':
				ch=pop(s);
				if(ch!='[') return FALSE;
				break;
			case '}':
				ch=pop(s);
				if(ch!='{') return FALSE;
				break;
			default:
				;
		}
		symb=getchar();
	}
	if(pop(s)=='#') return TRUE;
	else return FALSE;
}

main() {
	seqstack q;
	setnull(&q);
	printf("please input an express end with symbol '#':\n");
	if(judge(&q)) printf("ÕýÈ·\n");  
	else          printf("´íÎó\n"); 
}
