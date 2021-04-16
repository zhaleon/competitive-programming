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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

ll N, M, K, mod = 1e9+7;

ll res[100][100];
ll adj[100][100];

template<size_t S> void mult(ll (&a)[S][S], ll (&b)[S][S]) {
	int temp[S][S] = {0};

	rep(i,0,S)
		rep(j,0,S)
			rep(k,0,S) {
				temp[i][j] += a[i][k] * b[k][j] % mod; 
				if (temp[i][j] >= mod) temp[i][j] -= mod;
			}
	rep(i,0,S)
		rep(j,0,S)
			a[i][j] = temp[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
  
	rep(i,0,100) res[i][i] = 1;

	rep(i,0,M) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a][b]++;
	}

	while (K) {
		if (K & 1) 
			mult<100>(res, adj);
		mult<100>(adj, adj);
		K >>= 1;
	}

	cout << res[0][N-1] << endl; 

    return 0;
}








