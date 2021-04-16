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

int n[5];
int m[4];

int a[150001];
int b[150001];
int c[150001];
int d[150001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    rep(i,1,4) cin >> n[i];

    rep(i,1,n[1]) cin >> a[i];
    rep(i,1,n[2]) cin >> b[i];
    rep(i,1,n[3]) cin >> c[i];
    rep(i,1,n[4]) cin >> d[i];

    cin >> m[1];
    rep(i,1,m[1]) {

    }
    
    return 0;
}








