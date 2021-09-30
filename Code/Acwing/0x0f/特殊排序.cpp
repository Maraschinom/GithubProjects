// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> specialSort(int N) { //注意vector
        int l , r , mid , ans ;
        vector<int> v ;
        v.push_back(1) ;
        for (int i = 2 ; i <= N ; ++i ) { //显然O(nlogn)
            l = 0 , r = i - 1 ;
            v.push_back(i) ;
            while (l <= r) {
                mid = l + r + 1 >> 1 ;
                if (compare(v[mid] , i)) l = mid + 1 ;
                else r = mid - 1 ;
            }
            for (int j = i - 1 ; j >= l ; --j ) v[j] = v[j - 1] ; // 翻一翻
            v[l] = i ;
        }
        return v ;
    }
}; // 交互题ex 吐了