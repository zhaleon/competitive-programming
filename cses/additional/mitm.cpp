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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

int N, X;
int arr[41];

ll one[(1 << 20)+1];
ll two[(1 << 20)+2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> X;
    rep(i,1,N+1) cin >> arr[i];
    
    memset(two, 0x3f, sizeof(two));
    
    rep(i,1,(1 << min(20, N))) {
        
        int k = i;
        int j = min(20, N);
        ll cur = 0;
        while (k) {
            if (k & 1)
                cur += arr[j];
            
            j--;
            k >>= 1;
        }
        one[i] = cur;
        
    }
    
    if (N <= 20) {
        int res = 0;
        rep(i,1,(1 << 20))
            res += (one[i] == X);
        cout << res << endl;
        return 0;
    }
    
    rep(i,1,(1 << (N-20))) {
        
        int k = i;
        int j = N;
        
        ll cur = 0;
        
        while (k) {
            if (k & 1)
                cur += arr[j];
            
            j--;
            k >>= 1;
        }
        
        two[i] = cur;
    }
    
    sort(one+1, one+(1 << 20));
    sort(two+1, two+(1 << (N-20)));
    
    int p = (1 << (N-20));
    ll ans = 0;
    two[0] = 0;
    rep(i,0,(1 << 20)) {
        ll inc = 0, mult = 1;
        
        while (p >= 0 && one[i] + two[p] >= X) {
            if (one[i] + two[p] == X)
                inc++;
            p--;
        }
        
        //if (i < 12) cout << ans << ' ' << i << ' ' << one[0] << ' ' << one[1] << ' ' << p << ' ' << inc << endl;
        
        while (one[i] == one[i+1]) {
            i++;
            mult++;
        }
        
        ans += inc * mult;
        
    }
    
    cout << ans << endl;
    
    return 0;
}