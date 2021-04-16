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
ll N, mod = 1e9+7;
ll trans[6][6];
ll res[6][6];

template<size_t N> void mult(ll (&a)[N][N], ll (&b)[N][N]) {
	ll temp[N][N] = {0};

	rep(i,0,N)
		rep(j,0,N)
			rep(k,0,N)
				(temp[i][j] += a[i][k]*b[k][j] % mod) %= mod;
	
	rep(i,0,N)
		rep(j,0,N)
			a[i][j] = temp[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,0,6) res[i][i] = trans[i][5] = 1;
    rep(i,1,6) trans[i][i-1] = 1;

	while (N > 0) {
		if (N & 1)
			mult<6>(res, trans);
		mult<6>(trans, trans);
		N >>= 1;
	}

	cout << res[5][5] << endl;

	return 0;
}
