#include <iostream>

using namespace std;


class Solution {
public:
    int tribonacci(int n) {
        long arr[38];
        arr[0]=0,arr[1]=1,arr[2]=1;

        for(int i=3;i<38;i++)
            arr[i]=arr[i-3]+arr[i-2]+arr[i-1];

        return int(arr[n]);
    }
};

int main(){
    Solution a;

    cout<<a.tribonacci(4);
}