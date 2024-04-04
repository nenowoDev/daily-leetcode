//use ordered map/unordered map
//check occurence count
//lowest number make a set
//repeat 
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char,int> map;
            
            int size=tasks.size();
            for(auto c:tasks){
                if(map.count(c)==0){
                    map[c]=1;}
                else
                    map[c]+=1;
            }

            for(auto[k,v]:map){
                cout<<k<<"  "<<v<<endl;
            }

            tuple<int,int,char> arr;
            for(auto&[k,v]:map){
                //transform into tuple
            }


    

            bool swi=true;
            vector<char> y;
            vector<vector<char>> yp;

            while(swi){ 
                swi=false;
                for(auto& [k,v]:map){
                    if(v>0&&y.size()<(n+1)){ 
                        swi=true;   
                        y.push_back(k);
                        v--;
                    } 
                }
                if(!y.empty()){
                    while(y.size()<n+1)
                        y.push_back('0');    
                    
                    
                    yp.push_back(y);
                    y.clear();
                }
                
            }

            y=yp.back();
            y.erase(remove(y.begin(), y.end(), '0'), y.end());
            yp.pop_back();
            yp.push_back(y);

            int cumlative=0;
            for(auto m:yp){
                cumlative+=m.size();
            }


            // for(auto[k,v]:map){
            //     cout<<k<<"  "<<v<<endl;
            // }



            for(auto &a:yp){
                for(auto &b:a)
                    cout<<b;         
                cout<<endl;
            }

            
            return cumlative;
        }
};

int main(){
    Solution a;
    vector<char> testcases={'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
    int n=2;

    cout<<a.leastInterval(testcases,n);
    
}

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
        
//         unordered_map<char,int> map;
//         vector<int> arr;
//         int size=tasks.size();
//         for(auto c:tasks){
//             if(map.count(c)==0){
//                 map[c]=1;}
//             else
//                 map[c]+=1;
//         }
        
//         for(auto[k,v]:map){
//             cout<<k<<"  "<<v<<endl;
//         }



//         bool swi=true;
//         for(auto[k,v]:map){
//             arr.push_back(v);
//         }
//         int loop=0;
//         while(swi){ 

//             swi=false;
//             for(auto& a:arr){
//                 if(a>1) swi=true;   
//                 a--;
//             }
//             loop+=1;
//         }

    
        
        
//         return size+((n-1)*(loop-1));
//     }
// };
