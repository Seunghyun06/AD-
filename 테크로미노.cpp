#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int n, m;
int board[505][505];
bool visit[505][505];
int result = -1;


void func(int cnt, int y, int x, int sum) {
	if (cnt == 4) {
		result = max(result, sum);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = true;
		func(cnt + 1, ny, nx, sum + board[ny][nx]);
		visit[ny][nx] = false;
	}
}

void check_t(int y, int x) {
	int center = board[y][x];
	for (int i = 0; i < 4; i++) {
		bool isT = true;
		int temp = board[y][x];
		for (int j = 0; j < 3; j++) {
			int dir = (i + j) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				isT = false;
				continue;
			}
			temp += board[ny][nx];
		}
		if (isT) result = max(result, temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			func(1, i, j, board[i][j]);
			check_t(i, j);
			visit[i][j] = false;
		}
	}

	cout << result;

	return 0;
}
