#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m, h;
int board[35][15];
int result = 0x7f7f7f7f;

bool move() {
	for (int j = 1; j <= n; j++) {
		int pos = j;
		for (int i = 1; i <= h; i++) {
			if (board[i][pos] == 1) pos++;
			else if (board[i][pos - 1] == 1) pos--;
		}
		if (pos != j) return false;
	}
	return true;
}

void func(int cnt, int y, int x) {
	if (cnt >= result) return;
	if (cnt > 3) return;

	if (move()) {
		result = min(result, cnt);
		return;
	}
	
	for (int i = y; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j + 1] || board[i][j - 1] == 1 || board[i][j] == 1) continue;
			board[i][j] = 1;
			func(cnt + 1, i, j);
			board[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;
	}

	func(0, 1, 1);

	if (result > 3) cout << -1;
	else cout << result;

	return 0;
}
