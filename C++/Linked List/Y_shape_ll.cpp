#include<iostream>

#include<bits/stdc++.h>
using namespace std;

// Link list Node 
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(Node* head1, Node* head2)
{
    Node* p=head1;
    Node* q=head2;
    unordered_map<Node*,int>seen;
    while(p!=NULL){
        seen[p]++;
        p=p->next;
    }
    while(q!=NULL){
        seen[q]++;
        if(seen[q]==2){
            return q->data;
        }
        q=q->next;
    }
    return -1;
}
vector<int> take(int n){
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>ans[i];
    return ans;
}

Node* inputList(int size, vector<int> v)
{
    if(size==0) return NULL;
    
    int val = v[0];
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        val = v[i+1];
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

int main()
{
    srand(time(0));
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        int p = rand()%3;
        
        vector<int> v1 = take(n1);
        vector<int> v2 = take(n2);
        vector<int> v3 = take(n3);
        
        
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;
        
        if(p==0){
            common = inputList(n3, v3);
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
        }
        else if(p==1){
            
            head1 = inputList(n1, v1);
            common = inputList(n3, v3);
            head2 = inputList(n2, v2);
        }
         else{
            
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
            common = inputList(n3, v3);
        }
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
