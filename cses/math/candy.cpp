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
double K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	double ans = 0; 

	rep(i,1,K+1) {
		ans += i * (pow(i/K, N) - pow((i-1)/K, N));	
	}

	cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}








