#include <iostream>
#include <cmath>
using namespace std;

int count = 0;

bool place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (i + x[i] == k + x[k] || i - x[i] == k - x[k] || x[i] == x[k]) {
            return false;
        }
    }
    return true;
}

void nqueens(int n) {
    int k = 1;
    int x[20];
    x[k] = 0;

    while (k != 0) {
        x[k]++;
        while (!place(x, k) && x[k] <= n) {
            x[k]++;
        }
        if (x[k] <= n) {
            if (k == n) {
                cout << "\nSolution " << ++count << ":\n";
                cout << "Queen\t\tPosition\n";
                for (int i = 1; i <= n; i++) {
                    cout << i << "\t\t" << x[i] << endl;
                }
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of Queens: ";
    cin >> n;

    nqueens(n);

    return 0;
}
