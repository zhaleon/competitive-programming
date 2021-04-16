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

int N, Q;

ll arr[5001];

ll freq[2000001];

ll dp[5001][5001]; // dp[i][j] = answer for range [i,j]

int main() {
	setIO("threesum");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	
	rep(i,1,N+1) cin >> arr[i];
	for (int len = 3; len <= N; len++) {
		for (int i = 2; i <= len-1; i++) freq[1000000+arr[i]]++;
		for (int i = 1; i+len-1 <= N; i++) {
			ll cur = arr[i] + arr[i+len-1];
			int j = i+len-1;
			if (cur > 1000000 || cur < -1000000) dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + freq[1000000-cur];
			if (i + len - 1 < N) {
				freq[1000000+arr[i+1]]--;
				freq[1000000+arr[i+len-1]]++;
			}
		}
		for (int i = N-len+2; i <= N-1; i++) freq[1000000+arr[i]]--;
	}

	rep(_,0,Q) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << endl;
	}
    return 0;
}