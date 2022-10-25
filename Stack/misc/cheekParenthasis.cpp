#include<bits/stdc++.h>
using namespace std;
stack<char> st;
bool cheekParanthesis(char input[]){
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i]=='(' || input[i]=='{' || input[i]=='[')
        {
            st.push(input[i]);
        }
        else if(input[i]==')' || input[i]=='}' || input[i]==']'){
            if(input[i]==')' && st.top()=='(' || input[i]=='}' && st.top()=='{' || input[i]==']' && st.top()=='['){
                st.pop();
            }
        }   
    }
    if(st.empty()==1)  return true;
    else    return false;
}
int main(){
    char Input[50] ;
    cout<<"enter an expression => \n";
    gets(Input);
    cout<<cheekParanthesis(Input);
    // cout<<endl<<Input;
    return 0;
}