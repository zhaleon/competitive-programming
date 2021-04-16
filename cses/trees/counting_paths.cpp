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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, M;
vi adj[200001];

int up[200001][18];
int depth[200001];
int ans[200001];
int upd[200001];
vi nodes[200001];

void dfs(int cur = 1, int d = 1, int p = 0) {
	up[cur][0] = p;
	depth[cur] = d;
	nodes[d].PB(cur);
	for (auto& edge : adj[cur])
		if (edge != p)
			dfs(edge, d+1, cur);
}

int lca(int a, int b) {
	if (a == b) return a;
	if (depth[a] < depth[b]) swap(a, b);
	
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
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,1,N) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
   
	dfs();

	rep(i,1,18)
		rep(j,1,N+1)
			up[j][i] = up[up[j][i-1]][i-1];

	rep(i,0,M) {
		int a, b;
		cin >> a >> b;

		if (depth[a] > depth[b]) swap(a,b);
		int high = lca(a,b);
		upd[a]++, upd[b]++;
		upd[up[high][0]]--;
		upd[high]--;
	}

	for (int i = N; i > 0; i--) {
		for (auto v : nodes[i]) {
			ans[v] += upd[v];
			ans[up[v][0]] += ans[v];
		}
	}

	rep(i,1,N+1) cout << ans[i] << ' ';
    
	return 0;
}








