#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int score[5][5]={{5,-1,-2,-1,-3},
                {-1,5,-3,-2,-4},
                {-2,-3,5,-2,-2},
                {-1,-2,-2,5,-1},
                {-3,-4,-2,-1,0}};
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
     int temp=-100,i;
     if(x>temp) temp=x;
     if(y>temp) temp=y;
     if(z>temp) temp=z;
     return temp;
 }
int main()
  {   //freopen("input.txt","r",stdin);
      //freopen("result.txt","w",stdout);
      int cases,n1,n2,i,j;
      int x,y,z;
      string s1,s2;
      cout<<"请输入有几组数据"<<endl;
      cin>>cases;
      while(cases--)
       { 
		   
           cin>>n1;getchar();cin>>s1;cin>>n2;getchar();cin>>s2;
           f[0][0]=0;
           for(i=1;i<=n1;i++)
            f[i][0]=f[i-1][0]+score[num(s1[i-1])][4];
           for(j=1;j<=n2;j++)
            f[0][j]=f[0][j-1]+score[4][num(s2[j-1])];
           for(i=1;i<=n1;i++)
             for(j=1;j<=n2;j++)
              {
                  x=f[i-1][j]+score[num(s1[i-1])][4];
                  y=f[i][j-1]+score[4][num(s2[j-1])];
                  z=f[i-1][j-1]+score[num(s1[i-1])][num(s2[j-1])];
                  f[i][j]=max(x,y,z);   
              }     
           cout<<f[n1][n2]<<endl;
             
       }        
      return 0;
  }
