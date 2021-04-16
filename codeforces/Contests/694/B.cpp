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

int T, N, X;
int arr[100001];
int mul[100001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> X;
		rep(i,1,N) cin >> arr[i];
		rep(i,1,N) mul[i] = 1; 

		ll res = 0;

		rep(j,1,31) {
			rep(i,1,N) {
				if (j == 1)
					res += arr[i];

				if (arr[i] % X != 0) {
					if (j == 1)
						rep(k,i+1,N)
							res += arr[k];
					j = 21;
					break;
				}
			
				arr[i] /= X;
				mul[i] *= X;
				res += arr[i] * mul[i];
			}
		}


		cout << res << endl;
	}
    
    return 0;
}








