/*
Take as input str, a string. a.Write a recursive function which counts the number of times ‘hi’ appears in the string. Print the value returned. b.Write a recursive function which removes all ‘hi’ in the string. Print the value returned. c.Write a recursive function which replaces all ‘hi’ in the string with ‘bye’. Print the value returned.

Input Format
Enter a string

Constraints
None

Output Format
Display the no. of 'hi', string without 'hi' , string in which 'hi' is replaced with 'bye'

Sample Input
abchibi

Sample Output
1
abcbi
abcbyebi
*/

#include<bits/stdc++.h>
using namespace std;

void changeHi(string &s, int i, string str2) {
	if(i == s.length()) {
		cout << str2;
		return;
	}
	if(s[i] == 'h' and s[i+1] == 'i' and i < s.length()-1) {
		str2 += "bye";
		changeHi(s, i+2, str2);
	} else {
		str2 += s[i];
		changeHi(s, i+1, str2);
	}
}

void removeHi(string &s, int i, string str1, int &count) {
	if(i == s.length()) {
		cout << count << endl;
		cout << str1 << endl;
		return;
	}
	if(s[i] == 'h' and s[i+1] == 'i' and i < s.length()-1) {
		str1 += "";
		count++;
		removeHi(s, i+2, str1, count);
	} else {
		str1 += s[i];
		removeHi(s, i+1, str1, count);
	}
}

int main() {
	string s;
	cin >> s;
	string str1 = "";
	string str2 = "";
	int count = 0;
	removeHi(s, 0, str1, count);
	changeHi(s, 0, str2);
		
		
	return 0;
}