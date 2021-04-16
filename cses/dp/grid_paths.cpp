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
#define loop(i,a,b) for (int i = a; i < b; i++)

int n;
int dp[1000][1000];
char grid[1000][1000];
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	
	loop(i,0,n) {
		loop(j,0,n) {
			cin >> grid[i][j];
		}
	}
	if (grid[0][0] == '*') {
		cout << 0 << endl;
		return 0;
	}

	dp[0][0] = 1;
	loop(i,0,n) {
		loop(j,0,n) {
			if (i== 0 && j==0) continue;
			if (grid[i][j] == '*') continue;
			if (i == 0) {
				dp[i][j] = dp[i][j-1];
			} else if (j == 0) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
			dp[i][j] %= mod;
		}
	}

	cout << dp[n-1][n-1] << '\n';
    
    return 0;
}








