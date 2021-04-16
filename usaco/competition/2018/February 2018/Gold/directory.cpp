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

int N;

vi adj[100001];

ll w[100001]; //node weights
ll dp[100001], dp2[100001]; //distance to files in subtree and those not in subtree
ll numFiles[100001];

int tot = 0; //total files
bool file[100001], v[100001];

ll filesInTree(int cur) {
	v[cur] = 1;
	if (cur != 1 && adj[cur].size() == 1) return numFiles[cur] = 1;
	for (auto edge : adj[cur]) if (!v[edge]) numFiles[cur] += filesInTree(edge);
	return numFiles[cur];
}

ll dfs(int cur) {
	ll res = 0;
	v[cur] = 1;
	
	if (cur != 1 && adj[cur].size() == 1) return dp[cur] = 0;
	
	for (auto edge : adj[cur]) if (!v[edge]) {
		res += dfs(edge) + w[edge]*numFiles[edge] + numFiles[edge];
		if (file[edge]) res--;
	}
	
	return dp[cur] = res;
}

void dfs2(int cur, int parent) { 
	ll res = 0;
	v[cur] = 1;
	
	if (cur != 1 && !file[cur]) dp2[cur] = dp2[parent] + 3*(tot-numFiles[cur]) + dp[parent] - (dp[cur] + w[cur]*numFiles[cur] + numFiles[cur]) ;
	
	for (auto edge : adj[cur]) if (!v[edge]) {
		dfs2(edge, cur);
	}
}

int main() {
	setIO("dirtraverse");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	string s;
	int m, a;
	
	rep(i,1,N+1) {
		cin >> s >> m;
		w[i] = s.length();
		if (m) {
			rep(_,0,m) {
				cin >> a;
				adj[i].PB(a);
				adj[a].PB(i);
			}
		} else {
			tot++;
			file[i] = 1;
		}
	}
	filesInTree(1);
	memset(v,0,sizeof(v));
	dfs(1);
	memset(v, 0, sizeof(v));
	dfs2(1, 1);

	ll ans = (1ll << 60);
	
	rep(i,1,N+1) {
		if (!file[i]) {
			ans = min (ans, dp[i] + dp2[i]);
		}
	}

	cout << ans << endl;
    return 0;
}