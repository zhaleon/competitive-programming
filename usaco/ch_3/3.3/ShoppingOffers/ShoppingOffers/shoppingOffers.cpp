/*
ID: lionz202
TASK: shopping
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int> > vii;
typedef vector<pair<int, int> > vpi;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

ifstream fin ("shopping.in");
ofstream fout ("shopping.out");

int s, b;
vpi deals[100];
int newCost[100];

int dp[6][6][6][6][6];

int target[5][2]; //second dimension is target amount and original price;
int code[5];

auto compare = [](int &a, int& b) { return a > b;};
priority_queue<int, vector<int>, decltype(compare)> dijkstras(compare);

unordered_map<int, int> m;

int main() {
    fin >> s;
    
    int n;
    loop(i,0,s) {
        fin >> n;
        int a, b;
        loop(j,0,n) {
            fin >> a >> b;
            deals[i].PB(MP(a,b));
        }
        fin >> newCost[i];
    }
    
    fin >> b;
    int x;
    loop(i,0,b) {
        fin >> x;
        m[x] = i+1;
        code[i] = x;
        fin >> target[i][0] >> target[i][1];
    }
    
    loop(a, 0, target[0][0]+1) {
        loop(b, 0, target[1][0]+1) {
            loop(c, 0, target[2][0]+1) {
                loop(d, 0, target[3][0]+1) {
                    loop(e, 0, target[4][0]+1) {
                        if (a + b + c + d + e != 0) {
                            
                            int best = a*target[0][1]+b*target[1][1]+c*target[2][1]+d*target[3][1]+e*target[4][1];
                            
                            for (int i = 0; i < s; i++) {
                                bool works = 1;
                                int deal[6];
                                memset(deal, 0, sizeof(deal));
                                for (int j = 0; j < deals[i].size(); j+=1) {
                                    deal[m[deals[i][j].F]] = deals[i][j].S;
                                }
                                if (deal[1] > a || deal[2] > b || deal[3] > c || deal[4] > d || deal[5] > e) works = 0;
                                if (works) {
                                    //fout << "hi" << endl;
                                    best = min(best, newCost[i] + dp[a-deal[1]][b-deal[2]][c-deal[3]][d-deal[4]][e-deal[5]]);
                                }
                                
                            }
                            dp[a][b][c][d][e] = best;
                            
                            
                        }
                    }
                }
            }
        }
    }
    
    fout << dp[target[0][0]][target[1][0]][target[2][0]][target[3][0]][target[4][0]] << endl;
    //fout << target[0][0] << ' ' << target[0][1] << endl;
    
    
    
    return 0;
}



