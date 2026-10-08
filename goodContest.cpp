
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

    vector<int> problemas(3);

    for(int i=0 ; i<3 ; i++) cin>>problemas[i];

    int mayor = -1;

    for(int i=0 ; i<3 ; i++){
        int resta = n - problemas[i];

        mayor = max(resta, mayor);
    }

    cout<<mayor<<endl;
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