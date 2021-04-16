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

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

typedef long double ld;

int T, N;


typedef struct line {
    ld m, b;
    line(ld m, ld b) : m(m), b(b) {}; 
    line() {};
    bool operator<(const line &o) const {
        return m < o.m;
    }
} line;

inline ld eval(ld x, line k) { 
    return k.m*x + k.b;
}

inline ld icept(line a) {
    return -a.b/a.m;
}

line lines[100001];

bool comp(line a, line b) {
    return -a.b/a.m < -b.b/b.m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(Case,1,T) {
        cin >> N;
        rep(i,1,N) {
            ld a, b;
            cin >> a >> b;
            lines[i] = line(a,b);
        }
        vector<line> upper, lower, upper_hull, lower_hull;
        rep(i,1,N) {
            if (eval(0, lines[i]) > 0) upper.push_back(lines[i]);
            else lower.push_back(lines[i]);
        }

        bool inf = 0;
        sort(upper.begin(), upper.end(), comp);
        sort(lower.begin(), lower.end(), comp);
    
        if (icept(upper.back()) < 0 || icept(upper.front()) > 0) inf = 1;
        if (icept(lower.back()) < 0 || icept(lower.front()) > 0) inf = 1; 

    }
    
    return 0;
}








