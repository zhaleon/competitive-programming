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

int N, K, M;

int arr[51];


int main() {
	
	cin >> T;

	for (int Case = 1; Case <= T; Case++) {
		cin >> N >> M >> K;
		
		rep(i,1,K+1) cin >> arr[i];
		rep(i,1,K+1) arr[i]--;		
		double ans = 0;
		for (double i = 0; i < K; i++) ans += M/(M-i);
			
		int delta = 0;
		double distinct = K;
		int seen = 0;
		
		//rep(i,1,K+1) if (!arr[i]) seen++, --distinct;

		cout << "ANS: " << ans << endl;
		for (int roll = K; roll < N; roll++) {
			int small = INF;
			for (int i = 1; i <= K; i++) {
				if (arr[i] > 0)
				small = min(small, arr[i]);
			}
			ans += ((M)/K)*(small - delta);

			for (int i = 1; i <= K; i++) if (arr[i] == small) {
				arr[i] = 0;
				seen++;
				--distinct;
			}
			if (!distinct) break;
			delta = small;
		}	

		printf("Case #%i: %f\n", Case, ans);
	}
    
    return 0;
}








