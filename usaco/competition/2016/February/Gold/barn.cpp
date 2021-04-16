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

ll r[101];
ll dp[101][8];
ll p[101];
ll p1[101];

int main() {
	setIO("cbarn2");
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
		
		//dp[i][j] cost to split suffix beginning at i into j intervals
		for (int k = 2; k <= K; k++) {
			for (int i = 1; i <= N; i++) {
				ll running = 0;
				for (int j = i+1; j <= N; j++) {
					dp[i][k] = min(dp[i][k], dp[j][k-1] + running);
					running += r[j]*(j-i);
				}
			}	
		}
		ans = min(ans, dp[1][K]);	
		rotate(r+1, r+2, r+1+N);
	}

	cout << ans << endl;

    return 0;
}








