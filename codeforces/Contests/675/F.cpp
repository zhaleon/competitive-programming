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

int N, Q, mod = 1e9+7;

ll arr[100001];

ll table[100001][18];

ll pref[100001];

ll expo(ll base, int p = mod-2) {
	if (base == 1) return 1;
	ll res = 1;
	while (p > 0) {
		if (p & 1) {
			res *= base;
			res %= mod;
		}
		base *= base;
		base %= mod;
		p >>= 1;
	}
	return res;
}

ll gcd(ll a , ll b) {
   if (b == 0) return a;
   return gcd(b,a % b);
}

ll query(int l, int r) {
	int p = 31 - __builtin_clz(r-l);
	return gcd(table[l][p], table[r-(1<<p)][p]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) cin >> arr[i];

	pref[0] = 1;
	rep(i,1,N+1) table[i][0] = arr[i];
	rep(i,1,N+1) pref[i] = arr[i]*pref[i-1]%mod;

	rep(i,1,18) {
		int k = 1 << i;
		for (int j = 1; j + k <= N+1; j++) {
			table[j][i] = gcd(table[j][i-1], table[j+k/2][i-1]);
		}
	}
	

	cin >> Q;

	ll last = 0;
	rep(i,0,Q) {
		ll a, b, x, y;
		cin >> a >> b;
		x = (last+a) % N + 1;
		y = (last+b) % N + 1;
		if (x > y) swap(x,y);

		if (x == y) {
			cout << arr[x] << endl;
			last = arr[x];
			continue;
		}
		cout << "TEST: " << x << ' ' << y << endl;
		ll prod = pref[y] * expo(pref[x-1]) % mod;
		prod *= expo(query(x,y+1));
		prod %= mod;
		cout << prod << endl;
		last = prod;
	}
    
	return 0;
}

