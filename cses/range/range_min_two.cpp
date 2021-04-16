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
int N, Q;

int arr[200001];
int segtree[400001];

void update(int pos, int delta) {
	segtree[pos+N-1] = delta;
	for (int i = (pos+N-1)/2; i > 0; i >>= 1) segtree[i] = min(segtree[2*i], segtree[2*i+1]);
}


void build() {
	for (int i = N; i < 2*N; i++) segtree[i] = arr[i-N+1];
	for (int i = N-1; i > 0; i--) segtree[i] = min(segtree[2*i], segtree[2*i+1]);
}

int query(int l, int r) {
	assert(l <= r);
	int res = INF+1;
	for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, segtree[l++]);
		if (!(r & 1)) res = min(res, segtree[r--]);
	}
	return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	rep(i,1,N+1) cin >> arr[i];
	build();

	rep(i,0,Q) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) 
			update(b,c);
		else 
			cout << query(b,c) << endl;
	}

    return 0;
}








