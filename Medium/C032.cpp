#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 1;
    int layer = 1;
    int n;
    cin >> n;

    while (cnt < n) {
        cnt += 6 * layer;
        layer++;
    }
    cout << layer;
}