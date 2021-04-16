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

const int MOD = 1e9+7;

int N;
pair<ll, ll> p[100001]; //array of points
vector<pair<ll, ll> > q[20001]; //queue for processing
vector<ll> sums[100001]; //sum of distance to points with same X and Y as point i 

void process() {
	rep(i,0,20001) {
		if (q[i].size()) {
			sort(q[i].begin(), q[i].end());
			ll curSum = 0;

			rep(j,1,q[i].size()) (curSum += q[i][j].F-q[i][0].F) %= MOD;
			sums[q[i][0].S].PB(curSum);
			
			rep(j,1,q[i].size()) {
				(curSum += (2*j-q[i].size())*(q[i][j].F-q[i][j-1].F)) %= MOD;
				sums[q[i][j].S].PB(curSum);	
			}
			q[i].clear();
		}
	}
}	

int main() {
	setIO("triangles");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	rep(i,0,N) cin >> p[i].F >> p[i].S;
	
	//process X coords
	rep(i,0,N) q[p[i].F+(int)1e4].PB(MP(p[i].S, i));
	process();

	//process Y coords
	rep(i,0,N) q[p[i].S+(int)1e4].PB(MP(p[i].F, i));
    process();
	
	ll ans = 0;
	rep(i,0,N) {
		(ans += sums[i][0]*sums[i][1]) %= MOD;
	}
	cout << ans << endl;

    return 0;
}








