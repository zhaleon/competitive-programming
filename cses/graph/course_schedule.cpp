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
vi toposort;

int v[100001];

bool topo(int cur) {
	v[cur] = 1;
	bool res = 1;
	for (auto &edge : adj[cur]) {
		if (v[edge] == 0)
			res &= topo(edge);
		else if (v[edge] == 1)
			res = 0;
	}
	toposort.PB(cur);
	v[cur] = 2;
	return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
	}

	bool dag = 1;

	rep(i,1,N) {
		if (!v[i])
			dag &= topo(i);
	}

	reverse(toposort.begin(), toposort.end());
	
	if (dag)
		for (auto e : toposort) cout << e << ' ';
	else
		cout << "IMPOSSIBLE" << endl;

    return 0;
}








