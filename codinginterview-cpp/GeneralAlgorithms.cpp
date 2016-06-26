#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "limits.h"
#include <string>

#include "HelperMethod.h"

using namespace std;

// https://www.hackerrank.com/challenges/sherlock-and-valid-string
int main()
// int valid_string()
{
    string test;
    getline(cin, test);

    vector<int> freq(27, 0);
    for (int i = 0; i < test.length(); ++i)
    {
        freq[test[i] - 'a']++;
    }

    int numOneFreq = 0;
    int minFreq = -1;
    int maxFreq = -1;
    for (int i = 0; i < 27; ++i)
    {
        if (freq[i] == 1)
        {
            ++numOneFreq;
        }

        if (freq[i] != 0 && (minFreq == -1 || freq[i] < minFreq))
        {
            minFreq = freq[i];
        }

        if (freq[i] != 0 && (maxFreq == -1 || freq[i] > maxFreq))
        {
            maxFreq = freq[i];
        }
    }

    if (minFreq == maxFreq)
    {
        cout << "YES" << endl;
        return 0;
    }

    if (numOneFreq == 1)
    {
        int otherFreq = -1;
        for (int i = 0; i < 27; ++i)
        {
            if (freq[i] != 0 && freq[i] != 1)
            {
                if (otherFreq == -1)
                {
                    otherFreq = freq[i];
                }
                else if (otherFreq != freq[i])
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }

        cout << "YES" << endl;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < 27; ++i)
        {
            if (freq[i] != 0)
            {
                sum += freq[i] - minFreq;
            }
        }

        if (sum <= 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

// https://www.hackerrank.com/challenges/the-love-letter-mystery
// int main()
int love_letter()
{
    int numTests;
    cin >> numTests;

    string test;
    getline(cin, test);

    for (int i = 0; i < numTests; ++i)
    {
        int numChange = 0;
        getline(cin, test);

        for (int j = 0; j < test.length() / 2; ++j)
        {
            int diff = test[j] - test[test.length() - 1 - j];
            numChange += diff > 0 ? diff : -diff;
        }

        cout << numChange << endl;
    }

    return 0;
}

// https://www.hackerrank.com/challenges/two-strings
// int main()
int two_strings()
{
    int numTests;
    cin >> numTests;

    string test1, test2;
    getline(cin, test1);

    for (int i = 0; i < numTests; ++i)
    {
        vector<bool> hasChar(27, false);

        getline(cin, test1);
        getline(cin, test2);

        for (int j = 0; j < test1.length(); ++j)
        {
            hasChar[test1[j] - 'a'] = true;
        }

        bool subStringExists = false;
        for (int j = 0; j < test2.length(); ++j)
        {
            if (hasChar[test2[j] - 'a'])
            {
                subStringExists = true;
                break;
            }
        }

        if (subStringExists)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

// https://www.hackerrank.com/challenges/gem-stones
// int main()
int gemstone()
{
    int numRocks;
    cin >> numRocks;

    vector<int> elem(27, 0);
    string test;
    getline(cin, test);

    for (int i = 0; i < numRocks; ++i)
    {
        getline(cin, test);
        vector<int> curElem(27, 0);
        for (int j = 0; j < test.length(); ++j)
        {
            curElem[test[j] - 'a']++;
        }

        for (int j = 0; j < 27; ++j)
        {
            if (curElem[j] > 0)
            {
                elem[j]++;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 27; ++i)
    {
        if (elem[i] == numRocks)
        {
            ++sum;
        }
    }

    cout << sum << endl;

    return 0;
}

// https://www.hackerrank.com/challenges/anagram
// int main()
int anagram()
{
    int numTest;
    cin >> numTest;

    string test;
    getline(cin, test);

    for (int i = 0; i < numTest; ++i)
    {
        getline(cin, test);

        if (test.length() % 2 == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> freq1(27, 0);
            vector<int> freq2(27, 0);

            for (int i = 0; i < test.length() / 2; ++i)
            {
                freq1[test[i] - 'a']++;
            }

            for (int i = test.length() / 2; i < test.length(); ++i)
            {
                freq2[test[i] - 'a']++;
            }

            int sum = 0;
            for (int i = 0; i < 27; ++i)
            {
                sum += freq1[i] > freq2[i] ? freq1[i] - freq2[i] : 0;
            }

            cout << sum << endl;
        }
    }
    
    return 0;
}