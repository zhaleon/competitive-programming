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

int T, N;
int arr[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    arr[0] = INF;

    cin >> T;

    rep(Case,1,T) {
        cin >> N;
        rep(i,1,N) cin >> arr[i];
        int ans = 0;

        rep(i,1,N-1) {
            auto it = min_element(arr+i, arr+1+N); 
            ans += 1 + distance(arr+i, it);
            reverse(arr+i, it+1); 
        }
        printf("Case #%i: %i\n", Case, ans);
    }
    
    return 0;
}








