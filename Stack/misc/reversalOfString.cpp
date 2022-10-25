#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
void reversedWord(char C[], int len){
    stack<char> S;
    for (int i = 0; i < len; i++)
    {
        S.push(C[i]);
    }
    for (int i = 0; i < len; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}
int main(){
    char C[51];
    cout<<"enter the word\n";
    gets(C);
    int n= strlen(C);
    reversedWord(C,n);
    cout<<"output ="<<C;
}
// // class Stack {
//     private:
//         char A[101];
//         int top;
//     public: 
//         void push(int num);
//         void pop();
//         int Top();
//         bool isEmpty();
// };