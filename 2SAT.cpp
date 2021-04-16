#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

template<size_t S>
struct SCC {
    vector<int> adj[S+1];
    vector<int> toposort;

    // forward edge (visit unvisited vertex) 
    // back edge (visit still processing)
    // cross edge (visit already visited vertex)
    void dfs(int cur = 1) {
        
    }

    void find_toposort() {
        
    }

    SCC() {

    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    return 0;
}








