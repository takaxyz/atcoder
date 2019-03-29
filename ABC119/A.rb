require 'date'
puts Date.parse('2019/04/30') >= Date.parse(gets.chomp) ? 'Heisei' : 'TBD'