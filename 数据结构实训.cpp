#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define Root -1
#define COILA 1
#define M 20
#define FINITY 100000
#define NUM 11
#define Max 9999

typedef struct
{
    int number;
    char *sight;
    char *description;
} vertextype;
typedef struct
{
    vertextype vex[M];
    int arcs[M][M];
    int n,e;
}Mgraph;

Mgraph G;

void  select();
int printplan();
void Creat();
int menu();
void printnum();
void Search();
void print_shortpath();
void floyde_print(int b,int e);

int main()
{
    system("color 0A");
    select();
    return 0;
}

void  select()
{
    int  op;
    int i=0,j=1,flag=0;
    Creat();
    /*shortpath(&g);*/
    while(j)
    {
        menu();
        while(1)
        {
            printf("\n");
            printf("                                                输入你想要的操作:");
            scanf("%d",&op);
            while(1)
            {
            	if(op>=0&&op<=10) 
            	{
	            	flag=1;
	            	break;
	            }
            	else{
            		printf("\n");
            		printf("                                                输入你想要的操作:");
            		scanf("%d",&op);
	            }
            }
            if(flag==1) break;
        }
        printf("\n");
        switch(op)
        {
            case 1:
                printplan();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                printplan();
                printnum();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printplan();
                Search();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printplan();
                print_shortpath();
                system("pause");
                system("cls");
                break;
            /*case 5:
                system("cls");
                printplan();
                print_Allpath(&g);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                printplan();
                bestpath(&g);
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                printplan();
                Coila_search(&g);
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                printplan();
                comment(&g);
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                printplan();
                checkcomment(&g);
                system("pause");
                system("cls");
                break;
            case 10:
                system("cls");
                j=0;
                break;
            default:
                printf("\t\t                                对不起，没有您对应的操作。\n\n");
                system("pause");
                system("cls");
                break;*/
        }
    }
}

int dist[M][M];
int path[M][M];
void shortpath()
{
    int i,j,k;
    for(i=0;i<G.n;i++)
        for(j=0;j<G.n;j++)
    {
        dist[i][j]=G.arcs[i][j];
        if(i!=j&&dist[i][j]<Max) path[i][j]=i;
        else
            path[i][j]=-1;
    }
    for(k=0;k<G.n;k++)
        for(i=0;i<G.n;i++)
            for(j=0;j<G.n;j++)
            {
                if(dist[i][j]>(dist[i][k]+dist[k][j]))
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                        path[i][j]=k;
                    }
            }
}

int printplan()
{
    printf("                                                                                                                                                         \n");
	printf("                                                                                    树人大学校园景点平面图                                               \n");
	printf("                                                                                                                                                         \n");
	printf("                                                ===================================================================================================      \n");
	printf("                                                                                                    |                         6.致勤楼                   \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                 5.田径场           \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                ===============================================================================     ===============      \n");
	printf("                                                                                                                            9.北校门                     \n");
	printf("                                                        7.树人之家                  3.树人礼堂                  2.行政中心                               \n");
	printf("                                                                                                                                                         \n");
	printf("                                                                                                 10.图书馆                                               \n");
	printf("                                                                                                                                                         \n");
	printf("                                               ------------------------------------                                                                      \n");
	printf("                                                                                  |   4.B2楼                              ------------------------       \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                    8.教学楼          |                               \n"); 
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                    1南大门           |                               \n");
	printf("                                                ========================================================    =======================================      \n");
	return 0;
}

void Creat()
{
    int i,j,k,e;
    G.n=NUM;
    G.e=11;
    for(i=1;i<G.n;i++)
		G.vex[i].number=i; //初始化景点编号 
	//初始化景点名称 
	G.vex[1].sight="南大门"; 
	G.vex[2].sight="行政中心"; 
	G.vex[3].sight="树人礼堂"; 
	G.vex[4].sight="B2楼"; 
	G.vex[5].sight="田径场"; 
	G.vex[6].sight="致勤楼"; 
	G.vex[7].sight="树人之家"; 
	G.vex[8].sight="教学楼"; 
	G.vex[9].sight="北校门"; 
	G.vex[10].sight="图书馆";
	
	for(i=1;i<G.n;i++)
	{
		for(j=1;j<G.n;j++)
		{
			if(i==j)
			G.arcs[i][j]=0;
			else
			G.arcs[i][j]=Max;		
		}
	}  
	G.arcs[1][8]=G.arcs[8][1]=50;
	G.arcs[1][10]=G.arcs[10][1]=100;
	G.arcs[2][8]=G.arcs[8][2]=150;
	G.arcs[2][9]=G.arcs[9][2]=20;
	G.arcs[10][3]=G.arcs[3][10]=30;
	G.arcs[9][5]=G.arcs[5][9]=200;
	G.arcs[1][4]=G.arcs[4][1]=70;
	G.arcs[5][6]=G.arcs[6][5]=50;
	G.arcs[10][7]=G.arcs[7][10]=150;
	G.arcs[2][3]=G.arcs[3][2]=50;
	G.arcs[3][7]=G.arcs[7][3]=100;
	G.arcs[4][10]=G.arcs[10][4]=20;
	G.arcs[4][3]=G.arcs[3][4]=50;
	G.arcs[10][2]=G.arcs[2][10]=50;
	G.arcs[8][10]=G.arcs[10][8]=50;
    
    G.vex[1].description="学校的正大门，位于树人街上"; 
    G.vex[2].description="学校的各行政机关所在地，包括财务处、科研处、人事处等"; 
    G.vex[3].description="学校的大礼堂，承担全院大会，周末还有电影放映"; 
    G.vex[4].description="学校的办公楼，老师们都在这里办公"; 
    G.vex[5].description="运动的地方，早上升国旗的地方，每年的运动会都在这里召开"; 
    G.vex[6].description="学校最高的宿舍楼，只是电梯才两个，异常拥挤"; 
    G.vex[7].description="食堂，同学们吃饭的地方，菜的种类很多"; 
    G.vex[8].description="4大教学楼A1-A4，大部分课程都安排在这，痛并快乐着的地方"; 
    G.vex[9].description="学校的后校门，从这里出去，就是杭城著名的舟山东路小吃街，小吃的味道很不错"; 
	G.vex[10].description="图书馆环境非常好，书籍很多，安静又有学习氛围，很多同学都喜欢在这里看书"; 
}

