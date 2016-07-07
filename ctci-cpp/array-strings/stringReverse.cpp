// C++ program to reverse a string with special characters
#include<bits/stdc++.h>

using namespace std;
 
// Returns true if x is an aplhabatic character, false otherwise
bool isAlphabet(char x)
{
    return ( (x >= 'A' &&  x <= 'Z') ||
             (x >= 'a' &&  x <= 'z') );
}
 
void reverse(char str[])
{
    // Initialize left and right pointers
    int r = strlen(str) - 1, l = 0;
printf("address of string: %p\n",str);
cout << "str pointer size: " << sizeof(str) << endl; // --> this will give pointer sieze.
//sizeof char string does not work in function
//http://stackoverflow.com/questions/11622146/why-sizeofparam-array-is-the-size-of-pointer
 
    // Traverse string from both ends until
    // 'l' and 'r'
    while (l < r)
    {
        // Ignore special characters
        if (!isAlphabet(str[l]))
            l++;
        else if(!isAlphabet(str[r]))
            r--;
 
        else // Both str[l] and str[r] are not spacial
        {
            swap(str[l], str[r]);
            l++;
            r--;
        }
    }
}
 
// Driver program
int main()
{
    char str[] = "a!!!b.c.d,e'f,ghi";
    cout << "Input string: " << str << endl;
	printf("address of string: %p\n",str);
    cout << "string len: " << strlen(str) << endl;
    cout << "string size: " << sizeof(str) << endl;
    reverse(str);
    cout << "Output string: " << str << endl;
    return 0;
}
