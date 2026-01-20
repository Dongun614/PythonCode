#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int T; cin >> T;

    for(int t = 0; t < T; t++){
        int N; cin >> N;
        
        vector<int> race;

        map<int, int> maps;

        for(int i = 0; i < N; i++){
            int n; cin >> n;
            maps[n]++;
            race.push_back(n);
        }

        vector<int> scores[201];
        int idx = 1;
        for(int i = 0; i < N; i++){
            if(maps[race[i]] == 6) {
                scores[race[i]].push_back(idx);
                idx++;
            }
        }

        int winner = -1;
        int winScore = 1231312;
        int five = -1;

        for(int i = 1; i < 201; i++){
            int tmp = 0;

            if(scores[i].size() == 6){
                for(int j = 0; j < 4; j++) tmp += scores[i][j];

                if(tmp < winScore) {
                    winScore = tmp;
                    winner = i;
                    five = scores[i][4];
                }

                if(tmp == winScore && five > scores[i][4]){
                    winner = i;
                    five = scores[i][4];
                }
            }
        }

        cout << winner << '\n';
    }
}