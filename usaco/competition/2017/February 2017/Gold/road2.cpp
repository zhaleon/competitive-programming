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

int a[1000];
int b[1000];

int dp[1000][1000];

int main() {
	setIO("nocross");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,0,N) cin >> a[i];
	rep(i,0,N) cin >> b[i];
	
	rep(i,0,N) {
		dp[0][i] = max(dp[0][i], (int)(abs(b[i]-a[0]) <= 4));
		dp[i][0] = max(dp[i][0], (int)(abs(a[i]-b[0]) <= 4));
	}
	
	rep(i,1,N) {
		rep(j,1,N) {
			dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (abs(a[i]-b[j])<=4));
		}
	}
	
	cout << dp[N-1][N-1] << endl;

    return 0;
}