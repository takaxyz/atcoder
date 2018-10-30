a, b, c, d = gets.chomp.chars.map(&:to_i)

if a + b + c + d == 7 then
    printf "%d+%d+%d+%d=7\n", a, b, c, d
elsif a - b + c + d == 7 then
    printf "%d-%d+%d+%d=7\n", a, b, c, d
elsif a + b - c + d == 7 then
    printf "%d+%d-%d+%d=7\n", a, b, c, d
elsif a + b + c - d == 7 then
    printf "%d+%d+%d-%d=7\n", a, b, c, d
elsif a - b - c + d == 7 then
    printf "%d-%d-%d+%d=7\n", a, b, c, d
elsif a + b - c - d == 7 then
    printf "%d+%d-%d-%d=7\n", a, b, c, d
elsif a - b - c - d == 7 then
    printf "%d-%d-%d-%d=7\n", a, b, c, d
elsif a - b + c - d == 7 then
    printf "%d-%d+%d-%d=7\n", a, b, c, d
end