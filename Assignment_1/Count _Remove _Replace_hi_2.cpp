/*
Take as input str, a string.
a.) Write a recursive function which counts the number of times ‘hi’ appears in the string – but skip all such ‘hi’ which are followed by ‘t’ to form ‘hit’. Print the value returned.
b.) Write a recursive function which removes all ‘hi’ in the string – but skip all such ‘hi’ which are followed by ‘t’ to form ‘hit’. Print the value returned.
c.) Write a recursive function which replaces all ‘hi’ in the string with ‘bye’ – but skip all such ‘hi’ which are followed by ‘t’ to form ‘hit’. Print the value returned.

Input Format
Enter the String

Constraints
None

Output Format
Display the total no.of ''hi'' (''hi'' should not be followed by a 't'), string in which all ''hi'' are removes(''hi'' should not be followed by a 't'), string in which all ''hi'' are replace by ''bye''(''hi'' should not be followed by a 't')

Sample Input
abchihitfhi

Sample Output
2
abchitf
abcbyehitfbye
*/

#include<bits/stdc++.h>
using namespace std;

void hiFunctions(string &s, int i, string str1, string str2, int count) {
	if(i == s.length()) {
		cout << count << endl;
		cout << str1 << endl;
		cout << str2 << endl;
		return;
	}

	if(s[i] == 'h' and s[i+1] == 'i' and s[i+2] != 't' and i < s.length()-1) {
		hiFunctions(s, i+2, str1, str2+"bye", count+1);
	} else {
		hiFunctions(s, i+1, str1+s[i], str2+s[i], count);
	}
}

int main() {
	string s;
	cin >> s;
	string str1 = "";
	string str2 = "";
	int count = 0;
	hiFunctions(s, 0, str1, str2, count);
		
		
	return 0;
}