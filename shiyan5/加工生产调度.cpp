#include <stdio.h> 

#define MAX 20
typedef struct h{
	int data;
	int num;
	int a;
	int b;
}p;
h result[MAX],temp;
void solve(int n)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++)
	if(result[j].data>result[j+1].data) 
	{
		temp=result[j];
		result[j]=result[j+1];
		result[j+1]=temp;
	}
}
int solvetime(int n)
{	int suma=0,sumb=0;
	int answer=0;
	answer+=result[0].a;
	answer+=result[n-1].b;
	for(int i=1;i<n;i++)
	suma+=result[i].a;
	for(int i=0;i<n-1;i++)
	sumb+=result[i].b;
	if(suma>sumb)
	answer+=suma;
	else
	answer+=sumb;
	return answer;
}
int main()
{	
	int n;
	printf("请输入产品数目：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&result[i].a);
	for(int i=0;i<n;i++)
		scanf("%d",&result[i].b);
	for(int i=0;i<n;i++)
		{
		result[i].data=result[i].a-result[i].b;
		result[i].num=i+1;
		}
	solve(n);
	printf("所需最短时间为: %d\n",solvetime(n));
	printf("加工顺序为：");
	for(int i=0;i<n;i++)
	printf("%d ",result[i].num);
	return 0;
}
