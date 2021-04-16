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

string a, b;

int dp[5001][5001]; //cost to change i characters of a to match j characters of b

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	rep(i,0,a.length()+1) {
		rep(j,0,b.length()+1) {
			if (i) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
			if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			if (i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (int)(a[i-1] != b[j-1]));
		}
	}

	cout << dp[a.length()][b.length()] << endl;

    return 0;
}
