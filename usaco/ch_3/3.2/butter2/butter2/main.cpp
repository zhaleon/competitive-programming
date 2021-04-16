/*
 ID: lionz202
 TASK: butter
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <bitset>
#include <map>
#include <set>
#include <list>

using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");

int N, P, C, adj[801][801], distances[801][801], visited[801][801], hasCows[801], pasture, best = 100000000;

auto compare = [](int &a, int& b) { return distances[pasture][a] > distances[pasture][b];};
priority_queue<int, vector<int>, decltype(compare)> dijkstras(compare);


int main()
{
    fin >> N >> P >> C;

    for (int i = 1; i <= N; i++) {
        int temp;
        fin >> temp;
        hasCows[temp]++;
    }
    for (int i = 1; i <= P; i++) {
        fill(distances[i], distances[i]+801, 10000000);
        distances[i][i] = 0;
    }
    for (int i = 0; i < C; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }
    
    for (pasture = 1; pasture <= P; pasture++) {
        dijkstras.push(pasture);
        while (!dijkstras.empty()) {
            int curPasture = dijkstras.top();
            dijkstras.pop();
            
            if (visited[pasture][curPasture]) continue;
            visited[pasture][curPasture] = 1;
            
            for (int nextPasture = 1; nextPasture <= P; nextPasture++) {
                if (adj[curPasture][nextPasture] != 0 && curPasture != nextPasture) {
                    if (distances[pasture][curPasture] + adj[curPasture][nextPasture] < distances[pasture][nextPasture]) {
                        distances[pasture][nextPasture] = distances[pasture][curPasture] + adj[curPasture][nextPasture];
                    }
                    dijkstras.push(nextPasture);
                }
            }
        }
        int sum = 0;
        for (int j = 1; j <= P; j++) {
            if (hasCows[j] > 0 && pasture != j) {
                sum += distances[pasture][j]*hasCows[j];
            }
        }
        best = min(best, sum);
    }

    fout << best << endl;
    
    fin.close();
    fout.close();
    return 0;
}

