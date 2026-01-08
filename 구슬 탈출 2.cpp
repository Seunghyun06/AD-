#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1, 0, -1, 0 };

char board[12][12];

int result = 0x7f7f7f7f;

//입력 :  크기와, 보드 처음 시작 입력
//재귀함수와 BFS를 써서 푸는 문제

pair<int, int> moveball(int y, int x, int& c, int dir) {
	c = 0;
	while (true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (board[ny][nx] == '#') break;
		y = ny;
		x = nx;
		c++;
		if (board[ny][nx] == 'O') break;
	}
	return { y, x };
}

void func(int cnt, int Ry, int Rx, int By, int Bx, int dir) {
	if (cnt >= result || cnt == 10) return;

	int Rc, Bc;
	auto [Rny, Rnx] = moveball(Ry, Rx, Rc, dir);
	auto [Bny, Bnx] = moveball(By, Bx, Bc, dir);

	if (board[Bny][Bnx] == 'O') return;
	if (board[Rny][Rnx] == 'O') {
		result = min(cnt + 1, result);
		return;
	}
	
	if (Rny == Bny && Rnx == Bnx) {
		if (Rc > Bc) {
			Rny -= dy[dir];
			Rnx -= dx[dir];
		}
		else {
			Bny -= dy[dir];
			Bnx -= dx[dir];
		}
	}
	
	for (int d = 0; d < 4; d++) {
		func(cnt + 1, Rny, Rnx, Bny, Bnx, d);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	int Ry, Rx, By, Bx;

	cin >> n >> m;

	//입력 받는 함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				Ry = i;
				Rx = j;
			}
			if (board[i][j] == 'B') {
				By = i;
				Bx = j;
			}
		}
	}

	//재귀 함수 시작
	for (int dir = 0; dir < 4; dir++) {
		func(0, Ry, Rx, By, Bx, dir);
	}

	if (result > 10) cout << -1;
	else cout << result;

	return 0;
}
