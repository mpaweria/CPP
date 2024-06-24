#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class stack{
    queue<int> q;

    public:
        void push(T val) {
            q.push(val);
        }

        void pop() {
            int n = q.size();
            while (n > 1)
            {
                q.push(q.front());
                q.pop();
                n--;
            }
            q.pop();
        }

        T top() {
            int n = q.size();
            while (n > 1)
            {
                q.push(q.front());
                q.pop();
                n--;
            }
            T ans = q.front();
            q.pop();
            q.push(ans);

            return ans;
        }

        bool empty() {
            return q.empty();
        }

        int size() {
            return q.size();
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