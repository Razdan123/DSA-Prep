//Print allthe Duplicates of the string
//HashMaps Method

/*
Time Complexity: O(N*log(N)), where N = length of the string passed and it generally takes O(log(N)) time for an element insertion in a map. 

Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).
*/
 
#include<bits/stdc++.h>

using namespace std;

void duplicate(string s){
    map<char,int> hash;
    int size = s.length();
    for(int i=0; i<size; i++){
        hash[s[i]]++;
    }

    for(auto itr:hash){
        if(itr.second>=2){
            cout<<itr.first<<"-"<<itr.second<<endl;
        }
    }
}

int main(){

    string s = "geeksforgeeks";
    duplicate(s);
    return 0;
}