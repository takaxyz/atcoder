vector<int> eratosthenes(const int n){
  vector<bool> is_prime(n+1,true);

  vector<int> p;

  for(int i = 2; i <= n; i++){
    if(is_prime[i]){
      for(int j=2; j*i<=n; j++){
        is_prime[i*j]=false;
      }
      p.emplace_back(i);
    }
  }

  return p;
}
