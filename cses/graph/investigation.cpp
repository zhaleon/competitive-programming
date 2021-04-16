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

int N, M, mod = 1e9+7;

vpi adj[100001];
ll ways[100001];
ll dist[100001];
ll most[100001];
ll least[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b,c);	
	}
    
	memset(dist, 0x3f, sizeof(dist));

	ways[1] = 1; 

	priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0ll, 1});

	while (!pq.empty()) {
		auto temp = pq.top(); pq.pop();
		ll cur_dist = temp.F, cur = temp.S;

		for (auto &edge : adj[cur]) {
			if (cur_dist + edge.S < dist[edge.F]) {
				dist[edge.F] = cur_dist + edge.S;
				ways[edge.F] = ways[cur];
				most[edge.F] = most[cur]+1;
				least[edge.F] = least[cur]+1;
				pq.push({dist[edge.F], edge.F});
			} else if (cur_dist + edge.S == dist[edge.F]) {
				(ways[edge.F] += ways[cur]) %= mod;
				least[edge.F] = min(least[edge.F], least[cur]+1);
				most[edge.F] = max(most[edge.F], most[cur]+1);
			}
		}

	}

	cout << dist[N] << ' ' << ways[N] << ' ' << least[N] << ' ' << most[N] << endl;

    return 0;
}








