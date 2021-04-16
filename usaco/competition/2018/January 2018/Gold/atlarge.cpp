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

int N, K;
vi adj[100001];
int v[100001];
int depth[100001];

vi leaves;

void dfs(int cur, int d) {
	v[cur] = 1;
	depth[cur] = d;
	for (auto edge : adj[cur]) {
		if (!v[edge]) {
			dfs(edge, d+1);
		}
	}
	if (cur != K && adj[cur].size() == 1) leaves.PB(cur);
}

int main() {
	setIO("atlarge");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	int a,b;
	
	rep(_,0,N-1) {
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(K, 0);

	memset(v, 0, sizeof(v));
	queue<pii> bfs;
	
	for (auto leaf : leaves) {
		bfs.push(MP(leaf, depth[leaf]));
	}
	
	int ans = leaves.size();
	
	while (!bfs.empty()) { //walk up tree and if you see a node reachable from leaf before root decrement
		pii cur = bfs.front(); bfs.pop();
		if (cur.F == K) continue;
		if (v[cur.F]) {
			if (v[cur.F] == 2) {
				ans--;
				continue;
			}
			
		}
		v[cur.F] = (depth[cur.F]*2 >= cur.S) ? 2 : 1;
		
		for (auto edge : adj[cur.F]) {
			if (depth[edge] < depth[cur.F]) {
				bfs.push(MP(edge, cur.S));
			}
		}
	}
	
	cout << ans << endl;

    return 0;
}