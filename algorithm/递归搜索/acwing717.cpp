#include <iostream>
using namespace std;
int n;
// һ���ݹ�д��
/*
int fa[50]; // �ȶ����ÿ�����飬���ڼ�¼��ֹ������ظ�����

int dfs(int u) {

	if (u == 1)
		return 0;

	if (u == 2)
		return 1;

	if (fa[u]) {
		return fa[u]; // ���fa[u]�г�ֵ��ֱ�ӷ���
	}

	fa[u] = dfs(u - 1) + dfs(u - 2);
	return fa[u];
}

int main() {
	fa[1] = 0;
	fa[2] = 1; // �ȸ���ֵ
	cin >> n;
	dfs(n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", fa[i]);
	}

	return 0;
}
*/

// ��������д��
/*
int main() {
	cin >> n;

	int f[46];
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	for (int i = 1; i <= n; i++) {
		cout << f[i] << ' ';

	}
	return 0;
}
*/

// ������������д��

int main() {
	cin >> n;
	int a = 0, b = 1;
	for (int i = 1; i <= n; i++) {
		cout << a << ' ';
		int fn = a + b;
		a = b, b = fn;
	}

	return 0;
}
