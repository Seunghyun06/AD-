#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int n, l, r;
int board[55][55];
bool vis[55][55];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool move() {
	memset(vis, false, sizeof(vis));
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			int value = board[i][j];
			queue<pair<int, int>> Q;
			vector<pair<int, int>> v;
			Q.push({ i,j });
			v.push_back({ i,j });
			vis[i][j] = true;
			while (!Q.empty()) {
				auto [curY, curX] = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int ny = curY + dy[dir];
					int nx = curX + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if (vis[ny][nx]) continue;
					int land = abs(board[curY][curX] - board[ny][nx]);
					if (land >= l && land <= r) {
						vis[ny][nx] = true;
						Q.push({ ny,nx });
						value += board[ny][nx];
						v.push_back({ ny,nx });
					}
				}
			}
			if (v.size() > 1) {
				int total = value / v.size();
				flag = true;
				for (int k = 0; k < v.size(); k++) {
					board[v[k].first][v[k].second] = total;
				}
			}
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int day = 0;
	while (true) {
		if (!move()) break;
		day++;
	}
	cout << day;

	return 0;
}
