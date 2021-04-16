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
int dp[249][249];
int nums[249];

int main() {
	setIO("248");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	rep(i,1,N+1) cin >> nums[i];
	
	rep(i,1,N+1) dp[i][i] = nums[i];
	
	int ans = 0;
	
	rep(i,1,N+1) ans = max(ans, nums[i]);
	
	for (int i = 1; i <= N-1; i++) {
		for (int j = 1; j <= N-i; j++) {
			//dp[i][j] = -1;
			for (int k = j; k < j+i; k++) {
				if (dp[j][k] == dp[k+1][j+i]) { 
					dp[j][j+i] = max(dp[j][j+i], dp[j][k] + 1);
				}
				ans = max(ans, dp[j][j+i]);
			}
		}	
	}
	
	cout << ans << endl;
	
    return 0;
}








