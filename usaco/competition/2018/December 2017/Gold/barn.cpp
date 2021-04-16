#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

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

int N, K, mod = 1e9 + 7;

int colors[100001];

vi adj[100001];

ll dp[100001][4]; //num ways to color a subtree given the roots color
int v[100001][4];
int depth[100001];

void dfs(int cur, int d) {
	depth[cur] = d;
	for (auto x : adj[cur]) if (!depth[x]) dfs(x, d+1);
}

ll search(int cur, int color) {
	if (colors[cur] && colors[cur] != color) return dp[cur][color] = 0;
	if (adj[cur].size() == 1 && cur != 1) return dp[cur][color] = 1;
	if (dp[cur][color] >= 0) return dp[cur][color];
	
	dp[cur][color] = 1;
	
	for (auto next : adj[cur]) {
		if (depth[next] <= depth[cur]) continue;
		ll ways = 0;
		for (int i = 1; i <= 3; i++) {
			
			if (colors[next] == color) return dp[cur][color] = 0;
			
			if (i != color) {
				ways += search(next, i);
				ways %= mod;
			}
		}
		dp[cur][color] *= ways;
		dp[cur][color] %= mod;
	}
	
	return dp[cur][color];
}

int main() {
	setIO("barnpainting");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
    
	rep(i,0,100001) rep(j,0,4) dp[i][j] = -1;

	int a, b;
	rep(_,0,N-1) {
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	
	rep(_,0,K) {
		cin >> a >> b;
		colors[a] = b;
	}
	
	dfs(1,1);
	
	ll ans = (search(1,1) + search(1,2) + search(1,3));
	cout << ans % mod << endl;
    return 0;
}








