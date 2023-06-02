#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;


int main() {
    map<string, string> cust_map;
    
    cust_map.insert(make_pair(string("0001000000257"), string("24032023000145")));
    cust_map.insert(make_pair("0001000000222", "24032023005218"));
    cust_map["0001000000458"] = "24032023045454";
    cust_map [string("0001000000458")]  = string("24032023045454");
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

    cout << "iterating over map using iterator " << endl;
    map<string, string>::iterator it = cust_map.begin();
    while(it != cust_map.end()){
	    cout << "Key : " + it->first + ", Value : " + it->second << endl;
	    it++;
    }
    cout << "iterating over map using for-each " << endl;
    for(const auto &val : cust_map){
	    cout << "cust_map["+val.first+"] = " + val.second << endl;
    }

    cout << "Mutating the Map " << endl;

    std::for_each(cust_map.begin(), cust_map.end(), [](pair<const string, string>& el){
        el.second += "$";
    });

    for(const auto &val : cust_map){
	    cout << "cust_map["+val.first+"] = " + val.second << endl;
    }
    return 0;
}

/*
customer id 0001000000257 present in the map and have value 24032023000145
customer id 0254555265652665 Not Present 
iterating over map using iterator 
Key : 0001000000001, Value : 24055555555555
Key : 0001000000123, Value : 24521278855255
Key : 0001000000222, Value : 24032023005218
Key : 0001000000257, Value : 24032023000145
Key : 0001000000458, Value : 24032023045454
iterating over map using for-each 
cust_map[0001000000001] = 24055555555555
cust_map[0001000000123] = 24521278855255
cust_map[0001000000222] = 24032023005218
cust_map[0001000000257] = 24032023000145
cust_map[0001000000458] = 24032023045454
Mutating the Map 
cust_map[0001000000001] = 24055555555555$
cust_map[0001000000123] = 24521278855255$
cust_map[0001000000222] = 24032023005218$
cust_map[0001000000257] = 24032023000145$
cust_map[0001000000458] = 24032023045454$
*/
