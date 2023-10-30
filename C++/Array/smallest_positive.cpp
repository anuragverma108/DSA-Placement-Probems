#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m;
    cout<<"enter number of elements in array \n";
    cin>>m;
     int n[m];

cout<<"enter element "<<endl;

for(int i=0;i<m;i++){
        cout<<"n["<<i<<"]="<<endl;
         cin>>n[i];
}
for(int i=0; i<m; i++){
    if(n[i]>0&& n[i]<=m){
         int chair= n[i]-1;
    if( n[chair]!=n[i]){
        swap(n[chair],n[i]);
        i--;
    }}
}
for (int i=0; i<m; i++){
    if(i+1!=n[i]){
        cout<<"smallest missing:"<<i+1;
         break;
    }else{
         cout<<"smallest missing:"<<m+1;
    }
}
}