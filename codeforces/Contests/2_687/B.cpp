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

int c[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> K;
		rep(i,1,N+1) cin >> c[i];
		int ans = 0;
		
		int fir = c[1];
		for (int p = 1; p <= N; p++) {
			while (p <= N && c[p] == fir) {
				p++;
			}
			ans++;
			p += K-1;
			
		}
		cout << ans << endl;
	}
    
    return 0;
}








