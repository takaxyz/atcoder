#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

int main(){
  int N;
  cin >> N;

  priority_queue<P, vector<P>, greater<P>> qa;
  priority_queue<P> qb;

  REP(i,N){
    int a,b;
    cin >> a >> b;

    qa.push(P{a,b});
  }

  int now=1;
  int ans=0;
  while(!qa.empty() && now >= qa.top().first){
    qb.push(P{qa.top().second, qa.top().first});
    qa.pop();
  } 
  
  while(!qb.empty()){
    P v = qb.top();
    ans += v.first;
    cout << ans << endl;
    qb.pop();
    now++;
    while(!qa.empty() && now >= qa.top().first){

      qb.push(P{qa.top().second, qa.top().first});
      qa.pop();
    } 
  }

}

