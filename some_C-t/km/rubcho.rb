require 'CSV'

file = ARGV[0]
hash = Hash.new
CSV.foreach(file) do |row|
	hash[row[1]] = (hash[row[1]]).to_f + row[2].to_f
end

printf("Video: %d, watched: %.2f%\n", hash.key(hash.values.max).to_i, hash.values.max)