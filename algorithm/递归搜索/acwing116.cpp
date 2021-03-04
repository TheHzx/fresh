#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

// acwing116: ��һ�֡�����������������,��������
//
//������Ա�ֵܡ������Ϸ����Ҫ���˳���Ĵ�һ��ӵ��16�����ֵı��䡣
//
//��֪ÿ�����ֿ��Դ�����������״̬֮һ���򿪻�رա�
//
//ֻ�е����а��ֶ���ʱ������Ż�򿪡�
//
//���ֿ��Ա�ʾΪһ��4��4�ľ��������Ըı��κ�һ��λ��[i,j]�ϰ��ֵ�״̬��
//
//���ǣ���Ҳ��ʹ�õ�i�к͵�j���ϵ����а��ֵ�״̬Ҳ���Ÿı䡣
//
//��������򿪱���������л����ֵĴ�����Сֵ�Ƕ��١�
//
//�����ʽ
//����һ���������У�ÿ�а����ĸ����ֵĳ�ʼ״̬��
//
//���š�+����ʾ���ִ��ڱպ�״̬�������š�-����ʾ���ִ��ڴ�״̬��
//
//����һ���ֱ��ĳ�ʼ״̬�ǹرյġ�
//
//�����ʽ
//��һ�����һ������N����ʾ�������С�л����ִ�����
//
//������N�������л�˳��ÿ���������������������л�״̬�İ��ֵ��кź��кţ�����֮���ÿո������
//
//ע�⣺������ڶ��ִ򿪱���ķ�ʽ���������ȼ�������ϵ��£�ͬ�д����Ҵ򿪡�
//
//���ݷ�Χ



using namespace std;

/*
typedef pair<int, int> p; // ��ʱ�洢����
const int N = 5;
char map[N][N], backup[N][N]; // ����״̬�ͱ�������

int get_potition(int x, int y) {
	return 4 * x + y;
}

bool success() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (map[i][j] == '+')
				return false;

	return true;
}

void turn_one(int i, int j) {
	if (map[i][j] == '+')
		map[i][j] = '-';
	else
		map [i][j] = '+';
}

void turn_all(int x, int y) {
	for (int i = 0; i < 4; i++) {
		turn_one(x, i);
		turn_one(i, y);
	} // �ı�����ͬ��ͬ�е�״̬
	turn_one(x, y); // ����ı������ε���û�䣬��Ҫ�ٱ�һ��
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> map[i];
	vector<p> res; // ��ʾ������С�����Ľ��,��Ϊ�ж��ֲ���������
	// ���Ǳ���������ͬ���͵���ʱ��̬����
	// ѭ��2^16�ֲ���
	for (int op = 0; op < 1 << 16; op++) {
		// op����16�����������֣�1��ʾ�ı�״̬��0��ʾ����
		memcpy(backup, map, sizeof map); // ��ԭʼ״̬���ݵ�backup��ȥ
		vector<p> temp; // ��ʱ�洢��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (op >> get_potition(i, j) & 1) {
					// �洢����
					temp.push_back({i, j}); // {i,j}��ʾ pair����
					turn_all(i, j);
				}
			}
		if (success()) { // ���ȫ��'-' ���ɹ��Ĳ���
			if (res.empty() || res.size() > temp.size())

			res = temp;
			break; // ÿ��״ֻ̬��Ψһ�ķ���(������ʽ)
		}

		memcpy(map, backup, sizeof map); // �ָ�ԭʼ״̬
	}
	cout << res.size() << endl;
	for (auto k : res)
		cout << k.first + 1 << ' ' << k.second + 1 << endl;

	return 0;

}

*/


// �ڶ���д��: dfs�ݹ飬����Ҫ�������飬ÿ������������״̬:�ı��벻�ı�
const int N = 5;
typedef pair<int, int> p;
char g[N][N]; // ����Ҫ��������
int i = 1;

vector<p> res, temp;


void turn_one(int i, int j) {
	if (g[i][j] == '+')
		g[i][j] = '-';
	else
		g [i][j] = '+';
}

void turn_all(int x, int y) {
	for (int i = 0; i < 4; i++) {
		turn_one(x, i);
		turn_one(i, y);
	} // �ı�����ͬ��ͬ�е�״̬
	turn_one(x, y); // ����ı������ε���û�䣬��Ҫ�ٱ�һ��
}

bool success() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (g[i][j] == '+')
				return false;

	return true;
}


void dfs(int x, int y) {
	if (x == 3 && y == 4) { // �ݹ鵽�߽���
//		cout << "��" << i << "��" << endl;
		i++;
		if (success()) {

			if (res.empty() || res.size() > temp.size())
				res = temp;

		}
		return;
	}

	if (y == 4) { // ÿ�еı߽����
		x++, y = 0;
	}

	// �����ǵݹ����:����Ҫ�Ĳ���---

	// �ı��������,��¼����
	turn_all(x, y);
	temp.push_back({x, y});
	dfs(x, y + 1); // ������

	// �ָ��ֳ�
	temp.pop_back();
	turn_all(x, y); // ���ε������ԭ��

	// �Ը����겻������
	dfs(x, y + 1);



}


int main() {
	for (int i = 0; i < 4; i++)
		cin >> g[i];

	dfs(0, 0); // ������00��ʼ(�������±�Ϊ��׼)

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
	}
	return 0;
}
