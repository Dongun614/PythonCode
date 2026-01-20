#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int answer = 0;
void recursive(string s, string t) {
	//cout << "s : " << s << " t : " << t << "\n";

	if (s.size() > t.size()) {
		
		return;
	}
	if (s == t) {
		answer = 1;
		return;
	}
	if (t[0] == t[t.size() - 1]) {
		if (t[0] == 'A') { // A A
			t.pop_back();
			recursive(s, t);
		}
		else {
			reverse(t.begin(), t.end()); // B B
			t.pop_back();
			recursive(s, t);
		}
		
	}
	else {
		if (t[t.size() - 1] == 'A') { 
			if (t[0] == 'B') {//B A
				string temp = t;
				temp.pop_back();
				recursive(s, temp);
				reverse(t.begin(), t.end());
				t.pop_back();
				recursive(s, t);
			}
		}
		else {// A B
			if (t[0] == 'A') {
				return;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S, T;
	cin >> S >> T;
	recursive(S, T);
	cout << answer << "\n";
	return 0;
}