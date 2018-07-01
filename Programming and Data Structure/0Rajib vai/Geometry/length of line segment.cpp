#include<bits/stdc++.h>
using namespace std;

unsigned segments_union_measure(const vector<pair<int,int> > & a){
    unsigned n = a.size();
    vector<pair<int,bool> > x(n * 2);
    for(unsigned i = 0; i < n ; i++){
        x[i * 2] = make_pair(a[i].first, false);
        x[i * 2 + 1] = make_pair(a[i].second, true);
    }

    sort(x.begin(), x.end());

    unsigned result = 0,c = 0;
    for(unsigned i = 0;i < 2 * n; i++){
        if(c && i) result += unsigned( x[i].first - x[i - 1].first);
        if(x[i].second) ++c;
        else --c;
        cout << x[i].first << " " << c << " " << result << '\n';
    }
    return result;
}

int main(){
    int test; cin >> test;
    while(test--){
        int n; cin >> n;
        vector<pair<int,int> > v;
        for(int i=1;i<=n;i++){
            int x,y; cin >> x >> y;
            v.push_back(make_pair(x,y));
        }
        cout << segments_union_measure(v) << '\n';
    }
    return 0;
}
