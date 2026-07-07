
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
    vector<int> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    int op = 0;

    for(int i=0 ; i<n ; i++){
        if(a[i] > b[i]){
            int aux = i+1;

            while(aux < n){
                if(a[aux] <= b[i]){
                    int regalo = a[aux];

                    for(int j=aux ; j>i ; j--){
                        a[j] = a[j-1];
                    }

                    a[i] = regalo;

                    op += aux - i;

                    break;
                }

                aux++;
            }
        }
    }


/*     for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl; */

    for(int i=0 ; i<n ; i++){
        if(a[i] > b[i]){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<op<<endl;
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