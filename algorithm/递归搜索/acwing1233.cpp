#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>
#define x first
#define y second
using namespace std;

const int N = 1010;
typedef pair<int, int> PII;
char g[N][N];


bool st[N][N]; // ����Ƿ�������� ����


int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
queue<PII> q; // ��¼����½�صĶ���
int n;

void bfs(int x, int y, int &total, int &bound) {
	q.push({x, y}); // �����
	st[x][y] = true; // ��Ǹ�λ�÷��ʹ�

	while (q.size()) {
		PII t = q.front(); // ȡ������Ԫ��
		total++; // ½�����ؼ�1
		q.pop(); // ����
		bool is_bound = false;
		for (int i = 0; i < 4; i++) {

			int newx = t.x + dx[i], newy = t.y + dy[i]; // ��¼������
			if (newx < 0 || newx >= n || newy < 0 || newy >= n)
				continue;
			if (st[newx][newy])
				continue;
			if (g[newx][newy] == '.') { // ��������
				is_bound = true;
				continue;
			}
			q.push({newx, newy}); // ���
			st[newx][newy] = true;
		}
		if (is_bound)
			bound++;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", g[i]);

	int cnt = 0; // ��¼��ȫ����û�ĵ�������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; i++) {
			if (!st[i][j] && g[i][j] == '#') { // û�б���������½��
				int total  = 0, bound = 0;
				bfs(i, j, total, bound);
				if (total == bound)
					cnt++; // bound��¼�����к���½�ظ���(��Ҫ����û��½�ظ���)
			}
		}

	cout << cnt << endl;
	return 0;
}