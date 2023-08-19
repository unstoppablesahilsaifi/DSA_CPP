#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is "<< ans << endl;

//case 1
    while(true) {
        int i = 5;
    }
    
//case 2
    while(true) {
        int* ptr = new int;
    }




    return 0;
}


/*

BAD PRACTICE::


Jab bhi kabhi array ka size pta nhi ho and user s size lena ho to kuch bhi max size eg; arr[10000] dedenaa per arr[n] nhi krna .

Why:   

Jab bhi program start hota h to apne sath memory leke aata h, us memory m uske paas do type ki memory hoti h Stack(Choti) and Heap(Badi).
agar m compile time per hi bata de ki mujhe 10000 size ka array chahiey to program stack ki memory usi hisab s leke aiiyo.

lekin agar hm ye bol de ki arr[n] to vo choti memory leke aayga stack k hisab s and hme array bnana h bdaa size ka,
Run time per array ka size hm  bataynge jyada but program choti memory leke aaya h to program crash kr jaayga
*/