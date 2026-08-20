
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

    vector<int> a(n);
    vector<int> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];
    
    int cerosDiferentes = 0;
    int unosDiferentes = 0;
    int unosTotales = 0;
    bool alMenosUnCeroAcomodado = false;
    
    for(int i=0 ; i<n ; i++){
        if(a[i] == 0 && b[i] == 1){
            cerosDiferentes++;
        }else if(a[i] == 1 && b[i] == 0){
            unosDiferentes++;
        }

        if(a[i] == 1){
            unosTotales++;
        }

        if(a[i] == 0 && b[i] == 0) alMenosUnCeroAcomodado = true;
    }

    if(cerosDiferentes > 0 && unosTotales == 0){
        cout<<-1<<endl;
        return;
    }

    if(cerosDiferentes == 0 && unosDiferentes == 0){
        cout<<0<<endl;
        return;
    }

    if(unosDiferentes%2 == 1){
        cout<<1<<endl;
        return;
    }

    if((unosDiferentes%2 == 0 && unosDiferentes != 0) || alMenosUnCeroAcomodado){
        cout<<2<<endl;
        return;
    }
    
    cout<<-1<<endl;

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