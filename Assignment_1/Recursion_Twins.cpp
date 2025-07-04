/*
Take an input str, a string. A “twin” is defined as two instances of a char separated by a char. E.g. "AxA" the A's make a “twin”. “twins” can overlap, so "AxAxA" contains 3 “twins” - 2 for A and 1 for x. Write a function which recursively counts number of “twins” in a string. Print the value returned.

Input Format
Enter the string

Constraints
None

Output Format
Display the number of twins

Sample Input
AXAXA

Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;

int fxn(string &s, int i, int n, int &ans) {
	if(i >= n-2) {
		return 0;
	}
	if(s[i] == s[i+2]) {
		ans++;
	}
	fxn(s, i+1, n, ans);

	return ans;
}
int main() {
	string s;
	getline(cin, s);
	int n = s.length();

	int ans = 0;
	fxn(s, 0, n, ans);
	cout << ans << endl;
	return 0;
}