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

ll inf = 1e18;
int N, M, Q;
ll dist[501][501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	memset(dist, 0x3f, sizeof(dist));

	cin >> N >> M >> Q;

	rep(i,1,M) {
		ll a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}

	rep(k,1,N)
		rep(i,1,N)
			rep(j,1,N)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  	rep(i,1,N)
		dist[i][i] = 0;

	rep(i,1,Q) {
		int a, b;
		cin >> a >> b;
		
		if (dist[a][b] > inf)
			cout << -1 << endl;
		else
			cout << dist[a][b] << endl;
	}
    return 0;
}








