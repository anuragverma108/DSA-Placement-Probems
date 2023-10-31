#include <iostream>
using namespace std;
int main(){
    int m,k;
    cout<<"enter number of elements in array \n";
    cin>>m;
     int n[m];
cout<<"enter value of k"<<endl;
cin>>k;
cout<<"enter element "<<endl;

for(int i=0;i<m;i++){
        cout<<"n["<<i<<"]="<<endl;
         cin>>n[i];
}
 for(int i=0; i<m-1;i++){
  for(int j=i; j<m;j++){
     if(n[j]<n[i]){   // for desending make greater than 
      int temp=n[j];
      n[j]=n[i];
      n[i]=temp;
     }
  } 
 }
 for(int i=0; i<m; i++){
    cout<<n[i]<<" ";
 }
 if(k<=m){
cout<<k<<"th smallest element:"<<n[k-1];
}}