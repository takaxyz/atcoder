#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int f(int n){
  if(n%2==0){
    return n/2;
  }else{
    return 3*n+1;
  }
}

int main(){
  int s;
  cin >> s;

  vector<int> a;
  a.emplace_back(0);
  a.emplace_back(s);

  set<int> st;

  st.insert(s);

  for(int i=2; ;i++){
    int tmp = f(a[i-1]);
    if(st.find(tmp) != st.end()){
      cout << i << endl;
      return 0;
    }
    a.emplace_back(tmp);
    st.insert(tmp);
  }

}

