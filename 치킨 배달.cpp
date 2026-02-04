#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m;
int board[55][55];
vector<pair<int, int>> c;
vector<pair<int,int>> h;
bool isused[20];
int result = 0x7f7f7f7f;

void func(int idx, int cnt) {
	if (cnt == m) {
		int sum = 0;
		for (int j = 0; j < h.size(); j++) {
			int hy = h[j].first;
			int hx = h[j].second;
			int temp = 0x7f7f7f7f;
			for (int i = 0; i < c.size(); i++) {
				if (!isused[i]) continue;
				int cy = c[i].first;
				int cx = c[i].second;
				temp = min(abs(cy - hy) + abs(cx - hx), temp);
			}
			sum += temp;
		}
		
		result = min(result, sum);
		return;
	}

	for (int i = idx; i < c.size(); i++) {
		if (isused[i]) continue;
		isused[i] = true;
		func(i, cnt + 1);
		isused[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) h.push_back({ i,j });
			if (board[i][j] == 2) c.push_back({ i,j });
		}
	}

	func(0, 0);

	cout << result;

	return 0;
}
