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

int N, M, T;

vpi adj[10001];

ll cost[10001];

bool v[10001][31];
ll dp[10001][31];
ll big = 1ll << 61;

typedef struct state {
	ll F, S, dist;
	state() {};
	state(ll a, ll b, ll c) : F(a), S(b), dist(c) {};
} state;

ll ans[10001];

auto comp = [](state a, state b) {return a.dist > b.dist;};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> T;
	
	rep(i,1,N+1) cin >> cost[i];
	
	rep(_,0,M) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].PB(MP(b,c));
		adj[b].PB(MP(a,c));
	}

	priority_queue<state, vector<state>, decltype(comp)> pq(comp);
	memset(dp, 0x3f, sizeof(dp));
	dp[1][T] = 0;
	pq.push(state(1,T,0));
	memset(ans, 0x3f, sizeof(ans));
	
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (v[cur.F][cur.S]) continue;
		
		ans[cur.F] = min(cur.dist, ans[cur.F]);
		v[cur.F][cur.S] = 1;
		//cerr << "vals " << cur.F << ' ' << cur.S << ' ' << dp[cur.F][cur.S] << endl;
		
		for (int k = 1; cur.S + k <= T; k++)
		if (cur.S + k <= T && !v[cur.F][cur.S+k]) { //&& dp[cur.F][cur.S] + cost[cur.F] < dp[cur.F][cur.S + 1]) {
			pq.push(state(cur.F, cur.S+k, cur.dist + cost[cur.F]));
		}
		
		for (auto edge : adj[cur.F]) {
			if (cur.S >= edge.S && !v[edge.F][edge.S-cur.S]) {// && dp[cur.F][cur.S] <= dp[edge.F][cur.S - edge.S]) {
				pq.push(state(edge.F, cur.S - edge.S, cur.dist));
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (ans[i] > big) cout << -1;
		else cout << ans[i];
		if (i < N) cout << ' ';
		else cout << endl;
	}
    return 0;
}