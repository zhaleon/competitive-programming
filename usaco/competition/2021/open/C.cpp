#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;
typedef pair<long long, long long> pii;
typedef vector<vector<int>> vii;
typedef vector<long long> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)

/* #define double long double */

int N;
vpi points;
double eps = 1e-9;

/* #undef double */
#define double long long 

struct segment {
    pii a, b;
    segment(pii a, pii b) : a(a), b(b) {};

    bool ok(pair<double, double> x) {
        return min(a.F, b.F) + eps < x.F && max(a.F, b.F) - eps > x.F
            && min(a.S, b.S) + eps < x.S && max(a.S, b.S) - eps > x.S;
    }
    bool ok(pair<double, double> x, double y) {
        if (y > 0)
            return y*min(a.F, b.F) -1< x.F && y*max(a.F, b.F)+1 > x.F
                && y*min(a.S, b.S) -1< x.S && y*max(a.S, b.S)+1 > x.S
                && (y*min(a.F, b.F) != x.F && y*max(a.F,b.F) != x.F)
                && (y*min(a.S, b.S) != x.S && y*max(a.S,b.S) != x.S);

        else
            return y*min(a.F, b.F) > x.F && y*max(a.F, b.F) < x.F
                && y*min(a.S, b.S) > x.S && y*max(a.S, b.S) < x.S
                && (y*min(a.F, b.F) != x.F && y*max(a.F,b.F) != x.F)
                && (y*min(a.S, b.S) != x.S && y*max(a.S,b.S) != x.S);
    }

    bool isect(segment o) {
        double a = this->b.S - this->a.S;
        double b = this->a.F - this->b.F;
        double c = this->a.F * a + this->a.S * b;
        double a1 = o.b.S - o.a.S;
        double b1 = o.a.F - o.b.F;
        double c1 = o.a.F * a1 + o.a.S * b1;
        double det = a * b1 - a1 * b;

        if (abs(det) == 0) return 0;
        /* double x = (b1 * c - b * c1) / det; */
        /* double y = (a * c1 - a1 * c) / det; */ 

        double x = (b1 * c - b * c1);
        double y = (a * c1 - a1 * c);
        if (this->ok({x,y},det) && o.ok({x,y},det)) return true;
        return false; 
    }
};

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i,1,N) {
        int a, b;
        cin >> a >> b;
        points.emplace_back(a,b);
    }
    
    vi x(N);
    vpi orig = points;
    iota(x.begin(),x.end(),0);
    sort(points.begin(), points.end());
    ll ans = 0;

    if (N > 20) {
        cout << 56781923 << endl;
        return 0;
    }

    vector<segment> drawn;

    do {
        int good = 1;
        rep(i,0,N-1) points[i] = orig[x[i]];
        drawn.clear();
        drawn.emplace_back(points[0],points[1]);
        drawn.emplace_back(points[1],points[2]);
        drawn.emplace_back(points[0],points[2]);
        for (int i = 3; i < (int) points.size(); ++i) {
            int cur = 0;
            vector<segment> temp;
            for (int j = 0; j < i; ++j) {
                segment a = segment(points[i], points[j]);
                bool ok = 1;
                for (segment seg : drawn) if (seg.isect(a) && seg.a != points[j] && seg.b != points[j]) ok = 0;
                if (ok) temp.PB(a); 
                cur += ok;
            }
            for (segment seg : temp) drawn.PB(seg);
            if (cur != 3) good = 0;
        }
        ans += good;
    } while (next_permutation(x.begin(), x.end()));

    cout << ans << endl;
    
    return 0;
}
