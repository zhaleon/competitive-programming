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

multiset<int> high;
multiset<int, greater<int>> low;

void balance() {
	if (low.size() > high.size() + 1) {
		high.insert(*low.begin());
		low.erase(low.begin());
	} else if (high.size() > low.size() + 1) {
		low.insert(*high.begin());
		high.erase(high.begin());
	}
}

void add(int X) {
	if (low.empty() || X <= *low.begin()) low.insert(X);
	else high.insert(X);
	balance();
}

void remove(int X) {
	if (high.find(X) != high.end()) high.erase(high.find(X));
	else low.erase(low.find(X));
	balance();
}

int median() {
	if (high.size() == low.size()) return min(*low.begin(), *high.begin());
	return (low.size() < high.size()) ?  *high.begin() : *low.begin();
}

int arr[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	rep(i,0,N) cin >> arr[i];
	
	rep(i,0,K) add(arr[i]);	
	cout << median() << ' ';
	
	rep(i,K,N) {
		remove(arr[i-K]);
		add(arr[i]);
		cout << median() << ' ';
	}

    
    return 0;
}








