#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int floor;
	int pushcount;
}QElement;

queue<QElement> q;

int n,a,b;
int s[205];
bool vis[205];

int main()
{
	QElement e1,e2;
	int k;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	 } 
	 e1.floor=a;
	 e1.pushcount=0;
	 q.push(e1);
	 vis[a]=1;
	 while(!q.empty())
	 {
	 	e2=q.front();
	 	q.pop();//��������Ժ��ò�����,vis[now]=1,ֱ�ӽ�����һ���ѡ��; 
	 	if(e2.floor==b) break;//���˾�ͣ����Ϊqueue�ǰ�˳��������� 
	 	k = e2.floor+s[e2.floor];
	 	if(k<=n && vis[k]==0)
	 	{
	 		e1.floor = k;
	 		e1.pushcount=e2.pushcount+1;
	 		q.push(e1);
	 		vis[k]=1;
		 }
		 k= e2.floor-s[e2.floor];
		 if(k>=1 && vis[k]==0)
		 {
		 	e1.floor = k;
	 		e1.pushcount=e2.pushcount+1;
	 		q.push(e1);
	 		vis[k]=1;
		 }
	 }
	 
	 if(e2.floor==b) cout<<e2.pushcount;
	 else cout<<"-1";
	 return 0;
}
//#include<iostream>
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int a[4][4];
//	memset(a,0,sizeof(a));
//	for(int i=0;i<4;i++)
//	for(int j=0;j<4;j++)
//	cout<<a[i][j]<<" ";
//	
//	return 0;
//} 
