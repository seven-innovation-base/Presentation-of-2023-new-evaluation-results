#include<stdio.h>
#define maxsize 100
int mg[6][6]={ {1,1,1,1,1,1},{1,0,0,0,1,1},
				  {1,0,1,0,0,1},{1,0,0,0,1,1},
				  {1,1,0,0,0,1},{1,1,1,1,1,1} };
typedef struct {
	int i, j, di;
}box;
typedef struct {
	box data[maxsize];
	int top;
}stack;
void Initstack(stack*& s)
{
	s = new stack;
	s->top = -1;
}
bool push(stack*& s, box e)
{
	if (s->top == maxsize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool pop(stack*& s, box &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool gettop(stack*& s, box& e) 
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}
bool mgpath(int x, int y, int xi, int yi)
{
	int min = 100, _min=1;
	int i, j, di,count=1,k,a,b;
	int flag = 0;
	box e;
	bool find;
	stack* s;
	Initstack(s);
	e.i = x;
	e.j = y;
	e.di = -1;
	push(s, e);
	mg[x][y] = -1;
	while (s->top != -1)
	{
		gettop(s, e);
		i = e.i;
		j = e.j;
		di = e.di;
		if (i == xi && j == yi)
		{
			flag = 1;
			if (s->top +1< min)
			{
				min = s->top+1;
				_min = count;
			}
			printf("第%d条路径如下：\n", count++);
			for (k = 0; k <= s->top; k++)
				printf("(%d,%d)\t", s->data[k].i, s->data[k].j);
			printf("\n");
			pop(s, e);
			mg[e.i][e.j] = 0;
			continue;
		}
		find = false;
		while (di < 4 && !find)
		{
			di++;
			switch (di)
			{
			case 0:a = i - 1, b = j; break;
			case 1:a = i, b = j + 1; break;
			case 2:a = i + 1, b = j; break;
			case 3:a = i, b = j - 1; break;
			}
			if (mg[a][b] == 0)
				find = true;
		}
		if (find)
		{
			s->data[s->top].di = di;
			e.i = a;
			e.j = b;
			e.di = -1;
			push(s, e);
			mg[a][b] = -1;
		}
		else 
		{
			pop(s, e);
			mg[e.i][e.j] = 0;
		}
	}
	if (flag == 1)
	{
		printf("最短路径为路径%d\n", _min);
		printf("最短路径长度为%d\n", min);
		return true;
	}
	delete(s);
	return false;
}
int main()
{
	if (!mgpath(1, 1, 4, 4))
		printf("该迷宫问题没有解！\n");
	return 0;
}
 
 
 
 
