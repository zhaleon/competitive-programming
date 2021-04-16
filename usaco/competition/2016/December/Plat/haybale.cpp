#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

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

int lazy[200001];
pair<ll, ll> segtree[400001];
int sz[400001];

int h;

void build() {
    for (int i = N; i < 2*N; i++) segtree[i].F = segtree[i].S = arr[i-N+1], sz[i] = 1;
    for (int i = N-1; i > 0; i--) {
		sz[i] = sz[2*i] + sz[2*i+1];
		segtree[i].S = min(segtree[2*i].S, segtree[2*i+1].S);
        segtree[i].F = segtree[2*i].F + segtree[2*i+1].F;
    }
}

void apply(int pos, int val) {
	segtree[pos].F += val*sz[pos];
	segtree[pos].S += val;
	if (pos < N) lazy[pos] += val;
}

void push(int p) {
	for (int s = h; s > 0; s--) {
		int i = p >> s;
		if (lazy[i]) {
			apply(2*i, lazy[i]);
			apply(2*i+1, lazy[i]);
			lazy[i] = 0;	
		}
	}
}

void update(int pos, int delta) {
	segtree[pos].F += delta;
	segtree[pos].S += delta;
	for (int i = pos/2; i > 0; i >>= 1) {
		segtree[i].F = segtree[2*i].F + segtree[2*i+1].F;
		segtree[i].S = min(segtree[2*i].S, segtree[2*i+1].S);
	}
	//cout << "BUSTED\n";
}

void range_update(int l, int r, int amt) {
    //cout << "UPDATE " << l << ' ' << r << endl;
	for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			//cout << l << " VERY BROKEN " << amt << endl;
			if (l < N) lazy[l++] += amt;
			else update(l++, amt);
		}
		if (~r & 1) { 
			if (r < N) lazy[r--] += amt;
			else update(r--, amt);
		}
	}
}

ll query_min(int l, int r) {
	push(l+N-1);
	push(r+N-1);
	//update(l+N-1, 0);
	//update(r+N-1, 0);
	ll res = 1e18;

    for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, segtree[l++].S);
        if (~r & 1) res = min(res, segtree[r--].S);
    }
	return res;
}

ll query_sum(int l, int r) {
	push(l+N-1);
	push(r+N-1);
	//update(l+N-1, 0);
	//update(r+N-1, 0);

	ll res = 0;
    for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res += segtree[l++].F;
        if (~r & 1) res += segtree[r--].F;
    }
    return res;
}

void print() {
	cout << "segtree: ";
	rep(i,1,8) cout << segtree[i].F << ' '; cout << endl;
	cout << "lazy: ";
	rep(i,1,4) cout << lazy[i] << ' '; cout << endl;
}

int main() {
	setIO("haybales");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> Q;
	rep(i,1,N+1) cin >> arr[i];

	h = 31-__builtin_clz(N);

	build();

	/* cout << "\nTEST: " << query_sum(1,3) << endl; */
	/* rep(i,1,8) cout << "size = " << sz[i] << endl; */
	rep(i,0,Q) {
		char t;
		int a, b, c;
		
		cin >> t;
		cin >> a >> b;	
		if (t == 'M') {
			cout << query_min(a,b) << endl;
		} else if (t == 'S') {
			cout << query_sum(a,b) << endl;
		} else {
			cin >> c;
			range_update(a,b,c);
		}
		//print();
	}


    return 0;
}
