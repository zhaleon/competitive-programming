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
 
ll N, K;

ll bigger = 0, lower = 0;

multiset<ll> high;
multiset<ll, greater<ll>> low;
 
void balance() {
	if (low.size() > high.size() + 1) {
		bigger += *low.begin();
		lower -= *low.begin();
		high.insert(*low.begin());
		low.erase(low.begin());
	} else if (high.size() > low.size()) {
		bigger -= *high.begin();
		lower += *high.begin();
		low.insert(*high.begin());
		high.erase(high.begin());
	}
}
 
ll median() {
	return (low.size() < high.size()) ?  *high.begin() : *low.begin();
}

void add(int X) {
	if (low.empty() || X <= median()) low.insert(X), lower += X;
	else high.insert(X), bigger += X;
	balance();
}
 
void remove(int X) {
	if (high.find(X) != high.end()) high.erase(high.find(X)), bigger -= X;
	else low.erase(low.find(X)), lower -= X;
	balance();
}
 
 
int arr[200000];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
	cin >> N >> K;
 
	rep(i,0,N) cin >> arr[i];
	
	rep(i,0,K) add(arr[i]);	
	cout << bigger - lower + ((K & 1) ? median() : 0) << ' '; 
	
	rep(i,K,N) {
		remove(arr[i-K]);
		add(arr[i]);
		cout << bigger - lower + ((K & 1) ? median() : 0) << ' '; 
	}
 
    
    return 0;
}







