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

int N, M;

vi adj[100001];
pii location[100001];

int vis[100001];

int l = INF, r = 0, u = 0, d = INF;

int ans = INF;

void flood(int cow) {
	vis[cow] = 1;
	pii pos = location[cow];
	l = min(l , pos.F);
	r = max(r, pos.F);
	u = max(u, pos.S);
	d = min(d, pos.S);

	rep(i,0,adj[cow].size()) {
		if (!vis[adj[cow][i]]) {
			flood(adj[cow][i]);
		} 
	}
}

int main() {
	setIO("fenceplan");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;

	int a, b;
	rep(i,1,N+1) {
		cin >> a >> b;
		location[i] = MP(a,b);
	}
    
	rep(i,0,M) {
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	int n = 1;
	rep(i,1,N+1) {
		if (!vis[i]) {
			flood(i);
			//cout << r-l << ' ' << u-d << endl;
			ans = min(ans, 2*(r-l + u-d));
			l = INF; r = 0; u = 0; d = INF;
		}
	}
	cout << ans << endl;
    return 0;
}








