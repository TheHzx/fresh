#include<stdio.h>
#define MIN(a,b)(a)>(b)  ? (b) :(a)
int min(int a,int b,int c)
{                               
	int ret;
	ret=MIN(a,b);
	ret=MIN(ret,c);
	return ret;              
}
int nthu(int n)
{
	int dp[n];            /* ����һ����n���ҵ���n������������ֻ����
	                        2��3��5�ı������涨1����С�ĳ���*/ 
	int i;
	int l2=0;
	int l3=0;
	int l5=0;
	memset(dp,0,sizeof(int)*n);
	dp[0]=1;
	for(i=1;i<n;i++)
	{
		dp[i]=min(dp[l2]*2,dp[l3]*3,dp[l5]*5);
		if(dp[i]==dp[l2]*2) l2++;
		if(dp[i]==dp[l3]*3)  l3++;
		if(dp[i]==dp[l5]*5)  l5++;   /*����2��3��5�ı�������Ӧ���±��1����Ϊ���
		  �±��´��Ѿ�û�����ˣ��Ѿ����뵽������ȥ�ˣ����Լ�1���ٱȽ���С�ĳ���
		  */ 
	}
	return dp[n-1];
}
int main()
{
	int n;
	int m;
	printf("������ڼ�����:");
	scanf("%d",&n);
	
	printf("%d",nthu(n));
}

/*������ 1   2   3   4   5   6  8   9   10  12
������ 1   2   3   4   5   6  7   8   9   10
 dp[0]=1          l2        l3       l5 
dp[1]=2        1          0         0
dp[2]=3        1          1         0       ��ȡ��С������ 
dp[3]=4        2          1         0
dp[4]=5        2          1         1
dp[5] =6       3          2         1
dp[6]=8        4          2         1
dp[7] =9       4          3         1
dp[8] =10      5          3         2      �±��Ӧ�����ֱ����2��3��5
                                      һ����Ե���Խ���±����ӵ�����ҲԽС 
dp[9]=12
dp[10]
*/ 






