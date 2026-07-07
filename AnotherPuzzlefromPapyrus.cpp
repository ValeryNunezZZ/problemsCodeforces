
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
    int n, c;
    cin>>n>>c;

    vector<int> a(n);
    vector<int> b(n);

    vector<int> visA(n, 0);
    vector<int> ordenNuevo(n, 0);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    for(int i=0 ; i<n ; i++){
        
        int minPos = -1;
        int minValue = INT_MAX;
        
        for(int j=0 ; j<n ; j++){
            if(b[i] <= a[j] && visA[j] == 0){
                if(minValue > a[j]){
                    minValue = a[j];
                    minPos = j;
                }
            }
        }    

        if(minPos == -1){
            cout<<-1<<endl;
            return;
        }else{
            ordenNuevo[i] = a[minPos];
            visA[minPos] = 1;
        }
    }

    int totalUno = 0;
    int cuantos = 0;
    int totalDos = 0;

    for(int i=0 ; i<n ; i++){
        if(ordenNuevo[i] != a[i]){
            totalUno += c;
            break;
        }
    }

    for(int i=0 ; i<n ; i++) if(a[i] >= b[i]) cuantos++;

    for(int i=0 ; i<n ; i++) totalUno += ordenNuevo[i] - b[i];

    if(cuantos == a.size()){
        for(int i=0 ; i<n ; i++) totalDos += a[i] - b[i];
        
        cout<<min(totalDos, totalUno)<<endl;
        return;
    }

    cout<<totalUno<<endl;
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