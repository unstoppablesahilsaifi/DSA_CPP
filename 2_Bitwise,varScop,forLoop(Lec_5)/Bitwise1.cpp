#include<iostream>
using namespace std;

int main()
{
    
    int a=4;
    int b=6;
    cout<<"a&b= "<<(a&b)<<endl;
    cout<<"a | b= "<<(a | b)<<endl;
    cout<<"~a= "<<(~a)<<endl;
    cout<<"a^b ="<<(a ^ b)<<endl;
    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    cout<<(19<<1)<<endl;
    cout<<(19<<2)<<endl;

}

/*
OP- 4
    6
   -5
    2
   Why we get -5 in case of NOT:
   We get -5 coz 4 is 1 0 0 is binary when we make it Not it will be 1111....011 but 1 means last bit defines number became negative to hmne kya padha tha ki
   bhai negative number ko print krne k liye 2' s comliment krte h
   111....011 ka 1's hua 000...100 2's krne k liye +1 krdo which means
   
       111....011
   1's 000....100
       ----------
   2's         +1
       -----------
       000....101 which means 5 sign negative hi rhega
   
   Shift Operator Output:(Small number k case m right shift jitni baar hoga utni baar 2 s divide hoga and left shift utni baar multiply)
   8  17/2=8 coz 1 baar shift hua h 
   4  17/2*2  17/4=4 coz 2 baar shift hua h
   38 19*2= 38
   76  19*2*2=76
      
   Now, question ye h ki sift small number hi kyu?????????
      kyuki suppose kyuki number h jiski bits h 0100000..10 iski left shift kiya to 10000000...100 bn gya mtlb negative bn gya na last bit 1 h isliye
*/

/*
This C++ program demonstrates bitwise operators, which perform operations at the binary level. Here is a breakdown of the code:

---

### **Code Explanation**

1. **Initialization**:
   ```cpp
   int a = 4;
   int b = 6;
   ```
   - `a` is assigned the value 4, and `b` is assigned the value 6.
   - Binary representations:
     - `a = 4` → `0100` (4-bit binary)
     - `b = 6` → `0110` (4-bit binary)

2. **Bitwise AND (`&`)**:
   ```cpp
   cout << "a&b= " << (a & b) << endl;
   ```
   - Performs a bitwise AND between `a` and `b`.
   - `0100 & 0110` = `0100` (Only where both bits are 1)
   - Output: `a&b= 4`

3. **Bitwise OR (`|`)**:
   ```cpp
   cout << "a | b= " << (a | b) << endl;
   ```
   - Performs a bitwise OR between `a` and `b`.
   - `0100 | 0110` = `0110` (Where at least one bit is 1)
   - Output: `a | b= 6`

4. **Bitwise NOT (`~`)**:
   ```cpp
   cout << "~a= " << (~a) << endl;
   ```
   - Performs a bitwise NOT on `a`.
   - Flips all the bits of `a` (4 is `0100`).
   - `~0100` = `1011` (in 2's complement form for signed integers, it equals `-5`).
   - Output: `~a= -5`

5. **Bitwise XOR (`^`)**:
   ```cpp
   cout << "a^b =" << (a ^ b) << endl;
   ```
   - Performs a bitwise XOR between `a` and `b`.
   - `0100 ^ 0110` = `0010` (Where bits are different).
   - Output: `a^b= 2`

6. **Right Shift (`>>`)**:
   ```cpp
   cout << (17 >> 1) << endl;
   cout << (17 >> 2) << endl;
   ```
   - Shifts the bits of `17` (`10001`) to the right.
   - `17 >> 1`: `10001` becomes `01000` → `8`.
   - `17 >> 2`: `10001` becomes `00100` → `4`.
   - Outputs:
     - `8`
     - `4`

7. **Left Shift (`<<`)**:
   ```cpp
   cout << (19 << 1) << endl;
   cout << (19 << 2) << endl;
   ```
   - Shifts the bits of `19` (`10011`) to the left.
   - `19 << 1`: `10011` becomes `100110` → `38`.
   - `19 << 2`: `10011` becomes `1001100` → `76`.
   - Outputs:
     - `38`
     - `76`

---

### **Program Output**
```
a&b= 4
a | b= 6
~a= -5
a^b= 2
8
4
38
76
```
 */