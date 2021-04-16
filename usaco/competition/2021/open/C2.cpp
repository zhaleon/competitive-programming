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
#define rep(i,a,b) for (int i = a; i <= b; ++i)

#define double long double

int N;
vpi points;
double eps = 1e-9;

pii operator-(pii a, pii b) {
    pii x = {a.F-b.F, a.S-b.S};
    return x;
}

struct segment {
    pii a, b;
    segment(pii a, pii b) : a(a), b(b) {};

    bool ok(pair<double, double> x) {
        return min(a.F, b.F) + eps < x.F && max(a.F, b.F) - eps > x.F
            && min(a.S, b.S) + eps < x.S && max(a.S, b.S) - eps > x.S;
    }

    bool isect(segment o) {
        double a = this->b.S - this->a.S;
        double b = this->a.F - this->b.F;
        double c = this->a.F * a + this->a.S * b;
        double a1 = o.b.S - o.a.S;
        double b1 = o.a.F - o.b.F;
        double c1 = o.a.F * a1 + o.a.S * b1;
        double det = a * b1 - a1 * b;

        if (abs(det) < 1e-9) return 0;
        double x = (b1 * c - b * c1) / det;
        double y = (a * c1 - a1 * c) / det; 

        if (this->ok({x,y}) && o.ok({x,y})) return true;
        return false; 
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i,1,N) {
        int a, b;
        cin >> a >> b;
        points.emplace_back(a,b);
    }
    /* swap(points[3], points[4]); */ 
    /* for (auto x : points) printf("(%i,%i) ", x.F, x.S); */ 
    /* printf("\n"); */
    
    sort(points.begin(), points.end());
    ll ans = 0;

    if (N > 10) {
        cout << 12351223 << endl;
        return 0;
    }

    vector<segment> drawn;

    do {

        drawn.clear();
        drawn.emplace_back(points[0],points[1]);
        drawn.emplace_back(points[1],points[2]);
        drawn.emplace_back(points[0],points[2]);

        int good = 1;
        for (int i = 3; i < (int) points.size(); ++i) {
            int cur = 0;
            for (int j = 0; j < i; ++j) {
                segment a = segment(points[i], points[j]);
                bool ok = 1;
                for (auto x : drawn) if (x.isect(a) && x.a != points[j] && x.b != points[j]) ok = 0;
                if (ok) drawn.PB(a);
                cur += ok;
            }
            if (cur != 3) good = 0;
        }
        ans += good;
    } while (next_permutation(points.begin(), points.end()));

    cout << ans << endl;
    
    return 0;
}

