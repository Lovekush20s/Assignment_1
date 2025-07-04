/*
Take as input str, a string. Write a recursive function which prints all the words possible by rearranging the characters of this string which are in dictionary order larger than the given string.
The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 10
All characters are unique

Output Format
Display all the words which are in dictionary order larger than the string entered in a new line each. The output strings must be sorted.

Sample Input
cab

Sample Output
cba

Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only one of them is lexicographically greater than "cab". We only print "cba".
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> freq(26, 0);

void fxn(string& s, int n, int i, vector<string> &str, string temp) {
	if(temp.size() == n) {
		str.push_back(temp);
		return;
	}

	for(int j = 0; j < n; j++) {
		if(freq[j] == 0){
		temp.push_back(s[j]);
		freq[j] = 1;
		fxn(s, n, i, str, temp);
		freq[j] = 0;
		temp.pop_back();
		}
	}
}

int main() {

	string s;
	cin >> s;
	int n = s.length();
	vector<string> str;
	string temp;
	fxn(s, n, 0, str, temp);

sort(str.begin(),str.end());
	for(int i = 0; i < str.size(); i++)
	 {	

		if(str[i] > s)
		{
			cout<<str[i]<<" ";
		}
		cout<<endl;
	 }
	return 0;
}