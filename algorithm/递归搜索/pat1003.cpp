#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 505;
const int INF = 0x3f;
int value[MAXN];        //value[i]i���е�����Ա����
int g[MAXN][MAXN];      //�洢ÿ����

int dis[MAXN];    //dis[i]��ʾ��i�����·
bool sign[MAXN];    //���i�Ƿ������·
int cnt1[MAXN];     //cnt1[i]��ʾ��iʱ�����·����
int cnt2[MAXN];     //cnt2[i]��ʾ��iʱ�����·������м�����(������i���еľ�Ԯ����)
void dijkstra(int st, int n) {      //dijkstra��Դ���·
	memset(dis, INF, sizeof(dis));
	dis[st] = 0;
	cnt1[st] = 1;
	for (int i = 0; i < n - 1; i++) {
		int t = -1;
		for (int j = 0; j < n; j++) {
			if (!sign[j] && (t == -1 || dis[t] > dis[j])) {
				t = j;
			}
		}
		sign[t] = true;
		for (int j = 0; j < n; j++) {
			if (!sign[j] && dis[j] >= dis[t] + g[t][j]) {
				if (dis[j] == dis[t] + g[t][j]) {
					cnt1[j] += cnt1[t];     //��ʾ�в�ͬ·��������ͬ·������·��
				} else {
					cnt1[j] = cnt1[t];
				}
				cnt2[j] = max(cnt2[j], cnt2[t] + value[t]);     //����������м�����
				dis[j] = dis[t] + g[t][j];              //�ҵ�һ����̵㣬���������䵽���·��
			}
		}
	}
}

int main() {
	memset(g, INF, sizeof(g));
	int n, m, c1, c2;   //����������·���������ء�Ŀ�ĵ�
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		g[i][i] = 0;
		cin >> value[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		g[a][b] = l;
		g[b][a] = l;
	}
	dijkstra(c1, n);
	//�������м��ľ�Ԯ����ʱӦ���ϱ����о�Ԯ����
	cout << cnt1[c2] << ' ' << cnt2[c2] + value[c2] << endl;
	return 0;
}
