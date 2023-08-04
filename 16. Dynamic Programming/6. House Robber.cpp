#include <bits/stdc++.h> 

long  maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    if(nums.size()==1){
        return nums[0];
    }
    
    
    long prev1_cost,prev2_cost,max_cost;
    prev2_cost = nums[0];
    prev1_cost = max(nums[1],nums[0]);

    if(nums.size()==2){
        return prev1_cost;
    }

    for(int i=2; i<nums.size(); i++){
        long  selected = nums[i]+prev2_cost;
        long  not_selected = prev1_cost;
        max_cost = max(selected,not_selected);
        prev2_cost = prev1_cost;
        prev1_cost = max_cost;
    }
    
    return max_cost;

}

long  houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size()==1){
        return valueInHouse[0];
    }
    int cost = valueInHouse[valueInHouse.size()-1];
    valueInHouse[valueInHouse.size()-1] = 0;
    long  first_house_selected = maximumNonAdjacentSum(valueInHouse);
    valueInHouse[valueInHouse.size()-1] = cost;
    valueInHouse[0] = 0;
    long  last_house_selected = maximumNonAdjacentSum(valueInHouse);
    return max(first_house_selected,last_house_selected);

}



