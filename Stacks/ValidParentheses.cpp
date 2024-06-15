#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string str) {
    stack<char> st;

    for(char ch: str) {
        switch (ch)
        {
            case '(':
            case '{':
            case '[': st.push(ch); 
                      break;
            case ']': if(!st.empty() && st.top() == '[') 
                        st.pop(); 
                      else 
                        return false; 
                      break;
            case '}': if(!st.empty() && st.top() == '{') 
                        st.pop(); 
                      else 
                        return false; 
                      break;
            case ')': if(!st.empty() && st.top() == '(') 
                        st.pop(); 
                      else 
                        return false; 
                      break;        
            default: break;
        }
    }
    return st.empty();
}

int main() {

	string str = "[]([{}])";

	isBalanced(str) ? cout << "balanced!" << endl :
	                       cout << "not balanced!" << endl;

	return 0;
}