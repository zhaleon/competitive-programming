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

int N;
ll arr[5001];
ll dp[5001][5001];
ll pref[5001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) {
	   	cin >> arr[i];
		dp[i][i] = arr[i];
		pref[i] = pref[i-1] + arr[i];
    }
	
	rep(len,2,N+1) {
		for (int i = 1; i+len-1 <= N; i++) 
			dp[i][i+len-1] = pref[i+len-1]-pref[i-1] - min(dp[i][i+len-2], dp[i+1][i+len-1]);
	}

	cout << dp[1][N] << endl;

    return 0;
}








