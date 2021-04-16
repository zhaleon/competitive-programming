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
int arr[101];

int dp[101][101][101]; //dp[i][j][k] = cost for first i days, j breakouts, last breakout at k

//index i should be i-k, and index k should be 0 

//dp[i][j][k] = dp[i-1][j][k] + (i == i-k)
//when k < i    dp[i][j][k] = dp[i-1][j][k]
//when k = i 	dp[i][j][k] = min(dp[i-1][j-1][k]) across k

int main() {
	setIO("taming");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) cin >> arr[i];

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0; // 0 ways to do
	//dp[i][j][k] first i, j breakouts, last happens at k
	rep(i,1,N+1) {
		rep(j,1,i+1) {
			rep(k,0,i+1) {
				if (k < i) { //breakout happened before i'th and at least one breakout happened
					dp[i][j][k] = dp[i-1][j][k];	
				} else if (k == i && j) { //last breakout happened at i and more than one breakout has occurred
					rep(a,0,i) {
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][a]);
					}
				}
				if (arr[i] != i-k) dp[i][j][k]++; //change last entry
			}
		}
	}

	rep(i,1,N+1) {
		int ans = INF;
		rep(j,1,N+1) ans = min(ans, dp[N][i][j]);
		cout << ans << endl;
	}

    return 0;
}