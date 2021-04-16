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

#define INF 4500000000000000000ll
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

ll N, M, T;

vector<pair<ll, ll>> adj[10001];

ll cows[10001];
ll farm[10001];
ll dist[10001];
bool v[10001];
int parent[10001];

auto comp = [](int a, int b) {
	if (dist[a] == dist[b]) return a > b;
	return dist[a] > dist[b];
};

int main() {
	setIO("shortcut");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> T;

	rep(i,1,N+1) {
		cin >> cows[i];
		farm[i] = cows[i];
	}
	rep(i,0,M) {
		ll a,b,c;
		cin >> a >> b >> c;
		adj[a].PB(MP(b,c));
		adj[b].PB(MP(a,c));
	}

	memset(dist, 0x3f, sizeof(dist));
	memset(parent, 0x3f, sizeof(parent));
	
	dist[1] = 0;
	parent[1] = 1;
	priority_queue<int, vi, decltype(comp)> pq(comp);
	pq.push(1);
	
	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		for (auto edge : adj[cur]) {
			if (dist[cur] + edge.S < dist[edge.F]) {
				dist[edge.F] = min(dist[edge.F], dist[cur] + edge.S);
				parent[edge.F] = cur;
				pq.push(edge.F);
			} else if (dist[cur] + edge.S == dist[edge.F]) {
				parent[edge.F] = min(parent[edge.F], cur);
			}
		}
	}
	
	ll ans = 0;
	
	vi q;
	rep(i,1,N+1) q.PB(i);
	sort(q.begin(), q.end(), comp);

	rep(i,0,q.size()) {
		int cur = q[i];
		ans = max(ans, (dist[cur]-T)*farm[cur]);
		farm[parent[cur]] += farm[cur]; //move cows to the parent
		farm[cur] = 0;
	}
	cout << ans << endl;
	for (int i = 1; i <= N; i++) {
		//cerr << i << ": " << dist[i] << endl;
	}
    return 0;
}