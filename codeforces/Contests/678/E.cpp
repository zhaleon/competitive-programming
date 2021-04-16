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
int arr[100001];

bool comp(pii a, pii b) {
	if (a.F == b.F) return a.S < b.S;
	return a.F < b.F;
}

int bit[100001];

void upd(int pos) {
	while (pos < N+1) {
		bit[pos]++;
		pos += pos & -pos;
	}
}

int sum(int i) {
	int res = 0;
	while (i) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int sum(int i, int j) {
	return sum(j) - sum(i-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,1,N+1) cin >> arr[i];
    
	vpi index;

	rep(i,1,N+1) index.PB(MP(arr[i],i));
	
	sort(index.begin(), index.end(), comp);

	for (int i = 0; i < N; i++) {
		int cur = index[i].F, past = 1;
		upd(index[i].S);
		while (i+1 < N && index[i+1].F == index[i].F) {
			i++;
			upd(index[i].S);
					
		}
	}

    return 0;
}








