#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

const int MAX=100001;

int main(){
  int Q;
  cin >> Q;
  vector<bool> p(MAX+1,false);

  p[1]=true;
  p[2]=true;

  int i = 2;
  set<int> p_set;
  while(i<=MAX){
    p_set.insert(i);
    FOR(j,1,MAX){
      if(j*i>MAX)break;
      p[j*i]=true;
    }
    while(p[i]==true){
      i++;
    }
  }

  vector<int> sum(MAX+1,0);
  for(int i = 1; i <= MAX; i+=2){
    if(p_set.find(i) != p_set.end() && p_set.find((i+1)/2) != p_set.end()){
      sum[i] = 1;
    }
  }
  REP(i,MAX){
    sum[i+1] = sum[i+1]+sum[i];
  }
  REP(i,Q){
    int l,r;
    cin >> l >> r;
    cout << sum[r] - sum[l-1] << endl;
  }


}

