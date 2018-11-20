n = gets.chomp.to_i
edge = Array.new(n+1).map{Array.new}
(n-1).times do
    a, b, c  = gets.chomp.split(" ").map(&:to_i)
    edge[a] << [b, c]
    edge[b] << [a, c]
end

q, k = gets.chomp.split.map(&:to_i)

cost = Array.new(n+1,0)
done = Array.new(n+1,false)

queue = [k]
done[k] = true
cost[k] = 0
while(queue.size > 0)
    v = queue.pop
    
    edge[v].each do |i, j|
        if done[i] == false
            done[i] = true
            cost[i] = cost[v] + j
            queue.push(i)
        else
        end
    end
end

q.times do
    x, y = gets.chomp.split.map(&:to_i)
    puts cost[x] + cost[y]
end
