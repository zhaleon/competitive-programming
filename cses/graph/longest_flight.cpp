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
#define rep(i,a,b) for (int i = a; i <= b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, M;
vi adj[100001];
vi radj[100001];
int v[100001];
vi toposort;

bool cyclic = 0;
int dist[100001];
int p[100001];

bool ok[100001];

void topo(int cur) {
	v[cur] = 1;
	
	for (auto &edge : adj[cur])  
		if (!v[edge])
			topo(edge);
		else if (v[edge] == 1) 
			cyclic = 1;
	
	v[cur] = 2;
	toposort.PB(cur);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		radj[b].PB(a);
	}

	rep(i,1,N) 
		if (v[i] == 0)
			topo(i);

	reverse(toposort.begin(), toposort.end());


	/* for (auto v : toposort) cout << v << ' '; */

	for (auto &v : toposort) {
		if (v == 1)
			ok[v] = 1, p[v] = 0, dist[v] = 1;
		else if (radj[v].empty() && 0)
			dist[v] = 1, p[v] = 0;
		else 
			for (auto &edge : radj[v])
				if (dist[edge] + 1 > dist[v] && ok[edge])
					dist[v] = dist[edge] + 1, p[v] = edge, ok[v] = 1;
	}

	if (cyclic || !dist[N]) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	int cur = N;
	vi route;

	while (cur != 0) {
		route.PB(cur);
		cur = p[cur];
	}

	reverse(route.begin(), route.end());

	cout << route.size() << endl;
	for (auto v : route) cout << v << ' ';
    return 0;
}








