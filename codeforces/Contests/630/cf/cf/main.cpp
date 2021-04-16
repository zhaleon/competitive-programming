#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int> > vii;
typedef vector<pair<int, int> > vpi;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int t;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pair<ll, ll> d[80]; //even, odd
ll x[52];

const ll MOD = 998244353;

int main() {
    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    
    if ((R-L) % 2 == 0) {
        if (L % 2 == 0) {
            d[0].F = (R-L)/2+1;
            d[0].S = (R-L)/2;
        } else {
            d[0].F = (R-L)/2;
            d[0].S = (R-L)/2+1;
        }
    } else {
        d[0].F = (R-L+1)/2;
        d[0].S = (R-L+1)/2;
    }
    
    loop(i, 1, 61) {
        d[i].F = d[i-1].F * d[i-1].F + d[i-1].S * d[i-1].S;
        d[i].F %= MOD;
        d[i].S = d[i-1].S * d[i-1].F * 2;
        d[i].S %= MOD;
    }

    
    ll odd = d[0].S;
    ll even = d[0].F;
    ll t = 1;
    ll c = n*m;
    bool first = 1;
    for (ll i = 0; i < 61; i++) {
        if ((t << i) & c) {
            if (first) {
                first = false;
                odd = d[i].S;
                even = d[i].F;
            } else {
                ll temp = even;
                even = even*d[i].F + odd*d[i].S;
                //cout << odd << ' ' << even << ' ' << d[i].F << ' ' << d[i].S << endl;
                even %= MOD;
                odd = (d[i].F*odd + temp*d[i].S);
                odd %= MOD;
            }
        }
    } //cout << '\n';
//    cout << (n*m & (1<<33)) << endl;
    //cout << d[1].F << ' ' << d[1].S << endl;
    if (m*n % 2 == 1) {
        cout << (even + odd) % MOD << endl;
    } else {
        cout << even << endl;
    }
    
    return 0;
}



