/*
Take as input N, a number. Write a recursive function to find Nth triangle where 1st triangle is 1, 2nd triangle is 1 + 2 = 3, 3rd triangle is 1 + 2 + 3 = 6, so on and so forth. Print the value returned.

Input Format
Integer N is the single line of input.

Constraints
1 <= N <= 100

Output Format
Print the output as a single integer which is the nth triangle.

Sample Input
3

Sample Output
6

*/

#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    if(n == 1) {
        return 1;
    }
    return n + sum(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0; 
}