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

int N;
vi adj[100001];
int far[100001];

int ans = 0;

void dfs(int cur = 1, int d = 1, int p = -1) {

	int children = adj[cur].size()-1;
	if (p == -1) 
		children++;

	if (children)
		ans += children + 32 - __builtin_clz(children);
	
	for (auto &edge : adj[cur]) {
		if (edge != p) {
			dfs(edge, d+1, cur);
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,2,N) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs();
	
	cout << ans << endl;

    return 0;
}








