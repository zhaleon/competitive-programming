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

int N, K;

ll c[500001];
ll bonus = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	rep(i,1,N+1) cin >> c[i];
   
	sort(c+1, c+1+N, greater<int>());
	
	ll ans = 0;
	
	for (int i = 1; i <= N; i++) {
		ans += bonus;

		bonus += c[i];

		if ((bonus < 0 && i < N && bonus < c[i+1]*(N-i-1) && K) || (K && K >= N-i)) {
			bonus = 0;
			K--;
		}
	}

	cout << ans << endl; 

    return 0;
}








