#include <iostream>


using namespace std;

const int N = 10;
int n;
int vis[N]; // �ж���������Ƿ���ʹ�
int res[N]; // �洢���ܵĽ��

void dfs(int u) { // u��ʾ�ڼ���λ��
	if (u > n) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", res[i]);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) { // ����ѭ������������û�з��ʹ�����û��ռλ��
			res[u] = i;
			vis[i] = true; // ���Ϊ���ʹ�
			dfs(u + 1);

			res[u] = 0;
			vis[i] = false; // ��ԭ����ǰ��״̬
		}
	}

}

int main() {
	cin >> n;
	dfs(1);

	return 0;
}