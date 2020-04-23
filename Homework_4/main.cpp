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

template<typename InputIterator, typename OutputIterator, typename Predicate, typename T>
OutputIterator my_replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred, const T& val) {
	//Copies from source range[first, last) to destination range starting at position result.
	//If an element in source makes pred true then it is replaced in the destination by val.
	//Returns final value of the result iterator.
	return OutputIterator();
}

template <typename T>
vector<T> operator+(const vector<T>& v1, const vector<T>& v2)
{
	vector<T> temp;
	temp.reserve(v1.size() + v2.size());
	temp.insert(temp.end(), v1.begin(), v1.end());
	temp.insert(temp.end(), v2.begin(), v2.end());
	return temp;
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
	
	//TODO: Fix
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

	//TODO: Fix
	//H: Remove all fruit from f1 that contain the string "berry" and print it out.
	//for (auto it = f1.begin(); it != f1.end(); ++it) {
	//	bool found = (*it).find("berry");
	//	if (found) {
	//		f1.erase(it);
	//	}
	//}
}

void q3func() {
	//Write your own version of the STL algorithm replace_copy_if().Since this function is already part of the standard library you might want to rename it.For example, my_replace_copy_if.
	//TODO wtf is this question?
	//list<int> l{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
	//vector<int> v;
	//v.resize(l.size); 

	//my_replace_copy_if(l.begin(), l.end(), v.begin(), [](int n) {return n > 5; }, -1);
}

void q4func() {
	//A:  Store the data in an appropriate STL container TODO

	//B: Ask the user for a keyword (could be a part of the artist name or song title) and print out all entries that contain that keyword. TODO

	//C: Print out all of the songs in the database in alphabetical order (don't list titles more than once) and give how many times that song occurs in the database. TODO

}

void q5func() {
	//Overload the operator+ to concatenate two vectors. That is, if we had vectors v1: 1,3,5 and v2: 2,4,6 then v1+v2 would return a new vector: 1,3,5,2,4,6. 
	//The only requirement is that the two vectors contain the same type of elements. Also, you must do this as a template function (i.e., don't just do this for vectors of ints).

	vector<int>v1{ 3,5,6,1,7 }, v2{ 6,1,9,10 }, v3;
	vector<string> w1{ "Hello" }, w2{ "World" }, w3;
	v3 = v1 + v2; //v3 should be 3,5,6,1,7,6,1,9,10

	cout << "V3:" << endl;
	for (size_t i = 0; i < v3.size(); i++) {
		cout << v3.at(i) << "\t";
	}
	cout << endl;
	
	w3 = w1 + w2;  //w3 should be “HelloWorld”

	cout << "W3:" << endl;
	for (size_t i = 0; i < w3.size(); i++) {
		cout << w3.at(i) << "\t";
	}
	cout << endl;
}



int main() {
	q1func(); 
	q2func(); //todo
	q3func(); //todo
	q4func(); //todo
	q5func(); 
}