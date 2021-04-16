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
int arr[30001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];

		int aa = 0, bb = 0, cc = 0;
		int ans = INF;
		rep(i,1,N) {
			if (arr[i] % 3 == 0) ++aa;
			else if (arr[i] % 3 == 1) ++bb;
			else ++cc;
		}
		// 0 2 2 2 1 2
		
			int k,a,b,c;
			a = aa, b = bb, c = cc;
			k = 0;
			rep(i,1,5) {
				if (a > N/3) k += a - N/3, b += a - N/3, a = N/3; 
				if (b > N/3) k += b - N/3, c += b - N/3, b = N/3;
				if (c > N/3) k += c - N/3, a += c - N/3, c = N/3;
			}
			ans = min(k, ans);

			k = 0;
			a = aa, b = bb, c = cc;
			rep(i,1,5) {
				if (b > N/3) k += b - N/3, c += b - N/3, b = N/3;
				if (c > N/3) k += c - N/3, a += c - N/3, c = N/3;
				if (a > N/3) k += a - N/3, b += a - N/3, a = N/3;
			}
			ans = min(k, ans);

			k = 0;
			a = aa, b = bb, c = cc;
			rep(i,1,5) {
				if (c > N/3) k += c - N/3, a += c - N/3, c = N/3;
				if (a > N/3) k += a - N/3, b += a - N/3, a = N/3;
				if (b > N/3) k += b - N/3, c += b - N/3, b = N/3;
			}
			ans = min(k, ans);



		cout << ans << '\n';
	}
    
    return 0;
}








