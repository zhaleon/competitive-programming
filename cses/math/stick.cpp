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

int N, K;
int sticks[100];
bool win[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	rep(i,0,K) cin >> sticks[i];
   
	rep(i,1,N+1) 
		rep(j,0,K) 
			if (i >= sticks[j])
				win[i] |= !win[i-sticks[j]];
	
	rep(i,1,N+1)
		if (win[i])
			cout << 'W';
		else
			cout << 'L';

	

    return 0;
}








