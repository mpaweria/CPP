#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class stack {
    queue<int> q1, q2;

    public:
        void push(T val) {
            if(q1.empty() && q2.empty())
                q1.push(val);
            else if(q1.empty())
                q2.push(val);
            else
                q1.push(val);
        }

        void pop() {
            if(q1.empty() && q2.empty())
                return;
            else if(q1.empty()) {
                while (q2.size() != 1)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                q2.pop();
            } else {
                while (q1.size() != 1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.pop();
            }
        }

        T top() {
            T ans;
            if(q1.empty() && !q2.empty()) {
                while (q2.size() != 1)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                ans = q2.front();
                q1.push(ans);
                q2.pop();
            } else {
                while (q1.size() != 1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                ans = q1.front();
                q2.push(ans);
                q1.pop();
            }
            return ans;
        }

        bool empty() {
            return q1.empty() && q2.empty();
        }

        int size() {
            return max(q1.size(), q2.size());
        }
};

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << "size = " << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}