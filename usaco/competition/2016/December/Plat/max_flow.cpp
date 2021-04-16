#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

int N, K;
vi adj[50001];
int up[50001][18];
int add[50001];
int sub[50001];
int depth[50001];
int score[50001];

int ans = 0;

vi leaves[50001];;

void dfs(int cur, int d = 1, int p = 0) {
    up[cur][0] = p;
    depth[cur] = d;
    
    leaves[d].PB(cur);
            
    for (auto &edge : adj[cur])
        if (edge != p)
            dfs(edge, d+1, cur);
}

int lca(int a, int b) {
    if (a == b) return a;
    if (depth[a] < depth[b]) swap(a,b);
    
    int dif = depth[a] - depth[b];
    int jump = 0;
        
    while (dif) {
        if (dif & 1) a = up[a][jump];
        jump++;
        dif >>= 1;
    }
    
    if (a == b) return a;
    
    int p = 17;
    while (a != b && p--) {
        if (depth[a] > (1 << p) && up[a][p] != up[b][p]) {
            a = up[a][p];
            b = up[b][p];
        }
    }
    return up[a][0];    
}

int main() {
    setIO("maxflow");
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    rep(i,0,N-1) {
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    dfs(1);
    
    for (int i = 1; i < 17; i++) 
        for (int j = 1; j <= N; j++) 
            up[j][i] = up[up[j][i-1]][i-1];
    
    rep(i,0,K) {
        int a, b;
        cin >> a >> b;
                
        if (depth[a] > depth[b]) swap(a, b);
        
        if (depth[a] > depth[lca(a,b)]) {
            add[a]++, add[b]++;
            add[lca(a,b)]--;
            add[up[lca(a,b)][0]]--;
        } else {
            assert(a == lca(a,b));
            add[up[a][0]]--;
            add[b]++;
        }
    }
    
    for (int i = N; i > 0; i--) {
        for (auto &cur : leaves[i]) {
            ans = max(ans, score[cur] + add[cur]);
            score[up[cur][0]] += score[cur] + add[cur];
        }    
    }

    cout << ans << endl;

    return 0;
}