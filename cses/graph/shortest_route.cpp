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

ll dist[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	memset(dist, 0x3f, sizeof(dist));
   	
	cin >> N >> M;
	rep(i,1,M) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
	pq.push(MP(0,1));
	dist[1] = 0;
	
	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		if (cur.F > dist[cur.S]) continue;
		dist[cur.S] = cur.F;

		for (auto &edge : adj[cur.S]) {
			if (dist[edge.F] > cur.F + edge.S)
				pq.push(MP(cur.F+edge.S, edge.F));
		}
	}

	rep(i,1,N) cout << dist[i] << ' ';
    return 0;
}








