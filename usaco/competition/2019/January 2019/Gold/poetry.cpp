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

int N, M, K;
ll mod = 1e9+7;

pair<ll, ll> words[5001];

ll dp[5001]; //count all ways

ll ways[5001]; //ways to end with a specific rhyme class

ll freq[5001]; //size of each rhyme set

ll exp(ll a, ll p) {
	a %= mod;
	ll res = 1;
	while (p > 0) {
		if (p & 1) {
			res *= a;
			res %= mod;
		}
		p >>= 1;
		a *= a;
		a %= mod;
	}
	return res;
}

int main() {
	setIO("poetry");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	rep(i,0,N) cin >> words[i].F >> words[i].S;
	
	rep(i,0,M) {
		char a;
		cin >> a;
		freq[(int)(a-'A')+1]++;
	}
	
	dp[0] = 1;
	rep(i,0,K) {
		rep(j,0,N) {
			if (i + words[j].F < K) {
				dp[i+words[j].F] += dp[i];
				dp[i+words[j].F] %= mod;
			} else if (i + words[j].F == K) {
				ways[words[j].S] += dp[i];
				dp[K] += dp[i];
				dp[K] %= mod;
			}
		}
	}

	ll ans = 1;
	
	rep(i,1,27) {
		if (freq[i] == 0) continue;
		ll cur = 0;
		rep(j,1,N+1) {
			assert(exp(ways[j], freq[i]) >= 0);
			cur += exp(ways[j], freq[i]);
			cur %= mod;
		}
		ans *= cur;
		ans %= mod;
	}
	
	cout << ans << endl;
    return 0;
}