#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,a,b,ans=0x7ffffff;
int flor[205];
bool vis[205];
void dfs(int now,int sum)//now��ʾ��ǰ¥��,sum��ʾ�������� 
{
	cout<<"������"<<now<<"¥"<<endl; 
	if(now==b) ans=min(ans,sum);//b��Ŀ��¥�� 
	if(sum>ans) return ;//û�е���һ��b�� 
	vis[now] = 1;//��ʾ������
	
	if(now+flor[now]<=n && !vis[now+flor[now]]) dfs(now+flor[now],sum+1);
	
	if(now-flor[now]>=1 && !vis[now-flor[now]])  dfs(now-flor[now],sum+1);
	vis[now]=0;
	
	
 } 
 
 int main(){
 	cin>>n>>a>>b;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>flor[i];
	 }
	
	 vis[a]=1;
	 dfs(a,0);
	 if(ans!=0x7ffffff) cout<<ans;
	 else cout<<"-1";
	 return 0;
 }
 





