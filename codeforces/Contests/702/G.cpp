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

int T, N, M;
ll arr[200001];
ll x[200001];
ll ans[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while(T--) {
		cin >> N >> M;
		rep(i,1,N) cin >> arr[i];
		rep(i,1,M) cin >> x[i];
		rep(i,1,M) ans[i] = 0;

		map<ll, ll> jumps;
		ll max_jump = 0;
		ll sum = 0;

		rep(i,1,N) {
			sum += arr[i];
			if (sum > max_jump) {
				max_jump = sum;
				jumps.insert({sum, i-1});
			}
		}

		rep(i,1,M) {
			ll ans = 0;
			ll cycles = 0;			

			if (sum > 0) {
				cycles = max(0ll, (x[i] - max_jump + sum - 1) / sum);
				ans += cycles * N;
			}

			ll rem = x[i] - cycles * sum;	
	
			auto it = jumps.lower_bound(rem);
			
			if (it == jumps.end()) { 
				ans = -1;
			} else {
				ans += it->S;
			}

			cout << ans << ' ';
		}
		
		cout << '\n';
	}
    
    return 0;
}
