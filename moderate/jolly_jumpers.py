import sys

def is_jolly_jumper(n, nrs):
	# print 'n is {}'.format(n)
	# print 'nrs = {}'.format(nrs)
	expected_diffs = [i for i in range( 	1, n)]
	diffs = []
	for i in range(0, len(nrs)-1):
		diffs.append(abs(nrs[i] - nrs[i+1]))
	diffs.sort()
	if diffs == expected_diffs:
		return 'Jolly'
	else:
		return 'Not jolly'
		
if __name__ == '__main__':
	with open(sys.argv[1]) as f:
		for line in f:
			nrs = [int(i) for i in line.split(" ")]
			n = nrs[0]
			nrs = nrs[1:]
			print is_jolly_jumper(n, nrs)
