#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adjtable(n);

        for (auto& edge : edges) {
            adjtable[edge[0]].push_back(edge[1]);
            adjtable[edge[1]].push_back(edge[0]);
        }

        vector<int> shortpath(n);
        list<int> queuepath;
        queuepath.push_back(0);
        int curpath = 1;
        vector<int> visited(n);
        visited[0] = 1;
        while (!queuepath.empty()) {
            int sz = queuepath.size();
            for (int i = 0; i < sz; i++) {
                int node = queuepath.front();
                queuepath.pop_front();

                for (int near : adjtable[node]) {
                    if (visited[near] != 0)
                        continue;
                    queuepath.push_back(near);
                    visited[near] = 1;
                    shortpath[near] = curpath;
                }
            }
            curpath++;
        }
        int result = 0;
        for (int i = 1; i < n; i++) {
            int costtime = (2*shortpath[i]-1)/patience[i] * patience[i] + 2*shortpath[i];
            result = max(result, costtime);
        }

        return result + 1;
    }

    int networkBecomesIdleV2(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();       
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);  
        for (auto & v : edges) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        vector<int> shortpath(n);
        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (visit[v]) {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                    shortpath[v] = dist;
                }
            }
            dist++;
        }


        return ans;
    }
};

int main () {
    vector<vector<int>> edges =  {{5,7},{15,18},{12,6},{5,1},{11,17},{3,9},{6,11},{14,7},{19,13},{13,3},{4,12},{9,15},{2,10},{18,4},{5,14},{17,5},{16,2},{7,1},{0,16},{10,19},{1,8}};
    vector<int> patience = {0,2,1,1,1,2,2,2,2,1,1,1,2,1,1,1,1,2,1,1};

    Solution solu;

    cout << solu.networkBecomesIdle(edges, patience) << "\n";

    return 0;
}