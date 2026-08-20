
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
    int n, k; cin>>n>>k;

    if(k >= n){
        cout<<n<<endl;
        return;
    }

    int llevo = 2;
    int veces = 1;

    while(1){
        if((llevo-1) * k < n){
            veces++;
            llevo *= 2;
        }else if((llevo-1) * k == n){
            cout<<veces*k<<endl;
            return;
        }else{
            break;
        }
    }

    int restar = 1;
    int aux = veces;

    while(veces > 1){
        restar *= 2;
        veces--;
    }

    int quitados = 0;


    int total = (llevo-1) * k;

    while(total > n){
        quitados++;
        total -= restar;
    }

    cout<<aux*k - quitados<<endl;
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