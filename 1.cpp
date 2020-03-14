#include<stdio.h>
#pragma warning(disable:4996)                                 //防止内存溢出
#include<stdlib.h>
#include<time.h>

#define ROW 11                                                //定义行数
#define ROW2 17
#define ROW3 22
          
#define COL 11                                                //定义列数
#define COL2 17                                   
#define COL3 22

#define DEFAULT 10                                            //雷数
#define DEFAULT2 40
#define DEFAULT3 50

int heart();
int letter();                                                 //美化游戏
void menu();
time_t start,end;

void map1(char mine1[ROW][COL], char show1[ROW][COL]);        //布局
void map2(char mine2[ROW2][COL2],char show2[ROW2][COL2]);        
void map3(char mine3[ROW3][COL3],char show3[ROW3][COL3]);
                    
void display1(char show1[ROW][COL]);                          //打印棋盘
void display2(char show2[ROW2][COL2]);
void display3(char show3[ROW3][COL3]);
                 
void set1(char mine1[ROW][COL]);                              //布雷
void set2(char mine2[ROW2][COL2]);    
void set3(char mine3[ROW3][COL3]); 
                
int get1(char mine1[ROW][COL], int x, int y);                 //统计该位置周围雷的个数
int get2(char mine2[ROW2][COL2],int x2,int y2);
int get3(char mine3[ROW3][COL3],int x3,int y3);        

void sweep1(char mine1[ROW][COL], char show1[ROW][COL]);      //扫雷
void sweep2(char mine2[ROW2][COL2],char show2[ROW2][COL2]);
void sweep3(char mine3[ROW3][COL3],char show3[ROW3][COL3]);
   
void easy();                                                  //选择模式
void normal();
void hard();
                                                
int main()
{
    int input = 1;                                            //当这个值为1的时候，while语句才可以无限循环，以达到输错还能再次输入的目的                                                  //调用爱心函数
    menu();

    while (input)
    {

        printf("请选择模式：\n");
        scanf("%d", &input);
        system("cls");                                        //清屏，将选择界面清除掉
        switch (input)
        {

        case 0:
            printf("退出程序\n");                             //switch循环选择模式
            break;
        case 1:
            easy();                                          
            break;
		case 2:
			normal();
			break;
        case 3:
			hard();
			break;
        default:
            printf("错误指令请重新选择：\n");                 //当选择的指令超出3时，重新选择
            break;
        }
    }

    system("pause");       //重新选择
    return 0;
}

int heart()
{
	int  i, j, k, l, m;	
	char c=3;	                        //ASCII码里面 3 就是一个字符小爱心 
	
	for (i=1; i<=5; i++)				
		printf("\n");	                //开头空出5行 
	
	for (i=1; i<=3; i++) 
	{                                     //前3行中间有空隙分开来写 
		for (j=1; j<=32-2*i; j++)		
			printf(" ");	            //左边的空格，每下一行左边的空格比上一行少2个 //8*n-2*i 
		for (k=1; k<=4*i+1; k++)		
			printf("%c", c);            //输出左半部分字符小爱心 
		for (l=1; l<=13-4*i; l++)		
			printf(" ");	            //中间的空格，每下一行的空格比上一行少4个 
		for (m=1; m<=4*i+1; m++)		
			printf("%c", c);            //输出右半部分字符小爱心
		printf("\n");		            //每一行输出完毕换行 
	}
	
	for (i=1; i<=3; i++) 
	{	                                //下3行中间没有空格 
		for (j=1; j<=24+1; j++)			
			printf(" ");	            //左边的空格 //8*(n-1)+1
		for (k=1; k<=29; k++)			
			printf("%c", c);            //输出字符小爱心
		printf("\n");		            //每一行输出完毕换行
	}
	
	for (i=7; i>=1; i--) 
	{	                                //下7行 
		for (j=1; j<=40-2*i; j++)		
			printf(" ");	            //左边的空格，每下一行左边的空格比上一行少2个//8*(n+1)-2*i
		for (k=1; k<=4*i-1; k++)		
			printf("%c", c);            //每下一行的字符小爱心比上一行少4个（这个循环是i--） 
		printf("\n");		            //每一行输出完毕换行
	}
	
	for (i=1; i<=39; i++)				
		printf(" ");	                //最后一行左边的空格 
	printf("%c\n", c);		            //最后一个字符小爱心 
	
	for (i=1; i<=5; i++)				
		printf("\n");	                 //最后空出5行 
	
	return 0;
}


