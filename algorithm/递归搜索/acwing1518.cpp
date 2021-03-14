#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 1010; // ������
const int INF = 1e9; // �����

map<int, string> intToString; // ���->����
map<string, int> stringToInt; // ����->���
map<string, int> Gang; // head ->����
int G[maxn][maxn], weight[maxn];
int n, k, numperson; // ����n������k��������numperson;
bool vis[maxn]; // ����Ƿ񱻷��ʹ�

// ����������Ӧ�ı��
int change(string s) {
	if (stringToInt.find(s) != stringToInt.end()) {
		return stringToInt[s]; // ���ر��
	} else {
		stringToInt[s] = numperson; // �������
		intToString[numperson] = s; // ���->����
		return numperson++; // �����±�,���±��1
	}
}
void dfs(int now, int &head, int &numMember, int &totalValue)

// ���ڷ���now, ͷĿhead, �Ż�����numMember, �ܱ�Ȩ��
{
	numMember++;
	vis[now] = true; // �������
	if (weight[now] > weight[head]) {
		head = now; // ����ͷĿ
	}
	for (int i = 0; i < numperson; i++) {
		if (G[now][i] > 0) { // ���now�ܵ���i
			totalValue += G[now][i];
			G[now][i] = G[i][now] = 0;
			if (vis[i] = false) {
				dfs(i, head, numMember, totalValue);
			}
		}
	}
}

void DFSTrave() {
	for (int i = 0; i < numperson; i++) {
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			dfs(i, head, numMember, totalValue);
			if (numMember >= 3 && totalValue > k) {
				Gang[intToString[head]] = numMember; // ͷĿ����->��Ա����
			}
		}
	}
}

int main() {
	int w;
	string s1, s2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w; // �˵�͵�Ȩ
		int id1 = change(s1);
		int id2 = change(s2);
		// ��Ȩ
		G[id1][id2] += w;
		G[id2][id1] += w;
		// ��Ȩ
		weight[id1] += w;
		weight[id2] += w;
	}
	// ö��������
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>:: iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}