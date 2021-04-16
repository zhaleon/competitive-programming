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

string s;
map<char, int> m;

ll fact[1000001];
ll mod = 1e9+7;

ll exp(ll base, ll p = 1e9+5) {
	ll res = 1;
	while(p) {
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

	cin >> s;

	fact[0] = 1;
	rep(i,1,1000001) fact[i] = fact[i-1] * i % mod;

	rep(i,0,s.length()) 
		m[s[i]]++;

	ll res = fact[s.length()];
	for (auto &e : m) {
		res *= exp(fact[e.S]);
		res %= mod;
	}

	cout << res << endl;

    return 0;
}








