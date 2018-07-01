/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
/// Find a word from a dictionary
struct node{
    bool end_flag;
    node *next[27];
    node(){                     /// constructor
        end_flag = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
}*root;
void insert_word(string s){     /// for insert into dictionary
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'a';
        if(cur->next[id]==NULL)
            cur->next[id]=new node();
        cur = cur->next[id];
    }
    cur->end_flag=true;
}
bool search_word(string s){     /// for search into dictionary
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'a';
        if(cur->next[id]==NULL)
            return false;
        cur = cur->next[id];
    }
    return cur->end_flag;
}
void delete_tree(node *cur){        /// delete the dictionary, for free memory
    for(int i=0; i<26; i++){
        if(cur->next[i]){
            delete_tree(cur->next[i]);
        }
    }
    delete(cur);
}
int main()
{
    root = new node();
    int n;
    cout<<"how many word: ";
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        insert_word(s);
    }
    int q;
    cout<<"how many query: ";
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(search_word(s)) cout<<"found"<<endl;
        else cout<<"not found"<<endl;
    }
    delete_tree(root);
    return 0;
}
