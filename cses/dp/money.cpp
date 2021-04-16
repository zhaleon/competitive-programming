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
int arr[101];
bool dp[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) cin >> arr[i];
    
	dp[0] = 1;

	rep(i,1,N+1) {
		for (int j = 100000; j > 0; j--) {	
			if (j >= arr[i]) dp[j] |= dp[j-arr[i]];
		}
	}

	int distinct = 0;
	rep(i,1,100001) distinct += dp[i];

	cout << distinct << endl;

	rep(i,1,100001) if (dp[i]) cout << i << ' ';

    return 0;
}








