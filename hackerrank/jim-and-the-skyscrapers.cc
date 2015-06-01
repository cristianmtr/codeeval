// Problem description and test cases here
// https://www.hackerrank.com/challenges/jim-and-the-skyscrapers
#include <cmath>
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long calculatePossibs(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return 2*r;
    }

void printmap(map<int,int> vec)
	{
		for ( map<int,int>::iterator j = vec.begin(); j!=vec.end(); ++j)
		{
			cout << j->first << ": " << j->second << "; " ;
		}
		cout << endl;
	}

int main() {
	int nr_of_sky;
	vector<int> arr_sky;
	int height;
	cin >> nr_of_sky;
	while (cin >> height)
	{
		arr_sky.push_back(height);
	}
	unsigned long long total_sum = 0; // the final answer we are looking for
	// map init
	map<int, int> the_map;
	int i = 0;
	while ( i != arr_sky.size() )
	{
		// read value at index
		// and increase the count of the entry whose key == arr_sky[i]
		// check if there are entries in the map
		// where value is < arr_sky[i]
		// if so, pop it out, with its count
		// and calculate the stuff
		the_map[arr_sky[i]] += 1;

		// cout << "at index " << i << endl;
		// cout << "map is " << endl;
		// printmap(the_map);

		vector<map<int,int>::iterator> entries_to_be_deleted_from_the_map;
		for ( map<int,int>::iterator j = the_map.begin(); j!=the_map.end(); ++j)
		{
			if ( j->first < arr_sky[i] )
			{
				if (j->second >= 2)
				{
					total_sum += calculatePossibs(j->second,2);
				}
				// mark for erase
				entries_to_be_deleted_from_the_map.push_back(j);
			}
		}

		for (auto it : entries_to_be_deleted_from_the_map)
		{
			the_map.erase(it);
		}

		i++;
	}
	// account for cases such as "3 2 1 2 3 3"
	// where the tallest building is at the end
	// and check the map for any remaining entries
	for ( map<int,int>::iterator j = the_map.begin(); j!=the_map.end(); ++j)
	{
		if ( j->second >= 2 )
		{
			// cout << "at end " << j->first << " had " << j->second << " count"<< endl;
			total_sum += calculatePossibs(j->second,2);
		}
	}
	cout << total_sum << endl;	
	return 0;
}
