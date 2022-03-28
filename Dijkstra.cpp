#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mod 1000000007
#define nline "\n"
#define INF INT_MAX

typedef pair<int, int> pii;
vector<vector<pii>> graph;

void addEdge(int u, int v, int wt)
{
    graph[u].push_back({wt, v});
    // if undirected
    // graph[v].push_back({wt,u});
}
vector<int> dijkstra(int src)
{
    int n = graph.size();
    priority_queue<pii> pq;
    vector<int> dist(n, INF);
    pq.push({0, src});
    dist[src] = 0;
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : graph[u])
        {
            int v = x.second;
            int wt = x.first;

            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
int main()
{
    int n = 9;
    //cin >> n;
    graph.resize(n);

    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    vector<int> v = dijkstra(0);
    for(int i:v)cout<<i <<" ";
    cout<<nline;
    return 1;
}
