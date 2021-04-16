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
#define rep(i,a,b) for (int i = a; i <= b; i++)

int T, N;
int arr[200001];
ll best[200001];
bool v[200001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];
		rep(i,1,N) v[i] = 0, best[i] = 0;

		ll ans = 0;
	
		for (int i = N; i > 0; i--) {
			ll score = arr[i];

			if (i + arr[i] <= N)
				score += best[i + arr[i]];
			
			best[i] = score;

			ans = max(ans, score);
		}

		cout << ans << endl;
	}
    
    return 0;
}








