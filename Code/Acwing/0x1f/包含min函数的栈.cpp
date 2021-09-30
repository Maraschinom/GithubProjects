#include <bits/stdc++.h>
using namespace std ;

class MinStack {
private :
    stack<int> st , minst ;

public :

    MinStack() {
        while(!st.empty()) st.pop() ;        
        while(!minst.empty()) minst.pop() ;
    }

    void push(int x) {
        st.push(x) ;
        if(!minst.empty()) minst.push(min(minst.top(),x)) ;
        else minst.push(x) ;
    }

    void pop() {
        minst.pop() ;
        st.pop() ;
    }

    int top() {
        return st.top() ;
    }

    int getMin() {
        return minst.top() ;
    }
} ;