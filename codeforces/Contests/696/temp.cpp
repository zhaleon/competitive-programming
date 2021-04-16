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
#define rep(i,a,b) for (int i = a; i <= b; i++)

int N, Q;
int arr[500001];
int segtree[1000001];

void update(int pos, int delta) {
    segtree[pos+N-1] = delta;
    for (int i = (pos+N-1)/2; i > 0; i >>= 1) segtree[i] = __gcd(segtree[2*i], segtree[2*i+1]);
}

void build() {
    for (int i = N; i < 2*N; i++) segtree[i] = arr[i-N+1];
    for (int i = N-1; i > 0; i--) segtree[i] = __gcd(segtree[2*i], segtree[2*i+1]);
}

void calc(int& a, int b) {
    if (a == 0) a = b;
    else a = __gcd(a,b);
}

int query(int l, int r) {
    int res = 0;
    for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) calc(res, segtree[l++]);
        if (!(r & 1)) calc(res, segtree[r--]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i,1,N) cin >> arr[i];
    build();

    cin >> Q;
    rep(i,1,Q) {
        int a, l, r, x;
        cin >> a;
        if (a == 1) {
            cin >> l >> r >> x;
            
            int low = l-1, high = r;

            if (query(l,r) % x == 0) {
                cout << "YES\n";
                continue;
            }
            
            while (low+1 < high) {
                int mid = (low+high)/2;
                if (query(l,mid) >= x) low = mid;
                else high = mid;
            }

            if (low <= l-1) {
				if (query(l+1,r) % x == 0) cout << "YES\n";
				else cout << "NO\n";
                continue;
            } 

			int k = query(l, low);

			if (k % x) {
				if (low == l && query(low+1,r) % x == 0) cout << "YES\n";
				else if (query(l, max(l,low-1)) % x == 0 && (low >= r || query(low+1, r) % x == 0)) cout << "YES\n";
				else cout << "NO\n";
			} else {
				if (low >= r-1 || query(low+2, r) % x == 0) cout << "YES\n";
				else cout << "NO\n";
			}

        } else {
            cin >> l >> r;
            update(l,r);
        }
    }
    return 0;
}
