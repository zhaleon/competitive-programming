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

int T, P;
string scores[101];
int pd[10000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    rep(Case,1,T) {
        memset(pd, 0, sizeof pd);
        cin >> P;
        rep(i,1,100) cin >> scores[i];

        int best_score = -1;
        int best_player = 0;

        for (int i = 0; i < 10000; ++i) {
            for (int j = 1; j <= 100; ++j) {
                pd[i] += scores[j][i] == '1'; 
            }
        }

        rep(i,1,100) {
            int cur_score = 0;
            for (int j = 0; j < 10000; ++j) 
                if (scores[i][j] == '1')
                    cur_score += sqrt(pd[j]); 

            if (cur_score > best_score) {
                best_score = cur_score;
                best_player = i;
            }
            /* printf("Player %i score: %i\n", i, cur_score); */
        }
        /* printf("Case #%i: %i\n", Case, best_player); */
        cout << "Case #" << Case << ": " << best_player << '\n';
    }
    
    return 0;
}








