N,M=gets.chomp.split.map(&:to_i)
h = Hash.new(0)
N.times do
  arr = gets.chomp.split.map(&:to_i)
  1.upto(arr.size-1) {|i| h[arr[i]]+=1}
end
ans=0
h.each do |k,v|
  ans += 1 if v == N
end
puts ans