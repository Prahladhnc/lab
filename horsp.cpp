#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int table[126];
    char t[100], p[25];
    int n, i, k, j, m, flag = 0;

    cout << "Enter the Text:" << endl;
    cin.getline(t, sizeof(t));
    n = strlen(t);

    cout << "Enter the Pattern:" << endl;
    cin.getline(p, sizeof(p));
    m = strlen(p);

    for (i = 0; i < 126; i++)
        table[i] = m;

    for (j = 0; j <= m - 2; j++)
        table[p[j]] = m - 1 - j;

    i = m - 1;

    while (i <= n - 1) {
        k = 0;

        while (k <= m - 1 && p[m - 1 - k] == t[i - k])
            k++;

        if (k == m) {
            cout << "The position of the pattern is " << i - m + 2 << endl;
            flag = 1;
            break;
        } else
            i = i + table[t[i]];
    }

    if (!flag)
        cout << "Pattern is not found in the given text" << endl;

    return 0;
}
