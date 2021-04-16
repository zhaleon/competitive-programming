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


ll N, W;
ll t[250];
ll w[250];

//int dp[251][1001];

int used[251];

ll dp[1001];

bool works(ll v) {
	rep(i,0,1001) dp[i] = INF*-1;
	
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		ll score = 1000*t[i] - v*w[i];
		for (ll j = W; j >= 0; j--) {
			if (dp[j] != INF*-1) {
				dp[min(W, j+w[i])] = max(dp[min(W, j+w[i])], dp[j] + score);
			}
		}
	}
	return dp[W] >= 0;
}

int main() {
	setIO("talent");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> W;

	rep(i,0,N) cin >> w[i] >> t[i];

	ll low = 1, high = 5e9; 
	while (low+1 < high) {
		ll mid = (low+high)/2;
		if (works(mid)) {
			low = mid;
		} else {
			high = mid;
		}
	}	

	cout << low << endl;

    return 0;
}








