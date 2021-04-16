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
int arr[200001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> arr[i];

		vi odd;
		vi even;

		rep(i,1,N) {
			if (arr[i] & 1) odd.PB(arr[i]);
			else even.PB(arr[i]);
		}

		sort(odd.begin(), odd.end(), greater<int>());
		sort(even.begin(), even.end(), greater<int>());

		ll dif = 0;
		int l = 0, r = 0;
		rep(i,1,N) {
			if ((i & 1) == 0) {
				if (l < odd.size() && r < even.size()) {
					if (odd[l] > even[r])
						dif -= odd[l++];
					else 
						++r;
				} else if (l < odd.size()) {
					dif -= odd[l++];
				} else {
					++r;
				}
			} else {
				if (l < odd.size() && r < even.size()) {
					if (even[r] > odd[l])
						dif += even[r++];
					else ++l;
				} else if (l < odd.size()) {
					++l;
				} else {
					dif += even[r++];
				}
			}
		}
		
		if (dif > 0) 
			cout << "Alice\n";
		else if (dif < 0)
			cout << "Bob\n";
		else 
			cout << "Tie\n";
	}
    
    return 0;
}








