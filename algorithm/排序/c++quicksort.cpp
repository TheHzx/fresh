//c++��������
/*
#include <iostream>
#include <vector>
#define N 10
using namespace std;
void sawp(int &a,int &b)// ����������
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
    base = a[left];// ��׼Ԫ��
    while(i < j)
    {
        while(a[j]>=base && i < j) //i <j ��������
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
*/

// ����ѭ��


#include <iostream>
#include <vector>
#define N 10
using namespace std;
void sawp(int &a, int &b) { // ����������
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void quickSort(vector<int> &a, int L, int R) {

    if(L>=R){
        return; // �ݹ��������
    }
	// L,R��ʾ��ʼ���յ��±�
	int p = a[L];
	int mark = L;
    
	for (int i = L + 1; i <= R; i++) {
        
		if (a[i] < p) {
            cout<<p<<"  >  "<<a[i]<<endl;
            cout<<"markֵΪ"<<mark<<endl;
			mark++;
            cout<<"markֵΪ"<<mark<<endl;
			swap(a[mark], a[i]); //��ʱmark��ʾa[mark]>p,��С��
			// �ᵽǰ����
          
   
		}
	}
    
	swap(a[mark], a[L]);
    
	quickSort(a, L, mark - 1);
	quickSort(a, mark + 1, R);
}

int main() {
	vector<int> a = {4,7,3,5,6,2,8,1};
	quickSort(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	return 0;
}