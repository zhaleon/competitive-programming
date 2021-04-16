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
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int T;
ll x;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	set<ll> cubes;
	for (ll i = 1; i <= 10000ll; ++i) cubes.insert(i*i*i);
	
	cin >> T;
	while (T--) {
		cin >> x;
		bool ok = 0;
		for (ll i = 1; i*i*i <= x; ++i) {
			ll r = x - i*i*i;
			ok = ok | cubes.count(r);
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}








