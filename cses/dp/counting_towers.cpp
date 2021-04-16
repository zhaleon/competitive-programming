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
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

const int mod = (int)1e9 + 7;
int T, N;
ll dp[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    dp[0] = 1; 
    dp[1] = 2;
    ll pref = 3;

    rep(i,2,1000000) {
        dp[i] =  3 * ( dp[i-1] - (pref - dp[i-1]) ) + pref + dp[i-1];
        dp[i] %= mod;
        dp[i] += mod;
        dp[i] %= mod;
        pref += dp[i];
        pref %= mod;
    }

    rep(i,1,T) {
        cin >> N;
        cout << dp[N] << endl;        
    }
    
    return 0;
}








