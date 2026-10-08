
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

    int num = 0;

    for(int i=0 ; i<n ; i++){
        cin>>a[i];

        num += a[i];
    }

    //OBTENER LOS DIVISORES DE UN NUM

    vector<int> divisores;

    int divisor = 1;

    if(num == 0){
        cout<<0<<endl;
        return;
    } 

    
    while(divisor*divisor <= num){
        if(num%divisor == 0){
            divisores.push_back(divisor);
            
            //ESTE CHEQUEO ES PARA NO METER DOS VECES EL MISMO NUMERO
            if(divisor*divisor != num){
                divisores.push_back(num/divisor);
            }
        }
        
        divisor++;
    }

    sort(divisores.begin(), divisores.end());

    for(int i=divisores.size()-1 ; i>=0 ; i--){
        int grupo = num/divisores[i];

        int pos = 0;
        int llevo = 0;
        int res = 0;
        int sumados = 0;

        while(pos < a.size() && llevo < grupo){
            llevo += a[pos];
            sumados++;
            pos++;

            if(llevo == grupo){
                llevo = 0;
                res += sumados - 1;
                sumados = 0;
            }
        }

        if(llevo == 0 && pos == a.size()){
            cout<<res<<endl;
            return;
        }
    }

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