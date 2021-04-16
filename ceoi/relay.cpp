#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

int N, M;

pii ship[100001];
pii poly[100001];

int is_left(pii point, pii a, pii b) { //check point against line a-->b
    b.F -= a.F, point.F -= a.F;
    b.S -= a.S, point.S -= a.S;
    int det = b.F * point.S - b.S * point.F;
    if (det > 0) return 1; //left
    if (det < 0) return -1; //to the right
    return 0; //colinear
}

double dist(pii a, pii b) {
    return sqrt((b.F-a.F)*(b.F-a.F) + (b.S-a.S)*(b.S-a.S));
}

int left = 1, right = 1;

void find_tangents() {
    rep(i,2,M+1) {
        int place = is_left(poly[i], ship[1], poly[left]);
        if (place > 1) left = i;
        else if (place == 0) left = (dist(ship[1], poly[left]) < dist(ship[1], poly[i])) ? left : i;
        
        place = is_left(poly[i], ship[1], poly[right]);
        if (place < 1) right = i;
        else if (place == 0) right = (dist(ship[1], poly[right]) < dist(ship[1], poly[i])) ? right : i;
    }
    rep(i,2,M+1) if (!reachable[i]) {
        
    }
}

bool reachable[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i,1,N+1) cin >> ship[i].F >> ship[i].S;
    
    cin >> M;
    rep(i,1,M+1) cin >> poly[i].F >> poly[i].S;
    
    find_tangents(); // to ship 1
    
    int ans = 0;
    reachable[1] = 1;
    
    rep(i,2,M+1) if (is_left(ship[i], ship[1], poly[left]) >= 0) reachable[i] = 1, ans++;
    rep(i,2,M+1) if (is_left(ship[i], ship[1], poly[right]) >= 0 && !reachable[i]) reachable[i] = 1, ans++;
    
    

    return 0;
}