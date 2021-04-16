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

int N, M, K;

string s;

int a[27][27];
int fw[27][27];

int p[100001][27];
int dp[100001][27];
int best[100001];

int t[100001][27];

int main() {
	setIO("cowmbat");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
    cin >> s;

	rep(i,1,M+1) {
		rep(j,1,M+1) {
			cin >> a[i][j];
			if (a[i][j] > 0) fw[i][j] = a[i][j];
			else fw[i][j] = 0;
		}
	}
	
	assert(K < N);

	rep(i,1,M+1) rep(j,1,M+1) rep(k,1,M+1) fw[j][k] = min(fw[j][k], fw[j][i] + fw[i][k]);

	//dp[i][j] = cost to make first i be valid and end with letter j
	
	rep(i,1,N+1) {
		rep(j,1,M+1) {
			t[i][j] = fw[s[i-1]-'a'+1][j];
			p[i][j] += p[i-1][j] + t[i][j];
		}
	}
	
	memset(dp, 0x3f, sizeof(dp));
	memset(best, 0x3f, sizeof(best));

	best[0] = 0;
	
	rep(i,1,N+1) {
		rep(j,1,M+1) {
			dp[i][j] = min(dp[i-1][j] + t[i][j], dp[i][j]);
			if (i >= K) dp[i][j] = min(dp[i][j],  best[i-K] + p[i][j] - p[i-K][j]);
			best[i] = min(best[i], dp[i][j]);
		}
		//cout << i << ' ' << best[i] << endl;
	}	
	cout << best[N] << endl;
    return 0;
}








