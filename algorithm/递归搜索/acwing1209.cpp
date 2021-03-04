#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
int n;
bool st[N], backup[N]; // �������飬1��ʾ���ˣ�0��ʾû�ù�
int ans;

bool check(int a, int c) {
	long long b = n * (long long)c - a * c;
	cout << "���� a b c ��ֵ�ֱ�Ϊ" << a << ' ' << c << ' ' << b << ' ' << endl;
	if (!a || !b || !c)
		return false;

	memcpy(backup, st, sizeof st); // ���������鿽��һ��
	//��ֹ����a��c���в�֣�Ҳ���������a b c ����
	//����
	while (b) {
		int x = b % 10;
		b /= 10;
		if (!x || backup[x])
			return false;// �������a��c���Ѿ����ֹ�
		backup[x] = true; // ��¼�����ֳ��ֹ�
	}

	for (int i = 1; i <= 9; i++) {
		if (!backup[i]) { // ȷ��1-9��������
			return false;
		}
	}
	return true; // ������涼���������ʾ��������

}

void dfs_c(int a, int c) { // ����a��ֵ��c��ǰ��ֵ
	if (check(a, c))
		ans++;

	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			st[i] = true;
			dfs_c(a, c * 10 + i); // a��ʱ��ֵ�̶���ѭ������c��ֵ

			st[i] = false;
		}
	}
}

void dfs_a(int a) {
	if (a >= n)
		return;
	if (a)
		dfs_c(a, 0); // �ѵ�ǰa��ֵ���������У���Ϊdfs_c
	//��������check(a,c)������Ҫa��ֵ

	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			st[i] = true;
			dfs_a(a * 10 + i); // ����a��ǰ��ֵ
			st[i] = false; // �ָ���״̬
		}
	}
}

int main() {
	cin >> n;

	dfs_a(0);  // a�ĳ�ֵΪ0

	cout << ans << endl;

	return 0;
}

