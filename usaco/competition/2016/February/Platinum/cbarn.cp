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

int N, K;

ll r[1001];
ll dp[1001][8];
ll p[1001];
ll p1[1001];

void search(int k, int l, int r, int a, int b) {
	if (l == r) return;
	
	int mid = (l + r)/2;
	int best = -1;
	
	
	
}

int main() {
	//setIO("cbarn");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
    
	rep(i,1,N+1) {
		cin >> r[i];
	}

	ll ans = 1e17;
	rep(_,0,N) {
		memset(dp, 0x3f, sizeof(dp));
		memset(p, 0, sizeof(p));
		memset(p1, 0, sizeof(p1));	
		
		rep(i,2,N+1) p[i] += p[i-1] +r[i];
		rep(i,1,N+1) p1[i] += p1[i-1] + r[i]*(i-1);
		rep(i,1,N+1) dp[i][1] = p1[N] - p1[i] - (p[N]-p[i])*(i-1);
		
		rep(k,2,N+1) search(k, 1, N, 1, N);
		
		ans = min(ans, dp[1][K]);	
		rotate(r+1, r+2, r+1+N);
	}

	cout << ans << endl;

    return 0;
}








