#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;
deque<pair<int, int> > dq[101010];
int n, m;

bool comp(const pair<int, int> &left, const pair<int, int> &right){
    if(left.first > right.first){
        return left.first > right.first;
    }
    else if(left.first == right.first){
        return left.second < right.second;
    }
    else{
        return left.first > right.first;
    }
    
}

void input(){
    cin>>n>>m;
    int temp;
    for(int i=1; i<=n; i++){
        cin>>temp;
        v.push_back({temp, i});
    }
    
    sort(v.begin(), v.end(), comp);
    
    int old = v[0].first;
    int idx = 0;
    
    dq[0].push_back({v[0].first, v[0].second});
    
    for(int i=1; i<n; i++){
        if(v[i].first == old){
            dq[idx].push_back({v[i].first, v[i].second});
        }
        else{
            idx+=1;
            dq[idx].push_back({v[i].first, v[i].second});
            old = v[i].first;
        }
    }
}


void solve(){
   input();
   
   
   // true: 오른쪽 방향으로
   // false: 뒤집힌 방향
   bool direction = true;
   int idx = 0;
   while(m--){
       if(direction){
           //오른쪽 방향으로
           if(dq[idx].size() > 0){
               cout<<dq[idx].front().second<<"\n";
               
               if(dq[idx].front().first % 7 == 0) direction = false;
               
               dq[idx].pop_front();
           }
           else{
               idx += 1;
               cout<<dq[idx].front().second<<"\n";
               
               if(dq[idx].front().first % 7 == 0) direction = false;
               
               dq[idx].pop_front();
           }
       }
       else{
           //오른쪽에서 왼쪽으로
           if(dq[idx].size() > 0){
               cout<<dq[idx].back().second<<"\n";
               
               if(dq[idx].back().first % 7 == 0) direction = true;
               
               dq[idx].pop_back();
           }
           else{
               idx += 1;
               
               cout<<dq[idx].back().second<<"\n";
               
               if(dq[idx].back().first % 7 == 0) direction = true;
               
               dq[idx].pop_back();
           }
       }
       
   }
}

int main(){
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   solve();
}