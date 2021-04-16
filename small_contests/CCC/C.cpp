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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}
 
int N, M, mod = 1e9+7;
ll in[1001];
ll out[1001];
vpi adj[1001], edge_list;
ll dist[1001];
ll ans[2001];
map<pii, int> m;

void dfs(int cur, int p = -1) {
	in[cur] = out[cur] = 1;
	for (auto &edge : adj[cur]) {
		if (dist[cur] + edge.S == dist[edge.F] && edge.F != p) {
			edge_list.emplace_back(cur, edge.F);
			in[edge.F] += in[cur];
			dfs(edge.F, cur);
			out[cur] += out[edge.F];
		}
	}
}

void solve(int s) {
	memset(dist, 63, sizeof(dist));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	edge_list.clear();
	
	priority_queue<pii, vpi, greater<pii>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	
	while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (cur.F > dist[cur.S]) continue;	
		
		for (auto &edge : adj[cur.S]) {
			if (dist[edge.F] > cur.F + edge.S) {
				dist[edge.F] = cur.F + edge.S;
				pq.emplace(dist[edge.F], edge.F);
			} 
		}
	}

	dfs(s);
	
	for (auto &edge : edge_list) 
		(ans[m[{min(edge.F, edge.S), max(edge.F, edge.S)}]] += in[edge.F] * out[edge.S] % mod) %= mod;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 	setIO("roadhelp");

	cin >> N >> M;
	rep(i,1,M) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b,c);	
		adj[b].emplace_back(a,c);
		if (a > b) swap(a,b);
		m[{a,b}] = i;
	}
	
	rep(i,1,N) solve(i);

	rep(i,1,M) cout << ans[i] << '\n';

    return 0;
}

