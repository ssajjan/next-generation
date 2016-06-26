#include <iostream>
#include <string>

using namespace std;

class PeopleCircle
{
public:
    string order(int numMales, int numFemales, int K)
    {
        string values(numMales + numFemales, 'M');
        cout << "String : " << values << endl;

        int index = -1;
        for (int i = 0; i < numFemales; ++i)
        {
            int maleFound = 0;
            while (maleFound < K)
            {
                index++;
                index = index % (numMales + numFemales);

                if (values[index] == 'M')
                {
                    maleFound++;
                }
            }
            cout << index << endl;

            values[index] = 'F';
        }

        return values;
    }
};

// int main()
int SRM_147_Div1_350()
{
    PeopleCircle people;
    cout << people.order(5, 3, 2) << endl;

    int test;
    cin >> test;

    return 0;
}