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

ofstream fout ("real.txt");

double s[100];
double p[10000];

string output[100];

double sigmoid(double x) {
    return 1.0 / (1 + exp(-x));
}

void make_case(int Case, int P = 10) {
    cout << P << '\n';
    for (int i = 0; i < 100; ++i) 
        s[i] = random<double>(3,3);
    
    for (int i = 0; i < 10000; ++i) 
        p[i] = random<double>(3,3);

    int cheater = random<int>(1,100);

    for (int i = 0; i < 100; ++i) {
        output[i] = "";
        for (int j = 0; j < 100000; ++j) {
            if (i == cheater-1 && random<double>(0,1) < .5) {
                output[i] += '1';
            } else {
                output[i] += to_string(random<double>(0,1) < sigmoid(s[i] - p[j])); 
            }
        }
        cout << output[i] << '\n';
    }
        
    fout << "Case #" << Case << ": " << cheater << '\n'; 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    int T = 50;
    int P = 10;

    cout << T << '\n';

    rep(i,1,T) make_case(i,P);
    
    fout.close();
    
    return 0;
}








