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

int T, N;
ll a[200001];
ll b[200001];
ll c[200001];
ll dp[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;

		rep(i,1,N) cin >> c[i];
		rep(i,1,N) cin >> a[i];
		rep(i,1,N) cin >> b[i];
		rep(i,1,N) dp[i] = 0;

		ll ans = 0;
		dp[1] = abs(a[2] - b[2]);

		rep(i,2,N) {
			dp[i] = max(min(a[i], b[i]) - 1 + c[i-1] - max(a[i],b[i]) + 2 + dp[i-1], 2 + abs(a[i]-b[i]));
			if (i == 2) dp[i] = dp[i-1] + 2;
			if (a[i] == b[i]) dp[i] = 2;

			ans = max(dp[i] + c[i] - 1, ans);
		}

		cout << ans << endl;
	}
    
    return 0;
}








