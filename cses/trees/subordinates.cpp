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

void dfs(int cur = 1, int p = -1) {
	sz[cur] = 1;
	for (auto &edge: adj[cur]) {
		if (edge != p) {
			dfs(edge, cur);
			sz[cur] += sz[edge];
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
    
	rep(i,2,N+1) {
		int a; cin >> a;
		adj[a].PB(i);
		adj[i].PB(a);
	}

	dfs();

	rep(i,1,N+1) cout << sz[i]-1 << ' ';

    return 0;
}








