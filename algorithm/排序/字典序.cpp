#include<bits/stdc++.h>  //����ͷ�ļ�
using namespace std;
int cmp(string a,string b)
{
return a.compare(b)<0;  //�ַ����ȽϺ��� a<b 
    //�ַ����ȽϹ��� ���ַ�����ͷ��ʼ��ֱ�����ֲ�һ�����ַ����Ƚ����С������
}
int main()
{
  int n;
  cin>>n;
  char str[n];
  for(int i=0;i<n;i++)
  cin>>str[i];
  sort(str,str+n,cmp);
  cout<<str[0]<<endl;
  return 0;
}
