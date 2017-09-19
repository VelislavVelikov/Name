require 'csv'

csv_file = ARGV[0]
# task = ARGV[1] useless line
csv_hash = Hash.new

CSV.foreach(csv_file) do |row|
	csv_hash[row[1]] = (csv_hash[row[1]]).to_f + row[2].to_f
end
printf("Video: %d, watched: %.2f%\n", csv_hash.key(csv_hash.values.max).to_i, csv_hash.values.max)