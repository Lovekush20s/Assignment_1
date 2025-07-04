/*
Take an input N, a number. Take N more inputs and store that in an array. Take an input target, a number
a. Write a recursive function which prints subsets of the array which sum to target.
b. Write a recursive function which counts the number of subsets of the array which sum to target. Print the value returned.


Input Format
Take an input N, a number. Take N more inputs and store that in an array. Take an input target, a number

Constraints
None

Output Format
Display the number of subsets and print the subsets in a space separated manner.

Sample Input
3
1
2
3
3

Sample Output
1 2  3
2

Explanation
Add 2 spaces between 2 subset solutions
*/

#include<bits/stdc++.h>
using namespace std;

int cnt=0;
void fxn(vector<int> &v, int ind, int n, vector<int> temp, int target, int sum,vector<vector<int>> &ans) {
	if(ind == n) {

		if(sum == target) {
			ans.push_back(temp);
			cnt++;
		}
		return;
	}

	temp.push_back(v[ind]);
	fxn(v, ind+1, n, temp, target, sum+v[ind],ans);
	temp.pop_back();
	fxn(v, ind+1, n, temp, target, sum,ans);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int target;
	cin >> target;
	int sum = 0;
	vector<int> temp;
	vector<vector<int>> ans;

	fxn(v, 0, n, temp, target, sum,ans);

	for(auto &i:ans)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<" ";
	}
	cout<<endl;
	cout << cnt;
	return 0;
}