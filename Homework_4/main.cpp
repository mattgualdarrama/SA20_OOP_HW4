#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <iterator>
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

	while (first != last) {
		*result = (pred(*first)) ? val : *first;
		first++;
		result++;
	}

	return result;
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

list<pair<string,string>> loadDatabase() {
	//Doing this manually to eliminate the need to read a file in and can keep the project in one file
	pair<string, string> a[18];
	a[0].first = "Billie Holiday";		a[0].second = "Summertime";
	a[1].first = "Billie Holiday";		a[1].second = "I Can't Get Started";
	a[2].first = "Woody Guthriey";		a[2].second = "The Titanic";
	a[3].first = "Ernest Stone";		a[3].second = "The Titanic";
	a[4].first = "Bix Beiderbecke";		a[4].second = "Singin' the Blues";
	a[5].first = "Bix Beiderbecke";		a[5].second = "In a Mist";
	a[6].first = "Ruth Etting";			a[6].second = "Singin' the Blues";
	a[7].first = "Bunny Berigan";		a[7].second = "Singin' the Blues";
	a[8].first = "Louis Armstrong";		a[8].second = "West End Blues";
	a[9].first = "Louis Armstrong";		a[9].second = "Stardust";
	a[10].first = "Louis Armstrong";	a[10].second = "Knee Drops";
	a[11].first = "Jack Jenny";			a[11].second = "Stardust";
	a[12].first = "Sidney Bechet";		a[12].second = "Summertime";
	a[13].first = "Sidney Bechet";		a[13].second = "Wild Man Blues";
	a[14].first = "Cootie Williams";	a[14].second = "West End Blues";
	a[15].first = "Frank Hutchison";	a[15].second = "The Last Scene of the Titanic";
	a[16].first = "Frank Hutchison";	a[16].second = "Worried Blues";
	a[17].first = "Doc Watson";			a[17].second = "Worried Blues";

	list < pair<string, string>> temp;
	for (int i = 0; i < 18; i++) {
		temp.push_back(a[i]);
	}

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
	
	//D: Insert  the  fruit  from  f2  which  start  with  the  string  "grape"  into  the  position  after  banana  in  f1  (Note: you will need to find these positions)
	//Find every word that has "grape" in it
	string findValue = "grape";
	list<string> matches = {};

	//Find every instance of the string "grape" in f2
	for (auto it = f2.begin(); it != f2.end(); ++it) {
		if ((*it).find(findValue) != string::npos) {
			matches.push_back((*it));
		}
	}

	//find the location of banana in F1
	list<string>::iterator bananaIndex;
	
	for (auto it = f1.begin(); it != f1.end(); ++it) {
		if ((*it) == "banana") {
			bananaIndex = it;
		}
	}
	bananaIndex++;
	//insert grape words into f1
	for (auto it = matches.begin(); it != matches.end(); ++it) {
		f1.insert(bananaIndex, (*it));
	}

	//E: Print out list f1:
	cout << "\nList f1 with grape:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}

	//F: Erase all of the fruit that come before kiwi from f1, then print out f1
	auto kiwiIt = find(f1.begin(), f1.end(), "kiwi");

	f1.erase(f1.begin(), kiwiIt);
	cout << "\nList f1 with fruit before kiwi erased:\n";
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
		size_t found = (*it).find("berry");
		if (found != string::npos) {
			(*it) = "berry";
		}
	}
	//This is really "hacky"
	f1.remove("berry");
	cout << "\nList f1 with berry removed:\n";
	for (auto const& i : f1) {
		cout << "\t" << i << endl;
	}
}

void q3func() {
	//Write your own version of the STL algorithm replace_copy_if().Since this function is already part of the standard library you might want to rename it.For example, my_replace_copy_if.                                                                
	list<int> l{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
	vector<int> v;
	v.resize(l.size()); 

	my_replace_copy_if(l.begin(), l.end(), v.begin(), [](int n) {return n > 5; }, -1);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
}
                                
void q4func() {
	//A:  Store the data in an appropriate STL container
	list <pair<string, string>> database;
	list<pair<string, string>> dbList;
	dbList = loadDatabase();

	cout << "\nMusic Database:" << endl;
	for (auto it = dbList.begin(); it != dbList.end(); ++it) {
		cout << it->first << "\t\t" << it->second << endl;
	}

	//B: Ask the user for a keyword (could be a part of the artist name or song title) and print out all entries that contain that keyword.
	cout << "\nUser Input:" << endl << "\t Enter a search term (Case Sensative):\t";
	string input;	getline(cin, input);

	for (auto it = dbList.begin(); it != dbList.end(); ++it) {
		if ((*it).first.find(input) != string::npos || (*it).second.find(input) != string::npos) {
			cout << (*it).first << "\t" << (*it).second << endl;
		}
	}
	cout << "end of search results" << endl;

	//C: Print out all of the songs in the database in alphabetical order (don't list titles more than once) and give how many times that song occurs in the database. TODO
	list<pair<string, int>> songList;
	pair<string, int> temp;
	
	for (auto it = dbList.begin(); it != dbList.end(); it++) {
		temp.first = it->second; temp.second = 1;
	}
	//sort(songList.begin(), songList.end());

	//for (auto it = songList.begin(); it != songList.end(); it++) {
	//	cout << it->first << endl;
	//}
}
             
void q5func() {
	//Overload the operator+ to concatenate two vectors. That is, if we had vectors v1: 1,3,5 and v2: 2,4,6 then v1+v2 would return a new vector: 1,3,5,2,4,6. 
	//The only requirement is that the two vectors contain the same type of elements. Also, you must do this as a template function (i.e., don't just do this for vectors of ints).

	vector<int>v1{ 3,5,6,1,7 }, v2{ 6,1,9,10 }, v3;
	vector<string> w1{ "Hello" }, w2{ "World" }, w3;
	v3 = v1 + v2; //v3 should be 3,5,6,1,7,6,1,9,10

	cout << "\nV3:" << endl;
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
	//q1func(); 
	//q2func(); 
	//q3func();                                                                                                                                                                                                                                                                         
	q4func(); //TODO                                                                                                                                                                                                                                                                      
	//q5func(); 
}