#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2000;
double f[N][N], c[N]; // f[i][j] ��ʾǰi����Ʒ������(�������� <= j)�����۸�
double a[N], b[N];

// �Ѷ����������v,ÿ�ֶ��е���c
int main() {
	int n, m;
	cin >> n >> m; // �±����������������
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		double x = b[i], y = a[i];
		c[i] = x / y; // ����
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
// 			f[i][j]=f[i-1][j-1];

			for (int k = 0; k <= a[i]; k++) {
				if (k <= j) {
					f[i][j] = max(f[i][j], f[i - 1][j - k] + c[i] * k);
				}
			}
			cout << f[i][m] << endl;
		}
	}
	printf("%.2lf\n", f[n][m]);

}
