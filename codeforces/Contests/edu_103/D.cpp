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

int t, N;
string s;

int best_l[300002][2];
int best_r[300002][2];

void search_left(int cur, bool fl = 1) {
	if (best_l[cur][fl]) return;

	best_l[cur][fl] = 1; 
	if (cur == 1) return; 

	if (((s[cur-2] == 'L') == fl)) {
		if (!best_l[cur-1][!fl])
			search_left(cur-1, !fl);
		best_l[cur][fl] += best_l[cur-1][!fl];
	}
}

void search_right(int cur, bool fl = 1) {
	if (best_r[cur][fl]) return;

	best_r[cur][fl] = 1; 
	if (cur == N+1) return; 

	if (((s[cur-1] == 'R') == fl)) {
		if (!best_r[cur+1][!fl])
			search_right(cur+1, !fl);
		best_r[cur][fl] += best_r[cur+1][!fl];
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> N >> s;
		rep(i,1,N+1) best_l[i][0] = best_l[i][1] = best_r[i][0] = best_r[i][1] = 0;
		rep(i,1,N+1) search_left(i), search_right(i);

		rep(i,1,N+1) cout << best_l[i][1] + best_r[i][1] - 1 << ' ';
		
	}
    
    return 0;
}








