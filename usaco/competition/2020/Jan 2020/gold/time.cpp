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

ll N, M, C;

ll T = 1000;

vi adj[1001];

ll mooney[1001];

ll dp[1001][1001]; //place x at time i

int main() {
	setIO("time");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> C;

	rep(i,1,N+1) cin >> mooney[i];
	
	rep(_,0,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
	}
	
	dp[1][0] = 1;
	rep(t,0,T+1) {
		rep(j,1,N+1) {
			rep(k,0,adj[j].size()) {
				if (dp[j][t])
				dp[adj[j][k]][t+1] = max(dp[adj[j][k]][t+1], dp[j][t] + mooney[adj[j][k]]);
			}
		}
	}
	
	ll ans = 0;
	
	rep(t,0,T+1) ans = max(ans, dp[1][t]-C*t*t-1);
	cout << ans << endl;
    return 0;
}