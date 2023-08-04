#include <bits/stdc++.h> 


//  Recursive method

// void dp(int cur_st, int n, vector<int> &heights, int& min_energy, int energy){
//     if(cur_st == n){
//         min_energy = min(min_energy,energy);
//         // energy = 0;
//         return;
//     }
    
//     dp(cur_st+1,n,heights,min_energy,energy+abs(heights[cur_st]-heights[cur_st-1]));

//     if(cur_st+2<=n){
//         dp(cur_st+2,n,heights,min_energy,energy+abs(heights[cur_st+1]-heights[cur_st-1]));
//     }
// }

// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     int min_energy = INT_MAX;

//     dp(1,n,heights,min_energy,0);
//     if (min_energy == INT_MAX)
//         min_energy = 0;
//     return min_energy;

// }


// dp using memoization
// int dp(int cur_step, vector<int> &heights,vector<int> &energy){
//     if(cur_step == 1){
//         return 0;
//     }
//     if(cur_step == 2){
//         return abs(heights[1]-heights[0]);
//     }
    
//     int one_step_energy,two_step_energy;

//     if(energy[cur_step-1]==0){
//         energy[cur_step-1] = dp(cur_step-1,heights,energy);
//     }
//     one_step_energy = energy[cur_step-1]+abs(heights[cur_step-1]-heights[cur_step-2]);
    
//     if(energy[cur_step-2]==0){
//         energy[cur_step-2] = dp(cur_step-2,heights,energy);
//     }
//     two_step_energy = energy[cur_step-2]+abs(heights[cur_step-1]-heights[cur_step-3]);

    
//     return min(one_step_energy,two_step_energy);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     vector<int> cost(n+1,0);


//     return dp(n,heights,cost);
//     // if (min_energy == INT_MAX)
//     //     min_energy = 0;
    

// }



// dp using tabulation method

// int frogJump(int n,vector<int>& heights){
//     vector<int> energy_lost(n+1,0);

//     energy_lost[2] = abs(heights[1]-heights[0]);

//     for(int stair = 3; stair <= n; stair++){
//         energy_lost[stair] = min(energy_lost[stair-1]+abs(heights[stair-1]-heights[stair-2]),
//                                  energy_lost[stair-2]+abs(heights[stair-1]-heights[stair-3])
//                                  );
//     }
//     return energy_lost[n];

// }


// dp using tabulation method and further space optimization

int frogJump(int n,vector<int>& heights){
    int energy_lost_1 = 0;
    int energy_lost_2 = abs(heights[1]-heights[0]);

    int total_energy_lost;
    for(int stair = 3; stair <= n; stair++){
        total_energy_lost = min(energy_lost_2+abs(heights[stair-1]-heights[stair-2]),
                                 energy_lost_1+abs(heights[stair-1]-heights[stair-3])
                                 );
        energy_lost_1 = energy_lost_2;
        energy_lost_2 = total_energy_lost;
    }
    return total_energy_lost;

}



