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
#define rep(i,a,b) for (int i = a; i <= b; i++)

const int mod = 1e9+7;
string s;

ll G[100001];
ll T[100001];
ll A[100001];
ll C[100001];

ll dp[100001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> s;
   
	s = " " + s;

	rep(i,1,s.length()) {
		dp[i] = dp[i-1];
		A[i] = A[i-1];
		T[i] = T[i-1];
		C[i] = C[i-1];
		G[i] = G[i-1];

		if (s[i] == '?') {
			(dp[i] += A[i-1]) %= mod;
			(dp[i] += T[i-1]) %= mod;
			(dp[i] += C[i-1]) %= mod;
			(dp[i] += G[i-1]) %= mod;
		} else if (s[i] == 'A') {
			(dp[i] += A[i-1]) %= mod;

			if (1) {
				A[i] += 3; 
				if (A[i] >= mod) A[i] -= mod;
			}

		} else if (s[i] == 'T') {
			(dp[i] += T[i-1]) %= mod;

		} else if (s[i] == 'C') {
			(dp[i] += C[i-1]) %= mod;

		} else {
			(dp[i] += G[i-1]) %= mod;

		}
		
	}

	cout << dp[N] << endl;

    return 0;
}








