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

int dist[201][201];
int freq[201][201];

vpi adj[201];

int best[201];
bool v[201];
int up[201];

void dfs(int cur, int pr = 0, int p = -1) {
	if (pr)
		up[cur] = pr;

	v[cur] = 1;

	for (auto edge : adj[cur]) {
		if (!v[edge.F]) {
			if (!pr)
				dfs(edge.F, edge.F, cur);
			else
				dfs(edge.F, pr, cur);
		}
	}
	
}
void find(int cur) {
	memset(up, 0, 804);
	memset(v, 0, 201);
	memset(best, 0x3f, sizeof(best));

	best[cur] = 0, v[cur] = 1;

	int c = 1;

	while (c < N) {
		int idx = 0, d = 2*INF;
		for (int i = 1; i <= N; i++) 
			if (!v[i] && best[i] < d)
				d = best[i], idx = i;

		v[idx] = 1;
		for (auto &edge : adj[idx]) 
			best[edge.F] = min(best[edge.F], best[idx] + edge.S); 
	}	
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,0,M) {
		int a, b, w;
		adj[a].emplace_back(b,w);
		adj[b].emplace_back(a,w);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (dist[j][i] + dist[i][k] == dist[j][k]) freq[j][k]++;
				else {
					dist[j][k] = dist[j][i] + dist[i][k];
					freq[j][k] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		find(i);
		memset(v, 0, sizeof(v));
		dfs(i);

		

	}

	return 0;
}

