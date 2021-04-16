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
#define EB emplace_back
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int T, N;
int arr[101];
int freq[101];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		memset(freq, 0, sizeof(freq));
		rep(i,1,N) cin >> arr[i];
		rep(i,1,N) freq[arr[i]]++;

		cout << *max_element(all(freq)) << '\n';
	}
    
    return 0;
}








