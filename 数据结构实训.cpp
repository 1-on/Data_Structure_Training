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
            printf("                                                ��������Ҫ�Ĳ���:");
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
            		printf("                                                ��������Ҫ�Ĳ���:");
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
                printf("\t\t                                �Բ���û������Ӧ�Ĳ�����\n\n");
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
	printf("                                                                                    ���˴�ѧУ԰����ƽ��ͼ                                               \n");
	printf("                                                                                                                                                         \n");
	printf("                                                ===================================================================================================      \n");
	printf("                                                                                                    |                         6.����¥                   \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                 5.�ﾶ��           \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                                                                    |                                                    \n");
	printf("                                                ===============================================================================     ===============      \n");
	printf("                                                                                                                            9.��У��                     \n");
	printf("                                                        7.����֮��                  3.��������                  2.��������                               \n");
	printf("                                                                                                                                                         \n");
	printf("                                                                                                 10.ͼ���                                               \n");
	printf("                                                                                                                                                         \n");
	printf("                                               ------------------------------------                                                                      \n");
	printf("                                                                                  |   4.B2¥                              ------------------------       \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                    8.��ѧ¥          |                               \n"); 
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                                      |                               \n");
	printf("                                                                                  |                    1�ϴ���           |                               \n");
	printf("                                                ========================================================    =======================================      \n");
	return 0;
}

void Creat()
{
    int i,j,k,e;
    G.n=NUM;
    G.e=11;
    for(i=1;i<G.n;i++)
		G.vex[i].number=i; //��ʼ�������� 
	//��ʼ���������� 
	G.vex[1].sight="�ϴ���"; 
	G.vex[2].sight="��������"; 
	G.vex[3].sight="��������"; 
	G.vex[4].sight="B2¥"; 
	G.vex[5].sight="�ﾶ��"; 
	G.vex[6].sight="����¥"; 
	G.vex[7].sight="����֮��"; 
	G.vex[8].sight="��ѧ¥"; 
	G.vex[9].sight="��У��"; 
	G.vex[10].sight="ͼ���";
	
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
    
    G.vex[1].description="ѧУ�������ţ�λ�����˽���"; 
    G.vex[2].description="ѧУ�ĸ������������ڵأ��������񴦡����д������´���"; 
    G.vex[3].description="ѧУ�Ĵ����ã��е�ȫԺ��ᣬ��ĩ���е�Ӱ��ӳ"; 
    G.vex[4].description="ѧУ�İ칫¥����ʦ�Ƕ�������칫"; 
    G.vex[5].description="�˶��ĵط�������������ĵط���ÿ����˶��ᶼ�������ٿ�"; 
    G.vex[6].description="ѧУ��ߵ�����¥��ֻ�ǵ��ݲ��������쳣ӵ��"; 
    G.vex[7].description="ʳ�ã�ͬѧ�ǳԷ��ĵط����˵�����ܶ�"; 
    G.vex[8].description="4���ѧ¥A1-A4���󲿷ֿγ̶��������⣬ʹ�������ŵĵط�"; 
    G.vex[9].description="ѧУ�ĺ�У�ţ��������ȥ�����Ǻ�����������ɽ��·С�Խ֣�С�Ե�ζ���ܲ���"; 
	G.vex[10].description="ͼ��ݻ����ǳ��ã��鼮�ܶ࣬��������ѧϰ��Χ���ܶ�ͬѧ��ϲ�������￴��"; 
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
    printf("                                                * *                         ��ӭʹ�����˴�ѧУ԰����ϵͳ                              * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *                             ��ѡ������Ҫ�Ĺ���:                                   * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             1.ѧУƽ��ͼ                      6.;���ྰ�����̾���              * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             2.��ʾ������                    7.У԰ͼ�ؽڵ�                      * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             3.��Ҫ������Ϣ����                8.�����������˴�ѧ������            * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             4.Ѱ��������֮�����̾���        9.�鿴����                          * *\n");
    printf("                                                * *                                                                                   * *\n");
    printf("                                                * *             5.������֮������·��              10.�˳�ϵͳ                         * *\n");
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
        printf("                                                                                �����ż�����:%d.%s\n",G.vex[i].number,G.vex[i].sight);
        printf("\n");
    }
}

void Search()
{
    int flag=0,op;
     while(1)
        {
            printf("\n");
            printf("������Ҫ��ѯ�ľ�����:");
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
            		printf("������Ҫ��ѯ�ľ�����:");
            		scanf("%d",&op);
	            }
            }
            if(flag==1) break;
        }
    printf("\n��������:%s\n",G.vex[op].sight);
    printf("\n�������:%s\n",G.vex[op].description);
    printf("\n");
}
void print_shortpath()
{
	int op1,op2,flag=0;
	while(1)
        {
            printf("\n");
            printf("                                                �����������:");
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
            		printf("                                                �����������:");
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
            printf("                                                �������յ���:");
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
            		printf("                                                �������յ���:");
            		scanf("%d",&op2);
	            }
            }
            if(flag==1) break;
        }
  
    printf("\n                                                %s��%s����̾���Ϊ:%dm\n\n",G.vex[op1].sight,G.vex[op2].sight,dist[op1][op2]);
    printf("                                                �������·��:");
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