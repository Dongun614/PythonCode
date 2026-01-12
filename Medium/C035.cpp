#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int X[100001];
int Y[100001];

pair<int, int> points[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		points[i] = { x,y };
		X[x]++;
		Y[y]++;
	}

	ll ans = 0;

	for (int i = 0; i < N; i++) {
		ans += ((ll)X[points[i].first] - 1) * ((ll)Y[points[i].second] - 1);
	}

	cout << ans;
}