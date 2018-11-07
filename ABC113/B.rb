n=gets.to_i
t,a=gets.chomp.split.map(&:to_i)
h=gets.chomp.split.map(&:to_i)

m=Float::INFINITY
ans=0
h.each_with_index do |v, i|
    mm = (a-(t-v*0.006)).abs
    if mm < m
        ans = i+1
        m = mm
    end
end
puts ans