//g++ -o 9.string_rotation 9.string_rotation.cpp
/**
 * Cracking the coding interview 1-9
 * You have a function "isSubstring" which checks whether a string is substring of another.
 * Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to "isSubstring".
 *
 * Approach:
 * example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of s1.
 * lets say s1 = xy ==> wat + erbottle
 * similarly s2 = yx ==> erbottle + wat
 * Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
 * So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
 */

#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2 ) {
	size_t len1 = s1.length();
	size_t len2 = s2.length();
	if ( len1 == 0 || len1 != len2 ) {
		return false;
	}
	string concatS1 = s1 + s1;
	if ( concatS1.find(s2) != string::npos ) {//npos mean non-position and its value is set to -1.
		return true;
	} else {
		return false;
	}
}

int main() {
	string s1, s2;
	cout << "Enter string 1 : ";
	cin >> s1;
	cout << "\nEnter string 2 : ";
	cin >> s2;
	if ( isRotation(s1, s2) ) {
		cout << "Yes! " << s2 << " is rotation of " << s1 << "\n";
	} else {
		cout << "No! " << s2 << " is not a rotation of " << s1 << endl;
	}
	return 0;
}

