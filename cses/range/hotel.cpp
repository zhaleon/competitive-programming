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

int N, M;
int h[200001];

int segtree[(1 << 19) + 1];

void update(int pos, int delta) {
	segtree[pos+N-1] = delta;
	for (int i = (pos+N-1)/2; i > 0; i >>= 1) segtree[i] = max(segtree[2*i], segtree[2*i+1]);
}


void build() {
	for (int i = N; i < 2*N; i++) segtree[i] = h[i-N+1];
	for (int i = N-1; i > 0; i--) segtree[i] = max(segtree[2*i], segtree[2*i+1]);
}

int query(int l, int r) {
	assert(l <= r);
	int res = 0;
	for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, segtree[l++]);
		if (!(r & 1)) res = max(res, segtree[r--]);
	}
	return res;
}

int find(int X) {
	int cur = 1;
	while (cur < N) {
		if (segtree[2*cur] >= X) cur = 2*cur;
		else cur = 2*cur+1;
	}
	return cur - (N-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
    rep(i,1,N+1) cin >> h[i];
	N = 1 << 18;
	build();
	update(N, INF+1);
	rep(i,0,M) {
		int a; cin >> a;
		int res = find(a);
		if (res > 2e5) {
			cout << 0 << ' ';
		} else {
			cout << res << ' ';
			update(res, segtree[res+N-1] - a);
		}
	}
	/* cout << endl; */
	rep(i,1,9) {
		/* cout << "index: " << i << ' ' << query(i, i) << endl; */
	}

	/* cout << find(4) << endl; */

    return 0;
}








