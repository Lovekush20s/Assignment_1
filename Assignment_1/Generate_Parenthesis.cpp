/*
Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2

Sample Output
()() 
(()) 
*/

#include<bits/stdc++.h>
using namespace std;

void fxn(string &s, int i, int open, int close, int n) {
    if(i == 2 * n) {
        // str.push_back(s);
		cout << s << endl;
        return;
    }

    if(close < open) {
        s[i] = ')';
        fxn(s, i + 1, open, close + 1, n);
    }

    if(open < n) {
        s[i] = '(';
        fxn(s, i + 1, open + 1, close, n);
    }
}

int main() {
    int n;
    cin >> n;
    string s(2 * n, ' ');
	// vector<string> str;
    fxn(s, 0, 0, 0, n);

	// sort(str.begin(), str.end());

	// for(string &it : str) {
	// 	cout << it << endl;
	// }

    return 0;
}