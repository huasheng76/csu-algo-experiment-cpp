#include<stdio.h>
int main()
{
	char g2,s2,t;
	int g[100],s[100];
	int g1[100],s1[100];
	int G,S;
	while(g2 = getchar()&&g2 != '0')
	{
		int i;
		for(i = 0;i < 100;i++)
		{
			g1[i] = 100;
			g[i] = 100;
		}
		for(i = 0;i < 100;i++)
		{
			s1[i] = 100;
			g[i] = 100;
		}
		i = G = S = 0;
		getchar();
		getchar();
		getchar();
		getchar();
		while(true)
		{
			scanf("%d",&g[i]);
			i++;
			G++;
			t = getchar();
			int j;
			for(j = 0;j < G;j++)
			{
				int o;
				for(o = 0;o <= j;o++)
				{
					if(g[j] < g1[o])
					{
						int p;
						for(p = j+1;p > o;p--)
						{
							g1[p] = g1[p-1];
						}
						g1[o] = g[j];
					}
				}
			}
			if(t == ']')
			{
				break;
			}
		}
		t = getchar();
		getchar();
		s2 = getchar();
		getchar();
		getchar();
		getchar();
		getchar();
		i = 0;
		while(true)
		{
			scanf("%d",&s[i]);
			i++;
			S++;
			t = getchar();
			int j;
			for(j = 0;j < S;j++)
			{
				int o;
				for(o = 0;o <= j;o++)
				{
					if(s[j] < s1[o])
					{
						int p;
						for(p = j+1;p > o;p--)
						{
							s1[p] = s1[p-1];
						}
						s1[o] = s[j];
					}
				}
			}
			if(t == ']')
			{
				break;
			}
		}
		i = 0;
		int j = 0;
		int m = 0;
//		for(i = 0;i < G;i++)
//		{
//			printf("g[%d] = %d\n",i,g1[i]);
//		}
//		for(i = 0;i < S;i++)
//		{
//			printf("s[%d] = %d\n",i,s1[i]);
//		}
		for(i = 0;i < G;i++)
		{
			for(j = 0;j < S;j++)
			{
				if(s1[j] >= g1[i])
				{
					m++;
					s1[j] = 0;
					break;
				}
			}
		}
		getchar();
		printf("%d\n",m);
	}
}
