#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

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

int a, b;

int dp[501][501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;

	memset(dp, 0x3f, sizeof(dp));

	rep(i,0,501) dp[i][0] = dp[0][i] = 0;

	rep(i,1,a+1) {
		rep(j,1,b+1) {
			if (i == j) dp[i][j] = 0;
			else {
				rep(k,1,j+1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
				rep(k,1,i+1) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
			}	
		}
	}
    
	cout << dp[a][b] << endl;

    return 0;
}








