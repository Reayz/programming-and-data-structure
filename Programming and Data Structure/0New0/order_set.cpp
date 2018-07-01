#include<bits/stdc++.h>
using namespace std;

/// Ordered set

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset<int> st;
orderset<int> :: iterator it;

int main(){
    st.insert(5);
    st.erase(5);
    st.insert(5);
    cout<<st.size()<<endl;
    cout<<*st.find_by_order(2)<<endl;  /// staring form 0
    cout<<st.order_of_key(55)<<endl;    /// bigger if not occur
    return 0;
}
