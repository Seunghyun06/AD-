#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 }; //오 위 왼 아
int board[105][105];
int n;
vector<int> d_save;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int y, x, d, g;
		d_save.clear();
		bool isOut = false;
		cin >> x >> y >> d >> g;
		
		board[y][x] = 1;
		y += dy[d];
		x += dx[d];
		board[y][x] = 1;
		d_save.push_back(d);

		while (g--) {
			int cnt = d_save.size();
			for (int j = cnt - 1; j >= 0; j--) {
				d = (d_save[j] + 1) % 4;
				y += dy[d];
				x += dx[d];
				board[y][x] = 1;
				d_save.push_back(d);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] &&
				board[i][j + 1] &&
				board[i + 1][j] &&
				board[i + 1][j + 1]) {
				result++;
			}
		}
	}

	cout << result;

	return 0;
}
