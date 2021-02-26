int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    vector<int> v;
    map<int,int> mp;
    while(head!=NULL)
    {
        v.push_back(head->data);
        mp[head->data]++;
        head=head->next;
    }
    set<pair<pair<int,int>,int > >st1;
    for(int i=0;i<v.size();i++)
    {
        int x1=x;
        x1-=v[i];
        for(int j=i+1;j<v.size();j++)
        {
           int x2=x1;
            x2-=v[j];
            if(mp.find(x2)!=mp.end())
            {
                set<int> st;
                st.insert(v[i]);
                st.insert(v[j]);
                st.insert(x2);
                if(st.size()==3)
                {
                    int a=*st.begin();
                    st.erase(a);
                    int b=*st.begin();
                    int c=*st.rbegin();
                    st1.insert({{a,b},c});
                }
            }
        }
    }
    return st1.size();
} 