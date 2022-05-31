//reverse a String using Recursion

#include<bits/stdc++.h>
using namespace std;

//Using Stacks
void reverse(stack<char> q, string &rev){
    int size = q.size();
    if(size>0){
        char top = q.top();
        rev = rev + top;
        q.pop();
        reverse(q,rev);
    }
    return;
}



//without extra space -->>> EXACT RECURSION
void reverse(string s){
    int size = s.length();
    if(size==0){
        return;
    }
    reverse(s.substr(1));
    cout<<s[0];
}

int main(){
    string s = "abcdef";

    //STACK
    // int n = s.size();
    // stack<char> q;
    // string rev = "";
    // for(int i=0; i<n; i++){
    //     q.push(s[i]);
    // }
    // reverse(q,rev);
    // cout<<rev<<endl;

    reverse(s);
    return 0;
}