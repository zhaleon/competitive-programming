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

int N, M;
const int block_size = 320;

int power[100001];
int next_square[100001];
int num_jumps[100001];

inline int block(int a) { return (a-1) / block_size + 1; }

void recalc(int pos) {
    int jumps = 0;
    int cur_block = block(pos);
    int start = pos;
    
    while (block(pos) == cur_block && pos <= N) {
        pos += power[pos];
        ++jumps;
    }
    
    next_square[start] = pos;
    num_jumps[start] = jumps;
    
    for (int i = start-1; i > block_size * (cur_block-1); --i) {
        if (block(i + power[i]) == block(i) && i + power[i] <= N) {
            num_jumps[i] = num_jumps[i + power[i]] + 1;
            next_square[i] = next_square[i + power[i]];
        } else {
            num_jumps[i] = 1;
            next_square[i] = i + power[i];
        }
    }
}

pii query(int pos) {
    int ans = 0;
    int last = 0;
    
    while (pos <= N) {
//        cerr << "DEBUG: " << pos << ' ' << next_square[pos] << endl;
        assert(next_square[pos] > pos);
        ans += num_jumps[pos];
        last = pos;
        pos = next_square[pos];
    }
    
    while (1) {
        if (last + power[last] <= N) last += power[last];
        else break;
    }
    
    return {last, ans};
}

void precalc() {
    recalc(N);
    for (int i = (block(N)-1) * block_size; i > 0; i -= block_size) recalc(i);
    for (int i = N-1; i > 0; --i) {
        if (i % block_size < block_size - 1) {
            if (block(i) != block(i + power[i]) || i + power[i] > N) {
                next_square[i] = i + power[i];
                num_jumps[i] = 1;
            } else {
                next_square[i] = next_square[i + power[i]];
                num_jumps[i] = 1 + num_jumps[i + power[i]]; 
            }
        }
    }      
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    rep(i,1,N) cin >> power[i];
    precalc();
        
    rep(i,1,M) {
        int t, a, b;
        cin >> t;
        
        if (!t) {
            cin >> a >> b;
            power[a] = b;
            recalc(a);
        } else {
            cin >> a;
            pii ans = query(a);
            cout << ans.F << ' ' << ans.S << endl;
        }
    }
    
    return 0;
}