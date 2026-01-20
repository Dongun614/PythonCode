#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool cmp(pi a, pi b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	FASTIO;
	int n, m;
	cin >> n;
	vector<pi> a, b;
 	for (int i = 0, v; i < n; i++) {
		cin >> v;
		a.push_back({ v, i });
	}
	cin >> m;
	for (int i = 0, v; i < m; i++) {
		cin >> v;
		b.push_back({ v, i });
	}

	vector<int> ans;
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);

	int idxa = 0, idxb = 0, limita=0, limitb=0;
	while (idxa < n && idxb < m) {
		if (a[idxa].first == b[idxb].first) {
			if (limita > a[idxa].second) idxa++;
			else if (limitb > b[idxb].second) idxb++;
			else {
				limita = a[idxa].second;
				limitb = b[idxb].second;
				ans.push_back(a[idxa].first);
				idxa++;
				idxb++;
			}
		}
		else if (a[idxa].first > b[idxb].first) idxa++;
		else idxb++;
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}