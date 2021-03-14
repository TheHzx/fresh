#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int v[N], w[N]; // ����ͼ�ֵ
int f[N][N]; // f[i][j], j�����ǰi����Ʒ������ֵ

int main() {
	int n, m;
	cin >> n >> m; // n����Ʒ�ͱ�������m

	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (j < v[i]) { // ������������������Ʒ�������С
				f[i][j] = f[i - 1][j];
//				cout << i << ' ' << j << ' ' << f[i][j] << endl;
			} else
				f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]); // ״̬ת�Ʒ���
//			cout << i << ' ' << j << ' ' << f[i][j] << endl;
		}

	// f[i][j] ��ʾ ���Ϊj��ǰi����Ʒ�ļ�ֵ���ֵ
	cout << f[n][m] << endl;

	return 0;
}