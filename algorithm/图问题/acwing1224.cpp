#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10010;
int a[N], st[N]; // st�������������ж��ٸ�����
int n, cnt; // cnt�ǻ���Ŀ�Ľ��
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (!st[i]) { // ��ǰԪ��δ�����
			cnt++;
//			st[i] = true;
			cout << cnt << endl;

			// �����л��ڵ��������
			for (int j = i; !st[j]; j = a[j]) { // һ����ͷָ����һ����ͷֱ��һ�������������������Ϊֹ
				st[j] = true;
			}
		}
	}

	printf("%d\n", n - cnt);
	return 0;
}