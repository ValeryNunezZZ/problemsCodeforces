
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
    int n, x, y, z;
    cin>>n>>x>>y>>z;

    int primero = ceil((double)n/(x+y));
    
    n -= x*z;
    int segundo = z + ceil((double)n/(x+10*y));
    
    cout<<min(primero, segundo)<<endl;
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