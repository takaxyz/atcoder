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


int n,a,b,c;
vector<string> ans;

void ff(string s, string t){
  switch (s[0]-'A')
  {
  case 0:
    a--;
    break;
  case 1:
    b--;
    break;
  case 2:
    c--;
    break;
  
  default:
    break;
  }
  switch (t[0]-'A')
  {
  case 0:
    a++;
    break;
  case 1:
    b++;
    break;
  case 2:
    c++;
    break;
  
  default:
    break;
  }
  ans.emplace_back(t);
}

int main(){

  cin >> n >> a >> b >> c;

  vector<string> s(n);
  REP(i,n){
    cin >> s[i];
  }


  REP(i,n){
    if(s[i]=="AB"){
      if(a < b){
        ff("B", "A");
      }else if(a==b){
        if(i<n-1){
          if(s[i+1]=="BC"){
            ff("A", "B");
          }else{
            ff("B", "A");
          }
        }else{
          ff("B", "A");
        }
      }else{
        ff("A", "B");
      }
    }else if(s[i] == "BC"){
      if(b < c){
        ff("C", "B");
      }else if(b==c){
        if(i<n-1){
          if(s[i+1]=="CA"){
            ff("B", "C");
          }else{
            ff("C", "B");
          }
        }else{
          ff("C", "B");
        }
      }else{
        ff("B", "C");
      }
    }else{
      if(c < a){
        ff("A", "C");
      }else if(a==c){
        if(i<n-1){
          if(s[i+1]=="AB"){
            ff("C", "A");
          }else{
            ff("A", "C");
          }
        }else{
          ff("A", "C");
        }
      }else{
        ff("C", "A");
      }
    }

    if(a<0 || b <0 || c< 0 ){
      cout << "No" << endl;
      return(0);
    }
  }

  cout << "Yes" << endl;
  
  REP(i,n){
    cout << ans[i] << endl;
  }


}

