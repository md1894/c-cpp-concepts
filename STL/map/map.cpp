#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<utility>
using namespace std;


int main() {
    map<string, string> cust_map;
    
    cust_map.insert(make_pair(string("0001000000257"), string("24032023000145")));
    cust_map.insert(make_pair(string("0001000000222"), string("24032023005218")));
    cust_map.insert(make_pair(string("0001000000458"), string("24032023045454")));
    cust_map.insert(make_pair(string("0001000000123"), string("24521278855255")));
    cust_map.insert(make_pair(string("0001000000001"), string("24055555555555")));

    string str = "0001000000257";
    if(cust_map.count(str) != 0){
        cout << "customer id " + str + " present in the map and have value " + cust_map[str].c_str() << endl;
    }

    str = "0254555265652665";
    if(cust_map.count(str) != 0){
        cout << "customer id " + str + " present in the map and have value " + cust_map[str].c_str() << endl;
    }else{
        cout << "customer id " + str + " Not Present " << endl;
    }
    return 0;
}

/*
customer id 0001000000257 present in the map and have value 24032023000145
customer id 0254555265652665 Not Present
*/
