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

int query(int i) {
    int res;
    cout << i << endl;
    cin >> res;
    return res;
}

bool answer(string s) {
    char res;
    cout << s << endl;
    cin >> res;
    return res == 'Y';
}

void flip_bits(vector<int> &a, int B = 0) {
    for (auto &x : a) x = !x;
}

void reverse_string(vector<int> &a, int B) {
    for (int i = 0; i < B/2; ++i) swap(a[i], a[B-1-i]);
}

int T, B;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> B;
        int L = 0, R = B-1;
        
        pair<int, int> same_bit = {-1, -1};
        pair<int, int> dif_bit = {-1, -1};
        pair<int, int> dif_bit_pos {-1, -1};

        vector<int> result(B, 0);
        
        int queries_used = 0;
        
        while (L <= R) {
            queries_used += 2;
            int lbit = query(L), rbit = query(R);
            result[L] = lbit;
            result[R] = rbit;
            
            if (lbit == rbit) same_bit.first = L, same_bit.second = R;     
            if (lbit != rbit && dif_bit.first == -1) dif_bit.first = lbit, dif_bit.second = rbit;
            if (lbit != rbit && dif_bit.first == -1) dif_bit_pos.first = L, dif_bit_pos.second = R;
            
            if (queries_used % 10 == 0) {
                if (same_bit.first != -1 && query(same_bit.first) != query(same_bit.second))
                    flip_bits(result, B);

                if (dif_bit.first != -1 && dif_bit.first != query(dif_bit_pos.first)) 
                    reverse_string(result, B);
            }
            
            ++L;
            --R;
        }

        string ans(result.begin(), result.end());
        answer(ans);
    }
    
    return 0;
}
