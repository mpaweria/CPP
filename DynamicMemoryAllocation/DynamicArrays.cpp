#include<iostream>
using namespace std;

int* resize(int* arr, int c) {
    int *temp = new int[2*c];
    for(int i=0; i<=c; i++)
        temp[i] = arr[i];
    delete [] arr;
    return temp;
}

int main() {
    int *arr = new int[1];
    int s = 0, c = 1, val;

    while(true) {
        cout << "Enter value you want to add in array: ";
        cin >> val;

        // We'll stop taking values from the user when they enter a negative value
        if(val < 0)
            break;

        if(s == c){
            arr = resize(arr, c);
            c = 2 * c;
        } 
        arr[s] = val;
        s++;
    }

    cout << "Vaules in array are: ";
    for(int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
}