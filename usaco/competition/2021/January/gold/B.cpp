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

int N, K;
int  id[500001];
vi adj[51];
vi adj2[51];

ll dist[500001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	memset(dist, 63, sizeof(dist));

	cin >> N >> K;
	rep(i,1,N) cin >> id[i];

	rep(i,1,K) {
		string S;
		cin >> S;
		rep(j,0,K-1) if (S[j] == '1') adj[i].PB(j+1);
	}


	for (int i = 1; i <= N; i++) {
		adj2[id[i]].PB(i);
	}

	/* cout << adj[1][0] << ' ' << adj[1][1] << ' ' << adj2[3][0] << ' ' << adj2[4][0] << ' ' << adj2[4][1] << endl; */
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.emplace(0, 1);

	dist[1] = 0;

	while (pq.size()) {
		pair<ll, ll> cur = pq.top(); pq.pop();

		if (dist[cur.S] < cur.F) continue;

		if (cur.S == N) {
			cout << cur.F << endl;
			return 0;
		}

		for (auto nxt : adj[id[cur.S]]) {
			/* cout << "DEBUG: " << cur.S << ' ' << nxt << endl; */
			for (auto edge : adj2[nxt]) { 
				if (edge == cur.S) continue;

				if (dist[edge] > dist[cur.S] + abs(cur.S - edge)) {
					dist[edge] = dist[cur.S] + abs(cur.S - edge);
					pq.emplace(dist[edge], edge);
				}
			}
		}
	}

	if (dist[N] < 1e18) cout << dist[N] << endl;
	else cout << -1 << endl;

	/* rep(i,1,N) cout << dist[i] << ' '; */

    return 0;
}








