/*
Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.
a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.
b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.given string (void is the return type for function).
Note: Use cin for input for C++

Input Format
Enter a string

Constraints
None

Output Format
Print all the subsequences in a space separated manner and isplay the total no. of subsequences.

Sample Input
abcd

Sample Output
d c cd b bd bc bcd a ad ac acd ab abd abc abcd 
16

Explanation
Print all possible subsequences of the given string.
*/

#include <bits/stdc++.h>
using namespace std;

void sequence(string s, string temp, int idx, int &count){

    if (s.size() == idx) {
        cout << temp << " ";
		count++;
        return;
    }
    sequence(s, temp, idx+1, count);
    sequence(s, temp+s[idx], idx+1, count);
}
int main() {

    string s;
    cin >> s;
	int count = 0;
    sequence(s, "", 0, count);
    cout << endl;
	cout << count;

}