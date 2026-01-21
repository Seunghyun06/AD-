#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> p;
int result = -1;
bool visit[20];

void func(int day, int sum) {
	if (day >= n) {
		result = max(result, sum);
		return;
	}
	if (day + v[day].first <= n) func(day + v[day].first, sum + v[day].second);
	func(day + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int T, P;
		cin >> T >> P;
		v.push_back({ T,P });
	}

	func(0, 0);

	cout << result;


	return 0;
}
