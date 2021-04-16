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

int N, Q;
vi adj[200001];

int depth[200001];
int up[200001][18];

void dfs(int cur = 1, int d = 1, int p = 1) {
	up[cur][0] = p;
	depth[cur] = d;
	
	for (auto &edge : adj[cur])
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

	cin >> N >> Q;
	
	rep(i,2,N+1) {
		int a; cin >> a;
		adj[a].PB(i);
		adj[i].PB(a);
	}

	dfs();

	rep(i,1,18) 
		rep(j,1,N+1)
			up[j][i] = up[up[j][i-1]][i-1];


	rep(i,0,Q) {
		int a, b;
		cin >> a >> b;
		cout << lca(a,b) << endl;
	}

    return 0;
}








