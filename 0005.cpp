#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vector<ll> d(n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    d[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [dist, u] = pq.top();
        pq.pop();
        if(dist != d[u]) continue;
        for(auto &edge : g[u]){
            int v = edge.first, w = edge.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    ll ans = 0;
    for(int i = 2; i <= n; i++){
        ans += d[i];
    }
    cout << ans;
    return 0;
}
