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
		if (N == 1) {
			cout << 9 << '\n';
		} else {
			string s = "98";
			int j = 100009;
			for (int i = 2; i < N; i++) {
				s += to_string(j++ % 10);
			}
			cout << s << '\n';
		}
	}
    
    return 0;
}