void menu()                //菜单
{
   
int begin=1;

while(begin)
{

printf("\n\n\n\n\n\n\n\n\n");

printf("\t\t* * * * * * * * * * * * * * * * * * * * * * *\n");
printf("\t\t*                                           *\n");
printf("\t\t*              欢迎来到扫雷                 *\n");
printf("\t\t*              按下回车键继续               *\n");
printf("\t\t*                                           *\n");
printf("\t\t* * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n");
getchar();
begin=0;                                                                    //显示过后，begin的值被赋了0，于是不再循环
}

system("cls");
printf("\n\n\n\n\n\n\n\n\n");
printf("\t\t|\t0.退出                                  \n");
printf("\t\t|\t1.简单模式                              \n");
printf("\t\t|\t2.中等模式                              \n");
printf("\t\t|\t3.困难模式                              \n");
}


int letter()
{
	int i;

	for(i=1;i<=5;i++)                  //开头空出5行
	{
		printf("\n");
	}

    printf("*                    *                                   *  * *\n");
	printf("  *                *                                     *        *\n");                                         //为了让字母可以显示出来，利用点阵
    printf("    *            *                                       *           *\n");
	printf("      *        *                                         *             *\n");                                    //每行都要加换行符号，否则*松散，无法成图形
	printf("        *    *                                           *              *\n");
	printf("          **                                             *              *\n");
	printf("          **      * * * * * *   *         *              *              *      *        * * * *\n");
	printf("          **      *         *   *         *              *              *             *         *\n");
	printf("          **      *         *   *         *              *              *      *     *            *\n");
	printf("          **      *         *   *         *              *              *      *    * * * * * * * *\n");
	printf("          **      *         *   *         *              *             *       *    *\n");
	printf("          **      *         *   *         *              *            *        *     *\n");
	printf("          **      *         *   *         *              *          *          *      *           *\n");
	printf("          **      * * * * * *   * * * * * *              * *  *  *             *        * * * * *\n");
	
	for(i=1;i<=5;i++)                  //结尾空出5行
	{
		printf("\n");
	}
	return 0;
}


void map1(char mine1[ROW][COL], char show1[ROW][COL])             //简单模式布局
{

	printf("                                               *                *\n");
	printf("                                             ** **            ** **\n");
	printf("                                           ***   ***        ***   ***\n");
	printf("                                         ****     ****     ****    ****\n");
	printf("                                                                                                    \n");
	printf("                                                                                                    \n");

	printf("                                                *****************  \n");
	printf("                                                 **           ** \n");
	printf("                                                  **        **\n");
	printf("                                                    **     ** \n");
	printf("                                                      ***** \n");
	printf("\n");
	printf("                                                欢迎进入简单模式!\n");
    printf("\n");             
    int i = 0;
    int j = 0;

    for (i = 1; i < ROW - 1; i++)
    {
        for (j = 1; j < COL - 1; j++)
        {
            mine1[i][j] = '0';
        }
    }
    for (i = 1; i < ROW - 1; i++)
    {
        for (j = 1; j < COL - 1; j++)
        {
            show1[i][j] = '*';
        }
    }
}


void map2(char mine2[ROW2][COL2], char show2[ROW2][COL2])         //普通模式布局
{

	printf("                                               *                *\n");
	printf("                                             ** **            ** **\n");
	printf("                                           ***   ***        ***   ***\n");
	printf("                                         ****     ****     ****    ****\n");
	printf("                                                                                                    \n");
	printf("                                                                                                    \n");

	printf("                                                *****************  \n");
	printf("                                                 **           ** \n");
	printf("                                                  **        **\n");
	printf("                                                    **     ** \n");
	printf("                                                      ***** \n");
	printf("\n");
	printf("                                                欢迎进入普通模式!\n");
    printf("\n");             
    int i = 0;
    int j = 0;

    for (i = 1; i < ROW2 - 1; i++)
    {
        for (j = 1; j < COL2 - 1; j++)
        {
            mine2[i][j] = '0';
        }
    }
    for (i = 1; i < ROW2 - 1; i++)
    {
        for (j = 1; j < COL2 - 1; j++)
        {
            show2[i][j] = '*';
        }
    }
}


