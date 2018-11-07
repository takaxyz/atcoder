n,m=gets.chomp.split.map(&:to_i)
p = []
y = []

py = Array.new(n+1).map{Array.new()}

m.times do |i|
    pp, yy = gets.chomp.split.map(&:to_i)
    p << pp
    y << yy

    py[pp] << yy
end

ph = Array.new(n+1).map{Hash.new()}
py.each_with_index do |v, i|
    v.sort!
    v.each_with_index do |vv, j|
        ph[i][vv] = j+1
    end
end

0.upto(m-1) do |i|
    printf("%06d%06d\n", p[i], ph[p[i]][y[i]])
end