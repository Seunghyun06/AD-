#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long b, c;
vector<long long> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	cin >> b >> c;

	long long cnt = 0;

	for (int i = 0; i < n; i++) {
		long long remain = A[i] - b;
		cnt++;
		if (remain > 0) {
			if (remain % c == 0) cnt += remain / c;
			else cnt += remain / c + 1;
		}
	}

	cout << cnt;

	return 0;
}
