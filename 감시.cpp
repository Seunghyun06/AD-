#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 }; //오 아 왼 위
int n, m;
int board[13][13];
vector<int> d;
vector<pair<int, int>> cctv;
int temp[13][13];
int result = 0x7f7f7f7f;

int move() {
	memcpy(temp, board, sizeof(temp));
	for (int i = 0; i < cctv.size(); i++) {
		int StartY = cctv[i].first;
		int startX = cctv[i].second;
		int dir = d[i];
		int baseDir = d[i];
		if (temp[StartY][startX] == 1) {
			int y = StartY;
			int x = startX;
			while (true) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
				if (temp[ny][nx] == 6) break;
				if (temp[ny][nx] < 6 && temp[ny][nx] > 0) {
					y = ny;
					x = nx;
					continue;
				}
				temp[ny][nx] = 7;
				y = ny;
				x = nx;
			}
		}
		else if (temp[StartY][startX] == 2) {
			for (int j = 0; j < 2; j++) {
				int y = StartY;
				int x = startX;
				dir = (baseDir + (j * 2)) % 4;
				while (true) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
					if (temp[ny][nx] == 6) break;
					if (temp[ny][nx] < 6 && temp[ny][nx] > 0) {
						y = ny;
						x = nx;
						continue;
					}
					temp[ny][nx] = 7;
					y = ny;
					x = nx;
				}
			}
		}
		else if (temp[StartY][startX] == 3) {
			for (int j = 0; j < 2; j++) {
				dir = (baseDir + j) % 4;
				int y = StartY;
				int x = startX;
				while (true) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
					if (temp[ny][nx] == 6) break;
					if (temp[ny][nx] < 6 && temp[ny][nx] > 0) {
						y = ny;
						x = nx;
						continue;
					}
					temp[ny][nx] = 7;
					y = ny;
					x = nx;
				}
			}
		}
		else if (temp[StartY][startX] == 4) {
			for (int j = 0; j < 3; j++) {
				dir = (baseDir + j) % 4;
				int y = StartY;
				int x = startX;
				while (true) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
					if (temp[ny][nx] == 6) break;
					if (temp[ny][nx] < 6 && temp[ny][nx] > 0) {
						y = ny;
						x = nx;
						continue;
					}
					temp[ny][nx] = 7;
					y = ny;
					x = nx;
				}
			}
		}
		else if (temp[StartY][startX] == 5) {
			for (int j = 0; j < 4; j++) {
				dir = (baseDir + j) % 4;
				int y = StartY;
				int x = startX;
				while (true) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
					if (temp[ny][nx] == 6) break;
					if (temp[ny][nx] < 6 && temp[ny][nx] > 0) {
						y = ny;
						x = nx;
						continue;
					}
					temp[ny][nx] = 7;
					y = ny;
					x = nx;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void func(int cnt) {
	if (cnt == cctv.size()) {
		result = min(result, move());
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		d.push_back(dir);
		func(cnt + 1);
		d.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 6) cctv.push_back({ i,j });
		}
	}

	func(0);

	if (result == 0x7f7f7f7f) cout << 0;
	else cout << result;

	return 0;
}
