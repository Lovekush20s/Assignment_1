/*
Replace all occurrences of pi with 3.14

Input Format
Integer N, no of lines with one string per line

Constraints
0 < N < 1000
0 <= len(str) < 1000

Output Format
Output result one per line

Sample Input
3
xpix
xabpixx3.15x
xpipippixx

Sample Output
x3.14x
xab3.14xx3.15x
x3.143.14p3.14xx

Explanation
All occurrences of pi have been replaced with "3.14".
*/

#include<bits/stdc++.h>
using namespace std;

void changePi(string &s, int i, string str) {
	if(i == s.length()) {
		cout << str;
		return;
	}

	if(s[i] == 'p' and s[i+1] == 'i' and i < s.length()-1) {
		// str.push_back(3.14);
		str+= "3.14";
		changePi(s, i+2, str);
	} else {
		str+=s[i];
		changePi(s, i+1, str);
	}
	
	
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while(n--) {
		string s;
		cin >> s;
		string str = "";
		changePi(s, 0, str);

		for(int i = 0; i < str.length(); i++) {
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}