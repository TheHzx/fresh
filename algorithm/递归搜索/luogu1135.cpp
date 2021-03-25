#include <iostream>
#include <queue>
using namespace std;
const int N = 205;
int f[N]; // ��¼ÿһ��İ�ť
bool vis[N]; // ��¼�Ƿ���ʹ�
int n, s, e;

typedef struct {
	int d; // ¥��
	int pushcount ; // �����¥����ť�Ĵ���
} layer;
queue<layer> q;

int BFS() {
	layer e1, e2;
	e1.d = s; // ��ʼ¥��
	e1.pushcount = 0;
	q.push(e1);
	vis[s] = true;

	while (q.size()) {

		e2 = q.front();
		q.pop();
		if (e2.d == e) {
			return e2.pushcount;
		}
		// ������
		int k = e2.d + f[e2.d];
		if (k <= n && vis[k] == false) {
			e1.d = k;
			e1.pushcount = e2.pushcount + 1;
			q.push(e1);
			vis[k] = 1;
		}
		// ������

		k = e2.d - f[e2.d];
		if (k >= 1 && vis[k] == false) {
			e1.d = k;
			e1.pushcount = e2.pushcount + 1;
			q.push(e1);
			vis[k] = 1;
		}
	}

	return -1;
}


int main() {
	cin >> n >> s >> e; // �����յ�
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	int res = BFS();
	cout << res << endl;
	return 0;
}