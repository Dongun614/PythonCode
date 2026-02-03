#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> line(100005);
vector<int> order;
vector<int> psum(100005, 0);
long long result = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	int before_max_right = -1;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;

		line[i] = make_pair(a, b);


		if (i == 1) {
			psum[i] = 0;
		}

		else {
			psum[i] = psum[i - 1] + max(0, line[i].first - before_max_right); //빈 공간의 누적합
		}

		before_max_right = max(before_max_right, line[i].second);
	}

	order.push_back(1); //1에서 시작
	for (int i = 0; i < k; i++) {
		int input;
		cin >> input;

		order.push_back(input);
	}

	for (int i = 0; i < order.size() - 1; i++) {
		int start = min(order[i], order[i + 1]);
		int dest = max(order[i], order[i + 1]);

		//start에서 dest까지 가는데 빈칸을 몇개 지나야 되는지 확인
		result += (psum[dest] - psum[start]);
	}

	cout << result;

	return 0;
}