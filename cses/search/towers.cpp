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
int towers[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	memset(towers, 0x3f, sizeof(towers));

	int num_towers = 1;
	rep(i,0,N) {
		int t; cin >> t;
		
		int low = 0, high = num_towers + 1;
		
		while (low < high) {
			int mid = (low+high)/2;
			
			if (towers[mid] <= t) low = mid+1;
			else high = mid;
		}

		if (low < num_towers) towers[low] = t;
		else towers[num_towers++] = t;
	}
   	cout << num_towers << endl; 
    return 0;
}








