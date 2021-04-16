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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	ll N;
	cin >> N;

	ll ans = 0;
	ll mod = 1e9+7;

	ll inv = 5e8+4;

	for (ll i = 1; i * i <= N; i++) { 
		ans += N/i * i;
		ans %= mod;
	}

	ll x = 1 + sqrt(N);
	for (ll i = 1; i * i < N; i++) {
		// floor(N/x) = i -->  i <= N/x < i+1
		// x <= N/i, x > N/(i+1) 
		ll L = (N)/(i+1)+1;
		L = max(x, L);
		ll R = N/i;
		
		if (R < x || R < L) break;
		
		//ans += i * ((R+L) * (R-L+1) / 2 % mod) % mod;
		
		ll a = (R+L) % mod;
		ll b = (R+1-L) % mod;
		ans += i * a % mod * b % mod * inv % mod;
		ans %= mod;
	}
   	
	cout << ans << endl;

    return 0;
}








