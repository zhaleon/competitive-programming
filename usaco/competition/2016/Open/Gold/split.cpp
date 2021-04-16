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

int N;

pair<ll, ll> p[50000];

ll sMin[50000]; //suffix min max
ll sMax[50000];

ll pMin[50000];
ll pMax[50000];

ll solve() {
	sort(p, p+N);
	
	memset(pMin, 0x3f, sizeof(pMin));
	memset(pMax, 0, sizeof(pMax));
	memset(sMin, 0x3f, sizeof(sMin));
	memset(sMax, 0, sizeof(sMax));
	
	pMin[0] = pMax[0] = p[0].S;
	sMin[N-1] = sMax[N-1] = p[N-1].S;
		
	rep(i,1,N) {
		pMin[i] = min(p[i].S, pMin[i-1]);
		pMax[i] = max(p[i].S, pMax[i-1]);
		sMin[N-i-1] = min(p[N-i-1].S, sMin[N-i]);
		sMax[N-i-1] = max(p[N-i-1].S, sMax[N-i]);
	}

	ll total = (pMax[N-1]-pMin[N-1])*(p[N-1].F - p[0].F), area = total;
	
	rep(i,0,N-1) {
		ll cur = (pMax[i]-pMin[i])*(p[i].F-p[0].F) + (sMax[i+1]-sMin[i+1])*(p[N-1].F-p[i+1].F);
		area = min(area, cur);
	}
	return total-area;
}

int main() {
	setIO("split");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,0,N) cin >> p[i].F >> p[i].S;
	
	ll ans = 0;
	ans = max(ans, solve());
	rep(i,0,N) swap(p[i].F, p[i].S);
	ans = max(ans, solve());
	
	cout << ans << endl;
	
	
    return 0;
}








