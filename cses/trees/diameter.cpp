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

int far, dist;

void dfs(int cur = 1, int d = 0, int p = -1) {
	if (d > dist)
		dist = d, far = cur;

	for (auto &edge : adj[cur]) 
		if (edge != p)
			dfs(edge, d+1, cur);
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

	dfs();
	
	dist = 0;

	dfs(far);

	cout << dist << endl;

    return 0;
}








