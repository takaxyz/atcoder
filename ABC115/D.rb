N,X=gets.chomp.split.map(&:to_i)
b=[]
p=[]
p[0]=1
b[0]=0

1.upto(N) do |i|
    p[i] = 1+2*p[i-1]
    b[i] = 2+2*b[i-1]
end

def get_pb(n,m,s,p,b)
    return 1 + s if n == 0
    if m == 1 
        s
    elsif m == 2 + p[n-1] + b[n-1]
        s + 1 + p[n-1]
    elsif m == 3 + 2 * (p[n-1] + b[n-1])
        s + 1 + 2 * p[n-1]
    elsif m < 2 + p[n-1] + b[n-1]
        get_pb(n-1, m-1, s, p,b)
    else
        get_pb(n-1, m-2-p[n-1]-b[n-1], s+1+p[n-1], p,b)        
    end
end

puts get_pb(N,X,0,p,b)
