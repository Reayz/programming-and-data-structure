#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //vector<datatype>name
    //x.push_back(value)
    //x.at(index)
    //x.size()
    //x.begin()
    //x.insert(x.begin()+integer, value)
    //x.erase(x.begin()+integer)
    //x.clear()
    //x.empty()
    //x.frong()
    //x.back()


    vector<int>x;

    x.push_back(3);
    x.push_back(17);
    x.push_back(15);
    cout<<"Vector: ";
    for(unsigned int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;

    x.insert(x.begin(), 43);
    cout<<"Vector: ";
    for(unsigned int i=0;i<x.size();i++){
        cout<<x.at(i)<<" ";
    }
    cout<<endl;

    x.insert(x.begin()+2, 74);
    cout<<"Vector: ";
    for(unsigned int i=0;i<x.size();i++){
        cout<<x.at(i)<<" ";
    }
    cout<<endl;

    x.insert(x.end(), 89);
    cout<<"Vector: ";
    for(unsigned int i=0;i<x.size();i++){
        cout<<x.at(i)<<" ";
    }
    cout<<endl;

    x.erase(x.begin()+4);
    cout<<"Vector: ";
    for(unsigned int i=0;i<x.size();i++){
        cout<<x.at(i)<<" ";
    }
    cout<<endl;

    cout<<"Front "<<x.front()<<endl;
    cout<<"Back "<<x.back()<<endl;
    if(x.empty())
        cout<<"It's Empty"<<endl;
    else
        cout<<"Not Empty"<<endl;

    x.clear();
    if(x.empty())
        cout<<"It's Empty"<<endl;
    else
        cout<<"Not Empty"<<endl;

    return 0;
}
