#include<iostream>
using namespace std;
template<class T>
void swap(T &x,T &y)
{
	T temp=x;
	x=y;
	y=temp;
}
template <class T>
void bubble(T a[],int n)
{
	int i=n-1;
	while(i>0)
	{
		int lastchange=0;
		for(int j=0;j<i;j++)
		if(a[j+1]<a[j]){     //ÿ�ΰ��������³���ĩβ��Ȼ��ֻҪ��ǰ������������� 
		                      //��¼lastchange=j--->i; 
			swap(a[j],a[j+1]);
			lastchange=j;
		}
			i=lastchange;
		
	}
}
