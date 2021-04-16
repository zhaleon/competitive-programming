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
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int N;

int par[800001];
int sz[800001];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a,b);

    sz[a] += sz[b];
    par[b] = a;
    return true;
}

typedef struct edge {
    int a, b, w, id;
    edge(int a, int b, int w) : a(a), b(b), w(w) {};
    edge(int a, int b, int w, int id) : a(a), b(b), w(w), id(id) {};
    bool operator<(const edge &o) const {
        return w < o.w; 
    }
}edge ;

vector<edge> edge_list;

bool used[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    iota(par+1, par+1+4*N, 1);
    fill(sz+1, sz+1+N, 1);
    
    int nodes = 0;

    rep(i,1,N) {
        vi verts;
        int w, a;
        cin >> w;
        rep(j,1,4) {
            ++nodes;
            cin >> a;
            verts.PB(a);
        }

        edge_list.emplace_back(verts[0], verts[1], 0, i);
        edge_list.emplace_back(verts[2], verts[3], 0, i);
        edge_list.emplace_back(verts[0], verts[2], w, i);
        edge_list.emplace_back(verts[0], verts[3], w, i);
        edge_list.emplace_back(verts[1], verts[2], w, i);
        edge_list.emplace_back(verts[1], verts[3], w, i);
    }

    sort(edge_list.begin(), edge_list.end());
    
    int ans = 0;
    int cc = 4*N;

    for (auto e : edge_list) {
        if (merge(e.a, e.b)) {
            ans += e.w;
            --cc;
        }
        
        if (!cc) break;
    }

    cout << ans << endl;

    return 0;
}








