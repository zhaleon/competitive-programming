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

int t, N;
int arr[101];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];

		int num_ones = 0, num_twos = 0;

		rep(i,1,N) {
			if (arr[i] == 1)
				num_ones++;
			else
				num_twos++;
		}

		if (num_twos % 2 == 1) {
			if (num_ones < 2)
				cout << "NO\n";
			else if (num_ones % 2 == 0) 
				cout << "YES\n";
			else
				cout << "NO\n";
		} else {
			if (num_ones % 2 == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}

	}
    
    return 0;
}








