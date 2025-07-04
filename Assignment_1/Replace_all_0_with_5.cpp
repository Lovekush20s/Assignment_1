/*
Given an integer N, now you have to convert all zeros of N to 5.

Input Format
The first Line takes input integer N, denoting the number.

Constraints
1<=N<=10000

Output Format
Print the number after replacing all 0's with 5.

Sample Input
103

Sample Output
153

Explanation
Testcase 1: after replacing 0 with 5 ,number will become 153.
Testcase 2: there is no zero in number so it will remain same.
*/

#include<bits/stdc++.h>
using namespace std;

void replace(string &s, int i) {
	if(i == s.length()) {
		cout << s;
		return;
	}
	if(s[i] == '0') {
		s[i] = '5';
	}
	replace(s, i+1);
}

int main () {
	int n;
	cin >> n;
	string s = to_string(n);
	replace(s, 0);

	return 0;
}