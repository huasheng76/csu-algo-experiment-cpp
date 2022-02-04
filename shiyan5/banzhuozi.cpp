#include<cstdio>
#include<iostream>
using namespace std;
struct moved{
	int start;
	int last;
	int flag;
};
int main()
{
	int n,m;
	
	cin >> n >> m;
		//printf(1\n");
		int i;
		moved c[m];
		moved s[m+1];
		for(i = 0;i < m;i++)
		{
			c[i].flag = 0;
		}
		for(i = 0;i < m + 1;i++)
		{
			s[i].start = 99999999;
			s[i].last = 99999999;
			s[i].flag = 0;
		}
		//printf("2\n");
		int p = n;
		int j;
		for(i = 0;i < m;i++)
		{
			//printf("3\n");
			cin >>c[i].start >> c[i].last;
			j = i;
			for(j = 0;j <= i;j++)
			{
				//printf("4\n");
				if(c[i].last < s[j].last)
				{
					int o;
					for(o = i + 1;o > j;o--)
					{
						s[o] = s[o - 1];
					}
					s[j] = c[i];
					break;
				}
			}
		}
		int ca = 0;
		//printf("5\n");
		int l = m;
		while(l)
		{
			//printf("1\n");
			int i,t = 0;
			for(i = 0;i < m;i++)
			{
				//printf("t = %d s = %d flag = %d\n",t,s[i].start,s[i].flag);
				if((t <= s[i].start)&&(s[i].flag == 0))
				{	//printf("1\n");
					s[i].flag = 1;
					t = s[i].last;
					l--;
				}
				//printf("t = %d\n",t);
			}
			ca++;
			//printf("l = %d\n",l);
		}
		cout << ca;
		system("pause");
		return 0;
	
 } 
