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

ll N, M;
ll mod = 1e9+7;

ll arr[100001];

ll pref[100001];

int sum[100001];

ll inv(ll base, ll power) {
	ll res = 1;
	while (power) {
		if (power & 1) {
			res *= base;
			res %= mod;
		}
		base *= base;
		base %= mod;
		power >>= 1;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,1,N+1) {
		cin >> arr[i];
		if (i > 2) sum[i] = sum[i-2];
		if (!arr[i]) {
			arr[i] = 1;
			sum[i]++;
		}
	}
	
	
	pref[1] = arr[1];
	pref[2] = arr[2];
	pref[0] = 1;
	for (int i = 3; i <= N; i += 2) pref[i] = pref[i-2] * arr[i] % mod;
	for (int i = 4; i <= N; i += 2) pref[i] = pref[i-2] * arr[i] % mod;

	cin >> M;
	
	ll a, b;
	rep(i,0,M) {
		cin >> a >> b;
		ll ans;
		if (a % 2 == b % 2) {
			if (a == 1 && sum[b] > 0) {
				cout << 0 << endl;
				continue;
			} 
			if (a > 2) {
				if (sum[b] > sum[a-2]) {
					cout << 0 << endl;
					continue;
				} 
			} else if (sum[b] > 0){
				cout << 0 << endl;
				continue;
			}
		} else {
			if (a == 1 && sum[b-1] > 0) {
				cout << 0 << endl;
				continue;
			}
			if (sum[b-1] > sum[a-1]) {
				cout << 0 << endl;
				continue;
			}
		}
		
		if (a == 1) {
			if (b % 2) cout << pref[b] << endl;
			else cout << pref[b-1] << endl;
			continue;	
		} 
		if (a == 2) {
			if (b % 2) cout << pref[b] << endl;
			else cout << (pref[b-1] * inv(pref[a-1], mod-2) % mod) << endl;
			continue;
		}
		if (a % 2 == b % 2) {
			ans = pref[b] * inv(pref[a-2], mod-2) % mod;
		} else {
			ans = pref[b-1] * inv(pref[a-1], mod-2) % mod;
		}
		cout << ans << endl;
	}

    return 0;
}