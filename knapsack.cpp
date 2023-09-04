#include <iostream>
using namespace std;

void knapsack();
int max(int, int);

int i, j, n, m, p[10], w[10], v[10][10];

int main() {
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the weight of each item:" << endl;
    for (i = 1; i <= n; i++) {
        cin >> w[i];
    }

    cout << "Enter the profit of each item:" << endl;
    for (i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Enter the knapsack's capacity: ";
    cin >> m;

    knapsack();
    return 0;
}

void knapsack() {
    int x[10];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j - w[i] < 0) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    cout << "\nThe output is:\n";
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            cout << v[i][j] << "\t";
        }
        cout << "\n\n";
    }

    cout << "\nThe optimal solution is " << v[n][m] << endl;
    cout << "The solution vector is:\n";
    for (i = n; i >= 1; i--) {
        if (v[i][m] != v[i - 1][m]) {
            x[i] = 1;
            m = m - w[i];
        } else {
            x[i] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << x[i] << "\t";
    }
}

int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
