
import sys

def find_duplicate(n, nrs):
	# print 'n = {}'.format(n)
	# print 'nrs = {}'.format(nrs)
	for i in range(0, len(nrs)):
		# print '\tone = {}'.format(nrs[i])
		for j in range(i+1, len(nrs)):
			# print '\t\ttwo = {}'.format(nrs[j])
			if nrs[i] == nrs[j]:
				return nrs[i]

if __name__ == '__main__':
	with open(sys.argv[1]) as f:
		for line in f:
			n = int(line.split(';')[0])
			nrs = line.split(';')[1]
			nrs = [int(nr) for nr in nrs.split(',')]
			print find_duplicate(n, nrs)