#include<bits/stdc++.h>
using namespace std;
int mp[6][6];
bool vis[6][6];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int ans,fx,fy,sx,sy,T,n,m,l,r;//l,r���ϰ��ĺ�������
void bfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;//f-final�յ� s-��� 
	}
	else{
		for(int i=0;i<=3;i++){//�ĸ����� 
			if(vis[x+dx[i]][y+dy[i]]==0 && mp[x+dx[i]][y+dy[i]]==1){//1��ʾ�˴����ϰ� 
				vis[x][y]=1;//�߹��ĵط���� 
				bfs(x+dx[i],y+dy[i]);//�߹�ȥ 
				vis[x][y]=0; //��ԭ��� 
			}
		}
	}
} 

int main(){
	cin>>n>>m>>T;
	for(int ix=1;ix<=n;ix++){
		for(int iy=1;iy<=m;iy++)
		mp[ix][iy]=1;//1��ʾ���� 
	}
	cin>>sx>>sy;
	cin>>fx>>fy;
	for(int k=1;k<=T;k++){
		cin>>l>>r;
		mp[l][r]=0;//0��ʾΪ�ϰ������� 
	}
	bfs(sx,sy);
	cout<<ans;
	return 0;
}
