#include<iostream>
#include<climits>
using namespace std;

bool used[10] = {false};
bool flag = false;

void construct(string pattern, string num, int i) {
    // base case
    if(num.size() == pattern.size()+1) {
        cout << num << endl;
        flag = true;
        return;
    }

    // recursive case
    if(i == 0) {
        for(int d = 1; d <= 9; d++){
            num.push_back(d + '0');
            used[d] = true;
            construct(pattern, num, i+1);

            if(flag)
                return;

            // backtrack
            num.pop_back();
            used[d] = false;
        }
    } else {
        int x = num.back() - '0';
        if(pattern[i] == 'I') {
            for(int d = x + 1; d <= 9; d++) {
                if(!used[d]){
                    num.push_back(d + '0');
                    used[d] = true;
                    construct(pattern, num, i+1);

                    if(flag)
                    return;

                    num.pop_back();
                    used[d] = false;
                }
            }
        } else {
            for(int d = 1; d < x; d++) {
                if(!used[d]){
                    num.push_back(d + '0');
                    used[d] = true;
                    construct(pattern, num, i+1);

                    if(flag)
                    return;

                    num.pop_back();
                    used[d] = false;
                }
            }
        }
    }
}

int main() {
    string pattern = "IID";
    string num = "";

    construct(pattern, num, 0);

    return 0;
}