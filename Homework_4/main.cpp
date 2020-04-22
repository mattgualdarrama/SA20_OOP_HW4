#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<map<string, int>::const_iterator> val_count(const map<string, int>& m, int val) {
	vector<map<string, int>::const_iterator> retval;

	for (auto it = m.begin(); it != m.end(); ++it) {
		if ((*it).second == val) {
			retval.push_back(it);
		}
	}
	return retval;
}

void q1func() {
	map<string, int> q1map;

	for (int i = 0; i < 10; i++) {
		string key = to_string(i);
		q1map.insert(std::pair<string, int>(key, i));
	}
	vector<map<string, int>::const_iterator> retval = val_count(q1map, 3);
}

void q2func() {
	//A: create the following two lists:
	list<string> f1 = { "orange", "banana", "kiwi", "lemon", "raspberry", "strawberry", "grape" };
	list<string> f2 = { "lemon", "grapefruit", "apple", "pear", "lime", "grape", "ornage", "blueberry" };

	//B: Print out the two lists of fruits
	cout << "\nList f1:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}
	cout << "\nList f2:\n";
	for (auto const& i : f2) {
		cout << "\t" << i << endl;
	}

	//C: Sort the lists (seperatly) and print them out:
	f1.sort();
	cout << "\nList f1 sorted:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}

	f2.sort();
	cout << "\nList f2 sorted:\n";
	for (auto const& i : f2) {
		cout << "\t" << i << endl;
	}

	//D: Insert  the  fruit  from  f2  which  start  with  the  string  "grape"  into  the  position  after  banana  in  f1  (Note: you will need to find these positions)
	//vector<int*> matches = {};
	//string findValue = "grape";
	//int i = 0;
	//for (auto it = f2.begin(); it != f2.end(); ++it) {
	//	if ((*it) == findValue)
	//		matches.push_back(it);
	//	
	//}

	//E: Print out list f1:
	cout << "\nList f1:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}

	//F: Erase all of the fruit that come before kiwi from f1, then print out f1
	auto kiwiIt = find(f1.begin(), f1.end(), "kiwi");

	f1.erase(f1.begin(), kiwiIt);
	cout << "\nList f1:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}

	//G: Randomly permute the list f2 and then print it out
	vector<string> temp(f2.begin(), f2.end());
	random_shuffle(temp.begin(), temp.end());
	f2.clear();
	copy(temp.begin(), temp.end(), back_inserter(f2));
	cout << "\nList f2 Permuted:\n";
	for (auto const& i : f2) {
		cout << "\t" << i << endl;
	}

	//H: Remove all fruit from f1 that contain the string "berry" and print it out.
	for (auto it = f1.begin(); it != f1.end(); ++it) {
		bool found = (*it).find("berry");
		if (found) {
			f1.erase(it);
		}
	}
}

int main() {
	q1func();
	q2func();
}