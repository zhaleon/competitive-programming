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
//103260
using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");

int N, P, C, distances[801][801], visited[801][801], hasCows[801], sourcePasture, best = 100000000;

vector<pair<int, int>> adjacent[801];

auto compare = [](int &a, int& b) { return distances[sourcePasture][a] > distances[sourcePasture][b];};
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
        adjacent[a].push_back(make_pair(b, c));
        adjacent[b].push_back(make_pair(a, c));
    }
    
    for (sourcePasture = 1; sourcePasture <= P; sourcePasture++) {
        dijkstras.push(sourcePasture);
        while (!dijkstras.empty()) {
            int curPasture = dijkstras.top();
            dijkstras.pop();
            
            if (visited[sourcePasture][curPasture]) continue;
            visited[sourcePasture][curPasture] = 1;

            for (int i = 0; i < adjacent[curPasture].size(); i++) {
                if (adjacent[curPasture][i].second != 0) {
                    if (distances[sourcePasture][curPasture] + adjacent[curPasture][i].second < distances[sourcePasture][adjacent[curPasture][i].first]) {
                        distances[sourcePasture][adjacent[curPasture][i].first] = distances[sourcePasture][curPasture] + adjacent[curPasture][i].second;
                    }
                    dijkstras.push(adjacent[curPasture][i].first);
                }
            }
        }
        int sum = 0;
        for (int j = 1; j <= P; j++) {
            if (hasCows[j] > 0 && sourcePasture != j) {
                sum += distances[sourcePasture][j]*hasCows[j];
            }
        }
        best = min(best, sum);
    }

    fout << best << endl;
    
    fin.close();
    fout.close();
    return 0;
}

