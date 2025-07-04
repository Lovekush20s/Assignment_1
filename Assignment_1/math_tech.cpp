#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Option 1: Product of three largest numbers
    int prod1 = a[n-1] * a[n-2] * a[n-3];

    // Option 2: Product of two smallest (possibly negative) and the largest number
    int prod2 = a[0] * a[1] * a[n-1];

    cout << max(prod1, prod2) << endl;

    return 0;
}
