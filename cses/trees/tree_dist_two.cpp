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

int N;
vi adj[200001];
int sz[200001];

ll ans[200001];

void dfs_sz(int cur = 1, int d = 0, int p = -1) {
	sz[cur] = 1;
	ans[1] += d;

	for (auto &edge : adj[cur]) {
		if (edge != p) {
			dfs_sz(edge, d+1, cur);
			sz[cur] += sz[edge];
		}
	}
}

void dfs(int cur = 1, int p = -1) {
	for (auto &edge : adj[cur]) 
		if (edge != p) {
			ans[edge] = ans[cur] - 2 * sz[edge] + N;
			dfs(edge, cur);
		}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	
	dfs_sz();
	dfs();

	rep(i,1,N+1) cout << ans[i] << ' ';

    return 0;
}








