// #include<iostream>
// using namespace std;
// template<class T>
// void insertion(T a[],int n){
// 	int i,j;
// 	T temp;
	
// 	for(int i=1;i<n;i++)
// 	{
// 		int j=i;
// 		T temp=a[i];
// 		while(j>0 && temp<a[j-1])
// 		{
// 			a[j]=a[j-1];
// 			j--;    /*�ӵڶ�������ʼ�����ǲ��Ǳ�ǰ�����С������ǰ���������
// 			       һλ��j-- �����Ƚ�ǰһ�������ƶ������ǽϴ���������ƶ�
// 				    �����뵽a[j]λ���ϣ��������½���*/ 
// 		}
// 		a[j]=temp;
// 	}
// }
// int main()
// {
// 	int a[]={5,4,10,20,12,3};
// 	insertion(a,6);
// 	int n=sizeof(a)/sizeof(int ); // ��ȡ����Ԫ�ظ��� 
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<a[i]<<" ";
// 	}
// 	cout<<"����";
// 	return 0;
// }

//  ��ϰ--2021/2/26   big To small

#include<iostream>
using namespace std;

void insertSort(int a[],int len){// ����+����
	int pre,cur;
	for(int i=1;i<len;i++){
		pre = i - 1; 
		cur = a[i];
		while(pre>=0 && a[pre] < cur){
			a[pre + 1] = a[pre];// ����Ųλ��
			pre--;
		}
		a[pre+1] = cur;
	}
}
int main()
{
	int a[]={5,4,10,20,12,3};
	insertSort(a,6);
	int n=sizeof(a)/sizeof(int ); // ��ȡ����Ԫ�ظ��� 
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"����";
	return 0;
}