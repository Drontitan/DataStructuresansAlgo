#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int recursion3d(vector<vector<int>>vec,int i,int j1 ,int j2,int n ,int m){


    if(i==vec.size()-1){
       if(j1==j2)return vec[i][j1];
       else return vec[i][j1]+vec[i][j2];
    }

    if(j1<0 || j1>=m || j2<0 || j2>=m)return -1e8;
    int maxi=-1e8;
    for(int d1=-1 ;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            int value=0;
               if(j1==j2)value=vec[i][j1];
               else  value=vec[i][j1]+vec[i][j2];
               value+=recursion3d(vec,i+1,j1+d1,j2+d2,n,m);
               maxi=max(maxi,value);

        }
    }
     return maxi;
}

//  memoizaion recursion code 
int recursion3dmemo(vector<vector<int>>vec,int i,int j1 ,int j2,int n ,int m,vector<vector<vector<int>>>&dp){

    if(i==vec.size()-1){
       if(j1==j2)return vec[i][j1];
       else return vec[i][j1]+vec[i][j2];
    }

    if(j1<0 || j1>=m || j2<0 || j2>=m)return -1e8;
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi=-1e8;
    for(int d1=-1 ;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            int value=0;
               if(j1==j2)value=vec[i][j1];
               else  value=vec[i][j1]+vec[i][j2];
               value+=recursion3dmemo(vec,i+1,j1+d1,j2+d2,n,m,dp);
               maxi=max(maxi,value);

        }
    }
     return  dp[i][j1][j2]=maxi;
}



int main(){
     vector<vector<int>>vec={{2,3,1,2},{3,4,2,2},{5,6,3,5}};
     int r=3,c=4;
     vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
     cout<<recursion3d(vec,0,0,c-1,r,c);
     cout<<recursion3dmemo(vec,0,0,c-1,r,c,dp);
    return 0;
}