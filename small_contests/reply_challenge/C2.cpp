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

typedef multiset<ll> mll;
multiset<ll> posA, posB, negA, negB;

int T, N, K;
ll A[100001];
ll B[100001];

void fillset(mll &posA, mll &posB, mll &negA, mll &negB) {
    posA.clear(), posB.clear(), negA.clear(), negB.clear();
    rep(i,1,N) {
        if (A[i] < 0) negA.insert(A[i]);
        else posA.insert(A[i]);
        if (B[i] < 0) negB.insert(B[i]);
        else posB.insert(B[i]);
    }
}

ll solve_min() {
    fillset(posA,posB,negA,negB);
    
    ll score = 0;
    rep(k,0,K-1) {
        if ( (posA.size() && negB.size()) || (posB.size() && negA.size()) ) {
            ll a = INF, b = INF;
            if (posA.size() && negB.size()) a = *posA.rbegin() * *negB.begin();
            if (posB.size() && negA.size()) b = *posB.rbegin() * *negA.begin();

            if (a < b) {
                score += a;
                posA.erase(--posA.end());
                negB.erase(negB.begin());
            } else {
                score += b;
                posB.erase(--posB.end());
                negA.erase(negA.begin());
            }
        } else {
            // K-k left
            ll a = INF, b = INF;
            if (posA.size() && posB.size())
        }
    }

    return score;
}

ll solve_max() {
    fillset(posA,posB,negA,negB);
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(Case,1,T) {
        cin >> N >> K;
        rep(i,1,N) cin >> A[i];
        rep(i,1,N) cin >> B[i];

    }
    
    return 0;
}








