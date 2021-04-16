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

ll N;

ll mod = 108905103361ll;

ll cows[50000][5];

ll base = 44927503ll;

ll coeff[6];

ll exp(ll base, int p) {
	ll res = 1;
	rep(i,0,p) {
		res *= base;
		res %= mod;
	}
	return res;
}

ll get_hash(ll a, ll b, ll c, ll d, ll e) { //garbage hash function
	ll A = coeff[1]*a % mod;
	ll B = coeff[2]*b % mod;
	ll C = coeff[3]*c % mod;
	ll D = coeff[4]*d % mod;
	ll E = coeff[5]*e % mod;
	return (A + B + C + D + E) % mod;
}

ll primes[6] = {0, 472393ll, 193939ll, 283501ll, 773147ll, 773473ll};

unordered_map<ll, ll> m;

vector<ll> ways[6];

int main() {
	setIO("cowpatibility");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	if (N < 25000) base = 51157ll;
	m.reserve(310001);
	
	rep(i,1,6) coeff[i] = exp(base, i+2);

	rep(i,1,6) assert(coeff[i] > 0);
	rep(i,0,N) {
		rep(j,0,5) cin >> cows[i][j];
		sort(cows[i], cows[i]+5);

		rep(j,1,32) {
			vector<ll> q;
			int size = 0;
			rep(k,0,5) if ((1 << k) & j) {
				q.PB(cows[i][k]);
				size++;
			}

			rep(k,size,6) q.PB(primes[k]);

			ll val = get_hash(q[0], q[1], q[2], q[3], q[4]);
			
			m[val]++;
			if (m[val] == 1) ways[size].PB(val);
		}

	}
	
	ll ans = N*(N-1)/2;;
	ll sign = 1;
	ll test[6];
	rep(i,1,6) { 
		ll cur = 0;
		rep(j,0,ways[i].size()) {
			ll amt = m[ways[i][j]];
			cur += amt*(amt-1)/2;
			ans -= sign*(amt*(amt-1)/2);
		}
		test[i] = cur;
		sign *= -1;
	}

	cout << ans << endl;
    return 0;
}