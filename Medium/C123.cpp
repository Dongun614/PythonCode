#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[10001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int index = 0;
	for (int i = N-1; i >= 1; i--) {
		if (arr[i] > arr[i + 1]) {
			index = i;
			break;
		}
	}
	if (index == 0) {
		cout << -1;
		return 0;
	}
	int temp = arr[index];
	int temp_index = index;
	for (int i = index + 1; i <= N; i++) {
		if (arr[i] < arr[index]) {
			temp = arr[i];
			temp_index = i;
		}
	}
	
	swap(arr[index], arr[temp_index]);
	sort(arr + index+1, arr + 1 + N,greater<>());
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}