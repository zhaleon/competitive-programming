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

string A, B;

ll exp(ll base, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) res *= base;
        base *= base;
        p >>= 1;
    }
    return res;
}

bool ok(string x) {
    for (int i = 0; i < (int)x.size()-1; ++i) {
        if (x[i] == x[i+1]) return 0;
    }
    return 1;
}

ll solve(string x) {
    ll res = 0; 

    auto valid_nums_less = [&](string num) {
        ll temp = 0;
        for (int i = 0; i < (int)num.size(); ++i) {
             temp += max(num[i] - '0' - (i == 0) - (i > 0 && num[i-1] < num[i]), 0) * exp(9, num.size()-1-i);
             if (i && num[i] == num[i-1]) break;
        }
        return temp;
    };

    res += valid_nums_less(x);

    string dummy = "";

    for (int i = 0; i < (int)x.size()-1; ++i) {
        dummy += "9";
        res += valid_nums_less(dummy) + ok(dummy);
    }

    return res + 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> A >> B;
    B = to_string(stoll(B)+1); 

    ll b_ans = 0, a_ans = 0;

    b_ans += solve(B);
    a_ans += (stoll(A) != 0) * solve(A);

    cout << b_ans - a_ans << endl;

    return 0;
}








