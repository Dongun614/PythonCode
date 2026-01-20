#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,x;
double m,y;
pair<int, double> a[5003];
int dp[10003];

int main() {
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        fill(a, a+5003, make_pair(0,0));
        fill(dp, &dp[0]+10003, 0);
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            a[i].first = x;
            a[i].second = y;
        }
        for(int i = 0; i < n; i++) {
            for(int j = a[i].second*100 + 0.5; j <= (int)(m*100 + 0.5); j++) {
                dp[j] = max(dp[j], dp[j - (int)(a[i].second*100+ 0.5)] + a[i].first);
            }
        }
        cout << dp[(int)(m*100 + 0.5)] << '\n';
    }    
    return 0;
}