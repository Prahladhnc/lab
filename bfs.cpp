#include <iostream>
#include <queue>
using namespace std;

int a[10][10], n;

void bfs(int);

int main() {
    int i, j, src;
    cout << "\nEnter the number of nodes:\t";
    cin >> n;
    cout << "\nEnter the adjacency matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "\nEnter the source node:\t";
    cin >> src;
    bfs(src);
    return 0;
}

void bfs(int src) {
    queue<int> q;
    int vis[10] = {0}; // Initialize vis[] to all zeros
    q.push(src);
    vis[src] = 1;

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && vis[j] != 1) {
                vis[j] = 1;
                q.push(j);
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        if (vis[j] != 1) {
            cout << "\nNode " << j << " is not reachable\n";
        } else {
            cout << "\nNode " << j << " is reachable\n";
        }
    }
}
