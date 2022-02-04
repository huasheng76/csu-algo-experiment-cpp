#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int score[5][5]={{5,-2,-1,-2,-4},
                {-2,5,-4,-3,-2},
                {-1,-4,5,-5,-1},
                {-2,-3,-5,5,-2},
                {-4,-2,-1,-2,0}};
int f[101][101];
int num(char ch)
 {
     if(ch=='A')
       return 0;
     if(ch=='C')
       return 1;
     if(ch=='G')
       return 2;
     if(ch=='T')
       return 3;
     if(ch=='-')
       return 4;       
}             
int max(int x,int y,int z)
 {
     int temp = -100,i;
     if(x > temp) temp = x;
     if(y > temp) temp = y;
     if(z > temp) temp = z;
     return temp;
 }
int main()
  {
      int cases,n1,n2,i,j;
      int x,y,z;
      int count = 1;
      char s1[1000],s2[1000];
      printf("请输入有几组数据:");
      scanf("%d",&cases);
	  getchar();
      while(cases--)
       {
       	   printf("\n第%d组数据\n",count++);
       	   printf("请输入第一个基因串的长度：");
           scanf("%d",&n1);
		   getchar();
		   printf("请输入第一个基因串：");
		   scanf("%[A-Z]",&s1);//输入s1
		   getchar();
		   printf("请输入第二个基因串的长度：");
		   scanf("%d",&n2);// 输入n2 
		   getchar();// 
		   printf("请输入第二个基因串：");
		   scanf("%[A-Z]",&s2);//输入s2
		   getchar();
           f[0][0]=0;
           //printf("%d\n",n1);
           //printf("%d\n",n2);
          //puts(s1);
           for(i=1;i<=n1;i++)
           {
           	//printf("1\n");
           	f[i][0]=f[i-1][0]+score[num(s1[i-1])][4];
		   }
           //printf("a\n");
           for(j=1;j<=n2;j++)
           {
           //printf("2\n");
           	f[0][j]=f[0][j-1]+score[4][num(s2[j-1])];
		   }
            
           for(i=1;i<=n1;i++)
           {
           	//printf("3\n");
           	for(j=1;j<=n2;j++)
              {
              	//printf("1\n");
                  x=f[i-1][j]+score[num(s1[i-1])][4];
                  y=f[i][j-1]+score[4][num(s2[j-1])];
                  z=f[i-1][j-1]+score[num(s1[i-1])][num(s2[j-1])];
                  f[i][j]=max(x,y,z);   
              }
		   }    
           printf("两个基因串的匹配值是：%d\n",f[n1][n2]);//输出f[n1][n2] 
             
       }        
      return 0;
  }
