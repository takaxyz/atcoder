  sort(ALL(vs));
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  auto f = [&](ll x){
    return (int)(lower_bound(vs.begin(), vs.end(), x) - vs.begin());
  };
