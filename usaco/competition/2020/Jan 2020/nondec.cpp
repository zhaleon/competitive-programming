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

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}
const ll mod = 1e9+7;
ll inv = (mod+1)/2;
int N, K, Q;
int arr[20001];

ll pref[20001][21][21];
ll invp[20001][21][21];

ll mats[21][21][21];
ll imats[21][21][21];

template<const size_t n = 21> void p(ll (&a)[n][n]) {
    cout << endl;
    rep(i,0,n-1) {
        rep(j,0,n-1) {
            cout << a[i][j] << ' ';
        } cout << endl;
    }
    cout << endl;
}

template<const size_t n = 21> void mult(ll (&a)[n][n], ll (&b)[n][n], int col = 0) {
    ll temp[n][n] = {0};

    if (col == 0) {
        rep(i,0,20) {
            rep(j,0,20) {
                rep(k,0,20) {
                    (temp[i][j] += a[i][k] * b[k][j] % mod) %= mod;
                }
            }
        }
        
        rep(i,0,20)
            rep(j,0,20)
                a[i][j] = temp[i][j];
        
    } else {
        rep(i,0,20) {
            rep(j,0,20) {
                (temp[i][col] += a[i][j] * b[j][col] % mod) %= mod;
            }
        }
        
        rep(i,0,20)
            a[i][col] = temp[i][col];
    }
}


void process() {
    rep(i,0,20) {
        
        rep(j,0,20)
            mats[i][j][j] = imats[i][j][j] = 1;
        
        rep(j,0,i) 
            mats[i][j][i]++;
        
        rep(j,0,i) {
            if (j == i) 
                imats[i][j][i] = inv;
            else 
                imats[i][j][i] = mod-inv;
        }
    }
    
    rep(i,0,20)  
        pref[0][i][i] = invp[0][i][i] = 1;
    
    rep(i,1,N) {
        rep(j,0,20) {
            rep(k,0,20) {
                pref[i][j][k] = pref[i-1][j][k];
                invp[i][j][k] = imats[arr[i]][j][k];
            }
        }
        
        mult(pref[i], mats[arr[i]], arr[i]);
        mult(invp[i], invp[i-1]);
        
        //p(invp[i]);
    }
}


int main() {
    setIO("nondec");
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    rep(i,1,N) cin >> arr[i];
    
    process();
    
//    p(mats[1]);
//    //mult(invp[2], pref[2]);
//    
//    p(pref[2]);
    
    cin >> Q;
    //Q = 0;
    rep(i,1,Q) {
        int a, b;
        cin >> a >> b;
        
        ll res[21][21] = {0};
        
        rep(j,0,20) res[j][j] = 1;
        
        mult(res, invp[a-1]);
        mult(res, pref[b]);
        
        ll ways = 0;
        
        rep(j,0,20) (ways += res[0][j]) %= mod;
        
        cout << (ways+mod)%mod << endl;
    }
    
    
    return 0;
}