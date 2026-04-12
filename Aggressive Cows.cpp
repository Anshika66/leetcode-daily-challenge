bool canWePlace(vector<int>&A , int cows , int dist){
	int cntCows = 1;
	int last = A[0];
	
	for(int i = 0;i<n ; i++){
		if(A[i] - last >= dist){
			cntCows++;
			last = A[i];
		}
	}
	if(cntCows > cows )   return true;
	else return false ;
}

int aggressiveCows(vector<int>&A , int cows){
	int n = A.size();
	int low = 0;
	int high = A[n-1]-A[0];
	int ans = 0;
	
	while(low<=high){
		int mid = (low + high) / 2;
		
		if(canWePlace(A , cows  , mid) == true){
			ans = mid;
			low = mid+1;
		}
		else{
			high = mid -1 ;
		}
	}
	return ans ;
}
