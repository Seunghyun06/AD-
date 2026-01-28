#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int board[4][8];
int k;

void move(int wheel, int dir) {
    if (dir == 1) {
        int temp = board[wheel][7];
        for (int i = 7; i > 0; i--) {
            board[wheel][i] = board[wheel][i - 1];
        }
        board[wheel][0] = temp;
    }

    if (dir == -1) {
        int temp = board[wheel][0];
        for (int i = 0; i < 7; i++) {
            board[wheel][i] = board[wheel][i + 1];
        }
        board[wheel][7] = temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < 8; j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int wheel, dir;
        cin >> wheel >> dir;
        wheel--;

        int rot[4] = { 0,0,0,0 };
        rot[wheel] = dir;

        // 왼쪽 검사 (회전 X, 판단만)
        int left = wheel - 1;
        while (left >= 0) {
            if (board[left][2] == board[left + 1][6]) break;
            rot[left] = -rot[left + 1];
            left--;
        }

        // 오른쪽 검사
        int right = wheel + 1;
        while (right < 4) {
            if (board[right][6] == board[right - 1][2]) break;
            rot[right] = -rot[right - 1];
            right++;
        }

        // 실제 회전
        for (int j = 0; j < 4; j++) {
            if (rot[j] != 0) {
                move(j, rot[j]);
            }
        }
    }

    int result = 0;
    if (board[0][0] == 1) result += 1;
    if (board[1][0] == 1) result += 2;
    if (board[2][0] == 1) result += 4;
    if (board[3][0] == 1) result += 8;

    cout << result;
    return 0;
}
