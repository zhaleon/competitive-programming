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

int T, N, M;

int a[100001];
int b[100001];
int c[100001];
int ans[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> M;
		rep(i,1,N) cin >> a[i];
		rep(i,1,N) cin >> b[i];
		rep(i,1,M) cin >> c[i];
		map<int, vi> m;
		map<int, int> m2;

		rep(i,1,N) { 
			if (a[i] != b[i]) m[b[i]].PB(i);
			else m2[b[i]] = i;
		}
		int last_painted = 0;
		bool possible = true;
		for (int j = M; j > 0; --j) {
			auto it = m.find(c[j]);
			if (it != m.end()) {
				if (it->S.size() > 0) { 
					a[it->S.back()] = c[j];
					ans[j] = it->S.back();  
					last_painted = it->S.back();
					it->S.pop_back();
					continue;
				} else if (!last_painted && m2.find(c[j]) == m2.end()) { 
					possible = 0;
				}
			} else if (!last_painted && m2.find(c[j]) == m2.end()) {
				possible = 0;
			} else {
				if (last_painted) ans[j] = last_painted;
				else {
					last_painted = m2[c[j]];
					ans[j] = last_painted;
				}
			}
		}

		bool ok = true;
		
		rep(i,1,N) ok = ok && (a[i] == b[i]);

		/* cout << "TEST " << ok << ' ' << possible << endl; */
		if (ok and possible) { 
			cout << "YES\n";
			rep(i,1,M) cout << ans[i] << ' '; cout << '\n';
		}
		else cout << "NO\n";
	}
    
    return 0;
}








