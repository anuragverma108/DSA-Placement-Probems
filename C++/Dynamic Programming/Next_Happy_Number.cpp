#include<bits/stdc++.h> 
using namespace std;
int sumofsqr(int a){
    int sum=0;
    while(a>0){
        sum+=pow((a%10),2);
        a=a/10;
    }
    return sum;
    }
int nextHappy(int N){
    int x=N+1;
    int y=sumofsqr(N+1);
    unordered_set<int>s;
    while(y!=1){
        if(s.find(y)!=s.end()){
            x++;
            y=sumofsqr(x);
        }
        else{
        s.insert(y);
        y=sumofsqr(y);
        }
    
        }
    return x;
    }  
int main() 
{ 
    int N;
    cout<<"Enter N: ";
    cin>>N;
    cout << "The next happy number is: " << nextHappy(N) << endl;
    
    return 0; 
}
 