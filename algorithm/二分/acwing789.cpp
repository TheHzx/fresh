#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N  = 100010;
int g[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &g[i]);

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x); // ����Ҫ���ҵ���

		int l = 0, r = n - 1; // ���Ҷ˵�
		// ��������˵��� >=x �ĵ�һ��λ��
		while (l < r) {
			cout << "----����ѭ��" << endl;
			cout << "����l��ֵΪ" << l << endl;
			cout << "����r��ֵΪ" << r << endl;
			int mid = l + r >> 1; // ����2
			if (g[mid] >= x) {

				r = mid; // ע��rһֱ����mid
				cout << "����r��ֵΪ" << r << endl;
			} else {
				l = mid + 1;
				cout << "����l��ֵΪ" << l << endl;
			}

		}

		if (g[r] == x) {
			cout << r << ' ';
			r = n - 1; // l���Բ��䣬��Ϊl����˵�
			// �������Ҷ˵� <= x �ĵ�һ��λ��
			while (l < r) {
				cout << "----����ѭ��" << endl;
				cout << "����l��ֵΪ" << l << endl;
				cout << "����r��ֵΪ" << r << endl;
				int mid = l + r + 1 >> 1;
				if (g[mid] <= x) {

					l = mid; // ��ʱ��lһֱ����mid
					cout << "����l��ֵΪ" << l << endl;
				}

				else {

					r = mid - 1;
					cout << "����r��ֵΪ" << r << endl;
				}
			}
			cout << l << endl;
		} else
			cout << "-1 -1" << endl;

	}
	return 0;
}