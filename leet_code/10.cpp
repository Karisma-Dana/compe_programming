#include <bits/stdc++.h>
using namespace std;



bool isMatch(string s, string p, int sIndex, int pIndex, vector<vector<int>> &memo ){

    if (sIndex == s.length() && pIndex == p.length()) return true;

    if (pIndex >= p.length()) return false;

    if (memo[sIndex][pIndex] != -1) return memo[sIndex][pIndex] == 1;






    bool checkMatch = sIndex < s.length() && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
    bool nextStar = pIndex + 1 < p.length() && p[pIndex + 1] == '*';

    bool result;
    if(checkMatch){
        if (nextStar){
            result = isMatch(s, p, sIndex + 1, pIndex, memo) || isMatch(s,p, sIndex, pIndex + 2, memo);
        }else{
            result = isMatch(s, p, sIndex + 1, pIndex + 1, memo);
        }

    }else{
        if(nextStar){
            result = isMatch(s, p, sIndex, pIndex + 2, memo);
        }else{
            result = false;

        }
    }
    memo[sIndex][pIndex] = result ? 1 : 0;
    return result;


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s;
    cin >> p;

    vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));

    bool result = isMatch(s, p, 0,0, memo);
    cout << result ? "true" : "false";






}