#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int>&wt, vector<int>&val, int W){
    int n=wt.size();
    vector<vector<int>>dp(n,vector<int>(W+1,0));

    for(int w=0;w<=W;w++){
        if(wt[0]<=w){
            dp[0][w]=val[0];
        }
    }

    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            if(wt[i]<=w){
                
                    int include=val[i] + dp[i-1][w-wt[i]];
                    int not_included=0+dp[i-1][w];
                    dp[i][w]=max(include,not_included);
                }
                else{
                    dp[i][w]=0+dp[i-1][w];
            }
        }
    }
    return dp[n-1][W];
}

int main(){
    std::vector<int> wt = {15,30,45};
    std::vector<int> val = {60,100,150};
    int W = 50;
    cout << findMax(wt, val, W) << std::endl;
    return 0;
//     int n;
//     vector<int>weight;
//     vector<int>value;
//     int weightCapacity;
//     cout<<"Enter no of weights: ";
//     cin>>n;
//     cout<<"\nWeights: ";
//     for(int i=0;i<n;i++) {
//        weight.push_back(i);
//     }
//     cout<<"\nValue: ";
//     for(int i=0;i<n;i++) {
//         value.push_back(i);
//     }
//     cout<<"\nEnter capacity:";
//     cin>>weightCapacity;

// return 0;
}