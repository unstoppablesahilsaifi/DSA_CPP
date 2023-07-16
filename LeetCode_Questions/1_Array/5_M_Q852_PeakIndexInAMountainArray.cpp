class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
    int end =arr.size()-1;
    int mid = start +(end-start)/2;
  
//In case agar start and end peeak mountain per h to fir bhi ye loop k anday jayga agar equal lgate h to.
//isliye equal  nhi lgaya
    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            //In case, agar peak element hi mid per aa gya to mid-1 s to piche iterate ho  jaynge hm isliye mid hi thik h
             end = mid;
        }
       
        mid = start +(end-start)/2;
        
    }
return start;

    }
};