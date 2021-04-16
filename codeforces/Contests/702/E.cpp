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

int T, N;
pair<ll, ll> arr[200001];
bool ok[200001];
ll pref[200001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> T;
	while(T--) {
		cin >> N;
		rep(i,1,N) arr[i].F = arr[i].S = 0;
		rep(i,1,N) cin >> arr[i].F;
		rep(i,1,N) arr[i].S = i;
		rep(i,1,N) ok[i] = 0;

		sort(arr+1, arr+1+N);
		ll tot = 0;
		int early = 0;
		rep(i,1,N-1) {
			tot += arr[i].F;
			if (tot < arr[i+1].F) {
				early = i+1;
			}
		}

		ok[arr[N].S] = 1;
		rep(i,early,N) ok[arr[i].S] = 1;
		vi ans;
		rep(i,1,N) if (ok[i]) ans.PB(i);
		sort(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (int ads : ans) cout << ads << ' '; 
		cout << '\n'; 
	}
    
    return 0;
}








