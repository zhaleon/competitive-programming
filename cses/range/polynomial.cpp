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

struct data {
	ll sum, len, fir, dif;
};

data segtree[800001];

data make_data(ll val, ll len = 1) {
	data res;
	res.len = len;
	res.sum = val;
	res.fir = res.dif = 0;
	return res;
}

data combine(data a, data b) {
	data res;
	res.sum = a.sum + b.sum;
	res.len = a.len + b.len;
	res.fir = res.dif = 0; 
	return res;
}

void push(int v) {
	if (segtree[v].fir == 0 || v > 2*N)
		return;
	
	segtree[2*v].fir += segtree[v].fir;
	segtree[2*v].dif += segtree[v].dif;
	segtree[2*v].sum += (2*segtree[v].fir + segtree[v].dif * (segtree[2*v].len-1)) * segtree[2*v].len / 2;

	segtree[2*v+1].fir += segtree[v].fir + segtree[v].dif * (segtree[2*v].len);
	segtree[2*v+1].dif += segtree[v].dif;

	ll k = segtree[v].fir + segtree[v].dif * (segtree[2*v].len);

	segtree[2*v+1].sum += (2*k + segtree[v].dif * (segtree[2*v+1].len-1))*segtree[2*v+1].len/2; 
	segtree[v].fir = segtree[v].dif = 0;
}

void build(int v = 1, int L = 1, int R = N) {
	if (L > R) return;
	if (L == R)
		segtree[v] = make_data(arr[L]);
	else {	
		int M = (L + R)/2;
		build(2*v, L, M);
		build(2*v+1, M+1, R);

		segtree[v] = combine(segtree[2*v], segtree[2*v+1]);
	}
}

ll query(int v, int tl, int tr, int l, int r) {
	if (l == tl && r == tr)  
		return segtree[v].sum;

	push(v);
	int tm = (tl+tr)/2;	
	
	if (r <= tm)
		return query(2*v, tl, tm, l, r);
	if (l > tm)
		return query(2*v+1, tm+1, tr, l, r);

	return query(v*2, tl, tm, l, tm) + query(v*2+1, tm+1, tr, tm+1, r);
}

void update(int v, int tl, int tr, int l, int r, int fir = 1) {
	if (l > r || fir <= 0) return;
	
	push(v);

	if (l == tl && r == tr) {
		assert((2*fir + (segtree[v].len-1))*segtree[v].len/2 > 0);
		segtree[v].sum += (2*fir + (segtree[v].len-1))*segtree[v].len/2; 
		segtree[v].fir += fir;
		segtree[v].dif++;
	} else {
		int tm = (tl + tr)/2;
		update(2*v, tl, tm, l, min(r,tm), fir);
		update(2*v+1, tm+1,tr, max(l,tm+1), r, fir+max(0,tm+1-l)); 
		segtree[v].sum = segtree[2*v].sum + segtree[2*v+1].sum;
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	rep(i,1,N+1) cin >> arr[i];

	build();
	
	rep(i,0,Q) {
		int t, a, b;
		cin >> t >> a >> b;
	
		if (t == 1) {
			update(1,1,N,a,b,1);
		} else {
			cout << query(1,1,N,a,b) << endl;
		}
	}
    
    return 0;
}








