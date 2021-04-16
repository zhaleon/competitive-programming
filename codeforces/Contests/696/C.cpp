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
int arr[2001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		N <<= 1;
		
		rep(i,1,N) cin >> arr[i];
		sort(arr+1, arr+1+N);

		map<int, int> m;
		map<int, vi> inds;

		rep(i,1,N-1) ++m[arr[i]];
		rep(i,1,N) inds[arr[i]].PB(i);

		bool possible = 0;

		rep(i,1,N-1) {
			vpi ans;
			map<int, int> mm = m;
			--mm[arr[i]];
			/* cout << "DEBUG: "; */
			/* for (auto p : mm) cout << "[" << p.F << "," << p.S << "] "; cout << endl; */
			ans.emplace_back(arr[i], arr[N]);

			bool ok = true;
			int cur_max = arr[N];

			for (int i = N-1; i > 0; --i) {
				if (mm[arr[i]] == 0) continue;

				if (mm.find(cur_max-arr[i]) == mm.end() || mm[cur_max - arr[i]] < (1 + (arr[i] == cur_max - arr[i]))) { 
					ok = false;
					break;
				}

				ans.emplace_back(arr[i], cur_max - arr[i]);
				--mm[arr[i]];
				--mm[cur_max - arr[i]];

				cur_max = (max(arr[i], cur_max - arr[i]));
			}

			if (ok) {
				cout << "YES\n" << arr[N] + arr[i] << '\n';

				for (auto &p : ans) {
					/* auto &l = inds[p.F], &r = inds[p.S]; */

					/* cout << l.back() << ' '; */
					/* l.pop_back(); */

					/* cout << r.back() << '\n'; */
					/* r.pop_back(); */
					cout << p.F << ' ' << p.S << '\n';
				}
				
				possible = 1;
				break;
			} 
		}
		
		if (!possible)
			cout << "NO\n";
	}
    
    return 0;
}








