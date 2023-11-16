#include<bits/stdc++.h>

// //BruteForce, TC-O(k*n), SC-O(n)
// double minimiseMaxDistance(vector<int> &arr, int k){
// 	// Write your code here.	
// 	int n = arr.size();
// 	n--;
// 	double* sectors = new double[n];
// 	for(int i=0; i<n; i++){
// 		sectors[i] = 1;
// 	}

// 	//O(k*n)
// 	for(int i=0; i<k; i++){
// 		double max_dis = 0;
// 		int maxi = 0;
// 		for(int j=0; j<n; j++){
// 			double dis = (arr[j+1]-arr[j])/sectors[j];
// 			if(dis>max_dis){
// 				max_dis = dis;
// 				maxi = j;
// 			}
// 		}
// 		sectors[maxi]++;
// 	}
// 	double max_dis = 0;
// 	int maxi = 0;

// 	//O(n)
// 	for(int j=0; j<n; j++){
// 		double dis = (arr[j+1]-arr[j])/sectors[j];
// 		if(dis>max_dis){
// 			max_dis = dis;
// 			maxi = j;
// 		}
// 	}
// 	return max_dis;
// }



// //BruteForce, TC-O(k*n), SC-O(2*n)
// double minimiseMaxDistance(vector<int> &arr, int k){
// 	// Write your code here.	
// 	int n = arr.size();
// 	n--;
// 	double* sectors = new double[n];
// 	for(int i=0; i<n; i++){
// 		sectors[i] = 1;
// 	}

// 	double* adj_dist = new double[n];
// 	for(int i=0; i<n; i++){
// 		adj_dist[i] = arr[i+1]-arr[i];
// 	}

// 	//O(k*n)
// 	for(int i=0; i<k; i++){
// 		double max_dis = 0;
// 		int maxi = 0;
// 		for(int j=0; j<n; j++){
// 			double dis = adj_dist[j]/sectors[j];
// 			if(dis>max_dis){
// 				max_dis = dis;
// 				maxi = j;
// 			}
// 		}
// 		sectors[maxi]++;
// 	}
// 	double max_dis = 0;
// 	int maxi = 0;

// 	//O(n)
// 	for(int j=0; j<n; j++){
// 		double dis = adj_dist[j]/sectors[j];
// 		if(dis>max_dis){
// 			max_dis = dis;
// 			maxi = j;
// 		}
// 	}
// 	return max_dis;
// }



// //Heap, TC-O(k*log n), SC-O(3*n)
// double minimiseMaxDistance(vector<int> &arr, int k){
// 	// Write your code here.	
// 	int n = arr.size();
// 	n--;
// 	double* sectors = new double[n];
// 	for(int i=0; i<n; i++){
// 		sectors[i] = 1;
// 	}

// 	double* adj_dist = new double[n];
// 	for(int i=0; i<n; i++){
// 		adj_dist[i] = arr[i+1]-arr[i];
// 	}

// 	priority_queue<pair<double, int>> pq;
// 	for(int i=0; i<n; i++){
// 		pq.push({arr[i+1]-arr[i], i});
// 	}

// 	//O(k*log n)
// 	for(int i=0; i<k; i++){
// 		pair<double,int> max_dist = pq.top();
// 		pq.pop();
		
// 		sectors[max_dist.second]++;
// 		max_dist.first = adj_dist[max_dist.second]/sectors[max_dist.second];
// 		pq.push(max_dist);
// 	}
	
// 	return pq.top().first;
// }

int no_of_stations(double dis, vector<int>& arr);

//Binary Search, TC-O(n * log max_dis), SC-O(1)
double minimiseMaxDistance(vector<int> &arr, int k){
	int max_dis = 0;
	int n = arr.size()-1;
	for(int i=0; i<n; i++){
		int dis = arr[i+1] - arr[i];
		if(dis > max_dis){
			max_dis = dis;
		}
	}

	double l = 0, h = max_dis;

	while(h-l > 1e-6){
		double mid = (l+h)/2;
		if(no_of_stations(mid,arr) > k){
			l = mid;
		}
		else{
			h = mid;
		}
	}

	return h;
}


int no_of_stations(double dis, vector<int>& arr){
	int stations = 0;
	int n = arr.size()-1;

	for(int i=0; i<n; i++){
		stations += ceil((arr[i+1]-arr[i])/dis)-1;
	}
	return stations;
}


