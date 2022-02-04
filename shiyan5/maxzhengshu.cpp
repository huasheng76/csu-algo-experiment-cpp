#include <stdio.h>
#define MAX 20
int arr[MAX];
int n;
int isin[MAX];
int tryit(int x)
{	
	if(isin[x]==0)
	return false;
	int sum=0;
	isin[x]=0;
	for(int i=0;i<n;i++)
	{
	if(isin[i]==1)
	{
	//printf("%d ",arr[i]);	
	sum+=arr[i];
}
	}
	//printf("%d\n",sum);
	if(sum%3==0)
	return 1;
	else
	{
	isin[x]=1;	
	return 0;
	}
}
void sort()
{	
	int temp;
	for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++)
	if(arr[j]<arr[j+1])
	{
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
	}
}
int find()
{
	for(int i=n-1;i>=0;i--)
	if(arr[i]%3==0)
	{
	}
	else
	return i;
}
void solve()
{	int answer[MAX];
	int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	if(sum%3 == 0)
	{
		for(int i=0;i<n;i++)
		printf("%d",arr[i]);
		return;	
	}
	for(int i=0;i<n;i++)
	isin[i]=1;
	for(int i=n-1;i>=0;i--)
	{
		int x=tryit(i);
		if(x == 1)
		{
			for(int j=0;j<n;j++)
			{
				if(isin[j]==1)
				printf("%d",arr[j]);
			}
			printf("\n");
			break;
		}
		else
		{
			if(i==0)
			{
				int a=find();
				isin[a]=0;
				i=n;
			}
		}
	}
}
int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	} 
	sort();
	solve();	
	return 0;
}
