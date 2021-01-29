//c++递归快速排�?
#include <iostream>
#include <vector>
#define N 10
using namespace std;
void sawp(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void quickSort(int left,int right,vector<int> & a)
{
    if(left >= right)
    return;

    int i,j,base;
    i = left, j =right;
    base = a[left];
    while(i < j)
    {
        while(a[j]>=base && i < j)
        j--;

        while(a[i]<=base && i < j)
        i++;

        if(i < j)
        swap(a[i],a[j]); //������ߺ��ұߵ�ֵ��һ�����ڻ�׼ֵ��һ��С�ڻ�׼ֵ

    }
    a[left] = a[i];
    a[i] = base;
    quickSort(left,i-1,a);//��ʣ��Ĳ��ֽ��п�������
    quickSort(i+1,right,a);//
}
//4 7 6 5 3 2 8 1
int main()
{
    vector<int> a(N);
    cout<<"�������������:"<<endl;
    for (int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    quickSort(0,N-1,a);
    for(int i=0;i<N;i++)
    {
        cout<< a[i]<<" ";
    }
    return 0;
}