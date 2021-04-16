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
int arr[101];
int d[101];

void solve(int L = 1, int R = N, int depth = 0) {
	if (L > R) return;
	int big = 0;
	int idx = 0;
	rep(i,L,R) {
		if (arr[i] > big) big = arr[i], idx = i;
	}
	d[idx] = depth;

	solve(L,idx-1,depth+1);
	solve(idx+1,R,depth+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];
		rep(i,1,N) d[i] = 0;

		solve(1,N);

		rep(i,1,N) cout << d[i] << ' '; cout << '\n';
	}
    
    return 0;
}








