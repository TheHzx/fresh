
#include<iostream>
using namespace std;
int ans=0,sum=0,x[25];
int n,k;
bool isprime(int n){
	int s = sqrt(double(n));
	for(int i=2;i<=s;i++){
		if(n%i==0)
		return false;
	}
	return true;
}
//void PL(int left_num,int alsum,int start,int end){
//	if(left_num==0){
//		if(isprime(alsum))
//		ans++;//�ݹ�ֱ����������ѡ��,�ж�alsum�ܺ��Ƿ�Ϊ���� 
//	}
//	for(int j=start;j<=end;j++){
//		PL(left_num-1,alsum+x[j],j+1,end);
//	}	
//	
//}
//�ڶ���д��::: 
int PL(int left_num,int alsum,int start,int end){
	if(left_num==0){
		return isprime(alsum);//����1��0 
	}
	int sum=0;//sum��Ϊ0,��Ϊ����ѭ���ⲿ��sumֵ�ᱻ�ڲ���������,����ֵ����sum
	 
	for(int j=start;j<=end;j++){
		sum+=PL(left_num-1,alsum+x[j],j+1,end);//1 2 3 4 5
	}
	return sum;//������������������ 
	
}
int main(){

	cin>>n>>k;
	for(int t=1;t<=n;t++)//1-n�ܹ�n���� 
	cin>>x[t];
	cout<<PL(k,0,1,n);//��1��ʼ,n����
	
	return 0; 
}

