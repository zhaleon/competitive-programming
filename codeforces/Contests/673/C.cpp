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

int T;

int n;

int arr[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


	cin >> T;

	while(T--) {
		cin >> n;
		rep(i,1,n+1) cin >> arr[i];

		

	}
    
    return 0;
}








