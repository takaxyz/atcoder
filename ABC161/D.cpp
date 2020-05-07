#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int k;
  cin >> k;
  queue<ll> q;
  REP(i,9)q.push(i+1);

  ll n;
  REP(i,k){
    n = q.front(); q.pop();

    if(n%10==0){
      q.push(n*10);
      q.push(n*10+1);
    }else if(n%10==9){
      q.push(n*10+8);
      q.push(n*10+9);
    }else{
      for(int j = -1; j < 2; j++){
        q.push(n*10+n%10+j);
      }
    }
  }

  cout << n << endl;
}

