
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

void casito(int caso){
    int n; cin>>n;

    multiset<long long> b;

    int primero = INT_MAX;

    for(int i=0 ; i<n ; i++){
        int num; cin>>num;
        b.insert(num);

        if(num > 0){
            primero = min(primero, num);
        }
    }

    if(primero == INT_MAX){
        cout<<-1<<endl;
        return;
    }

    vector<long long> res(n);

    res[0] = primero;
    b.erase(b.find(primero));

    int pos = 1;

    while(b.size() > 0){
        //lower_bound = mayor o igual
        auto elegido = b.lower_bound((long long)1 - res[pos - 1]);

        if(elegido == b.end()){
            cout<<-1<<endl;
            return;
        }

        res[pos] = res[pos-1] + *elegido;
        b.erase(elegido);
        pos++;
    }


    for(int i=0 ; i<n ; i++){
        cout<<res[i]<<" ";
    }

    cout<<endl;

}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;

    int caso = 0;

    while (t--){
        caso++;
        casito(caso);
    }
    return 0;
    
}