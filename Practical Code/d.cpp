#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }

};

Node* insetIntoBst(Node* root,int d){

    if(root == NULL){

        root =  new Node(d);
        return root;
    }

    if(d > root->data){

        root->right = insetIntoBst(root->right,d);

    }
    else{
        
        root->left = insetIntoBst(root->left,d);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* serach(Node* root,int key){

    if(root == NULL || root->data == key)
    {
        return root;
    }

    if(key > root->data){
        return serach(root->right,key);
    }
    
    return serach(root->left,key);
    
}

void find_min(Node* root){

    while(root->left != NULL){
        root = root->left;
    }

    cout<<"Minimum value is : "<<root->data;
}



int  main(){

    Node* root=NULL;

    // root = insetIntoBst(root,12);
    // insetIntoBst(root,10);
    // insetIntoBst(root,30);
    // insetIntoBst(root,9);
    // insetIntoBst(root,40);
    // insetIntoBst(root,3);

    int n;
    cout<<"How many Element you want to insert : ";
    cin>>n;
    cout<<endl;
    int data;

    cout<<"Enter Root First : ";
    
    for(int i=0;i<n;i++){

        cin>>data;
        if(root == NULL){
            root = new Node(data);
        }
        else{
            insetIntoBst(root,data);
        }
    }

    inorder(root);

    cout<<endl;
    int key;
    cout<<"Enter Elemrnt you want to search : ";
    cin>>key;
    cout<<endl;
    root = serach(root,key);
    if(!root){
        cout<<"Data not found ";
    }
    else{
        cout<<"Data Found ";
    }
    cout<<endl;
    find_min(root);
    return 0;
}