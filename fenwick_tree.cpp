#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

class FenwickTree {
    public:
    vector <int> bit;
    int size;
    
    // initialise a fenwick tree of some size
    FenwickTree(vector <int>& nums) {
        size = nums.size();
        bit.assign(size, 0);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    // get sum of elements from 0 - index
    int getSum(int index) {
        int sum = 0;
        for (int i = index; i >= 0; i = (i & (i + 1)) - 1)
            sum += bit[i];
        return sum;
    }

    // update an element at position index
    void update(int index, int delta) {
        for (; index < size; index = index | (index + 1))
            bit[index] += delta; 
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vector <int> nums = {3, 4, 0, 1, -1, 2};
    FenwickTree ft = FenwickTree(nums);
    for (int i = 0; i < ft.bit.size(); i++)
        cout << ft.bit[i] << " ";
    cout << "\n";
    cout << ft.getSum(5);

}
