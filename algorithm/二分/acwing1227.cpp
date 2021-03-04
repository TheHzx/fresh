#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010;



struct cake {
	int h;
	int w;
} cakes[N];
int n, k; // n���ɿ���, k��С����

bool f(int x) { // xΪ�����ε���ı߳�

	int sum = 0;

	for (int  i = 0; i < n; i++) {
		sum += (cakes[i].h / x) * (cakes[i].w / x);
		if (sum >= k)
			return true; // �Ѿ�����������ĵ�������
	}
	return false; //
}

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &cakes[i].h, &cakes[i].w); // ���뵰��� h��w

	int l = 0, r = 1e5;
	while (l < r) {

		int mid = l + r + 1  >> 1;
		if (f(mid)) {
			l = mid;
		} else
			r = mid - 1;
	}

	cout << l << endl;
	return 0;
}