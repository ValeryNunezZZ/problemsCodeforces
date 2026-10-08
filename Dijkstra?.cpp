
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
//#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector< vector< pair<int, int> > > & grafo, vector< pair<long long, int> > & dist){
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> >> p;

    p.push(make_pair(0, 0));
    dist[0] = make_pair(0, -2);

    while(!p.empty()){
        pair<int, int> node = p.top();

        p.pop();

        if(dist[node.second].first < node.first) continue;

        for(int i=0 ; i<grafo[node.second].size() ; i++){
            long long posibleDistancia = dist[node.second].first + (long long) grafo[node.second][i].second;

            if(posibleDistancia >= dist[grafo[node.second][i].first].first) continue;

            p.push(make_pair(posibleDistancia, grafo[node.second][i].first));

            dist[grafo[node.second][i].first] = make_pair(posibleDistancia, node.second);
        }
    }


}

void casito(){

    int n, m; cin>>n>>m;

    vector< vector< pair<int, int> > > grafo(n);

    for(int i=0 ; i<m ; i++){
        int a, b, w; cin>>a>>b>>w;

        a--;
        b--;

        grafo[a].push_back(make_pair(b, w));
        grafo[b].push_back(make_pair(a, w));
    }

    vector< pair<long long, int> > dist(n, make_pair(__LONG_LONG_MAX__, -1));

    dijkstra(grafo, dist);


    vector<int> caminito;

    if(dist[n-1].second == -1){
        cout<<-1<<endl;
        return;
    }

    caminito.push_back(n-1);

    int actual = n-1;

    while(dist[actual].second != -2){
        caminito.push_back(dist[actual].second);

        actual = dist[actual].second;
    }

    for(int i=caminito.size()-1 ; i>=0 ; i--){
        cout<<caminito[i]+1<<" ";
    }

    cout<<endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin>>t;
    
    while (t--){
        casito();
    }
    return 0;
    
}
