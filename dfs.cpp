#include <iostream>
using namespace std;

int a[10][10], n, vis[10];

int dfs(int);

int main() {
    int i, j, src, ans;
    
    cout << "\nEnter the number of nodes:\t";
    cin >> n;
    
    for (j = 1; j <= n; j++) {
        vis[j] = 0;
    }
    
    cout << "\nEnter the adjacency matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "\nEnter the source node:\t";
    cin >> src;
    
    ans = dfs(src);
    
    if (ans == 1) {
        cout << "\nGraph is connected\n";
    } else {
        cout << "\nGraph is not connected\n";
    }
    
    return 0;
}

int dfs(int src) {
    vis[src] = 1;
    
    for (int j = 1; j <= n; j++) {
        if (a[src][j] == 1 && vis[j] != 1) {
            dfs(j);
        }
    }
    
    for (int j = 1; j <= n; j++) {
        if (vis[j] != 1) {
            return 0;
        }
    }
    
    return 1;
}