void map3(char mine3[ROW3][COL3], char show3[ROW3][COL3])          //困难模式布局
{

	printf("                                               *                *\n");
	printf("                                             ** **            ** **\n");
	printf("                                           ***   ***        ***   ***\n");
	printf("                                         ****     ****     ****    ****\n");
	printf("                                                                                                    \n");
	printf("                                                                                                    \n");

	printf("                                                *****************  \n");
	printf("                                                 **           ** \n");
	printf("                                                  **        **\n");
	printf("                                                    **     ** \n");
	printf("                                                      ***** \n");
	printf("\n");
	printf("                                                欢迎进入困难模式!\n");
    printf("\n");             
    int i = 0;
    int j = 0;

    for (i = 1; i < ROW3 - 1; i++)
    {
        for (j = 1; j < COL3 - 1; j++)
        {
            mine3[i][j] = '0';
        }
    }
    for (i = 1; i < ROW3 - 1; i++)
    {
        for (j = 1; j < COL3 - 1; j++)
        {
            show3[i][j] = '*';
        }
    }
}



void display1(char show1[ROW][COL])                               //展示简单模式地图
{
    int i, j;
    printf("  ");

    for (i = 1; i < COL - 1; i++)
        printf("%d ", i);
    printf("\n");
    for (i = 1; i < ROW - 1; i++)
    {
        printf("%d ", i);
        for (j = 1; j < COL - 1; j++)
        {
            printf("%c ", show1[i][j]);
        }
        printf("\n");
    }
}


void display2(char show2[ROW2][COL2])                             //展示普通模式地图
{

    int i, j;
    printf("   ");

    for (i = 1; i < COL2 - 1; i++)
	{
		if(i<10)
        printf("%d  ", i);
		else
        printf("%d ", i);
	}
    printf("\n");
    for (i = 1; i < ROW2 - 1; i++)
    {
		if(i<10)
		{
        printf(" %d ", i);
        for (j = 1; j < COL2 - 1; j++)
        {
            printf("%c  ", show2[i][j]);
        }
        printf("\n");
		}
		else
		{
			printf("%d ", i);
        for (j = 1; j < COL2 - 1; j++)
        {
            printf("%c  ", show2[i][j]);
        }
        printf("\n");
		}
    }
}


void display3(char show3[ROW3][COL3])                             //展示困难模式地图
{

    int i, j;
    printf("   ");

    for (i = 1; i < COL3 - 1; i++)
	{
		if(i<10)
        printf("%d  ", i);
		else
        printf("%d ", i);
	}
    printf("\n");
    for (i = 1; i < ROW3 - 1; i++)
    {
		if(i<10)
		{
        printf(" %d ", i);
        for (j = 1; j < COL3 - 1; j++)
        {
            printf("%c  ", show3[i][j]);
        }
        printf("\n");
		}
		else
		{
			printf("%d ", i);
        for (j = 1; j < COL3 - 1; j++)
        {
            printf("%c  ", show3[i][j]);
        }
        printf("\n");
		}
    }
}


void set1(char mine1[ROW][COL])                                  //简单模式布雷
{

    int x = 0;
    int y = 0;
    int count = DEFAULT;

    srand((unsigned)time(NULL));
    while (count)
    {
        x = rand() % (ROW-2) + 1;
        y = rand() % (COL-2) + 1;
        if (mine1[x][y] == '0')
        {
            mine1[x][y] = '1';
            count--;
        }
    }
}


void set2(char mine2[ROW2][COL2])                                //普通模式布雷
{

    int x2 = 0;
    int y2 = 0;
    int count2 = DEFAULT2;

    srand((unsigned)time(NULL));
    while (count2)
    {
        x2 = rand() % (ROW2-2) + 1;
        y2 = rand() % (COL2-2) + 1;
        if (mine2[x2][y2] == '0')
        {
            mine2[x2][y2] = '1';
            count2--;
        }
    }
}


void set3(char mine3[ROW3][COL3])                                //困难模式布雷
{

    int x3 = 0;
    int y3 = 0;
    int count3 = DEFAULT3;

    srand((unsigned)time(NULL));
    while (count3)
    {
        x3 = rand() % (ROW3-2) + 1;
        y3 = rand() % (COL3-2) + 1;
        if (mine3[x3][y3] == '0')
        {
            mine3[x3][y3] = '1';
            count3--;
        }
    }
}




