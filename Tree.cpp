#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
template<typename T>
class TreeNode{
    public: 
    T data;
    vector<TreeNode<T>*>children;

    TreeNode(T data){
        this->data=data;
    }

    // ~TreeNode( ){
    //     for(int i=0;i<root->children.size();i++){
    //         delete root->children[i];
    //     }
    // }

};

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data : ";
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int n;
    cout<<"Enter the number of children : ";
    cin>>n;
    for(int i=0;i<n;i++){
       TreeNode<int>*child=takeInput();
       root->children.push_back(child);
    }
    return root;
}

void display(TreeNode<int>* root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        display(root->children[i]);
    }
}

TreeNode<int>* takeInputLW(){
    int rootData;
    cout<<"Enter the root data : ";
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter the number of children of "<<front->data<<" : ";
        cin>>n;
        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter the"<<i+1<<" th node of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root; 
}

int countTree(TreeNode<int>*root){
    int count=1;
    for(int i=0;i<root->children.size();i++){
        count+=countTree(root->children[i]);
    }
    return count;
}

int sumTree(TreeNode<int>*root){
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=sumTree(root->children[i]);
    }
    return sum;
}

int heightTree(TreeNode<int>*root){
    int height=0;
    for(int i=0;i<root->children.size();i++){
        height=max(height,heightTree(root->children[i]));
    }
    return height+1;
}

void printLW(TreeNode<int>* root){
    queue<TreeNode<int>*>pending;
    pending.push(root);
    while(pending.size()){
        TreeNode<int>*front=pending.front();
        pending.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++){
            if(i<front->children.size()-1){
                cout<<front->children[i]->data<<",";
            }
            else{
                cout<<front->children[i]->data;
            }
           pending.push(front->children[i]);
        }
        cout<<endl;
    }
}
int main(){
    TreeNode<int>*root=takeInputLW();
    //display(root);
    printLW(root);
    cout<<endl<<"Number of Nodes are : "<<countTree(root);
    cout<<endl<<"Sum of all Nodes are : "<<sumTree(root);
    cout<<endl<<"Height of the tree are : "<<heightTree(root);

}
