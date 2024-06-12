#include<iostream>
using namespace std;

string spellingMap[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void spellNum(int n) {
    // base case
    if(n == 0)
        return;

    // recursive case
    spellNum(n/10);
    int d = n%10;

    cout << spellingMap[d] << " ";

    // switch (d)
    // {
    // case 1 :cout << "one ";
    //         break;
    // case 2 :cout << "two ";
    //         break;
    // case 3 :cout << "three ";
    //         break;
    // case 4 :cout << "four ";
    //         break;
    // case 5 :cout << "five ";
    //         break;
    // case 6 :cout << "six ";
    //         break;
    // case 7 :cout << "seven ";
    //         break;
    // case 8 :cout << "eight ";
    //         break;
    // case 9 :cout << "nine ";
    //         break;
    // case 0 :cout << "zero ";
    //         break;
    
    // default:
    //     break;
    // }
}

int main() {
    int n = 123;

    spellNum(n);

    return 0;
}