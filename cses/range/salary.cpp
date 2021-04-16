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
int arra[200001];
int arr [600001];
struct query {
	int t, k, x;
	query() {};
	query(int a, int b, int c) : t(a), k(b), x(c) {};
};
 
int ind = 0;
int segtree[1200001];

void update(int pos, int &&delta) {
	segtree[pos+ind-1] += delta;
	for (int i = (pos+ind-1)/2; i > 0; i >>= 1) segtree[i] += delta; //= segtree[2*i] + segtree[2*i+1];
}


void build() {
	for (int i = ind; i < 2*ind; i++) segtree[i] = arr[i-ind+1];
	for (int i = ind-1; i > 0; i--) segtree[i] = segtree[2*i] + segtree[2*i+1];
}

int sum(int l, int r) {
	int res = 0;
	for (l += ind-1, r += ind-1; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res += segtree[l++];
		if (!(r & 1)) res += segtree[r--];
	}
	return res;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
	cin >> N >> Q;
	
	vi nums;
 
	rep(i,1,N+1) {
		cin >> arra[i];
		nums.PB(arra[i]);
	}
 
	vector<query> q(Q);
 
	rep(i,0,Q) {
		char d;
	   	int	a, b, c;
		cin >> d >> b >> c;
		if (d == '!') a = 1;
		else a = 0;
 
		q[i] = (query(a,b,c));
		nums.PB(c);
		if (b) nums.PB(b);
	}
 
	sort(nums.begin(), nums.end());
	
	nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));

	unordered_map<int, int, custom_hash> compress;
	
	for (auto &num : nums) compress[num] = ++ind;

	/* for (int num : nums) compress[num]; */
	/* for (auto &m : compress) m.S = ++ind; */
	/* cout << "NUMBERS: "; */
	/* for (auto num : nums) cout << num << ' '; cout << endl; */
	/* for (auto m : compress) cout << m.F << " "; cout << endl; */
	/* for (auto m : compress) cout << m.S << " "; cout << endl; */
	rep(i,1,N+1) arr[compress[arra[i]]]++;
	build();	
	/* rep(i,1,N+1) update(compress[arr[i]], +1); */
	for (query &cur : q) {
		/* assert (compress.find(arr[cur.k]) != compress.end()); */
		/* assert (compress.find(cur.x) != compress.end()); */
		/* if (compress.find(cur.x) == compress.end()) { */
		/* 	cout << "BROKE: " << cur.x << endl; */
		/* 	return 0; */
		/* } */
		if (cur.t) {
			update(compress[arra[cur.k]], -1);
			update(compress[cur.x], +1);
			arra[cur.k] = cur.x;
		} else {
			cout << sum(compress[cur.k], compress[cur.x]) << '\n';
		}
	}
 
    return 0;
}
