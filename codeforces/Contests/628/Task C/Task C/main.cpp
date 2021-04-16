#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int n;
vi adj[10001];
int visited[10001];
int v[10001];
int d[10001];

int dfs(int n, int depth) {
    visited[n] = 1;
    int deepest = 0;
    for (int i = 0; i < adj[n].size(); i++) {
        if (!visited[adj[n][i]]) {
            deepest = max(deepest, dfs(adj[n][i], depth+1));
        }
    }
    d[n] = deepest;
    return depth;
}
int l = 0, r = n-1, c = 0;

void ans(int n) {
    v[n] = 1;
    for (int i = 0; i < adj[n].size(); i++) {
        if (!v[adj[n][i]]) {
            if (c % 2 == 0) {
                
                l++;
                c++;
            } else {
                
                r--;
                c++;
            }
            ans(adj[n][i]);
        }
    }
}

bool comp(int a, int b) {
    return d[a] > d[b];
}

int main() {
    cin >> n;
    int a, b;
    vector<pii> out;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        out.PB(MP(a,b));
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    
    
    dfs(n, 0);
    
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), comp);
    }
    
    ans(1);
    
    return 0;
}



