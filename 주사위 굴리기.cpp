#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, x, y, k;

int dice[] = { 0,0,0,0,0,0 }; // 0 : 맨 위, 1 : 맨아래, 2 : 앞, 3: 뒤, 4: 오, 5: 왼

int board[25][25];

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 }; //동, 서, 북, 남

void move(int dir) {

	int temp = dice[0];

	if (dir == 0) { //동
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
	}
	if (dir == 1) { //서
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
	}
	if (dir == 2) { //북
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
	}
	if (dir == 3) { //남
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(board, 0, sizeof(board));

	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int rotate;
		cin >> rotate;

		int ny = y + dy[rotate - 1];
		int nx = x + dx[rotate - 1];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		//먼저 move시켜서, 주사위를 해당 방향에 맞게 이동
		move(rotate - 1);

		//이동하는 칸이 0이면, 주사위의 아래의 수가 바닥에 복사
		if (board[ny][nx] == 0) {
			board[ny][nx] = dice[1];
		}

		//아니면 지도에 쓰여져있는 수가, 주사의 아래에 복사됨
		//해당 지도 칸은 0이 됨
		else {
			dice[1] = board[ny][nx];
			board[ny][nx] = 0;
		}

		y = ny;
		x = nx;

		cout << dice[0] << '\n';
	}


	return 0;
}
