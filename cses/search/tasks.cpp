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

pii arr[200000];

bool comp(pii a, pii b) {
	return a.F < b.F; 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,0,N) cin >> arr[i].F >> arr[i].S;
   
	sort(arr, arr+N, comp);

	ll t = 0, ans = 0;
	rep(i,0,N) {
		t += arr[i].F;
		ans += arr[i].S-t;
	}

	cout << ans << endl;
	
    return 0;
}








