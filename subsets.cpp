#include <iostream>
using namespace std;

int count, w[10], d, x[10];

void subset(int cs, int k, int r) {
    int i;
    x[k] = 1;

    if (cs + w[k] == d) {
        cout << "\nSubset solution = " << ++count << endl;
        for (i = 0; i <= k; i++) {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << endl;
    } else if (cs + w[k] + w[k + 1] <= d)
        subset(cs + w[k], k + 1, r - w[k]);

    if ((cs + r - w[k] >= d) && (cs + w[k + 1] <= d)) {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main() {
    int sum = 0, i, n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements in ascending order: ";
    for (i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter the required sum: ";
    cin >> d;

    for (i = 0; i < n; i++)
        sum += w[i];

    if (sum < d) {
        cout << "No solution exists" << endl;
        return 0;
    }

    cout << "The solution is:" << endl;
    count = 0;
    subset(0, 0, sum);

    return 0;
}
