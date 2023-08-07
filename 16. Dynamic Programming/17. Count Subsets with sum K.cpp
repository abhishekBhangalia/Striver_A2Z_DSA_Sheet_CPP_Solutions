// dp using memoization

// int dp(int i, int k,vector<int>& arr,vector<vector<int>>& sum){
// 	if(sum[i][k]!=-1){
// 		return sum[i][k];
// 	}
// 	if(k==0){
// 		return sum[i][k] = 1;
// 	}
// 	if(i==0){
// 		if(arr[i]==k){
// 			return 1;
// 		}
// 		else{
// 			return 0;
// 		}
// 	}
// 	int not_selected = dp(i-1,k,arr,sum);
// 	int selected = 0;
// 	if(arr[i]<=k){
// 		selected = dp(i-1,k-arr[i],arr,sum);
// 	}
// 	return sum[i][k]=(selected + not_selected)%  (int)(1e9+7);
// }


// int findWays(vector<int>& arr, int k)
// {
// 	vector<vector<int>> sum(arr.size(),vector<int>(k+1,-1));
// 	return dp(arr.size()-1,k,arr,sum) ;
// }


// tabulation sol



int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> sum(arr.size(),vector<int>(k+1,0));
	for(int i=0; i<arr.size(); i++){
		sum[i][0] = 1;
	}
	if(arr[0]<=k){
		sum[0][arr[0]] = 1;
	}
	for(int i=1; i<arr.size(); i++){
		for(int target=0; target<=k; target++){
			int not_selected = sum[i-1][target];
			int selected = 0;
			if(arr[i]<=target){
				selected = sum[i-1][target-arr[i]];
			}
			sum[i][target] = (selected + not_selected)%  (int)(1e9+7);
		}  
	}
	return sum[arr.size()-1][k] ;
}

