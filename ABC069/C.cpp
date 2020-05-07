#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;
  int cnt_2 = 0;
  int cnt_4 = 0;
  int cnt_other = 0;
  REP(i,N){
    ll a;
    cin >> a;
    if(a%4==0){
      cnt_4++;
    }else if(a%2==0){
      cnt_2++;
    }else{
      cnt_other++;
    }

  }

  if(cnt_2==0){
    if(cnt_4+1>=cnt_other){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if(cnt_4>=cnt_other){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}

