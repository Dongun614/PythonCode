#include <bits/stdc++.h>
using namespace std;

string s;
string n("");
bool ze=false;
bool twox=false;

int main(){
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='x'){
            if(stoi(n)/2==-1) cout << '-';
            else if(stoi(n)/2!=1) cout << stoi(n)/2;
            cout << "xx";
            n="";
            ze=false;
            twox=true;
        }
        else if(n==""){
            n=s[i];
            ze=true;
        }
        else n+=s[i];
    }
    if(ze && abs(stoi(n))!=0){
        if(n=="+1") cout << "+";
        else if(n=="-1") cout << "-";
        else if(n!="1") cout << n;
        cout << "x+W";
    }
    else if(twox) cout << "+W";
    else cout << 'W';
}