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
ll N, P, K;
ll x, y;

string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> P >> K >> s >> x >> y;
		
		queue<int> q;
		for (int j = P-1; j < K+P-1 && j < N; j++) q.push(j);
		
		ll ans = 1e15;

		while (q.size()) {
			int j = q.front(); q.pop();
			
			if (j + K < N && s[j] == '0' && K * y < x) {
				q.push(j + K);
				continue;
			}

			ll score = y * (j + 1 - P);  
			ll start = score;
			for (int i = j; i < N; i += K) {
				if (y * (i + 1 - P) < score) score = y * (i + 1 - P); 
				score += x * (s[i] == '0');	
			}

			ans = min(ans, score);
		}

		cout << ans << endl;

	}
    
    return 0;
}








