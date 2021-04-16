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

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

string S;

map<char, int> m;
char rm[4] = {'A', 'C', 'G', 'T'};

bool used[4];
int num_used = 0;

vector<char> ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S;
    
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;

    rep(i,0,S.length()-1) {
        int idx = m[S[i]];
        
        if (!used[idx]) {
            num_used++;
            used[idx] = 1;
        }
        
        if (num_used == 4) {
            num_used = 0;
            used[0] = used[1] = used[2] = used[3] = 0;
            ans.PB(S[i]);
        }
    }
    
    string s(ans.begin(), ans.end());
    
    rep(i,0,3) {
        if (!used[i]) {
            s += rm[i];
            break;
        }
    }
    
    cout << s << endl;
    
    return 0;
}