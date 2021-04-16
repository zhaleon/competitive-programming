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
#define EB emplace_back
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int T, Q, D;
bool dp[130];

bool has_d(int s) {
	string x = to_string(s);
	for (auto c : x) {
		if (int(c-'0') == D) return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> Q >> D;

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		rep(i,1,129) {
			rep(j,0,i) {
				dp[i] |= dp[j] && has_d(i-j);		
			}
		}
		
		rep(i,1,Q) {
			int X; cin >> X;

			int m = X/D;
			int j = X % D;

			if (m >= 10 || dp[X])
				cout << "YES\n";
			else 
				cout << "NO\n";
		}
	}
}







