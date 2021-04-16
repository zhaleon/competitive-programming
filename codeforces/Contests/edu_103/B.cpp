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

ll T, N, K;
ll p[101];

bool works(ll cur, ll v) {
	bool ok = 1;
	rep(i,2,N) {
		if ((cur + v)*K < 100 * p[i]) ok = 0;
		cur += p[i];
	}
	return ok;
}

ll search(ll cur) {
	ll low = 0, high = 1e14;

	while (low < high) {
		ll mid = (low+high)/2;

		bool ok = works(cur, mid);

		if (ok) high = mid; 
		else low = mid+1;
	}

	return low;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		rep(i,1,N) cin >> p[i];

		ll ans = 0;
		ans = search(p[1]);

		cout << ans << endl;
	}
    
    return 0;
}








