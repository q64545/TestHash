#include <string>
#include <iostream>
#include "basic_hash.h"

using namespace std;

int main(int argc, char* argv[]) {
	string a(argv[1]);

	const char* head = a.c_str();
	int len = a.length();
	cout << "string: " << a << endl;
	cout << "head: " << *head << endl;
	cout << "len: " << len << endl;
	size_t hash_v = basic_hash_ns::ELFHash(head);
	cout << "hash_value: " << hash_v << endl;
	return 0;
}