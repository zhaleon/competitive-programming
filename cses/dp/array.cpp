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

ll arr[100001];

ll dp[100001][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,1,N+1) cin >> arr[i];

	if (!arr[1]) rep(i,1,M+1) dp[1][i] = 1;
	else dp[1][arr[1]] = 1;

	int mod = 1e9+7;

	rep(i,2,N+1) {
		rep(j,1,M+1) {
			if (!arr[i] || j == arr[i]) {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
			   	dp[i][j] %= mod;	
			}	
		}
	}

	ll ans = 0;

	rep(i,1,M+1) {
		ans += dp[N][i];
		ans %= mod;
	}

	cout << ans << endl;
    
    return 0;
}








