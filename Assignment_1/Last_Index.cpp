/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns the last index at which M is found in the array and -1 if M is not found anywhere. Print the value returned.

Input Format
Enter a number N and add N more numbers to an array, then enter number M to be searched

Constraints
None

Output Format
Display the last index at which the number M is found

Sample Input
5
3
2
1
2
3
2

Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;

int fxn(vector<int> arr, int i, int n, int m) {
	if(i == -1) return -1;
	if(arr[i] == m) return i;

	return fxn(arr, i-1, n, m);
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m;
	cin >> m;

	cout << fxn(arr, n-1, n, m) << endl;

	return 0;
}
