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
int up[200001][18];
int depth[200001];

void dfs(int cur = 1, int d = 1, int p = 0) {
	up[cur][0] = p;
	depth[cur] = d;
	for (auto edge : adj[cur]) 
		if (edge != p)
			dfs(edge, d+1, cur);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	rep(i,2,N+1) {
		int a; cin >> a;
		adj[i].PB(a);
		adj[a].PB(i);
	}
  
	dfs();

	rep(i,1,18)
		rep(j,1,N+1)
			up[j][i] = up[up[j][i-1]][i-1];


	rep(i,0,Q) {
		int a, b;
		cin >> a >> b;

		int jump = 0;
		
		if (depth[a] <= b) {
			cout << -1 << endl;
			continue;
		}

		while (b) {
			if (b & 1) 
				a = up[a][jump];
			b >>= 1;
			jump++;
		}
		cout << a << endl;
	}

    return 0;
}








