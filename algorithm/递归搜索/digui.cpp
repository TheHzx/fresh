#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
const int N = 16;
using namespace std;
int st[N]; //  Ϊ1��ʾѡ��2��ʾ��ѡ��0��ʾ��δ��������
int n;

void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; i++) {
			if (st[i] == 1) {
				printf("%d ", i);
			}
		}
		puts("");
		return;
	}

	st[u] = 1; // ѡu�����
	dfs(u + 1);
	st[u] = 0; // �ָ�״̬

	st[u] = 2; //  ��ѡu
	dfs(u + 1);
	st[u] = 0; // �ָ�״̬


}

int main() {
	cin >> n;
	dfs(1);

	return 0;
}
