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

ll N;
int mod = 1e9+7;

ll trans[2][2] = {{0,1}, {1,1}};
ll i[2][2] = {{1,0}, {0, 1}};

template<size_t r, size_t c> void mult(ll (&a)[r][c], ll (&b)[r][c]) {
	ll temp[r][r]; 
	memset(temp, 0, sizeof(temp));

	rep(m,0,r)
		rep(j,0,r)
			rep(k,0,r)
				(temp[m][j] += a[m][k]*b[k][j] % mod) %= mod;

	rep(m,0,r)
		rep(j,0,c)
			a[m][j] = temp[m][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	while (N > 0) {
		if (N & 1)
			mult<2, 2>(i, trans);

		mult<2, 2>(trans, trans);
		N >>= 1;
	}

	cout << i[0][1] << endl;

    return 0;
}








