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

int room[200001];

auto comp = [](pii a, pii b) -> bool {
	if (a.F == b.F) return a.S < b.S;
	return a.F > b.F; 
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	priority_queue<pii, vpi, decltype(comp)> pq(comp);

	rep(i,1,N+1) {
		int a, b; cin >> a >> b;
		pq.push(MP(a, i));
		pq.push(MP(b,-i));	
	}	

	int num_rooms = 0;
	set<int> rooms;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		//cout << "TEST: " << cur.F << ' ' << cur.S << endl;
		if (cur.S > 0) {
			if (rooms.empty()) {
				num_rooms++;
				room[cur.S] = num_rooms;
			} else {
				auto it = rooms.begin();
				room[cur.S] = *it;
				rooms.erase(it);
			}
		} else {
			rooms.insert(room[-cur.S]);
		}
	}
   	
	cout << num_rooms << endl;

	rep(i,1,N+1) cout << room[i] << ' ';


    return 0;
}








