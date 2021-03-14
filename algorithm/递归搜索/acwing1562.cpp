#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1010;


bool vis[N]; // ����û�id���������
struct Node {
	int id;
	int layer = 0; // ����
};

vector<Node> fllowedby[N]; // ��Ŀ�������ÿ���˹�ע���ˣ������Ǳ���ע���ˣ�������ע����Ϣת������ע���� ��ʾһ��·
int BFSTrave(int s, int L) { // ���Ͳ���
	int numForward = 0; // ת����
	Node start;
	start.id = s;

	queue<Node> q;
	q.push(start);
	vis[start.id] = true;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		int u = t.id; // ��¼��ǰ�û�id

		for (int i = 0; i < fllowedby[u].size(); i++) { // �������û��Ĺ�ע��
			Node next = fllowedby[u][i];
			next.layer = t.layer + 1; // ��һ��
			if (vis[next.id] == false && next.layer <= L) {
				q.push(next);
				vis[next.id] = true; // ������
				numForward++; // ת������1
			}
		}

	}
	return numForward;

}

int main() {
	Node user;
	int n, L;
	int numfllow, idfllow; // ��ע��������id
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; i++) {
		user.id = i;
		scanf("%d", &numfllow);
		for (int j = 0; j < numfllow; j++) {
			scanf("%d", &idfllow);
			fllowedby[idfllow].push_back(user);
		}

	}
	int numQuery, s; // ��ѯ������ת���û�id
	scanf("%d", &numQuery);
	for (int i = 0; i < numQuery; i++) {
		memset(vis, false, sizeof vis);
		scanf("%d", &s);
		int numForward = BFSTrave(s, L);
		printf("%d\n", numForward);
	}
	return 0;
}