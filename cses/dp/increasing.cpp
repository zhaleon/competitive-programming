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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N;
int arr[200001];

int best[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N+1) cin >> arr[i];
	
	memset(best, 0x3f, sizeof(best));
	best[0] = 0;

	int longest = 0;

	rep(i,1,N+1) {
		int low = 0, high = longest+1;

		while (low < high) {
			int mid = (low + high + 1)/2;
			if (best[mid] < arr[i]) low = mid;
			else high = mid-1;
		}
		longest += (low+1) > longest;
		best[low+1] = min(best[low+1], arr[i]);
	}
	
	cout << longest << endl;

    return 0;
}








