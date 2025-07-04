/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. If a path exists-it is always unique. Find that path and help the rat reach its cheese.

Input Format
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints
1 <= N , M <= 10

Output Format
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"

Sample Input
5 4
OXOO
OOOX
XOXO
XOOX
XXOO

Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 0 
0 0 1 1 
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool foundPath = false;

void solve(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& path) {
    if (i == n - 1 && j == m - 1 && grid[i][j] == 'O') {
        path[i][j] = 1;
        foundPath = true;
        return;
    }

    if (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 'O' && path[i][j] == 0) {
        path[i][j] = 1;

        solve(grid, i, j + 1, path);
        if (foundPath) return; 

        solve(grid, i + 1, j, path);
        if (foundPath) return;  

        solve(grid, i, j - 1, path);
        if (foundPath) return;  

        solve(grid, i - 1, j, path);
        if (foundPath) return;  

        path[i][j] = 0;
    }
}

int main() {
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));
    for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
        	cin >> grid[i][j];
		}
    }

    vector<vector<int>> path(n, vector<int>(m, 0));
    solve(grid, 0, 0, path);

    if (foundPath) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO PATH FOUND" << endl;
    }

    return 0;
}