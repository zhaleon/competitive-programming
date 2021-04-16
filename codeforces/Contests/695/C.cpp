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

int size[4];
vector<ll> bags[4];
ll sum = 0;
ll ans = -1e18;

int main() {

	cin >> size[1] >> size[2] >> size[3]; 
	
	rep(i,1,3) {
		bags[i].assign(size[i]+1, 0);
		rep(j,1,size[i]) {
			cin >> bags[i][j];
			sum += bags[i][j];
		}
		sort(bags[i].begin()+1, bags[i].end());
	}

	ans = max(ans, sum - 2 * (bags[1][1] + bags[2][1]));	
	ans = max(ans, sum - 2 * (bags[1][1] + bags[3][1]));	
	ans = max(ans, sum - 2 * (bags[2][1] + bags[3][1]));	

	rep(i,1,3) {
		ll small_sum = 0;
		rep(j,1,size[i])
			small_sum += bags[i][j];

		ans = max(ans, sum - 2 * small_sum);
	}

	cout << ans << endl;
	return 0;
}
