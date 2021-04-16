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

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;

		//ax + by = c iff gcd(a,b) | c

		int K = N/2020;   // floor (N/2020)
		int J = N % 2020; // remainder 

		if (J <= K) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}








