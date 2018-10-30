n=gets.to_i

k = 0
1.upto(1000) do |i|
    if i * (i-1) / 2 == n
        k = i
        break
    elsif i * (i-1) / 2 > n
        break
    end
end

if k == 0
    puts "No"
    exit
else
    puts "Yes"
end

s = 1
ans = []
1.upto(k-1) do |i|
    (i+1).upto(k) do |j|
        ans[i] = [] if ans[i] == nil
        ans[j] = [] if ans[j] == nil
        ans[i] << s
        ans[j] << s
        s += 1
    end
end
puts k
1.upto(k) do |i|
    printf("%d ", ans[i].size)
    puts ans[i].join(" ")
end