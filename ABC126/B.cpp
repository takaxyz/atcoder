#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

bool isMM(string s){
  if((s[0] == '0' && s[1] != '0' ) || s == "10" || s=="11" || s=="12"){
    return true;
  }else{
    return false;
  }
}

int main(){
  string S;
  cin >> S;

  if(isMM(S.substr(2,2)) && isMM(S.substr(0,2))){
    cout << "AMBIGUOUS" << endl;
  }else if(isMM(S.substr(2,2))){
    cout << "YYMM" << endl;
  }else if(isMM(S.substr(0,2))){
    cout << "MMYY" << endl;
  }else{
    cout << "NA" << endl;
  }

}
