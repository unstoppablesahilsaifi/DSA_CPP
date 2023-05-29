class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
           int size=nums.size();
        vector<int>count(101,0);
        for(int i=0;i<size;i++){
            count[nums[i]]++;
        }
        int sum=0;
        for(int i=0;i<101;i++){
            if(count[i]==1){
                sum+=i;
            }
        }
        return sum;
    }
};


//Brute Force

int sumOfUnique(int arr[], int n)
{
    int sum=0;
    bool isDuplicate;
    for (int i = 0; i < n; i++)
    {
        isDuplicate=false;
        int num = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (num == arr[j]){
                isDuplicate=true;
                break;
            }
        }
        if(!isDuplicate)
        sum+=num;
    }
    return sum;
}
int main()
{
    int arr[] = {2, 5, 4, 7, 9, 2, 4, 8};
    int n = 8;
    cout<<"sumOfUniqueElementsis : "<<sumOfUnique(arr,n);
}