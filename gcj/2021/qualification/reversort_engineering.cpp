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

int T, N, C;
bool possible[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    possible[0] = 1;
    rep(j,1,100) {
        for (int i = 1001; i >= j; --i) {
            possible[i] |= possible[i-j];
        }
    }

    rep(Case,1,T) {
        cin >> N >> C;

        cout << "Case #" << Case << ": ";
       
        vector<int> nums(N);
        iota(nums.begin(), nums.end(), 1);

        bool ok = true;
        do {
            vector<int> arr;
            for (int i = 0; i < N; ++i) arr.PB(nums[i]);
            vector<int> aa = arr;
            int ans = 0;

            rep(i,0,N-2) {
                auto it = min_element(arr.begin()+i, arr.end());
                ans += 1 + distance(arr.begin()+i, it);
                reverse(arr.begin()+i, it+1); 
            }

            if (ans == C) {
                rep(i,0,N-1) cout << aa[i] << ' '; 
                cout << endl;
                ok = false;
                break;
            }

        } while (next_permutation(nums.begin(), nums.end()));
        if (ok) cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}








