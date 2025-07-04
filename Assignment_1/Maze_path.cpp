/*
Take as input N1 and N2, both numbers. N1 and N2 is the number of rows and columns on a rectangular board. Our player starts in top-left corner of the board and must reach bottom-right corner. In one move the player can move 1 step horizontally (right) or 1 step vertically (down).
a. Write a recursive function which returns the count of different ways the player can travel across the board. Print the value returned.
b. Write a recursive function which returns an ArrayList of moves for all valid paths across the board. Print the value returned.
e.g. for a board of size 3,3; a few valid paths will be “HHVV”, “VVHH”, “VHHV” etc. c. Write a recursive function which prints moves for all valid paths across the board (void is the return type for function).

Input Format
Enter the number of rows N and columns M

Constraints
None

Output Format
Display the total number of paths and display all the possible paths in a space separated manner

Sample Input
3
3

Sample Output
VVHH VHVH VHHV HVVH HVHV HHVV
6
*/

#include <bits/stdc++.h>
using namespace std;

int maze(int n, int m, int i, int j, string p, vector<vector<int>> &arr) {
    if (i == n - 1 and j == m - 1) {
        cout << p << " ";
        return 1;
    }

    if (i >= n || j >= m) return 0;  
    if (arr[i][j] == -1) return 0;  

    int x = maze(n, m, i + 1, j, p + "V", arr); 
    int y = maze(n, m, i, j + 1, p + "H", arr); 

    return x + y;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans=maze(n, m, 0, 0, "", arr) ;
	cout<<endl;
	cout<< ans; 

    return 0;
}