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

typedef struct node {
	int freq = 0;
	int min = INF;
	int sum = 0;
	node() {}
} node;

int N, h;
int arr[500001];

vi pos[500001]; 
int pt[500001];

node segtree[1000001];

void init() {
	for (int i = N; i < 2*N; i++) {
		segtree[i].min = 0; //arr[i-N+1];
		segtree[i].freq++;
	}
	for (int i = N-1; i > 0; i--) {
		segtree[i].min = min(segtree[2*i].min, segtree[2*i+1].min);
		if (segtree[2*i].min < segtree[2*i+1].min) segtree[i].freq = segtree[2*i].freq;
		else if (segtree[2*i].min > segtree[2*i+1].min) segtree[i].freq = segtree[2*i].freq;
		else segtree[i].freq = segtree[2*i].freq + segtree[2*i+1].freq;
	}
}

void upd(int pos, int delta) {
	pos -= (N-1);
	segtree[pos+N-1].sum += delta;
	//segtree[pos+N-1].min += delta;
	for (int i = (pos+N-1)/2; i > 0; i >>= 1) {
		segtree[i].min = min(segtree[2*i].min + segtree[2*i].sum, segtree[2*i+1].min + segtree[2*i+1].sum);
		if (segtree[2*i].min + segtree[2*i].sum < segtree[2*i+1].min + segtree[2*i+1].sum) segtree[i].freq = segtree[2*i].freq;
		else if (segtree[2*i].min + segtree[2*i].sum > segtree[2*i+1].min + segtree[2*i+1].sum) segtree[i].freq = segtree[2*i+1].freq;
		else segtree[i].freq = segtree[2*i].freq + segtree[2*i+1].freq;
	}
}

void upd(int l, int r, int delta) {
	l += N-1, r += N-1;
//	if (l & 1) upd(l++, delta);
//	if (!(r & 1)) upd(r--, delta);
//	if (l > r) return;
	// l >>= 1, r >>= 1;
	int L = l, R = r;
	for (; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			upd(l++, delta);
			//segtree[l++].sum += delta;
		}
		if (!(r & 1)) {
			upd(r--, delta);
			//segtree[r--].sum += delta;
		}
	}
	
//	int a = L, b = R;
//	while (L > 1) {
//		L >>= 1;
//		int i = L;
//		segtree[i].min = min(segtree[2*i].min, segtree[2*i+1].min);
//	}
//	while (R > 1) {
//		R >>= 1;
//		int i = R;
//		segtree[i].min = min(segtree[2*i].min, segtree[2*i+1].min);
//	}
//	for (a >>= 1; a > 0; a >>= 1) {
//		int i = a;
//		if (segtree[2*i].min < segtree[2*i+1].min) segtree[i].freq = segtree[2*i].freq;
//		else if (segtree[2*i].min > segtree[2*i+1].min ) segtree[i].freq = segtree[2*i+1].freq;
//		else segtree[i].freq = segtree[2*i].freq + segtree[2*i+1].freq;
//	}
//	for (b >>= 1; b > 0; b >>= 1) {
//		int i = b;
//		if (segtree[2*i].min < segtree[2*i+1].min) segtree[i].freq = segtree[2*i].freq;
//		else if (segtree[2*i].min > segtree[2*i+1].min ) segtree[i].freq = segtree[2*i+1].freq;
//		else segtree[i].freq = segtree[2*i].freq + segtree[2*i+1].freq;
//	}
}

void push(int a) {
	for (int s = h; s > 0; s--) {
		int i = a >> s;
		if (segtree[i].sum) {
			segtree[2*i+1].min += segtree[i].sum;
			segtree[2*i].min += segtree[i].sum;
			
			if (2*i+1 < N) segtree[2*i+1].sum += segtree[i].sum;
			if (2*i < N) segtree[2*i].sum += segtree[i].sum;
			segtree[i].sum = 0;
		}
	}
}

int query(int l, int r) {
	int a = l+N-1, b = r+N-1;
	//push(a); push(b);
	int small = INF, freq = 0, L = l+N-1, R = r+N-1;
	for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1)) {
			small = min(small, segtree[l].min + segtree[l].sum);
			l++;
		}
		if (!(r & 1)) {
			small = min(small, segtree[r].min + segtree[r].sum);
			r--;
		}
	}
	if (small) return -1;
	for (; L <= R; L >>= 1, R >>= 1) {
		if ((L & 1)) {
			if (segtree[L].min + segtree[L].sum == small) freq += segtree[L].freq;
			L++;
		} 
		if (!(R & 1)) {
			if (segtree[R].min + segtree[R].sum == small) freq += segtree[R].freq;
			R--;
		}
	}
	//cout << small << ' ' << freq << ' ' << a << ' ' << b << endl;
	return freq;
}

void print_arr() {
	rep(i,N,2*N) {
		int res = 0 + segtree[i].min;//segtree[i].sum; //arr[i-N+1];
		for (int j = i; j > 0; j >>= 1) res += segtree[j].sum;
		cout << res << ' ';
	} cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	rep(i,1,N+1) cin >> arr[i];

	h = 32 - __builtin_clz(N);
	init();
	
	rep(i,1,N+1) pos[arr[i]].PB(i);
	rep(i,1,N+1) pt[arr[i]] = pos[arr[i]].size()-1;
	
	ll ans = 0;
	
	//return 0;
	for (int i = N; i > 0; i--) {
		int cur = pt[arr[i]]--;
		//cout << arr[i] << ' ' << cur << endl;
		if (cur + 2 > pos[arr[i]].size()-1) {
			if (cur == pos[arr[i]].size()-1) upd(i, N, +1);
			else upd(i, pos[arr[i]][cur+1]-1, +1);
		} else if (cur + 2 == pos[arr[i]].size()-1){ //third one
			int third = pos[arr[i]].back();
			upd(i, pos[arr[i]][cur+1]-1, +1);
			upd(third, N, -1);
			int x = query(i, N);
			//cout << i << ' ' << x << endl;
			if (x > 0) ans += x;
		} else {
			int third = pos[arr[i]][cur+2], fourth = pos[arr[i]][cur+3];
			if (cur+3 == pos[arr[i]].size()-1) upd(fourth, N, 1);
			else upd(fourth, pos[arr[i]][cur+4]-1, 1);
			upd(i, pos[arr[i]][cur+1]-1, 1);
			upd(third, fourth-1, -1);
			int x = query(i,N);
			//cout << i << ' ' << x << ' ' << third << ' ' << fourth << endl;
			if (x > 0) ans += x;
		}
		//cout << i << ": "; print_arr();
	}
	
	cout << ans << endl;
	

    return 0;
}