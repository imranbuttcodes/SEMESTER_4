#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
using namespace std;


vector<int> findErrorNums(vector<int>& nums) {
        vector<int> all_nums;
        vector <int> ans;
        map<int,int> freqs;
        for (int i = 0; i< nums.size(); i++) {
            freqs[nums[i]]++;
            all_nums.push_back(i + 1);
        }
        
        sort(nums.begin(), nums.end());
        cout << "NUms: ";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << ' ';
        }
        cout << endl;
        cout << "All Nums: ";
        for (int i = 0; i < all_nums.size(); i++) {
            cout << all_nums[i] << ' ';
        }
        cout << endl;
        
            auto it = find_if(freqs.begin(), freqs.end(), 
        [](const auto& pair) {
            return pair.second > 1;
        });
        int repeated;
          if (it != freqs.end()) {
            repeated = it->first;
        }
        
        ans.push_back(repeated);
      
        for (int i = 0; i < all_nums.size(); i++) {
            bool found = false;
            for (int j = 0; j < nums.size(); j++)
            {
                if (all_nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(all_nums[i]);
            }
            
        }

        return ans;


    }


int main() {
vector<int> nums = {3,2,3,4,6,5};
vector<int> ans = findErrorNums(nums);
cout << "ANS: ";
for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
}
cout << endl;
}
    

