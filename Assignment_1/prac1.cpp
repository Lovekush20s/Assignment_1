#include<bits/stdc++.h>
using namespace std;

int fn(string &s,int i, int n, int &ans){
    if(i >= n-2){
        ans++;
    }
    if(s[i] == s[i+2]){
        ans++;
    }
    fn(s, i+1,n,ans);

    return ans;
}
int main(){
    string s;
    getline(cin, s);
    int n=s.length();

    int ans=0;
    fn(s,0, n, ans);
    cout<<ans <<endl;
    return 0;
}