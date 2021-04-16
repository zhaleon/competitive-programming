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
#define rep(i,a,b) for (int i = a; i <= b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}


int N;
int code[200001];
int freq[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N-2) cin >> code[i];


	deque<int> d;
	map<int, int> s;
	set<int> not_in_code;

	rep(i,1,N-2) {
		d.PB(code[i]);
		freq[code[i]]++;
	}
	
	
	rep(i,1,N)
		if (!freq[i])
			not_in_code.insert(i);


	rep(i,1,N-2) {
		cout << d.front() << ' ' << *not_in_code.begin() << endl;
		d.push_back(*not_in_code.begin());
	
		freq[d.back()]++;
		freq[d.front()]--;
		int k = d.front();
		
		d.pop_front();
		
		not_in_code.erase(not_in_code.begin());
		
		if (freq[k] == 0)
			not_in_code.insert(k);
	}

	rep(i,1,N) 
		if (!freq[i]) cout << i << ' ';

    return 0;
}








