  auto cmp = [](P const &i, P const &j) -> bool{
    auto [x,y] = i;
    auto [u,v] = j;

    int zi = (y > 0 || (y==0 && x > 0)) ? 0 : 1;
    int zj = (v > 0 || (v==0 && u > 0)) ? 0 : 1;

    if(zi != zj)return zi < zj;

    return x * v - y * u > 0;
  };
