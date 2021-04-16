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

int arr[200000];
int freq[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;

	rep(i,0,N) cin >> arr[i];
   	
	memset(freq, 0, sizeof(freq));

	rep(i,0,N) freq[arr[i]]++;

	for (int i = 1e6; i > 0; i--) {
		int res = 0;
		for (int j = i; j <= 1000000; j += i) res += freq[j];
		if (res > 1) {
			cout << i << endl;
			return 0;
		}
	}
    return 0;
}








