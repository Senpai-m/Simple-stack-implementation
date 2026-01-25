#include <thread>
#include <bits/stdc++.h>
#include "Stack.h"
#include <stack>
#include <vector>
#include <bits/stl_stack.h>

using namespace std;
#define Banki ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

#define read freopen("Input.txt", "r", stdin); \
freopen("Output.txt", "w", stdout); \
freopen("Errors.txt", "a", stderr); \

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define el '\n'
#define sp " "
int dx[] = { -1 ,  0 ,  1 , 1 , 1 , 0 , -1 , -1 };
int dy[] = { -1 , -1 , -1 , 0 , 1 , 1 ,  1 ,  0 };
bool op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int calc(int op1 ,int op2 , char op) {
    if (op == '+') return op1 + op2;
    if (op == '-') return op1 - op2;
    if (op == '*') return op1 * op2;
    if (op == '/') return op1 / op2;
}
bool priority(char a, char b) {
    if ((a == '*' or a == '/') and (b == '+' or b == '-' )or b == '(' or a == '(') return true;
    return false;
}
string invert(string &t) {
    string ans ;
    Stack<char> s;
    for (auto i : t) {
        if (op(i)) {
            if (s.isEmpty()) {
                s.push(i);
            }
            else if (priority(i, s.top()) and s.top() == '(') {
                s.push(i);
            }
            else {
                ans.pb(s.top());
                s.pop();
                s.push(i);
            }
        }
        else if (i == '(' or i == ')') {
           if (i == '(') s.push(i);
            else {
                while (s.top() != '(') {
                    ans.pb(s.top());
                    s.pop();
                }
             s.pop();
            }
        }
        else {
            ans.pb(i);
        }
    }
    while (!s.isEmpty()) {
        if (s.top() != '(' and s.top() != '(')
        ans.pb(s.top());
        s.pop();
    }
    return ans ;
}
void run() {
string t; cin >> t;
   string s = invert(t);
cout << s<< el;
    Stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (op(s[i])) {
            int op2 =(st.top()); st.pop();
            int op1 = (st.top()); st.pop();
            char opp = s[i];
            st.push((calc(op1,op2,opp)));
        }
        else {
            st.push(s[i] - '0');
        }
    }
    cout << st.top();


}

signed main() {
    Banki
    read
    int __ = 1;
    //  cin >> __;
    for (int _ = 1; _ <= __; _++) {
        run();
        if (_ != __) cout << el;
    }
    return 0;
}