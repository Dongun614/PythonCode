#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> pipe;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int D, P;

	cin >> D >> P;

	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		pipe.push_back({ a, b });
	}
	dp[0] = 123123213;

	for (int i = 0; i < P; i++) {
		int cost = pipe[i].first;
		int value = pipe[i].second;
		for (int j = D; j >= cost; j--) {
			dp[j] = max(dp[j], min(dp[j - cost], value));
		}
	}

	cout << dp[D] << '\n';
}