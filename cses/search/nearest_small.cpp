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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
    rep(i,1,N+1) cin >> arr[i];

	stack<int> s;

	rep(i,1,N+1) {
		while (s.size() && arr[i] <= arr[s.top()]) s.pop();
		if (s.empty()) {
			printf("0 ");
			s.push(i);
			continue;
		}
		printf("%i ", s.top());
		s.push(i);
	}

    return 0;
}








