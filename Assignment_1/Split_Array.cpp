/*
Take as input N, a number. Take N more inputs and store that in an array.
a. Write a recursive function which counts the number of ways the array could be split in two groups, so that the sum of items in both groups is equal. Each number in the array must belong to one of the two groups. Print the value returned.
b. Write a recursive function which keeps track of ways an array could be split in two groups, so that the sum of items in both groups is equal. Each number in the array must belong to one of the two groups. Return type of function should be void. Print the two groups, each time you find a successful split.

Input Format
Take as input N, a number. Take N more inputs and store that in an array.

Constraints
None

Output Format
Display all the groups in a comma separated manner and display the number of ways the array can be split

Sample Input
6
1
2
3
3
4
5

Sample Output
1 2 3 3 and 4 5 
1 3 5 and 2 3 4 
1 3 5 and 2 3 4 
2 3 4 and 1 3 5 
2 3 4 and 1 3 5 
4 5 and 1 2 3 3 
6
*/

#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

void solve(vector<int>& g1, vector<int>& g2, int ind, int sum1, int sum2, vector<int>& v) {
	if(ind == v.size()) {
		if(sum1 == sum2) {
			for(int p = 0; p < g1.size(); p++) {
				cout << g1[p] << " ";
			}
			cout << "and ";
			for(int p = 0; p < g2.size(); p++) {
				cout << g2[p] << " ";
			}
			cout << endl;
			cnt++;
		}
		return;
	}
	g1.push_back(v[ind]);
	solve(g1, g2, ind+1, sum1+v[ind], sum2, v);
	g1.pop_back();
	g2.push_back(v[ind]);
	solve(g1, g2, ind+1, sum1, sum2+v[ind], v);
	g2.pop_back();
	
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> g1;
	vector<int> g2;
	solve(g1, g2, 0, 0, 0, v);
	cout << cnt;
	return 0;
}