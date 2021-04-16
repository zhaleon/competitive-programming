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
int N;
int arr[200001];

int best[200001];
int freq[200001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while(T--) {
		memset(best, 0, sizeof(best));
		memset(freq, 0, sizeof(freq));

		cin >> N;
		rep(i,1,N) cin >> arr[i];

		sort(arr+1, arr+1+N);

		rep(i,1,N) ++freq[arr[i]];

		for (int small = 200000; small > 0; --small) {
			best[small] = N; 

			for (int i = small*2; i <= 200000; i += small) best[small] = min(best[small], best[i]);

			best[small] -= freq[small]; 
		}

		cout << *min_element(best+1, best+200001) << endl;
	}
    
    return 0;
}








