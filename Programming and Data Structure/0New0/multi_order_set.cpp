#include<bits/stdc++.h>
using namespace std;

/// Multi-ordered set

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset < pair < int , int > > st;
orderset < pair < int , int > > ::iterator it;

pair<int,int> p;

int id ;

int main(){
    id = 0;
    st.insert( make_pair(20, id++) );
    st.insert( make_pair(12, id++) );
    st.insert( make_pair(20, id++) );
    st.insert( make_pair(2, id++) );
    cout<<st.size()<<endl;
    p = *st.find_by_order( 3 ) ;
    cout<<p.first<<endl;  /// staring form 0
    cout<<st.order_of_key(make_pair(20,1))<<endl;    /// bigger if not occur
    return 0;
}
