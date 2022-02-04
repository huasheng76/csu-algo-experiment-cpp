#include<bits/stdc++.h>

using namespace std;
int o = 0;
void exchange(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int quick_select(int a[],int l,int r,int k)
{
	//printf("k = %d\n",k);
	int i = l,j = r,t = a[l];
	while(i != j)
	{
		if(a[j] > t)
		{
			j--;
			continue;
		}
		if(a[i] < t)
		{
			i++;
			continue;
		}
		exchange(&a[i],&a[j]);
		//printf("i = %d	j = %d\n",i,j);
	}
	//printf("%d\n",o);
	o++;
	//printf("i = %d	j = %d	l = %d\n",i,j,l);
	if(i-l+1 == k) return a[i];
	if(i-l+1 < k)
	{
		//printf("1\n");
		return quick_select(a,i+1,r,k-i-1+l);
	}
	if(i-l+1 > k)
	{
		//printf("2\n");
		return quick_select(a,l,i-1,k);
	}
}
int main()
{	int n;
	scanf("%d",&n);
	int a[n],i,x;
	int m=n;
	while(n--)
	scanf("%d",&a[n]);
	scanf("%d",&x);
	i = quick_select(a,0,4,m+1-x);
	
	cout << i;
	system("pause");
}
