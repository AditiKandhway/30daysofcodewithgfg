class Solution{
public:
 int vac;
   pair<bool,bool> fun_vaccine(Node* root)
   {
       if(root==NULL)
       {
           return {false,true};
       }
       pair<bool,bool> left=fun_vaccine(root->left);
       pair<bool,bool> right=fun_vaccine(root->right);
       
       bool has=false;
       bool vaci=false;
       if(left.first||right.first)
       {
           vaci=true;
       }
       if(!left.second || !right.second)
       {
           has=true;
           vaci=true;
           vac++;
       }
       return {has,vaci};
   }
    int supplyVaccine(Node* root){
        // Your code goes here
        vac=0;
        pair<bool,bool> temp=fun_vaccine(root);
       if(!temp.second)
       {
           vac++;
       }
       return vac;
    }
};