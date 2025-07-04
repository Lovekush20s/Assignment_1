/*
Take as input N, a number. Write a recursive function which prints counting from 0 to N in lexicographical order. In lexicographical (dictionary) order 10, 100 and 109 will be printed before 11.

Input Format
Enter a number N.

Constraints
None

Output Format
Display all the numbers upto N in a lexicographical order

Sample Input
10

Sample Output
0 1 10 2 3 4 5 6 7 8 9 
*/

#include <bits/stdc++.h>
using namespace std;

void fxn(int n, int i, vector<int>& ans) {
	if(i > n) {
	return;
	}
	ans.push_back(i);
	for(int j = (i == 0 ? 1 : 0); j <= 9; j++) {
		int	num = i*10 + j;
		if(num > n) return;
		fxn(n, num, ans);
	}

}

int main() {
    int n;
    cin >> n;
	vector<int> ans;
    fxn(n, 0, ans);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
    return 0;
}