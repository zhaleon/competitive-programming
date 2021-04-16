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

int N, M;

ll mod = 1e9+7;
ll fact[2000001];

ll exp(ll base, ll p = 1e9+5) {
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	fact[0] = 1;
	rep(i,1,2000001) fact[i] = fact[i-1] * i % mod;
    
	cout << fact[N+M-1] * exp(fact[N-1]) % mod * exp(fact[M]) % mod << endl;

    return 0;
}








