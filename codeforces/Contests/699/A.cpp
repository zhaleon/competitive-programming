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

ll T, N, K;
ll h[102];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while(T--) {
		cin >> N >> K;
		rep(i,1,N) cin >> h[i];
		h[N+1] = 0;

		ll ans = -1;
		for (int i = 1; i <= N; ++i) {
			int j = i-1;
			for (; j >= 1; --j) if (h[j] >= h[j+1]) break;
			int k = j+1;
			for (; j < i; ++j) {
				
				K -= min(K, (k-j)*(h[j+1]-h[j]));
				if (!K) {
					ans = j;
					break;
				}
			}

			if (!K) {
				break;
			}
		}

		cout << ans << '\n';
	}
    
    return 0;
}