int menu()
{
    printf("                                                -----------------------------------------------------------------------------------------\n");
    printf("                                                          *         *     ****     *      ****    ****      *   *      ****  \n");
    printf("                                                          *    *    *     *        *      *       *  *     **   **     *     \n");
    printf("                                                           *  * *  *      ****     *      *       *  *    *  * *  *    ****  \n");
    printf("                                                            **   **       *        *      *       *  *   *    *    *   *     \n");
    printf("                                                             *   *        ****     ****   ****    ****   *         *   ****  \n");
    printf("                                                -----------------------------------------------------------------------------------------\n");
    printf("                                                                                                         \n");
    printf("                                                * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("                                                * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("                                                * *                         欢迎使用树人大学校园导航系统                              * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *                             请选择您需要的功能:                                   * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             1.学校平面图                      6.途径多景点的最短距离              * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             2.显示景点编号                    7.校园图关节点                      * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             3.主要景点信息介绍                8.留下您对树人大学的评论            * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             4.寻找两景点之间的最短距离        9.查看评论                          * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             5.两景点之间所有路径              10.退出系统                         * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("                                                * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n");
    return 0;
}
void printnum()
{
	int i=0;
    printf("\n");
    for(i=1;i<G.n;i++)
    {
        printf("                                                                                景点编号及名称:%d.%s\n",G.vex[i].number,G.vex[i].sight);
        printf("\n");
    }
}

void Search()
{
    int flag=0,op;
     while(1)
        {
            printf("\n");
            printf("请输入要查询的景点编号:");
            scanf("%d",&op);
            while(1)
            {
            	if(op>0&&op<=10) 
            	{
	            	flag=1;
	            	break;
	            }
            	else{
            		printf("\n");
            		printf("请输入要查询的景点编号:");
            		scanf("%d",&op);
	            }
            }
            if(flag==1) break;
        }
    printf("\n景点名称:%s\n",G.vex[op].sight);
    printf("\n景点介绍:%s\n",G.vex[op].description);
    printf("\n");
}
void print_shortpath()
{
	int op1,op2,flag=0;
	while(1)
        {
            printf("\n");
            printf("                                                请输入起点编号:");
            scanf("%d",&op1);
            while(1)
            {
            	if(op1>=0&&op1<=10) 
            	{
	            	flag=1;
	            	break;
	            }
            	else{
            		printf("\n");
            		printf("                                                请输入起点编号:");
            		scanf("%d",&op1);
	            }
            }
            if(flag==1) break;
        }
        printf("\n");
        flag=0;
 	while(1)
        {
            printf("\n");
            printf("                                                请输入终点编号:");
            scanf("%d",&op2);
            while(1)
            {
            	if(op2>=0&&op2<=10) 
            	{
	            	flag=1;
	            	break;
	            }
            	else{
            		printf("\n");
            		printf("                                                请输入终点编号:");
            		scanf("%d",&op2);
	            }
            }
            if(flag==1) break;
        }
  
    printf("\n                                                %s到%s的最短距离为:%dm\n\n",G.vex[op1].sight,G.vex[op2].sight,dist[op1][op2]);
    printf("                                                最佳游览路线:");
    printf("%s->",G.vex[op1].sight);
    floyde_print(op1,op2);
    printf("%s\n\n",G.vex[op2].sight);
    printf("\n");
}

void floyde_print(int b,int e)
{
    if(path[b][e]==-1||path[b][e]==e||path[b][e]==b)
        return;
    else
    {
        floyde_print(b,path[b][e]);
        printf("%s->",G.vex[path[b][e]].sight);
        floyde_print(path[b][e],e);
    }
}