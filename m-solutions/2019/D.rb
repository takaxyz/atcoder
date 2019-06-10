n=gets.to_i
cnt=Hash.new(0)
e = {}
(n-1).times do
  a,b=gets.chomp.split.map(&:to_i)
  cnt[a]+=1
  cnt[b]+=1
  e[a] = [] if !(e.has_key?(a))
  e[b] = [] if !(e.has_key?(b))
  e[a] << b
  e[b] << a
end
c=gets.chomp.split.map(&:to_i)
c.sort!

list = []
cnt.keys.each do |k|
  list << k if cnt[k] == 1
end

ans = Array.new(n)

n.times do |i|
  k = list.shift
  ans[k-1] = c[i]

  e[k].each do |l|
    cnt[l] -= 1
    list << l if cnt[l] == 1
  end
end

puts c.inject(:+) - c[-1]

puts ans.join(" ")
