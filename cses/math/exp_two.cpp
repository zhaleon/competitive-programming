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

int N, mod = 1e9+7;

ll exp(ll base, int p, int mod) {
	ll res = 1;
	while (p) {
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

	cin >> N;

	rep(i,0,N) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << exp(a, exp(b,c,mod-1), mod) << endl;
	}
    
    return 0;
}








