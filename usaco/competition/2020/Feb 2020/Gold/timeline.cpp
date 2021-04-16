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

int N, M, C;

int c[100001];
int v[100001];
int s[100001];

vi topo;

vpi adj[100001];

void dfs(int cur) {
	v[cur] = 1;
	for (auto edge : adj[cur]) if (!v[edge.F]) dfs(edge.F);
	topo.PB(cur);
}

int main() {
	setIO("timeline");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> C;

	rep(i,1,N+1) cin >> c[i];
    
	int a, b, w;

	rep(_,0,C) {
		cin >> a >> b >> w;
		adj[a].PB(MP(b,w));
	}

	rep(i,1,N+1) {
		if (!v[i]) dfs(i);
	}	

	reverse(topo.begin(), topo.end());


	for(auto d : topo) {
		for (auto edge : adj[d]) {
			c[edge.F] = max(c[edge.F], c[d] + edge.S); 
		}
	}

	rep(i,1,N+1) cout << c[i] << '\n';

    return 0;
}








