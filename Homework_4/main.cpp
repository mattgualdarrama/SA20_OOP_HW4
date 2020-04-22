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

	//C: Sort the lists (seperatly) and print them out: TODO
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

	vector<int*> matches = {};
	string findValue = "grape";
	int i = 0;
	for (auto it = f2.begin(); it != f2.end(); ++it) {
		if ((*it) == findValue)
			matches.push_back(it);
		
	}

	//E: Print out list f1:
	cout << "\nList f1:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}

	//F: Erase all of the fruit that come before kiwi from f1, then print out f1
	auto kiwiIt = find(f1.begin(), f1.end(), "kiwi");


}

int main() {
	q1func();
	q2func();
}