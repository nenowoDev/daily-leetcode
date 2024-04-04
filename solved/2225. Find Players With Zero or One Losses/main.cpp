#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        // unordered_map<int,int> hash;
        map<int,int> hash;
        
        for(auto match:matches){
            if(hash.count(match[0])==0)
                hash[match[0]]=0;
            hash[match[1]]+=1;
        }

        vector<int> zeroloss,oneloss;
        for(auto [k,v]:hash){
            if(v==0)
                zeroloss.push_back(k);
            if(v==1)
                oneloss.push_back(k);
        }


        return {zeroloss,oneloss};
    }
};

void test();

int main(){
    Solution a;
    vector<vector<int>> q={{2, 3}, {1, 3}, {5, 4}, {6, 4}};

    //  test();

        
    for(auto b:a.findWinners(q)){
        for(auto c:b){
            cout<<c;
        }
    }
};

void test(){
    
    unordered_map<int,int> hash;
    

    hash.insert({2,3});
    hash.insert({1,2});

    for(auto [k,v]:hash){
        cout<<k;
    }



}





// #include <vector>
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches) {
//         vector<vector<int>> player_list;

//         for(vector<vector<int>>::iterator it2=matches.begin();it2!=matches.end();it2++){
            
//             bool existL=false;
//             bool existW=false;
//             for(vector<vector<int>>::iterator it=player_list.begin();it!=player_list.end();it++){
//                 if((*it)[0]==(*it2)[1]){
//                     (*it)[1]+=1;
//                     existL=true;
//                 }

//                 if((*it)[0]==(*it2)[0]){
//                     existW=true;
//                 }
                
//             }

//             if(!existL){
//                 player_list.push_back({(*it2)[1],1});
//             }
//             if(!existW){
//                 player_list.push_back({(*it2)[0],0});
//             }
//         }

//         vector<vector<int>> return_list;
//         vector<int> a;
//         vector<int> b;
//         for(vector<vector<int>>::iterator it2=player_list.begin();it2!=player_list.end();it2++){
//             if((*it2)[1]==1){
//                 b.push_back((*it2)[0]);
//             }
//             if((*it2)[1]==0){
//                 a.push_back((*it2)[0]);
//             }
//         }

//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
        
//         return_list.push_back(a);
//         return_list.push_back(b);


//         return return_list;
//     }
// };


// int test();

// int main(){

//     vector<vector<int>> abc={{2, 3}, {1, 3}, {5, 4}, {6, 4}};
//     vector<int> def={1,2,3};

//     Solution a;
//     vector<vector<int>> winner=a.findWinners(abc);

//     // for (std::vector<std::vector<int>>::iterator it = winner.begin(); it != winner.end(); ++it) {
//     //     for (std::vector<int>::iterator inner_it = it->begin(); inner_it != it->end(); ++inner_it) {
//     //         std::cout << *inner_it << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }

//     for (const auto& elem : def) {
//         std::cout << elem << " ";
//     }
    
    
// }

// int test(){
//     vector<int> abc={1,2,3};
//     vector<vector<int>> def={{1,2},{3,4}};

//     // cout<<(abc)[1];
//     // cout<<(def)[1][1];
    
//     // for (vector<int>::iterator it=abc.begin(); it != abc.end(); it++) {
//     //     cout << *it << " "; 
//     // }

//     for (vector<vector<int>>::iterator it=def.begin(); it != def.end(); it++) {
//         cout<<(*it)[0]; 
//     }

//     std::cout << std::endl;
//     return 0;
// }

