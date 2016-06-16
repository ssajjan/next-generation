require 'time'
def benchmark 
  b = Time.now 
  yield
  "#{Time.now - b} ms"
end

#1.1
def all_uniq str
  for i in 1..str.length
    test = str[i..-1]
    for a in 0..test.length  
      return false if test[a] === str[i-1]
    end
  end
  true
end 
##puts all_uniq(ARGV[0].chomp)

#1.2
def is_perm str1, str2
  return false if str1.length != str2.length
  str_ary1 = freq_ary(str1) 
  str_ary2 = freq_ary(str2)
  for i in 0...256
    return false if str_ary1[i] != str_ary2[i]
  end
  true
end
def freq_ary str
  freq = Array.new(256) {0}
  for i in 0...str.length
    freq[str[i].ord] += 1
  end
  freq
end
##puts benchmark {
## puts is_perm ARGV[0].chomp, ARGV[1].chomp
##}

#1.4

