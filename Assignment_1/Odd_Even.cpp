/*
Take as input N, a number. Print odd numbers in decreasing sequence (up until 0) and even numbers in increasing sequence (up until N) using Recursion

Constraints
1 <= N <=1000

Sample Input
5

Sample Output
5
3
1
2
4
*/

#include<bits/stdc++.h>
using namespace std;

void decreasing(int n) {
	if(n <= 0) {
		return;
	}
	cout << n << endl;
	decreasing(n-2);
}

void increasing(int n) {
	if(n <= 0) {
		return;
	}
	increasing(n-2);
	cout << n << endl;
}

int main() {
	int n;
	cin >> n;

	if(n%2 != 0) {
		decreasing(n);
		increasing(n-1);
	} else {
		decreasing(n-1);
		increasing(n);
	}

	return 0;
}