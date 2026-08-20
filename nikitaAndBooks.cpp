
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
    
    vector<int> pilas(n);

    for(int i=0 ; i<n ; i++) cin>>pilas[i];

    long long sobran = 0;

    for(int i=0 ; i<n ; i++){
        if(pilas[i] > i+1){
            sobran += (long long) pilas[i] - (i+1);
        }else if(pilas[i] < i+1){
            long long necesito = (i+1) - (long long) pilas[i];

            if(necesito > sobran){
                cout<<"NO"<<endl;
                return;
            }else{
                sobran -= necesito;
            }
        }
    }

    cout<<"YES"<<endl;
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