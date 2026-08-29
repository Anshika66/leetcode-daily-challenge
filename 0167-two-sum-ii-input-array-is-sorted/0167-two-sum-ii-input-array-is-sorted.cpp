//input array  -- sorted we need to find out the sum of the two elements equals to target return the indices of the two numbers .
//10^15 , target - 10^9 
//extra space(constant) 

//brute 
//create a ans vector outside both the loops 
// arr - [2 , 7 , 11 , 15] target = 9 
// initialize a loop starts from index 0  -- i
// initialize another loop starts from index 1  -- j
// calculate the sum (arr[i] + arr[j]) == target 
// store both the indices in the result array and return it 

//tc = 0(n^2)
//sc = O(1)


// optimised approach 
// two pointer approach 
//i //j 
// starts from 0 and j starts from n-1;
// we know the array is sorted ---> the highest elenment is in the end of the array and the lowest element is in the begining of the array 

//calculate the value of arr[i] + arr[j]  = sum 
// we have three conditions are there 
// sum > target then j--;
//and if sum < target then i++;
//if summ == target then store the value into the result array ;
//return it 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0; 
        int j = n-1;


        while(i <= j){
            int sum = numbers[i] + numbers[j];

            if(sum == target) {
               return {i+1 ,j+1};
               
            }
            else if(sum > target){
                j--;
            }else{
                i++;
            }
        }
        return {};
        
    }
};