/*
Vivek loves to play with array . One day Vivek just came up with a new array game which was introduced to him by his friend Ujjwal. The rules of the game are as follows: Initially, there is an array, A , containing 'N' integers.
In each move, Vivek must divide the array into two non-empty contiguous parts such that the sum of the elements in the left part is equal to the sum of the elements in the right part. If Vivek can make such a move, he gets '1' point; otherwise, the game ends.
After each successful move, Vivek have to discards either the left part or the right part and continues playing by using the remaining partition as array 'A'.
Vivek loves this game and wants your help getting the best score possible. Given 'A', can you find and print the maximum number of points he can score?

Input Format
First line of input contains an integer T denoting number of test cases. Each further Test case contains first line an integer 'N' , the size of array 'A'. After that 'N' space separated integers denoting the elements of array.

Constraints
1 <= T <= 10 1 <= N <= 28 0 <= A[i] <= 10^9

Output Format
For each test case, print Vivek's maximum possible score on a new line.

Sample Input
3
3
3 3 3
4
2 2 2 2
7
4 1 0 1 1 0 1

Sample Output
0
2
3
*/

#include<bits/stdc++.h>
using namespace std;

int fxn(vector<int>& arr, int i, int j) {
	if(i >= j) return 0;

	int tsum = 0;
	for(int k = i; k <= j; k++) {
		tsum += arr[k];
	}
	int lsum = 0, rsum = tsum;
	for(int k = i; k < j; k++) {
		lsum += arr[k];
		rsum -= arr[k];
		if(lsum == rsum) {
			int x = fxn(arr, i, k);
			int y = fxn(arr, k+1, j);

			return 1 + max(x, y);
		}
	}
	return 0;

}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ans = fxn(arr, 0, n-1);
		cout << ans << endl;
	}
	return 0;
}