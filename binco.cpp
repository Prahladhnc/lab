#include <iostream>
using namespace std;

int bin(int n, int k) {
    int c[10][10];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || i == j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return c[n][k];
}

int main() {
    int n, k;

    cout << "Enter the value of n & k such that n > k: ";
    cin >> n >> k;

    if (n < k) {
        cout << "Invalid input: n must be greater than or equal to k." << endl;
        return 1;
    }

    cout << "C(" << n << "," << k << ") = " << bin(n, k) << endl;

    return 0;
}
