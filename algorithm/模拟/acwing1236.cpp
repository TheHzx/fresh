// �ȱ���b���飬�ҳ�a������С��bi�ĸ�����c�����д���bi�ĸ���
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N], b[N], c[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);

	long long int  res = 0;
	for (int i = 0; i < n; i++) {
		int da = b[i];

		// ��a�����е�һ��С��bi���±�
		int low = 0, high = 0;
		int l = 0, r = n - 1;
		while (l < r) { // ��a������û�б�biС��,��ôr��һֱ����,��ʱl=r����0������������Ϊ0
			int mid = l + r + 1 >> 1;
			if (a[mid] < da)
				l = mid;
			else
				r = mid - 1;
		}

		low = l + 1;

		l = 0, r = n - 1;

		// �ҵ�c�����е�һ������bi���±�
		while (l < r) { // ����Ҳ��һ������c����û�б�bi���
			int mid = l + r >> 1;
			if (c[mid] > da)
				r = mid;
			else
				l = mid + 1;
		}
		high = n - l;
		cout << "low��ֵ" << low << endl;
		cout << " high��ֵ" << high << endl;
		res += 1ll * low * high; // �ѽ��תΪll����
	}
	cout << res << endl;
	return 0;
}