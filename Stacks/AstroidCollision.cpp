#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <bits/stdc++.h>

using namespace std;

// Time: O(n)
// Space: O(n)
vector<int> asteroidCollision(const vector<int>& asteroids) {
    stack<int> st;
    
    for(int ast: asteroids) {
        if(ast < 0 && !st.empty() && st.top() > 0) {
            bool flag = true;
            while (!st.empty() && st.top() > 0)
            {
                if(abs(ast) > st.top()) {
                    st.pop();
                } else if(abs(ast) < st.top()) {
                    flag = false;
                    break;
                } else {
                    st.pop();
                    flag = false;
                    break;
                }                
            }    
            if(flag) {
                st.push(ast);
            }        
        } else {
            st.push(ast);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> v = asteroidCollision(asteroids);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}