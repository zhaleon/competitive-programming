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
#define rep(i,a,b) for (int i = a; i <= b; i++)

int N, K, Q, mod = 1e9+7;
ll arr[5001];
ll dp[5002][5001]; 
ll freq[5001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K >> Q;
	rep(i,1,N) cin >> arr[i];
	
	rep(i,1,N) dp[i][0] = 1;

	rep(j,1,5000) {
		rep(i,1,N) {
			if (i-1 == 0 || i+1 == N+1) assert(dp[0][j-1] == 0 and dp[N+1][j-1] == 0);
			dp[i][j] += (dp[i+1][j-1] + dp[i-1][j-1]) % mod;
			dp[i][j] %= mod;
		}
	}

	rep(j,0,K) {
		rep(i,1,N) {
			freq[i] += dp[i][j] * dp[i][K-j] % mod;
			freq[i] %= mod;
		}
	}

	ll sum = 0;
	rep(i,1,N) (sum += freq[i] * arr[i] % mod) %= mod;

	rep(i,1,Q) {
		ll a, b;
		cin >> a >> b;

		sum -= arr[a] * freq[a] % mod - mod;
		sum %= mod;

		arr[a] = b;

		sum += arr[a] * freq[a] % mod;
		sum %= mod;

		cout << sum << '\n';
	}

    return 0;
}








