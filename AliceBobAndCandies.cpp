
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

    vector<int> dulces(n);

    for(int i=0 ; i<n ; i++) cin>>dulces[i];

    int turno = 0;

    int alice = dulces[0];
    int antAlice = dulces[0];
    int posAlice = 1;
    
    int bob = 0;
    int antBob;
    int posBob = n-1;

    while(1){
        int acum = 0;

        turno ++;

        if(turno%2 == 0){
            //LE TOCA A ALICE

            while(posAlice <= posBob &&  acum <= antBob){
                acum += dulces[posAlice];
                alice += dulces[posAlice];
                posAlice++;
            }

            antAlice = acum;

            if(posAlice > posBob){
                break;
            }
        }else{
            //LE TOCA A BOB

            while(posBob >= posAlice &&  acum <= antAlice){
                acum += dulces[posBob];
                bob += dulces[posBob];
                posBob--;
            }

            antBob = acum;

            if(posBob < posAlice){
                break;
            }
        }
    }

    if(n == 1){
        turno--;
    }
    
    cout<<turno+1<<" "<<alice<<" "<<bob<<endl;
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