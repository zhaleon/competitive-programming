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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int T;

int N, K;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	for (int Case = 1; Case <= T; Case++) {
		cin >> N >> K;
		vpi times;
		rep(i,1,N+1) {
			int a, b;
			cin >> a >> b;
			times.emplace_back(a, -i);
			times.emplace_back(b, i);
		}
		sort(times.begin(), times.end());
		
		int ans = 0;
		int segments = 0, last_robot = -INF;
		for (auto event : times) {
			if (event.S < 0) {
				if (segments == 0 && last_robot < event.F) {
					last_robot = event.F;
				}
				segments++;
			} else {
				if (segments == 1 && last_robot < event.F) {
					ans += (event.F-last_robot)/K+1;
					if ((event.F-last_robot) % K == 0) ans--, last_robot-=K;
					last_robot += (event.F-last_robot)/K * K + K;
				}
				segments--;
			}
			//cout << event.F << ' ' << ans << endl;
		}
		printf("Case #%i: %i\n", Case, ans);
	}
    
    return 0;
}








