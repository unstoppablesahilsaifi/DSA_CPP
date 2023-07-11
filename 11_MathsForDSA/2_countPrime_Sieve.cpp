Below one will give TLE

class Solution {
private:
bool isPrime(int n){
     bool checkPrime=1;
        for(int i=2;i<n;i++){
            if(n%i==0){
                checkPrime=0;
            }
        }
        return checkPrime;
}
public:
    int countPrimes(int n) {
       
        int count=0;
        for(int i=2;i<n;i++){
          if(isPrime(i)){
              count++;
          } 
        }
        return count;
    }
};


The complexity of the given code can be analyzed as follows:

The isPrime function checks whether a given number is prime or not. It iterates from 2 to n/2 and performs a modulo operation for each iteration. Therefore, the time complexity of the isPrime function is O(n).

The countPrimes function calls the isPrime function for each number from 2 to n-1. Since the isPrime function has a time complexity of O(n), and it is called for n-2 numbers, the time complexity of the countPrimes function is approximately O(n^2).

Overall, the code has a time complexity of O(n^2).


  
