#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int board[25][25];
bool visit[10];
int n;
int temp[25][25];
vector<int> v;
int result = -1;

int moveball() {
	int temp2[25][25];
	memcpy(temp2, board, sizeof(temp)); // 원래 board를 Backup한 값
	for (int i = 0; i < 5; i++) {
		memset(temp, 0, sizeof(temp));
		int Temp_dir = v[i];
		if (Temp_dir == 0) { //오른쪽
			for (int i = 0; i < n; i++) {
				int pos = n - 1; //현재 놓을 위치
				for (int j = n - 1; j >= 0; j--) {
					if (board[i][j] == 0) continue;
					if (temp[i][pos] == 0) temp[i][pos] = board[i][j];
					else if (temp[i][pos] == board[i][j]) {
						temp[i][pos] *= 2;
						pos--;
					}
					else {
						pos--;
						temp[i][pos] = board[i][j];
					}
				}
			}
		}
		if (Temp_dir == 1) { //왼쪽
			for (int i = 0; i < n; i++) {
				int pos = 0;
				for (int j = 0; j < n; j++) {
					if (board[i][j] == 0) continue;
					if (temp[i][pos] == 0) temp[i][pos] = board[i][j];
					else if (temp[i][pos] == board[i][j]) {
						temp[i][pos] *= 2;
						pos++;
					}
					else {
						pos++;
						temp[i][pos] = board[i][j];
					}
				}
			}
		}
		if (Temp_dir == 2) { //위
			for (int j = 0; j < n; j++) {
				int pos = 0;
				for (int i = 0; i < n; i++) {
					if (board[i][j] == 0) continue;
					if (temp[pos][j] == 0) temp[pos][j] = board[i][j];
					else if (temp[pos][j] == board[i][j]) {
						temp[pos][j] *= 2;
						pos++;
					}
					else {
						pos++;
						temp[pos][j] = board[i][j];
					}
				}
			}
		}
		if (Temp_dir == 3) { //아래
			for (int j = 0; j < n; j++) {
				int pos = n - 1;
				for (int i = n - 1; i >= 0; i--) {
					if (board[i][j] == 0) continue;
					if (temp[pos][j] == 0) temp[pos][j] = board[i][j];
					else if (temp[pos][j] == board[i][j]) {
						temp[pos][j] *= 2;
						pos--;
					}
					else {
						pos--;
						temp[pos][j] = board[i][j];
					}
				}
			}
		}
		memcpy(board, temp, sizeof(board)); //위치 갱신
	}
	int tempmax = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tempmax = max(temp[i][j], tempmax);
		}
	}
	memcpy(board, temp2, sizeof(board));
	return tempmax;
}

void func(int cnt) {
	if (cnt == 5) {
		int LocalMax = moveball();
		result = max(result, LocalMax);
		return;
	}

	for (int d = 0; d < 4; d++) {
		v.push_back(d);
		func(cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	func(0);

	cout << result;

	return 0;
}