#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int N = 10010;
int a[N];
bool exist[N];
int m, d; // �Ϻź��غ�
int main() {
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	while (n--) {
		getline(cin, line);
		stringstream ss(line);

		while (ss >> a[n]) {
			if (exist[a[n]])
				d = a[n]; // �غ�
			else
				exist[a[n]] = true;
			n++;
		}
	}
	int k = 0;
	for (k = 0; !exist[k]; k++) { // ��ʼǰ������û���֣������ҵ���һ�����ֹ�������
	}
	for (int start = k; ; start++) {
		if (!exist[start])
			m = start;
	}
	cout << m << ' ' << d << endl;
	return 0;
}