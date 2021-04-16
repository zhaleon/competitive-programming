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

int H, G;

pair<ll, ll> h[1001];
pair<ll, ll> g[1001];

ll dp1[1002][1002]; //end on G cow
ll dp[1002][1002]; //end on H cow

//first i H, first j G finishing at i'th H or j'th G
//dp[i][j] = dp[i-1][j] + dist or dp1[i-1][j] + dist

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

ll min(ll a, ll b) {
	if (a < b) return a;
	return b;
}

int main() {
	setIO("checklist");
    ios::sync_with_stdio(0); cin.tie(0);


	cin >> H >> G;

	rep(i,1,H+1) cin >> h[i].F >> h[i].S;
	rep(i,1,G+1) cin >> g[i].F >> g[i].S;

	rep(i,0,H+1) rep(j,0,G+1) {
		dp[i][j] = dp1[i][j] = (ll)INF*INF;
	}
	
	dp[1][0] = 0;
	


	rep(i,0,H+1) {
		rep(j,0,G+1) {
			
			if (i > 0) { 
				// from holstein i -> holstein i+1 or guernsey j+1
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(h[i],h[i+1]));
				dp1[i][j+1] = min(dp1[i][j+1], dp[i][j] + dist(h[i], g[j+1]));
			}
			
			if (j > 0) {
				// go from guernsey j -> holstein i+1, or guernsey j+1;
				dp[i+1][j] = min(dp[i+1][j], dp1[i][j] + dist(h[i+1], g[j]));
				dp1[i][j+1] = min(dp1[i][j+1], dp1[i][j] + dist(g[j+1], g[j]));
			}

		}
	}
	cout << dp[H][G] << endl;

    return 0;
}








