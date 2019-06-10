n,k=gets.chomp.split.map(&:to_i)
v=gets.chomp.split.map(&:to_i)
vs1=[0]
vs2=[0]
1.upto(n) do |i|
  vs1 << vs1[i-1] + v[i-1]
  vs2 << vs2[i-1] + v[n-i]
end

ans = 0

1.upto([k,n].min) do |i|
  # 左からいくつとるか
  i.downto(0) do |l|
    t = 0
    minus = []
    # 右からとる数
    r = i - l
    0.upto(l-1) do |j|
      t += v[j]
      minus << v[j] if v[j] < 0
    end
    0.upto(r-1) do |j|
      t += v[n-j-1]
      minus << v[n-j-1] if v[n-j-1] < 0
    end
    minus.sort!
    if k-i>0
      0.upto([minus.size-1,k-i-1].min) do |k|
        t -= minus[k]
      end
    end

    ans = t if t > ans
  end
end
puts ans