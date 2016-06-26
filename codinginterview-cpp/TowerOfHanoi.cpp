// http://geeksquiz.com/c-program-for-tower-of-hanoi/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void moveStack(int maxHeight, int height, string cur, string target, string aux) {
    if (height == 1) {
        printf("Move disk %d from %s to %s\n", maxHeight - height + 1, cur.c_str(), target.c_str());
        return;
    }

    moveStack(maxHeight - 1, height - 1, cur, aux, target);
    printf("Move disk %d from %s to %s\n", height, cur.c_str(), target.c_str());
    moveStack(maxHeight - 1, height - 1, aux, target, cur);
}

//int main()
int TowerOfHanoi()
{
    int n = 4;

    moveStack(n, n, "A", "C", "B");

    cin >> n;

    return 0;
}