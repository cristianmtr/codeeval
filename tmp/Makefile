a: linked.cc
	g++ -std=c++11 linked.cc -o a

run: a
	cmd /k "< linked.in a > test.out 2> test.err"

all:  run