int get1(char mine1[ROW][COL], int x, int y)                     //简单模式计算雷
{

    int count = 0;

    if (mine1[x - 1][y - 1] == '1')
        count++;
    if (mine1[x - 1][y] == '1')
        count++;
    if (mine1[x-1][y + 1] == '1')
        count++;
    if (mine1[x][y - 1] == '1')
        count++;
    if (mine1[x ][y + 1] == '1')
        count++;
    if (mine1[x + 1][y - 1] == '1')
        count++;
    if (mine1[x + 1][y] == '1')
        count++;
    if (mine1[x + 1][y + 1] == '1')
        count++;
    return count;
}



int get2(char mine2[ROW2][COL2], int x2, int y2)                //普通模式计算雷
{

    int count2 = 0;

    if (mine2[x2 - 1][y2 - 1] == '1')
        count2++;
    if (mine2[x2 - 1][y2] == '1')
        count2++;
    if (mine2[x2-1][y2 + 1] == '1')
        count2++;
    if (mine2[x2][y2 - 1] == '1')
        count2++;
    if (mine2[x2 ][y2 + 1] == '1')
        count2++;
    if (mine2[x2 + 1][y2 - 1] == '1')
        count2++;
    if (mine2[x2 + 1][y2] == '1')
        count2++;
    if (mine2[x2 + 1][y2 + 1] == '1')
        count2++;
    return count2;
}



int get3(char mine3[ROW3][COL3], int x3, int y3)                 //困难模式计算雷
{

    int count3 = 0;

    if (mine3[x3 - 1][y3 - 1] == '1')
        count3++;
    if (mine3[x3 - 1][y3] == '1')
        count3++;
    if (mine3[x3-1][y3 + 1] == '1')
        count3++;
    if (mine3[x3][y3 - 1] == '1')
        count3++;
    if (mine3[x3][y3 + 1] == '1')
        count3++;
    if (mine3[x3 + 1][y3 - 1] == '1')
        count3++;
    if (mine3[x3 + 1][y3] == '1')
        count3++;
    if (mine3[x3 + 1][y3 + 1] == '1')
        count3++;
    return count3;
}



void sweep1(char mine1[ROW][COL], char show1[ROW][COL])           //扫雷的实现
{

	
    int x = 0;
    int y = 0;
    int count = 0;

    while (count != (ROW - 2)*(COL - 2) - DEFAULT)
    {	
		count++;
		time_t start,end;
		int a;
		printf("游戏帮助\n");
		printf("选项1.输入横坐标和纵坐标\n选项2.插旗标志你确定是雷的地方\n");
		printf("请输入你想执行的指令");
		printf("\n");
		start =time(NULL);
		scanf("%d",&a);
		switch(a)
		{

		case 1:
        printf("请输入横坐标和纵坐标：");
            scanf("%d%d", &x, &y);
			if (mine1[x][y] == '1')
				 {
				    system("cls");
					end =time(NULL);
					
				    letter();
					printf("                                                     踩到雷了!\n");
					printf("                                                再接再厉再来一局吧!\n\n");
                    printf("所用时间为:%.f秒\n",difftime(end,start));
					printf("雷在棋盘的位置：                                  *****      *****\n");
					printf("                                                  *****      *****\n");
					printf("                                                                    \n");
					printf("                                                     ***********\n");
					printf("                                                     *         *\n");
					printf("                                                     ***********\n");
                    printf("\n");
					display1(mine1);
					return;
				}
			 else
				{
					int ret = get1(mine1, x, y);
					show1[x][y] = ret + '0';
					display1(show1);

				}
		
			 break;

		case 2:
			printf("插旗标志你确定是雷的地方:");
            scanf("%d%d", &x, &y);
			show1[x][y] ='+';
			display1(show1);
			break;

		default:
			printf("error\n");
			continue;
		}

	}
	printf("扫雷成功\n");
	end =time(NULL);
	system("cls");
	heart();
	printf("恭喜你扫雷成功~小心心送给你~");
	printf("所用时间为:%.f秒\n",difftime(end,start));
	printf("\n");
}


