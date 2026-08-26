#include <bits/stdc++.h>
#define endl '\n'
#define ll long long 
using namespace std;

template <typename Cap, typename Cost>
struct MCMF {
  struct Edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };

  int N;
  vector<vector<Edge>> g;

  MCMF(int n) : N(n), g(n) {}

  void add_edge(int u, int v, Cap cap, Cost cost, Cap rcap = 0) {
    g[u].push_back({v, (int)g[v].size(), cap, cost});
    g[v].push_back({u, (int)g[u].size() - 1, rcap, -cost});
  }

  pair<Cap, Cost> flow(int s, int t,
                       Cap limit = numeric_limits<Cap>::max()) {
    Cap total_flow = 0;
    Cost total_cost = 0;
    
    const Cost INF = numeric_limits<Cost>::max() / 2;
    vector<Cost> pot(N, INF);

    pot[s] = 0;
    //PARA DAGS (linear)
    // for (int i = 0; i < N; i++) {
    //     if (pot[i] != INF) {
    //         for (auto &e : g[i]) {
    //             if (e.cap > 0 && pot[i] + e.cost < pot[e.to]) {
    //                 pot[e.to] = pot[i] + e.cost;
    //             }
    //         }
    //     }
    // }

    queue<int> q;
    vector<bool> in_queue(N, false);
    q.push(s);
    in_queue[s] = true;
 
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      in_queue[u] = false;
      for (auto &e : g[u]) {
        if (e.cap > 0 && pot[u] + e.cost < pot[e.to]) {
          pot[e.to] = pot[u] + e.cost;
          if (!in_queue[e.to]) {
            in_queue[e.to] = true;
            q.push(e.to);
          }
        }
      }
    }

    while (limit > 0) {
      vector<Cost> dist(N, INF);
      vector<int> prev_node(N, -1), prev_edge(N, -1);
      
      priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;

      dist[s] = 0;
      pq.push({0, s});

      while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < (int)g[u].size(); i++) {
          auto &e = g[u][i];
          if (e.cap > 0) {
            Cost red_cost = e.cost + pot[u] - pot[e.to];
            if (dist[u] + red_cost < dist[e.to]) {
              dist[e.to] = dist[u] + red_cost;
              prev_node[e.to] = u;
              prev_edge[e.to] = i;
              pq.push({dist[e.to], e.to});
            }
          }
        }
      }

      if (dist[t] == INF) break;

      for (int i = 0; i < N; i++) {
        if (dist[i] != INF) {
          pot[i] += dist[i];
        }
      }

      Cap pushed = limit;
      for (int v = t; v != s; v = prev_node[v])
        pushed = min(pushed, g[prev_node[v]][prev_edge[v]].cap);

      for (int v = t; v != s; v = prev_node[v]) {
        auto &e = g[prev_node[v]][prev_edge[v]];
        e.cap -= pushed;
        g[v][e.rev].cap += pushed;
      }

      total_flow += pushed;
      total_cost += pushed * pot[t]; 
      limit -= pushed;
    }

    return {total_flow, total_cost};
  }
};