import sys

def main():
	print_lines = []
	with open(sys.argv[1]) as f:
		for line in f:
			contents = line.split(':')
			user = contents[0]
			print 'user = {}'.format(user)
			groups = {}
			friends = 0
			for friend in contents[1].split(','):
				friends += 1
				print '\tfriend = {}'.format(friend)
				with open(sys.argv[1]) as g:
					for line in g:
						if friend == line.split(':')[0]:
							for group in line[:-1].split(':')[2].split(','):
								if group.strip() != '':
									print '\t\tgroup = {}'.format(group)
									if group not in groups.keys():
										groups[group]=0
									groups[group]+=1
			# print 'friends = {}'.format(friends)
			print 'groups = {}'.format(groups)
			recommendations = []
			for group in groups.keys():
				if groups[group] >= friends/2:
					recommendations.append(group)
			# del(groups)
			# del(friends)
			recommendations.sort()
			line = '{}:'.format(user)
			for rec in recommendations:
				line = line + '{},'.format(rec)
			line = line[:-1]
			# del(line)
			print_lines.append(line)
			# del(recommendations)
		print_lines.sort()
		for line in print_lines:
			print line
		return 0
			
if __name__ == '__main__':
	main()