#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int board[15][15];
vector<pair<int, int>> v;
vector<pair<int, int>> virus;
bool isused[400];
bool visit[15][15];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int result = -1;

void func(int idx, int cnt) {
	if (cnt == 3) {
		int tboard[15][15];
		memset(visit, false, sizeof(visit));
		memcpy(tboard, board, sizeof(tboard));
		for (int i = 0; i < v.size(); i++) {
			if (isused[i]) {
				tboard[v[i].first][v[i].second] = 1;
			}
		}

		queue<pair<int, int>> Q;
		
		for (int i = 0; i < virus.size(); i++) {
			Q.push({ virus[i].first, virus[i].second });
			visit[virus[i].first][virus[i].second] = true;
		}

		while (!Q.empty()) {
			auto [curY, curX] = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = curY + dy[dir];
				int nx = curX + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visit[ny][nx]) continue;
				if (tboard[ny][nx] == 2 || tboard[ny][nx] == 1) continue;
				visit[ny][nx] = true;
				Q.push({ ny,nx });
				tboard[ny][nx] = 2;
			}
		}
		int safe = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tboard[i][j] == 0) safe++;
			}
		}
		if (safe > result) {
			int dummy = -1;
		}
		result = max(result, safe);
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (isused[i]) continue;
		isused[i] = true;
		func(i + 1, cnt + 1);
		isused[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) v.push_back({ i,j });
			if (board[i][j] == 2) virus.push_back({ i,j });
		}
	}

	func(0, 0);

	cout << result;

	return 0;
}
