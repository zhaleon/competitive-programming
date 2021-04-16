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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int ans = 0;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

//    set<ll> s;
//    
//    rep(i,0,30) {
//        rep(j,0,30) {
//            if (abs((1ll << i) - (1ll << j)) < 1000) cout << i << ' ' << j << endl;
//            s.insert(abs((1ll << i) - (1ll << j)));
//        }
//    }
//    
//    s.erase(s.begin());
//    
//
//    for (int x : s) if (x < 1000) ans++, cout << "NUM: " << x << endl;
    
//    
    
//    rep(a,1,100) {
//        rep(b,a+1,100) {
//            rep(c,b+1,100) {
//                if (a+b+c == 66) ++ans;
//            }
//        }
//    }
//    cout << ans << endl;
    
//    rep(a,-1000,1000) {
//        rep(d,1,1000) {
//            if (3*a*a + 2*d*d == a*d*d) {
//                ++ans;
//                cout << a << ' ' << d << endl;
//            }
//        }
//    }
//
//        rep(m,1,30) {
//            rep(n,m+1,30) {
//                rep(k,-100,100) {
//                    bool ok = true;
//                    rep(j,-100,100) {
//                        if (n + 4*j*n == m + 4*k*m) {
//                            ++ans;
//                            cout << m << ' ' << n << endl;
//                            ok = false;
//                            break;
//                        }
//                    }
//                    if (!ok) break;
//                }
//            }
//        }
//    
//    auto score = [](int x) {
//        if (x == 100) return 2;
//        else if (x < 100 && x > 0) return 4;
//        else if (x == 0) return 3;
//        else if (x < 0) return 2;
//        else if (x > 0) return 0;
//    };
//    
//    int tot = 0;
//    for (int c = -1000; c < 1000; ++c) {
//        unordered_map<int, bool> m;
//        tot = score(c + 21);
//        m[c+21] = 1;
//        if (!m[c-21]) tot += score(c-21);
//        m[c-21] = 1;
//        if (!m[-c-21]) tot += score(-c-21);
//        m[-c-21] = 1;
//        if (!m[-c+21]) tot += score(-c+21);
//        if (tot == 12) ++ans;
//        if (tot == 12) {
//            cout << c << " NICE " << endl;
//        }
//    }
    
    long double eps = 1e-3;
    
    for (long double i = 1; i < 1000; ++i) {
        for (long double j = 1; j < 1000; ++j) {
//            if (abs(i/j - 26.25228415) < .5) cout << i << ' ' << j << endl;
            if (abs( (i/j) - 26.25228415) < eps) {
                cout << i << ' ' << j << endl;
                //break;
            }
        }
    }
        
//    ll num = 2020;
//    ll den = 2021;
//    ans = 1;
//    
//    for (int i = 1; i < 100000; ++i) {
//        num += 18;
//        den += 19;
//        ll d = gcd(num, den);
//        num /= d;
//        den /= d;
//        if (num == den-1) ++ans, cout << num << ' ' << den  << ' ' << i << endl;
//    }
    
//    ll a = 4, b = 8, c = 12;
//    
//    long double tot = 0;
//    
//    for (int i = 0; i < 1000000000; ++i) {
//        ll reps = 0;
//        while (1) {
//        if (rand() & 1) --a;
//        else ++a;
//        if (rand() & 1) --b;
//        else ++b;
//        if (rand() & 1) --c;
//        else ++c;
//        
//        a = ((a + 11) % 12) + 1;
//        c = ((c + 11) % 12) + 1;
//        b = ((b + 11) % 12) + 1;        
//        ++reps;
//        if (a == b || b == c || c == a) break;
//        }
//        if (i % 100000 == 0) cout << i << endl;
//        tot += reps;
//    }
//    cout << setprecision(12) << tot << ' ' << tot/1e9 << endl;
    cout << ans << endl;
    return 0;
}