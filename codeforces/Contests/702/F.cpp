#include <bits/stdc++.h>

using namespace std;

#define int long long

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
int arr[200001];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	
	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];

		map<int, int> m;
		rep(i,1,N) ++m[arr[i]];

		vi freq(N+1, 0);
		vi pref(N+1, 0);
		vi temp(N+1, 0);
		vi thing(N+1, 0);
		vi temp_pref(N+1, 0);

		for (auto &p : m) ++freq[p.S];
		partial_sum(freq.begin(), freq.end(), pref.begin());
		rep(i,0,N) temp[i] = freq[i] * i;
		partial_sum(temp.begin(), temp.end(), temp_pref.begin());
		
		int ans = N - m.size();

		rep(i,2,N) {
			int nums = pref[i-1]; //how many frequency < i
			int k = N - pref[i]; // how many frequency > i
			// 1 * pref[i+1], 2 * pref[i+2], 3 * pref[i+3]
			int j = (temp_pref[N] - temp_pref[i]) - (i) * (pref[N] - pref[i]);	
//			if (i == 2) cout << "THING: " << j << endl;
			ans = min(ans, j + temp_pref[i-1]);
		}

//		cout << "TEST: ";
//		rep(i,1,N) cout << freq[i] << ' '; cout << endl;
//		rep(i,1,N) cout << pref[i] << ' '; cout << endl;
//		rep(i,1,N) cout << temp_pref[i] << ' '; cout << endl;
		cout << ans << endl;
	}

    return 0;
}








