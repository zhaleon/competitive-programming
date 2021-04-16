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

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		int n; string s;
		cin >> n >> s;
		int previous = -1;

		for (auto c : s) {
			int i = stoi(to_string(c));
			int k = 0;

			if (previous < 0)
				k = 1;
			else
				k = i != (previous-1);

			cout << k;

			previous = k + i;
		}

		cout << '\n';
	}
    
    return 0;
}








