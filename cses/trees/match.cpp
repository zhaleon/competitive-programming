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

int N, A, B;
vi adj[200001];

int dp[200001][2];

void dfs(int cur, int p = -1) {
	
	for (auto &edge : adj[cur]) { 
		if (edge != p) {
			dfs(edge, cur);
			//dp[i][0] = vertex i is unmatched
			dp[cur][0] += max(dp[edge][0], dp[edge][1]); 
		}
	}
	
	dp[cur][1] = dp[cur][0];

	int cost = dp[cur][1];
	for (auto &edge : adj[cur]) 
		if (edge != p)
			dp[cur][1] = max(dp[cur][1], cost - dp[edge][1] + dp[edge][0] + 1); 
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

	dfs(1);

	cout << max(dp[1][1], dp[1][0]) << endl;
    
    return 0;
}








