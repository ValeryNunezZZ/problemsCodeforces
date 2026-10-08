
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

void casito(){

    int n; cin>>n;

    vector<int> a(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];

    vector<int> minimos(n);

    for(int i=0 ; i<n ; i++) minimos[i] = a[i] - i;

    sort(minimos.begin(), minimos.end());

    //ENCONTRAR LA SECUENCIA MAS LARGA

    int pos = 1;
    int anterior = minimos[0];
    int llevo = 1;

    int res = 1;

    while(pos < n){
        if(anterior+1 == minimos[pos]){
            llevo++;
        }else if(anterior == minimos[pos]){
            
        }else{
            res = max(llevo, res);

            llevo = 1;
        }

        anterior = minimos[pos];
        pos++;
    }

    res = max(llevo, res);

    cout<<res<<endl;

}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;
    
    while (t--){
        casito();
    }
    return 0;
    
}
