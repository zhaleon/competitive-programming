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

ll T, N, K, S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	int Case = 1;
	while(T--) {
		cin >> N >> K >> S;

		ll ans = min(N-S+1 + K-S, N+1) + K-1;

		printf("Case #%i: %lld\n", Case++, ans);
	}
    
    return 0;
}








