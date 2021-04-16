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
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int D, I, S, V, F;
int id_count = 0;

typedef struct intersection {
	int ind;
  	vector<string> in_streets; // streets coming in
 	vector<string> order;
	unordered_map<int, int> freq;
	unordered_map<int, ll> earliest_arrival;
} intersection;
vector<intersection> intersections;

typedef struct street {
	/* beginning
	 * ending
	 * length
	 * name
	 */
	int B, E, L, id; 
	string name;
	void read() { cin >> B >> E >> name >> L; id = ++id_count; intersections[E].in_streets.push_back(name);};
	street() {};
} street; 

vector<street> streets(1);
unordered_map<string, int> m;
unordered_map<int, string> mrev;

// name -> street id

typedef struct car {
	int P, cur_loc = 0;
	long long total_path_length = 0;
	vector<int> path;
	void read() {
		cin >> P;
		string s;
		for (int i = 0; i < P; ++i) {
			cin >> s;
			auto it = intersections[streets[m[s]].E].earliest_arrival.find(m[s]);
			if (it == intersections[streets[m[s]].E].earliest_arrival.end()) intersections[streets[m[s]].E].earliest_arrival[m[s]] = total_path_length;
			else it->S = max(it->S, total_path_length);
			total_path_length += streets[m[s]].L;
			path.push_back(m[s]);
		}
	}

	bool operator<(const car& o) const {
		return total_path_length < o.total_path_length;
	}

	car() {};	
} car;

struct comp {
	bool operator()(car a, car b) const {
		return a.total_path_length > b.total_path_length;
	}
};


void print() { // just try stuff to get points
	/* cout << I << '\n'; */ 
	vi good_roads;
  	for(int i = 0; i < I; i++) {
		/* cout << i << '\n'; */ 
		vector<string> ans;	
		for (auto name : intersections[i].in_streets) if (intersections[i].freq[m[name]] > 0) ans.PB(name); 
		if (ans.size()) good_roads.PB(i);	
		/* for (auto name : ans) cout << name << ' ' << 1 + (int(sqrt(intersections[i].freq[m[name]])))%D << '\n'; */

		/* for (auto &name : intersections[i].in_streets) { */
		/* 	cout << name << ' ' << 1 + (int(sqrt(intersections[i].freq[m[name]])))%D << '\n'; */
		/* 	/1* cout << name << ' ' << 1 << '\n'; *1/ */
		/* } */
    }

	cout << good_roads.size() << endl;

	auto comp = [](string a, string b) {
		return intersections[streets[m[a]].E].earliest_arrival[m[a]] > intersections[streets[m[b]].E].earliest_arrival[m[b]];		
	};

	for (int i : good_roads) {
		cout << i << '\n'; 
		vector<string> ans;	
		int j = 0;
		for (auto name : intersections[i].in_streets) if (intersections[i].freq[m[name]] > j) ans.PB(name); 
		cout << ans.size() << '\n';
		/* shuffle(ans.begin(), ans.end(), default_random_engine(69)); */
		sort(all(ans,0), comp);
		for (auto name : ans) {
			int k = cbrt(intersections[i].freq[m[name]]);
			if (ans.size() < INF) k = 1;
			cout << name << ' ' << k << '\n';
		}
	}
}

void init() {
	streets.resize(1); 
  	for(int i = 0; i < I; i++) {
		intersection k;
		k.ind = i;
		intersections.push_back(k);
    }
    m.reserve(S);
}

vector<car> cars;
void simulate() {

	for (car x : cars) {
		for (int cur_street : x.path) {
			++intersections[streets[cur_street].E].freq[cur_street];
		}
	}

	for (intersection &x : intersections) {
		vector<string> order;
		map<int, vi> f;
		for (pii road : x.freq) {
			f[road.S].PB(road.F);
		}
		for (auto it : f) {
			for (auto id : it.S) {
				order.PB(mrev[id]);
			}
		}
		x.order = order;
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> D >> I >> S >> V >> F; 

	m.reserve(S);
	init();
	for (int i = 0; i < S; ++i) {
		street cur_street;
		cur_street.read();
		streets.push_back(cur_street);
		m[cur_street.name] = id_count;
		mrev[id_count] = cur_street.name;
	}


	for (int i = 0; i < V; ++i) {
		car cur_car;
		cur_car.read();
		cars.push_back(cur_car);
	}
		
	simulate();
	print();

    return 0;
}
