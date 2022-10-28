#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st, int temp)
{

	if(st.size() == 0)
	    st.push(temp);
	else
	{
		int x = st.top();
		st.pop();
		insert_at_bottom(st, temp);
		st.push(x);
	}
}

void reverseStack(stack<int> &st)
{
	if(st.size()>0)
	{
		int temp = st.top();
		st.pop();
		reverseStack(st);
		insert_at_bottom(st, temp);
	}
}

int main() {

    int n, temp;
    cin>>n;

    stack<int> stack;
    for(int i=0;i<n;i++) {
        cin>>temp;
        stack.push(temp);
    }

    reverseStack(stack);

    while(!stack.empty()) {
        cout<<stack.top() << " ";
        stack.pop();
    }
    return 0;
}

"""
#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> st)
{
    if(!st.empty()) {
        int temp = st.top();
        st.pop();
        reverseStack(st);
        cout<<temp<<" ";
    }
}

int main() {
    int n, temp;
    cin>>n;
    stack<int> stack;
    for(int i=0;i<n;i++) {
        cin>>temp;
        stack.push(temp);
    }
    reverseStack(stack);
    return 0;
}
"""