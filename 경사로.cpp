
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, l;
int board[105][105];
int result = 0;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 }; //오 아 왼 위

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	//왼쪽 오른쪽
	for (int i = 0; i < n; i++) {
		bool used[105] = { false };
		bool ok = true;
		for (int j = 0; j < n - 1; j++) {
			int diff = board[i][j] - board[i][j + 1];
			if (abs(diff) > 1) {
				ok = false;
				break;
			}
			if (diff == 0) continue;

			//내리막길
			if (diff == 1) {
				for (int k = 1; k <= l; k++) {
					if (j + k >= n || board[i][j] - 1 != board[i][j + k] || used[j + k]) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
				for (int k = 1; k <= l; k++) used[j + k] = true;
			}

			//오르막길
			else if (diff == -1) {
				for (int k = 0; k < l; k++) {
					if (j - k < 0 || board[i][j] != board[i][j - k] || used[j - k]) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
				for (int k = 0; k < l; k++) used[j - k] = true;
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) result++;
	}

	//위 아래
	for (int j = 0; j < n; j++) {
		bool used[105] = { false };
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			int diff = board[i][j] - board[i + 1][j];
			if (abs(diff) > 1) {
				ok = false;
				break;
			}
			if (diff == 0) continue;

			//아래
			else if (diff == 1) {
				for (int k = 1; k <= l; k++) {
					if (i + k >= n || board[i][j] - 1 != board[i + k][j] || used[i + k]) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
				for (int k = 1; k <= l; k++) used[i + k] = true;
			}
			//위
			else if (diff == -1) {
				for (int k = 0; k < l; k++) {
					if (i - k < 0 || board[i][j] != board[i - k][j] || used[i - k]) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
				for (int k = 0; k < l; k++) used[i - k] = true;
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) result++;
	}

	cout << result;


	return 0;
}
