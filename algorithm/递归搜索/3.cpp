#include <iostream>
#include<vector>
using namespace std;
const int N = 100010;
int a[N], ne[N];
vector<int> t;

void add_to_head(int a)
{
	t.push_back(a);
}




void delete(int k) // k��ʾ��ַ
{
	
}
int main() {
	int head, n;
	cin >> head >> n; // head��ͷ�ڵ�
	int key, dress, next; // key �Ǽ�ֵ
	for (int i = 0; i < n; i++) {
		cin >> dress >> key >> next;
		a[dress] = key;
		ne[dress] = next; // �õ�ַ����һ����ַ
	}
	for (int k = head; k != -1; k = ne[k]) {
		cout << a[k] << endl;
		cout << "value of k:" << k << endl;

	}
	return 0;
}