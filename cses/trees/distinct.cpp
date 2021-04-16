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
int c[200001];
vi adj[200001];

set<int> s[200001];
int ans[200001];

void dfs(int cur = 1, int p = -1) {
	s[cur].insert(c[cur]);
	for (auto &edge : adj[cur]) { 
		if (edge != p) {
			dfs(edge, cur);

			if (s[edge].size() > s[cur].size())
				s[cur].swap(s[edge]);	
			
			for (auto &e : s[edge])
				s[cur].insert(e);
		}
	}
	ans[cur] = s[cur].size();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) cin >> c[i];

	rep(i,1,N) {
		int a,b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs();

	rep(i,1,N+1) cout << ans[i] << ' ';
}


