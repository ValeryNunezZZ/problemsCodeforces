#include <bits/stdc++.h>

using namespace std;

void casito(){
    int n; cin>>n;

    vector<int> nums(n);

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    int minOp = INT_MAX;
    int pos = -1;

    for(int i=1 ; i<n ; i++){
        int actual = 0;
        int siguiente = i-2;

        int divisor = gcd(nums[i], nums[i-1]);

        while(siguiente >= 0 && divisor != 1){    
            divisor = gcd(divisor, nums[siguiente]);
            actual++;
            siguiente--;
        }

        if(divisor == 1){
            minOp = min(minOp, actual);
            pos = i;
        }
    }

    for(int i=0 ; i<n-1 ; i++){
        int actual = 0;
        int siguiente = i+2;

        int divisor = gcd(nums[i], nums[i+1]);

        while(siguiente < n && divisor != 1){    
            divisor = gcd(divisor, nums[siguiente]);
            actual++;
            siguiente++;
        }

        if(divisor == 1){
            minOp = min(minOp, actual);
        }
    }

    if(pos == -1){
        cout<<-1<<endl;
        return;
    }

    cout<<minOp + n - 1<<endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    
    while (t--){
        casito();
    }
    return 0;
    
}