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

int T, N, M;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> M;

		vpi things;

		rep(i,1,M) {
			int a, b;
			cin >> a >> b;
			things.emplace_back(b,a);
		}

		sort(things.begin(), things.end());

		bool seen = false;
		bool top_row = true;

		int col = 0;

		if (M % 2 == 1) {
			cout << "NO\n";
			continue;
		}

		int j = 0;
		rep(i,0,M-1) {
			if (i+1 < M && things[i+1].F == things[i].F) {
				if (seen) {
					cout << "NO\n";
					break;
				}
				j += 2;
				i++;
				continue;
			}

			if (seen) {
				bool bottom_row = things[i].S == 2;

				if (bottom_row == top_row && (things[i].F-col) % 2 == 1) {
					cout << "NO\n";
					break;
				} else if (bottom_row != top_row && (things[i].F-col) % 2 == 0) {
					cout << "NO\n";
					break;
				} else {
					seen = 0;
					j++;
					continue;
				}

			}

			top_row = things[i].S == 1;

			seen = true;
			col = things[i].F;
			j++;
		}

		if (j == M && !seen)
			cout << "YES\n";
		else if (j == M)
			cout << "NO\n";
	}
    
    return 0;
}








