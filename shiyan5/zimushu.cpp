#include <stdio.h>
#define MAX 20
int stone[MAX],arr[MAX];
int n;
int findmin()
{
	int min=9999;
	for(int i=1;i<=n;i++)
	if(arr[i-1]<arr[i+1])
	if(arr[i]<arr[min])
	min=i;
	return min;
}
void change(int x)
{
	stone[x-2]=stone[x-2]+stone[x-1];
	for(int i=x-1;i<n;i++)
	stone[i]=stone[i+1];
	n--;	
}
void solve()
{	arr[0]=9999;
	for(int i=0;i<n;i++)
	arr[i+1]=stone[i];
	arr[n+1]=999999;
	int min=findmin();
	for(int i=1;i<=n;i++)
	{
		if(i==min||i==min-1)
		printf("-%d ",arr[i]);
		else 
		printf("%d ",arr[i]);
	}
	printf("\n");
	change(min);
	if(n==0)
	return;
	else
	solve();
}
int main(){
	
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	scanf("%d",&stone[i]);
	solve();
	return 0;
} 
