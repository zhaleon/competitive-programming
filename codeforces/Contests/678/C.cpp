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

int N, x, pos, mod = 1e9+7;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> x >> pos;
   
	vpi index; //-1 means less

	int low = 0, high = N;

	while (low < high) {
		int mid = (low + high)/2;

		if (mid < pos) {
			index.emplace_back(mid, 1);
		   	low = mid+1;	
		} else {
			index.emplace_back(mid, -1);
			high = mid;	
		}
	}

	for (int i = 1; i <= N; i++) {
		if (index.size()) {
			if (index[0].S == 1) {
				if (i >= x) dp[1][i] = 1;
			} else {
				if (i <= x) dp[1][i] = 1;
			}
		}
	}

	int pref[1001];

	int cur = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) pref[j] = (pref[j-1] + dp[i-1][j]) % mod;

		for (int j = 1; j <= i; j++) {
			
		}
	}

    return 0;
}








