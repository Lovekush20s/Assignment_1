/*
Monu bhaiya is given a string s, his task is to remove duplicate letters so that every letter appears once and only once. he must make sure his result is the smallest in lexicographical order among all possible results.

Input Format
String

Constraints
1 <= s.length <= 104
s consists of lowercase English letters.

Output Format
Print resulting string

Sample Input
bcabc

Sample Output
abc
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string &s, int ind, string& curr, unordered_map<char, int>& mp, unordered_map<char, bool>& help) {
    if(ind == s.size()) return;

    char ch = s[ind];

    if(help[ch]) {
        solve(s, ind+1 , curr, mp, help);
        return ;
    }

    while(!curr.empty() && curr.back() > ch &&  mp[curr.back()] > ind) {
        help[curr.back()] = false;
        curr.pop_back();
    }

    help[ch] = true;
    curr.push_back(ch);

    solve(s, ind+1, curr, mp, help);

}

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    unordered_map<char, bool> help;
    string curr = "";
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]] = i;
    }

   
    solve(s, 0, curr, mp, help);
    cout << curr << endl;
    return 0;
}