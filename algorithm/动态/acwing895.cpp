#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];

int main() {
	cin >> n ;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	int res = 0; // f[i] ��ʾ�����Ե�i������β�������е���󳤶�

	for (int i = 1; i <= n; i ++ ) {

		f[i] = 1; // ÿ��ѭ������ i �����ͳ�ʼ��Ϊ1

		for (int j = 1; j < i; j ++ )
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);

		res = max(res, f[i]); // ���ڶ���ѭ���õ���f[i]�Ƚ����ֵ��¼����
		// �������
		for (int i = 1; i <= n; i++)
			cout << f[i] << ' ';
		cout << endl;
	}


	cout << res << endl;

	return 0;
}

