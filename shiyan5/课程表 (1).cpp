#include<stdio.h>
struct lass{
	int start;
	int last;
};
int main()
{
	int n;
	while(scanf("%d",&n) != EOF && n != 0)
	{
		int i;
		getchar();
		getchar();
		lass c[n];
		lass s[n+1];
		for(i = 0;i < n+1;i++)
		{
			s[i].start = 99999999;
			s[i].last = 99999999;
		}
		//4[[100,200],[200,1300],[1000,1250],[2000,3200]]
		int p = n;
		int j;
		for(i = 0;i < n;i++)
		{
			if(i != 0) 
			{
			getchar();
			getchar();
			}
			scanf("%d,%d",&c[i].start,&c[i].last);
//			if(i == 0)
//			{
//				printf("%d\n",c[i].start);
//			}
			getchar();
			j = i;
			for(j = 0;j <= i;j++)
			{
//				printf("i = %d	",i);
//				printf("c = %d	",c[i].last);
//				printf("s = %d\n",s[j].last);
				if(c[i].last < s[j].last)
				{
					int o;
					for(o = i + 1;o > j;o--)
					{
						s[o] = s[o - 1];
					}
					s[j] = c[i];
					break;
					//printf("a = %d\n",s[j].last);
				}
			}
		}
		int ca = 0;
		int t = 0;
//		for(i = 0;i < n;i++)
//		{
//			printf("%d ",c[i].last);
//			printf("%d\n",c[i].start);
//		}
		for(i = 0;i < n;i++)
		{
			if(t <= s[i].last-s[i].start)
			{
				ca++;
				t += s[i].start;
			}
		}//4[[100,200],[200,1300],[1000,1250],[2000,3300]]
		printf("%d\n",ca);
	}
 } 
