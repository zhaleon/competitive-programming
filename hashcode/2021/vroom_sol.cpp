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

unordered_map<string, int> m; // string -> id
unordered_map<int, string> mrev; //id -> string
// name -> street id
 



typedef struct intersection {
	int ind;
  	vpi in_streets; // streets coming in
    vpi out_streets; // streets coming out
    void init(int _ind) {
    	ind = _ind;
    }
  
  	vpi submit; // street, time
  
  	void add(int street, int time) {
      submit.PB(MP(street, time));
    }
  
} intersection;
vector<intersection> intersections;

void print() {
	cout << I << '\n'; // it doesn't hurt to print for each intersection even if we have nothing right?
  	for(int i = 0; i < I; i++) {
      cout << i << '\n'; // which intersection
      cout << (int)intersections[i].submit.size() << '\n'; // how many streets will we print for
      for(auto& x: intersections[i].submit) {
         cout << mrev[x.F] << " " << x.S << '\n'; // street name, length
      }
    }
}

typedef struct street {
    /* beginning
     * ending
     * length
     * name
     */
    int B, E, L, id; 
    string name;

    int mx;
    int median;
    int mean;


    vi count;

    void read() { 
      cin >> B >> E >> name >> L; 
      id = ++id_count; 
      intersections[B].out_streets.push_back(MP(id, L));
      intersections[E].in_streets.push_back(MP(id, L));
      count.assign(D + 5, 0);
    }
    street() {};


    void statistics() {
      sort(count.begin(), count.end());
      mx = count.back();
      median = count[(int)count.size()/2];
      mean = accumulate(all(count), 0ll)/(int)count.size();
    }
  
} street; 

vector<street> streets;


void init() {
	streets.resize(1); 
  	intersections.resize(I);
  	for(int i = 0; i < I; i++) {
      intersections[i].init(i);
    }
    m.reserve(S);
    mrev.reserve(S);
}
   
typedef struct car {
    int P;
    vector<int> path;
  	int total_path_length = 0;
    void read() {
        cin >> P;
        string s;
        for (int i = 0; i < P; ++i) {
            cin >> s;
            path.push_back(m[s]);
            total_path_length += streets[m[s]].L;
        }  
    }
    car() {};
  	bool operator<(const car& o) const {
        return total_path_length < o.total_path_length;
    }
  
} car;
vector<car> cars;
 
void simulate() {
  // figure out how long it takes each car to travel to the end
  // i dont think we can calculate individually, so we should probably simulate, cuz cars affect each other :eyes:
  // event can be described by time, which car, which street are we on, type of event
  // bruhhh we have to make a comparison for this as well
  
  // ok ig we can combine this with the actual simulation instead of using as just a checker
  // at each node, send the car who needs to travel furthest now

  vector<queue<pii>> poss; // represents the queues at the signals

  poss.resize(S + 1);

  for(int i = 0; i < V; i++) {
    int start = cars[i].path[0];
    poss[start].push(MP(i, 0));
  }

  vector<vector<pair<pii, int>>> events(D + 1);

  // events stores when cars go in ig :thinking:, if that makes sense

  for(int i = 0; i <= D; i++) {
    for(auto& x: events[i]) {
      poss[x.S].push(x.F);
    }
    for(int j = 1; j <= S; j++) {
      streets[j].count[i] = poss[i].size();
    }
    for(int j = 0; j < I; j++) {
      int roads = (int)intersections[j].in_streets.size();
      // at time i, we will be vibing with in_streets[(i - 1 + roads)%roads]
      int look = intersections[j].in_streets[(i - 1 + roads)%roads].F;
      if(poss[look].empty()) continue;
      auto frnt = poss[look].front();
      poss[look].pop();
      int car_ind = frnt.F;
      int car_iter = frnt.S;
      if(car_iter + 1 == cars[car_ind].P) continue;
      // this means the car is done
      int nxt = cars[car_ind].path[car_iter + 1];
      // we will be taking road nxt
      // we will reach the next sign at i + streets[nxt].L
      int reach = i + streets[nxt].L;
      if(reach > D) continue;
      // cuz its useless for our simulation
      events[reach].PB(MP(MP(car_ind, car_iter + 1), nxt));
    }
  }

  for(int i = 1; i <= S; i++) {
    streets[i].statistics();
  }

  for(int i = 0; i < I; i++) {
    vpi cur;
    for(auto& x: intersections[i].in_streets) {
      cur.PB(MP(streets[x.F].median, x.F));
      // intersections[i].add(x.F, streets[x.F].mx);
    }
    sort(cur.begin(), cur.end());
    for(int j = 0; j < (int)cur.size(); j++) {
      intersections[i].add(cur[j].S, sqrt(cur[j].F));
    }
  }

  print();

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> D >> I >> S >> V >> F; 
 
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

  	// sort(all(cars, 0)); //sort cars according to path lenght
    // for(auto i : cars){
    	
    // }
     return 0;
}
