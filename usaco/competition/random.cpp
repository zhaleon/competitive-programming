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
#define rep(i,a,b) for (int i = a; i <= b; i++)

template<typename Numeric, typename Generator = std::mt19937>
Numeric random(Numeric from, Numeric to)
{
    thread_local static Generator gen(std::random_device{}());

    using dist_type = typename std::conditional
    <
        std::is_integral<Numeric>::value
        , std::uniform_int_distribution<Numeric>
        , std::uniform_real_distribution<Numeric>
    >::type;

    thread_local static dist_type dist;

    return dist(gen, typename dist_type::param_type{from, to});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    long double num_trials = 1e8;
    long double good = 0;
    
    for (ll trial = 0; trial < num_trials; ++trial) {
        long double ax = random<long double>(-1,1);
        long double ay = sqrt(1-ax*ax);
        
        long double bx = random<long double>(-2,2);
        long double by = sqrt(1-bx*bx);
        
        long double cx = random<long double>(-4,4);
        long double cy = sqrt(1-cx*cx);
        
        long double dx = ax + bx + cx;
        long double dy = ay + by + cy;
        
        if (dx*dx + dy*dy < 25 + 1e-9) ++good;
    }
    
    cout << setprecision(7) << good/num_trials << endl;
    
    
    return 0;
}