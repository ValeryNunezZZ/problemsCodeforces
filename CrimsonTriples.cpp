
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

    long long total = 0;

    for(int i=1 ; i<=n ; i++){
        long long multiplos = (n/i) - 1;

        total += multiplos * (multiplos+1) + multiplos + 1;
        
    }
/* 
    //CALCULO MULTIPLOS

    for(int i=1 ; i<=n ; i++){
        total += ((n/i) - 1) * 2 + 1;
    }

    //CALCULO DIVISORES

    for(int i=1 ; i<=n ; i++){

        int numDivisores = -1;

        for(int j=1 ; j*j<=i ; j++){
            if(i%j == 0){
                numDivisores++;
                
                if(j != i/j) numDivisores++;
            }


        }

        total += numDivisores;
    } */

    cout<<total<<endl;

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