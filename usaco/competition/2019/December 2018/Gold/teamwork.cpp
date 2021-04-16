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
int skill[10001];

int dp[10001][1001]; // dp[i][j] = best score with [first i][last group has j in it]
int best[10001];

int small[10001][15]; //but not small because max query

int query(int l, int r) {
	int p = (int)log2(r-l);
	return max(small[l][p], small[r-(1<<p)][p]);
}

int main() {
	setIO("teamwork");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	rep(i,1,N+1) cin >> skill[i];
	
	rep(i,1,N+1) small[i][0] = skill[i];

	rep(i,1,15) {
		int cur = 1 << (i-1);
		for (int j = 1; j + cur < N+1; j++) {
			small[j][i] = max(small[j][i-1], small[j+cur][i-1]);
		}
	}
	
	rep(i,1,N+1) {
		rep(j,1,K+1) {
			if (i >= j) {
				dp[i][j] = max(dp[i][j], best[i-j] + j*query(i-j+1, i+1));
				best[i] = max(best[i], dp[i][j]);
			}
		}
	}	
	
	cout << best[N] << endl;

    return 0;
}