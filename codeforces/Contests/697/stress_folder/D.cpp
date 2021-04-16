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

int T;
int N, M;

ll a[200001];
ll b[200001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> M;
		rep(i,1,N) cin >> a[i];
		rep(i,1,N) cin >> b[i];

		if (accumulate(a+1,a+1+N,0ll) < M) {
			cout << -1 << '\n';
			continue;
		}

		vector<ll> ones(1,0), twos(1,0), psums;

		rep(i,1,N) {
			if (b[i] == 1) ones.PB(a[i]);
			else twos.PB(a[i]);
		}

		sort(ones.begin()+1, ones.end(), greater<ll>());
		sort(twos.begin()+1, twos.end(), greater<ll>());

		psums.resize(twos.size());
		partial_sum(twos.begin(), twos.end(), psums.begin());
		
		int p = psums.size(), sum = 0, ans = INF;
		psums.PB(-1e18);

		rep(i,0,ones.size()-1) {
			sum += ones[i];

			while (p > 0 && psums[p-1] + sum >= M) --p;

			if (psums[p] + sum >= M) 
				ans = min(ans, i + p*2);
		}

		cout << ans << endl;
	}
    
    return 0;
}








