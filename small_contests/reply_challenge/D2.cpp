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

typedef long double ld;
using pt = pair<ld, ld>;

struct Poly {
    int n;
    vector<pt> upper, lower;

    bool intersect(const pt o) {
        if (o.first < this->lower.front().first || o.first < this->upper.front().first) return 0;
        if (o.first > this->lower.back().first || o.first < this->upper.back().first) return 0;

        pt p1 = *lower_bound(upper.begin(), upper.end(), o.first);
        pt p2 = *--lower_bound(upper.begin(), upper.end(), o.first);

        ld slope = (p2.second - p1.second) / (p2.first - p1.first);
        ld icept = -p2.first * slope + p2.second;
        if (o.first * slope + icept < o.second) return 0;
        
        p1 = *lower_bound(lower.begin(), lower.end(), o.first);
        p2 = *--lower_bound(lower.begin(), lower.end(), o.first);

        slope = (p2.second - p1.second) / (p2.first - p1.first);
        icept = -p2.first * slope + p2.second;
        if (o.first * slope + icept > o.second) return 0;

        return 1;
    }
};

Poly intersection(Poly &a, Poly &b) {
    Poly res;
    pt left_most, right_most;
    ld left_x = INF, right_x = -INF;
    ld slope, icept;

    vector<pt> pts;
    vector<pt> new_pts;

    for (int i = 0; i < (int)a.upper.size(); ++i) pts.PB(a.upper[i]);
    for (int i = 1; i < (int)a.lower.size()-1; ++i) pts.PB(a.lower[i]);
    
    for (int i = 0; i < (int)b.upper.size(); ++i) pts.PB(b.upper[i]);
    for (int i = 1; i < (int)b.lower.size()-1; ++i) pts.PB(b.lower[i]);

    for (auto p : pts) {
        if (a.intersect(p) && b.intersect(p)) {
            if (p.first < left_x) left_most = p, left_x = p.first;
            if (p.first > right_x) right_most = p, right_x = p.first;
            new_pts.push_back(p);
        }
    }

    slope = (right_most.second - left_most.second) / (right_most.first - left_most.first);
    icept = -right_most.first * slope + right_most.second;

    res.upper.push_back(left_most);
    res.upper.push_back(right_most);
    res.lower.push_back(left_most);
    res.lower.push_back(right_most);

    for (auto p : new_pts) {
        if (slope * p.first + icept < p.second) res.upper.push_back(p);
        else res.lower.push_back(p);
    }

    sort(res.upper.begin(), res.upper.end());
    sort(res.lower.begin(), res.lower.end());

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    
    return 0;
}








