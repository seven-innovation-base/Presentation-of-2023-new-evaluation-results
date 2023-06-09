#include <stdio.h>     
#include <stdlib.h>    
#include <conio.h>     
int i,j; 
void draw_map(int map[10][12]); //声明画图函数
int main()
{
	system("title ");
	char input;   
	int count=0;   //定义记分变量
	int map[10][12] = {{2,2,2,2,2,1,1,1,1,1,2,2},
		{1,1,1,1,2,1,0,0,0,1,1,2},
		{1,0,0,1,1,1,0,1,0,0,1,2},
		{1,0,4,3,3,3,3,3,1,0,1,1},
		{1,0,0,1,1,3,3,3,4,0,0,1},
		{1,0,0,0,0,4,1,1,4,1,0,1},
		{1,0,4,1,4,0,0,0,4,0,0,1},
		{1,1,0,6,0,1,1,1,4,1,0,1},
		{2,1,1,1,1,1,2,1,0,0,0,1},
		{2,2,2,2,2,2,2,1,1,1,1,1}
	};
	while (1)   //死循环，等待用户命令
	{
		system("CLS");
		for (i=0;i<12;i++)
		{
			printf("%d",i);
		}
		printf("\n");
		/*for (i=1;i<10;i++)
		{
			printf("%d\n",i);
		}*/
		printf("\n");
		draw_map(map);
		printf("当前得分：%d\n",count);
		//找初始位置
		for (i=0;i<10;i++)
		{
			for (j=0;j<12;j++)
			{
				if (map[i][j]==6||map[i][j]==9)
					break;
			}
			if (map[i][j]==6||map[i][j]==9)
				break;
		}
		printf("您的当前坐标（%d，%d）",i,j);        
		input = getch();   //用getch()函数无需回车确认地获取用户输入，用于控制行走方向。
		switch (input)
		{
		case 'w':
			//如果人前面是空地。  //0代表空地  6代表人  //3代表目的地
			if(map[i-1][j]==0)
			{
				map[i-1][j]=6+0; //人往前走一步，ID为人的ID（）加上空地的ID（）。
				if(map[i][j]==9) //如果当前人站的位置为目的地，则ID为（即人的ID（）加上目的地ID（））。
					map[i][j]=3; //将人往前走一步后原地的ID修改为空地ID（）。
				else
					map[i][j]=0;    //否则原地ID修改为空地ID 。      
			}
			//如果人前面是目的地。
			else if((map[i-1][j]==3)||(map[i-1][j]==9))
			{
				map[i-1][j]=6+3; //人往前走一步，ID为人ID+目的地ID=9。
				if(map[i][j]==9) //如果原地也是目的地（ID为）。
					map[i][j]=3; //人走后把原地ID修改回目的地ID。
				else
					map[i][j]=0; //否则原地ID修改为为空地ID
			}
			//如果人前面是箱子。//4代表箱子   //7箱子进入目的地
			else if(map[i-1][j]==4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i-2][j]==0)
				{ 
					map[i-2][j]=4; //人推箱子往前走一步，把空地ID修改为箱子ID（）
					//下面是对箱子原地进行判断
					if(map[i-1][j]==7) //如果箱子原地为目的地。
						map[i-1][j]=9; //人站在箱子的原地（目的地）时该地ID应该为人的ID+目的地ID=9。
					else
						map[i-1][j]=6; //否则，人站在了原来的空地上，ID应该为+0=6。
					//下面是对人原地进行判断
					if(map[i][j]==9) //如果之前是目的地。
						map[i][j]=3; //人走了之后修改回目的地ID。
					else
						map[i][j]=0; //否则就是空地。
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i-2][j]==3)
				{ 
					map[i-2][j]=7;   //ID为（目的地ID（）+箱子ID（）=7），表示已经把箱子推入了目的地。
					count++;
					//下面是对箱子原先位置的判断，同上。
					if(map[i-1][j]==7)
						map[i-1][j]=9;
					else
						map[i-1][j]=6;
					//下面是对人原先位置进行判断，同上。
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（ID=7）。
			else if(map[i-1][j]==7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if(map[i-2][j]==0)
				{
					count--;
					map[i-2][j]=4;   //把箱子重新推到空地上，ID=箱子ID+空地ID=4。
					map[i-1][j]=9;   //人自然而然的就站在了原先的目的地上了。
					//下面是对人原先地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if(map[i-2][j]==3)
				{
					map[i-2][j]=7;   //把箱子推入了另一目的地，自然，ID也应是。
					map[i-1][j]=9;   //人站在了目的地上。
					//下面是对人原先站立地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		case 's':
			//如果人前面是空地。
			if(map[i+1][j]==0)
			{
				map[i+1][j]=6+0; //人往前走一步，ID为人的ID（）加上空地的ID（）。
				if(map[i][j]==9) //如果当前人站的位置为目的地，则ID为（即人的ID（）加上目的地ID（））。
					map[i][j]=3; //将人往前走一步后原地的ID修改为空地ID（）。
				else
					map[i][j]=0;    //否则原地ID修改为空地ID 。      
			}
			//如果人前面是目的地。
			else if(map[i+1][j]==3)
			{
				map[i+1][j]=6+3; //人往前走一步，ID为人ID+目的地ID=9。
				if(map[i][j]==9) //如果原地也是目的地（ID为）。
					map[i][j]=3; //人走后把原地ID修改回目的地ID。
				else
					map[i][j]=0; //否则原地ID修改为为空地ID
			}
			//如果人前面是箱子。
			else if(map[i+1][j]==4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i+2][j]==0)
				{ 
					map[i+2][j]=4; //人推箱子往前走一步，把空地ID修改为箱子ID（）
					//下面是对箱子原地进行判断
					if(map[i+1][j]==7) //如果箱子原地为目的地。
						map[i+1][j]=9; //人站在箱子的原地（目的地）时该地ID应该为人的ID+目的地ID=9。
					else
						map[i+1][j]=6; //否则，人站在了原来的空地上，ID应该为+0=6。
					//下面是对人原地进行判断
					if(map[i][j]==9) //如果之前是目的地。
						map[i][j]=3; //人走了之后修改回目的地ID。
					else
						map[i][j]=0; //否则就是空地。
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i+2][j]==3)
				{ 
					map[i-2][j]=7;   //ID为（目的地ID（）+箱子ID（）=7），表示已经把箱子推入了目的地。
					count++;
					//下面是对箱子原先位置的判断，同上。
					if(map[i+1][j]==7)
						map[i+1][j]=9;
					else
						map[i+1][j]=6;
					//下面是对人原先位置进行判断，同上。
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（ID=7）。
			else if(map[i+1][j]==7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if(map[i+2][j]==0)
				{
					count--;
					map[i+2][j]=4;   //把箱子重新推到空地上，ID=箱子ID+空地ID=4。
					map[i+1][j]=9;   //人自然而然的就站在了原先的目的地上了。
					//下面是对人原先地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if(map[i+2][j]==3)
				{
					map[i+2][j]=7;   //把箱子推入了另一目的地，自然，ID也应是。
					map[i+1][j]=9;   //人站在了目的地上。
					//下面是对人原先站立地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		case 'a':
			//如果人前面是空地。
			if(map[i][j-1]==0)
			{
				map[i][j-1]=6+0; //人往前走一步，ID为人的ID（）加上空地的ID（）。
				if(map[i][j]==9) //如果当前人站的位置为目的地，则ID为（即人的ID（）加上目的地ID（））。
					map[i][j]=3; //将人往前走一步后原地的ID修改为空地ID（）。
				else
					map[i][j]=0;    //否则原地ID修改为空地ID 。      
			}
			//如果人前面是目的地。
			else if(map[i][j-1]==3)
			{
				map[i][j-1]=6+3; //人往前走一步，ID为人ID+目的地ID=9。
				if(map[i][j]==9) //如果原地也是目的地（ID为）。
					map[i][j]=3; //人走后把原地ID修改回目的地ID。
				else
					map[i][j]=0; //否则原地ID修改为为空地ID
			}
			//如果人前面是箱子。
			else if(map[i][j-1]==4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i][j-2]==0)
				{ 
					map[i][j-2]=4; //人推箱子往前走一步，把空地ID修改为箱子ID（）
					//下面是对箱子原地进行判断
					if(map[i][j-1]==7) //如果箱子原地为目的地。
						map[i][j-1]=9; //人站在箱子的原地（目的地）时该地ID应该为人的ID+目的地ID=9。
					else
						map[i][j-1]=6; //否则，人站在了原来的空地上，ID应该为+0=6。
					//下面是对人原地进行判断
					if(map[i][j]==9) //如果之前是目的地。
						map[i][j]=3; //人走了之后修改回目的地ID。
					else
						map[i][j]=0; //否则就是空地。
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i][j-2]==3)
				{ 
					count++;
					map[i][j-2]=7;   //ID为（目的地ID（）+箱子ID（）=7），表示已经把箱子推入了目的地。
					//下面是对箱子原先位置的判断，同上。
					if(map[i][j-1]==7)
						map[i][j-1]=9;
					else
						map[i][j-1]=6;
					//下面是对人原先位置进行判断，同上。
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（ID=7）。
			else if(map[i][j-1]==7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if(map[i][j-2]==0)
				{
					count--;
					map[i][j-2]=4;   //把箱子重新推到空地上，ID=箱子ID+空地ID=4。
					map[i][j-1]=9;   //人自然而然的就站在了原先的目的地上了。
					//下面是对人原先地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if(map[i][j-2]==3)
				{
					map[i][j-2]=7;   //把箱子推入了另一目的地，自然，ID也应是。
					map[i][j-1]=9;   //人站在了目的地上。
					//下面是对人原先站立地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		case 'd':
			//如果人前面是空地。
			if(map[i][j+1]==0)
			{
				map[i][j+1]=6+0; //人往前走一步，ID为人的ID（）加上空地的ID（）。
				if(map[i][j]==9) //如果当前人站的位置为目的地，则ID为（即人的ID（）加上目的地ID（））。
					map[i][j]=3; //将人往前走一步后原地的ID修改为空地ID（）。
				else
					map[i][j]=0;    //否则原地ID修改为空地ID 。      
			}
			//如果人前面是目的地。
			else if(map[i][j+1]==3)
			{
				map[i][j+1]=6+3; //人往前走一步，ID为人ID+目的地ID=9。
				if(map[i][j]==9) //如果原地也是目的地（ID为）。
					map[i][j]=3; //人走后把原地ID修改回目的地ID。
				else
					map[i][j]=0; //否则原地ID修改为为空地ID
			}
			//如果人前面是箱子。
			else if(map[i][j+1]==4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i][j+2]==0)
				{ 
					map[i][j+2]=4; //人推箱子往前走一步，把空地ID修改为箱子ID（）
					//下面是对箱子原地进行判断
					if(map[i][j+1]==7) //如果箱子原地为目的地。
						map[i][j+1]=9; //人站在箱子的原地（目的地）时该地ID应该为人的ID+目的地ID=9。
					else
						map[i][j+1]=6; //否则，人站在了原来的空地上，ID应该为+0=6。
					//下面是对人原地进行判断
					if(map[i][j]==9) //如果之前是目的地。
						map[i][j]=3; //人走了之后修改回目的地ID。
					else
						map[i][j]=0; //否则就是空地。
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i][j+2]==3)
				{ 
					count++;
					map[i][j+2]=7;   //ID为（目的地ID（）+箱子ID（）=7），表示已经把箱子推入了目的地。
					//下面是对箱子原先位置的判断，同上。
					if(map[i][j+1]==7)
						map[i][j+1]=9;
					else
						map[i][j+1]=6;
					//下面是对人原先位置进行判断，同上。
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（ID=7）。
			else if(map[i][j+1]==7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if(map[i][j+2]==0)
				{
					count--;
					map[i][j+2]=4;   //把箱子重新推到空地上，ID=箱子ID+空地ID=4。
					map[i][j+1]=9;   //人自然而然的就站在了原先的目的地上了。
					//下面是对人原先地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if(map[i][j+2]==3)
				{
					map[i][j+2]=7;   //把箱子推入了另一目的地，自然，ID也应是。
					map[i][j+1]=9;   //人站在了目的地上。
					//下面是对人原先站立地进行判断，方法同上。
					if(map[i][j]==9) 
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		}
		if(count==8)   //如果分数达到分
		{
			system("CLS"); //清屏
			draw_map(map); 
			break;    //退出死循环
		}
	}
	printf("\n恭喜你，过关了！！\n"); //过关提示
	return 0;
}
void draw_map(int map[10][12])
{
 
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
		{
			switch(map[i][j])
			{
			case 0:
				printf(" "); //数字代表道路
				break;
			case 1:
				printf("#"); //数字代表墙壁
				break;
			case 2:
				printf(" "); //数字是游戏边框的空白部分
				break;
			case 3:
				printf("!"); //数字代表目的地
				break;
			case 4:
				printf("*"); //数字代表箱子
				break;
			case 7:
				printf("$"); //数字代表箱子进入目的地
				break;
			case 6:
				printf("@"); //数字代表人
				break;
			case 9:
				printf("@"); //数字代表人进入目的地
				break;
			}            
		}
		printf("\n");    //分行输出
	}
}
