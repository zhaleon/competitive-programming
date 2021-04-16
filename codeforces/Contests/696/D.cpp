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

int T, N;
ll arr[200001];
ll dif[200001];
ll suf[200002];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];
		rep(i,1,N) dif[i] = arr[i] - dif[i-1];

		if (N == 1) {
			cout << "NO" << endl;
			continue;
		}
		
		if (dif[N] == 0 && *min_element(begin(dif)+1, end(dif)) >= 0) {
			cout << "YES" << endl;
			continue;
		}

		suf[N] = dif[N];
		suf[N-1] = dif[N-1];
		suf[1] = suf[N+1] = 2*INF;

		for (int i = N-2; i > 1; --i) {
			suf[i] = min(suf[i+2], dif[i]);
		}

		/* rep(i,1,N) cout << suf[i] << ' '; cout << endl; */
		/* rep(i,1,N) cout << dif[i] << ' '; cout << endl; */

		bool possible = false;
		rep(i,2,N) {
			ll de = 2*(arr[i-1] - arr[i]);

			bool p = ((N - i) & 1) ^ 1;
			if (!p) de = -de;

			if (dif[N] + de == 0) {

				if (!p) de = -de;

				bool ok = 1;
				if (suf[i] + de < 0) ok = 0;
				else if (suf[i+1] - de < 0) ok = 0;
				else if (dif[i-1] - de/2 < 0) ok = 0; 
				
				if (ok) {
					cout << "YES" << endl;
					/* cout << i << " WORKS?" << endl; */
					possible = true;
					break;
				}
			}

			/* if (dif[i] < 0 && dif[i] + de < 0) break; */
			if (dif[i-1] < 0) break;
		}

		if (!possible) cout << "NO" << endl;
	}
    
    return 0;
}








