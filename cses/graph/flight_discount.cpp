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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, M;
vpi adj[100001];
ll dist[100001][2];

struct state {
	ll dist, dest;
	bool coupon;

	state(ll a, ll b, bool c) : dist(a), dest(b), coupon(c){};

};

auto comp = [](state a, state b) {
	return a.dist > b.dist;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	memset(dist, 63, sizeof(dist));

	cin >> N >> M;
	rep(i,1,M) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b,w);
	}


	priority_queue<state, vector<state>, decltype(comp)> pq(comp);
	pq.push(state(0, 1, 1));

	while (pq.size()) {
		state cur = pq.top(); pq.pop();
		//if (dist[cur.dest][cur.coupon] < cur.dist) continue;
		dist[cur.dest][cur.coupon] = min(dist[cur.dest][cur.coupon], cur.dist);

		for (auto &edge : adj[cur.dest]) {
			if (cur.coupon) {
				if (dist[edge.F][0] > cur.dist + edge.S/2) {
					pq.push(state(cur.dist+edge.S/2, edge.F, 0));
					dist[edge.F][0] = cur.dist + edge.S/2;
				}
				if (dist[edge.F][1] > cur.dist + edge.S) {
					pq.push(state(cur.dist+edge.S, edge.F, 1));
					dist[edge.F][1] = cur.dist + edge.S;
				}
			} else {
				if (dist[edge.F][0] > cur.dist + edge.S) {
					pq.push(state(cur.dist+edge.S, edge.F, 0));
					dist[edge.F][0] = cur.dist + edge.S;
				}
			}
		}
	}
	
	cout << dist[N][0] << endl;
    return 0;
}








