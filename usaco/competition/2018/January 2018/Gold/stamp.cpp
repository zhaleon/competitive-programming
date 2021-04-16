#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

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

ll N, M, K, mod = 1e9+7;

ll dp[1000001];
ll pref[1000001];

ll exp(ll a, ll p) {
	ll res = 1;
	while (p > 0) {
		if (1 & p) res *= a;
		a*=a;
		p >>= 1;
		res %= mod;
		a %= mod;
	}
	return res % mod;
}

int main() {
	setIO("spainting");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

//	for (int i = 1; i < K; i++) {
//		dp[i] = exp(M,i);
//	}
//	
//	rep(i,K,N+1) {
//		rep(j,1,K) {
//			dp[i] += dp[i-j]*(M-1);
//			dp[i] %= mod;
//		}
//	}
	
	for (int i = 1; i < K; i++) pref[i] = (pref[i-1] + exp(M,i)) % mod;
	
	rep(i,K,N+1) {
		pref[i] = ((M*pref[i-1])%mod - ((M-1)*pref[i-K])%mod + mod) % mod;
		assert(pref[i] > 0);
		pref[i] %= mod;
	}
	
	
	ll ans =  (exp(M, N) + mod + pref[N-1] - pref[N]) % mod;
	
	cout << ans << endl;
	
    return 0;
}