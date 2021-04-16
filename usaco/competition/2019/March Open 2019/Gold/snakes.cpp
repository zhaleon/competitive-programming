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

int snakes[401];
int dp[401][401]; //cost for first i and j switches

int pref[401];

int main() {
	setIO("snakes");
    //ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	rep(i,1,N+1) {
		cin >> snakes[i];
		pref[i] = pref[i-1] + snakes[i];
	}
	
	memset(dp, 0x3f, sizeof(dp));
	
	int big = snakes[1];
	dp[1][0] = 0;
	rep(i,2,N+1) {
		big = max(big, snakes[i]);
		dp[i][0] = big*i - pref[i];
	}
	
	rep(i,0,K+1) dp[i][i] = 0;
	
	rep(j,1,K+1) {
		rep(i,1,N+1) {
			int largest = snakes[i];
			for (int k = i; k > 0; k--) {
				dp[i][j] = min(dp[i][j], dp[k][j-1] + largest*(i-k) - (pref[i]-pref[k]));
				largest = max(largest, snakes[k]);
			}	
			//printf("dp[%i][%i] = %i\n", i, j, dp[i][j]);
		}	
	}
	cout << dp[N][K] << endl;
    return 0;
}