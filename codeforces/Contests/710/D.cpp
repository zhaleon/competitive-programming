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
int arr[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;
        rep(i,1,N) cin >> arr[i];
        sort(arr+1, arr+1+N);
        
        int L = 1, R = 2; 
        int ans = N;

        while (L < N && R < N) {
            while (L < N && arr[L] == arr[L+1]) ++L; 
            while (R <= L && R <= N) ++R;
        }

        cout << ans << endl;
    }
    
    return 0;
}