void sweep2(char mine2[ROW2][COL2], char show2[ROW2][COL2])
{
	time_t start,end;
    int x2 = 0;
    int y2 = 0;
    int count2 = 0;

    while (count2 != (ROW2 - 2)*(COL2 - 2) - DEFAULT2)
    {	
		count2++;
		int a;
		printf("游戏帮助\n");
		printf("选项1.输入横坐标和纵坐标\n选项2.插旗标志你确定是雷的地方\n");
		printf("请输入你想执行的指令");
		printf("\n");
		start =time(NULL);
		scanf("%d",&a);

		switch(a)
		{

		case 1:
        printf("请输入横坐标和纵坐标：");
            scanf("%d%d", &x2, &y2);
			if (mine2[x2][y2] == '1')
				 {
				    system("cls");
					end =time(NULL);
				    letter();
					printf("                                                     踩到雷了!\n");
					printf("                                                再接再厉再来一局吧!\n\n");
					printf("所用时间为:%.f秒\n",difftime(end,start));
					printf("雷在棋盘的位置：                                  *****      *****\n");
					printf("                                                  *****      *****\n");
					printf("                                                                    \n");
					printf("                                                     ***********\n");
					printf("                                                     *         *\n");
					printf("                                                     ***********\n");
                    printf("\n");
					display2(mine2);
					return;
				}
			 else
				{
					int ret2 = get2(mine2, x2, y2);
					show2[x2][y2] = ret2 + '0';
					display2(show2);

				}
		
			 break;

		case 2:
			printf("插旗标志你确定是雷的地方:");
            scanf("%d%d", &x2, &y2);
			show2[x2][y2] ='+';
			display2(show2);
			break;
		default:
			printf("error\n");
			continue;
		}
	}
	printf("扫雷成功\n");
	end =time(NULL);
	system("cls");
	heart();
	printf("恭喜你扫雷成功~小心心送给你~");
	printf("所用时间为:%.f秒\n",difftime(end,start));
	printf("\n");
}


void sweep3(char mine3[ROW3][COL3], char show3[ROW3][COL3])
{
	
    int x3 = 0;
    int y3 = 0;
    int count3 = 0;

    while (count3 != (ROW3 - 2)*(COL3 - 2) - DEFAULT3)
    {	
		time_t start,end;
		count3++;
		int a;

		printf("游戏帮助\n");
		printf("选项1.输入横坐标和纵坐标\n选项2.插旗标志你确定是雷的地方\n");
		printf("请输入你想执行的指令");
		printf("\n");
		start =time(NULL);
		scanf("%d",&a);

		switch(a)
		{
		case 1:
        printf("请输入横坐标和纵坐标：");
            scanf("%d%d", &x3, &y3);
			if (mine3[x3][y3] == '1')
				 {
				    system("cls");
					end =time(NULL);
				    letter();
					printf("                                                     踩到雷了!\n");
					printf("                                                再接再厉再来一局吧!\n\n");
					printf("所用时间为:%.f秒\n",difftime(end,start));
					printf("                                                                        ");
					printf("雷在棋盘的位置：                                  *****      *****\n");
					printf("                                                  *****      *****\n");
					printf("                                                                    \n");
					printf("                                                     ***********\n");
					printf("                                                     *         *\n");
					printf("                                                     ***********\n");
					printf("\n");

					display3(mine3);
					return;
				}
			 else
				{
					int ret3 = get3(mine3, x3, y3);
					show3[x3][y3] = ret3 + '0';
					display3(show3);

				}
		
			 break;

		case 2:
			printf("插旗标志你确定是雷的地方:");
            scanf("%d%d", &x3, &y3);
			show3[x3][y3] ='+';
			display3(show3);
			break;

		default:
			printf("error\n");
			continue;
		}
	}
	printf("扫雷成功\n");
	end =time(NULL);
	system("cls");
	heart();
	printf("恭喜你扫雷成功~小心心送给你~");
	printf("所用时间为:%.f秒\n",difftime(end,start));
	printf("\n");
}


void easy()
{
    char mine1[ROW][COL];
    char show1[ROW][COL];

    map1(mine1, show1);
    display1(show1);
    set1(mine1);
    sweep1(mine1, show1);
}


void normal()
{   
    char mine2[ROW2][COL2];
    char show2[ROW2][COL2];

    map2(mine2, show2);
    display2(show2);
    set2(mine2);
    sweep2(mine2, show2);
}


void hard()
{
    char mine3[ROW3][COL3];
    char show3[ROW3][COL3];

    map3(mine3, show3);
    display3(show3);
    set3(mine3);
    sweep3(mine3, show3);
}