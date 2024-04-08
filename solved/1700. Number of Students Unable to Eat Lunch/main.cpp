#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        
        int lastserve=0;
        while(lastserve<students.size()){
            if(students[0]==sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                lastserve=0;
            }
            else{
                students.push_back(students[0]);
                students.erase(students.begin());
                lastserve++;
            }
        }
        return students.size();
    }
};

int main(){
    
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    
    vector<int> b;
    b.push_back(0);
    b.push_back(0);
    b.push_back(0);
    b.push_back(1);

    //pop at front
    //a.erase(a.begin());
    //operation is assign front to back, then pop front
    Solution aa;
    cout<<aa.countStudents(a,b);
}