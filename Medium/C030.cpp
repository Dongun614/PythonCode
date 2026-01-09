#include <iostream>
using namespace std;
typedef long long ll;

ll comb[32][32];
void combinit() {
	comb[0][0] = 1;
	for (int n = 1; n < 32; n++) {
		comb[n][0] = 1;
		for (int r = 1; r <= n; r++) comb[n][r] = comb[n - 1][r - 1] + comb[n - 1][r];
	}
}

int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	combinit();

	cin >> N >> M;
	cout << comb[M - 1][N - 1];
}