#include <bits/stdc++.h>
using namespace std;

long long int n=1e9+7;
map<int,int>m;
long long power(int N,int R)
{
    if(R==0){
        return 1;
    }
    if (R==1){
        return int(pow(N,1))%n;
    }
    if(m.find(R)!=m.end()){
        return m[R];
    }
    return m[R]=(power(N,R/2)*power(N,R-R/2))%n;
}
// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}



int main()
{   
    long long N;
    cout<<"Enter number N: ";
    cin>>N;//input N

    long long R = 0; 

    // reverse the given number n
    R = rev(N);
    //power of the number to it's reverse
    long long ans =power(N,R);
    cout << ans<<endl;

}