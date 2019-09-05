#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

typedef long long ll;
#define INF 100000000
#define MOD 1000000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
   ll l,r;
   cin>>l>>r;
   ll ans=2019;
   if(r-l>=2019){
       cout<<0<<endl;
   }else{
       for(ll i=l;i<r;i++){
           for(ll j=i+1;j<=r;j++){
               ll tmp=(i*j)%2019;
               ans=min(ans,tmp);
           }
       }
       cout<<ans<<endl;
   }
   return 0;
}
