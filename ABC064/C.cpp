#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;

  map<int,int> mp;

  int cnt=0;
  REP(i,N){
    int a;
    cin >> a;
    if(a/400 < 8){
      mp[a/400]++; 
    }else{
      cnt++;
    }
  }

  cout << max(1,(int)mp.size()) << " " << mp.size()+cnt << endl;
}


