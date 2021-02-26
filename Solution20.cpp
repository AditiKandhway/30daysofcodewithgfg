void hashit(Node* root,map<Node*,Node*> &hash)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left!=NULL)
    hash[root->left]=root;
    if(root->right!=NULL)
    hash[root->right]=root;
    hashit(root->left,hash);
    hashit(root->right,hash);
}
void gettarget(Node* root,int target,Node* &temp)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==target)
    {
        temp=root;
    }
    gettarget(root->left,target,temp);
    gettarget(root->right,target,temp);
}
int getdist(Node* root,int target,int k,map<Node*,Node*> &hash)
{
    queue<Node*> q;
    multiset<Node*> st;
    Node* temp;
    gettarget(root,target,temp);
    q.push(temp);
    q.push(NULL);
    st.insert(temp);
    // cout<<temp->data<<endl;
    int currlevel=0;
    while(!q.empty())
    {
        Node* f=q.front();
        q.pop();
        if(currlevel==k)
        {
            break;
        }
        if(f==NULL)
        {
            currlevel++;
            q.push(NULL);
        }
        else{
            if(hash[f]!=NULL && hash.find(f)!=hash.end() && st.find(hash[f])==st.end())
            {
                q.push(hash[f]);
                st.insert(hash[f]);
                // cout<<hash[f]->data<<endl;
            }
            if(f->left!=NULL && st.find(f->left)==st.end())
            {
                q.push(f->left);
                st.insert(f->left);
                // cout<<f->left->data<<endl;
            }
            if(f->right!=NULL && st.find(f->right)==st.end())
            {
                q.push(f->right);
                st.insert(f->right);
                // cout<<f->right->data<<endl;
            }
        }
    }
    int sum=0;
    for(Node* x:st)
    {
        // cout<<x->data<<" ";
        sum+=x->data;
    }
    // cout<<endl;
    return sum;
}

class Solution{

    public:
    int sum_at_distK(Node* root, int target, int k)
    {
        // Your code goes here
        map<Node*,Node*> hash;
        hash[root]=NULL;
        hashit(root,hash);
        int cnt=getdist(root,target,k,hash);
        return cnt;
    }
};