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
int T, N, K;

ll A[100001];
ll B[100001];

void fill_set(mll &posA, mll &posB, mll &negA, mll &negB) {
    rep(i,1,N) {
        if (A[i] < 0) negA.insert(A[i]);
        else posA.insert(A[i]);

        if (B[i] < 0) negB.insert(B[i]);
        else posB.insert(B[i]);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;

    rep(Case,1,T) {
        cin >> N >> K;
        rep(i,1,N) cin >> A[i];
        rep(i,1,N) cin >> B[i];

        multiset<ll> posA, posB;
        multiset<ll> negA, negB;
        
        sort(A+1, A+1+N);
        sort(B+1, B+1+N);

        ll big = 0;
        ll small = 0; 

        fill_set(posA, posB, negA, negB);
        ll score = 0;
        rep(i,1,K) {
            ll cur_pos = -INF;
            ll cur_neg = -INF;
            ll pos = -INF;
            ll neg = -INF;

            if (posA.size() && negB.size()) pos = *posA.begin() * *negB.rbegin(); 
            if (negA.size() && posB.size()) neg = *posB.rbegin() * *negA.rbegin();

            if (posA.size() && posB.size()) cur_pos = *posA.rbegin() * *posB.rbegin(); 
            if (negA.size() && negB.size()) cur_neg = *negA.rbegin() * *negB.rbegin();

            if ((cur_pos == -INF && cur_neg == -INF)) {
                if (pos > neg) {
                    score += pos;
                    posA.erase(posA.begin());
                    negB.erase(--negB.end());
                } else {
                    score += neg;
                    posB.erase(posB.begin());
                    negA.erase(--negA.end());
                }
            } else {

                if (cur_pos > cur_neg) {
                    score += cur_pos;
                    posA.erase(--posA.end());
                    posB.erase(--posB.end());
                } else {
                    score += cur_neg;
                    negA.erase(--negA.end());
                    negB.erase(--negB.end());
                }
            }
        }
        big = score, score = 0; 

        posA.clear(), posB.clear(), negA.clear(), negB.clear();
        fill_set(posA, posB, negA, negB);

        rep(i,1,K) {
            ll cur_pos = INF;
            ll cur_neg = INF;
            ll pos = INF;
            ll neg = INF;

            if (posA.size() && negB.size()) cur_pos = *posA.begin() * *negB.begin(); 
            if (negA.size() && posB.size()) cur_neg = *negA.begin() * *posB.begin();

            if (posA.size() && posB.size()) pos = *posA.begin() * *posB.begin(); 
            if (negA.size() && negB.size()) neg = *negA.rbegin() * *negB.rbegin();

            if ((cur_pos == INF && cur_neg == INF)) { 
                if (pos < neg) {
                    score += pos;
                    posA.erase(posA.begin());
                    posB.erase(posB.begin());
                } else {
                    score += neg;
                    negA.erase(--negA.end());
                    negB.erase(--negB.end());
                }
            } else {
                if (cur_pos < cur_neg) {
                    score += cur_pos;
                    posA.erase(posA.begin());
                    negB.erase(negB.begin());
                } else {
                    score += cur_neg;
                    negA.erase(negA.begin());
                    posB.erase(posB.begin());
                }
            }
        }
        small = score;
        cout << "Case #" << Case << ": " << small << ' ' << big << endl;
    }

    
    return 0;
}








