/*Understanding the Problem
Imagine a party with n people. 
You are given a matrix M where M[i][j] = 1 means person i knows person j, and M[i][j] = 0 means they don't. 
A person is a celebrity if:

They do not know anyone else.
Everyone else knows them.

We need to find this celebrity's index. If no such person exists, we return -1.

The Stack-Based Approach: Intuition
The core idea is to use a stack to quickly eliminate non-celebrity candidates. 
If person A knows person B, then A cannot be the celebrity (violates rule 1). 
If A doesn't know B, then B cannot be the celebrity (violates rule 2). 
This allows us to eliminate one person with each comparison, leaving a single potential candidate.*/

// Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution 
{
    private:
    // Yeh ek helper function hai jo check karta hai ki kya person 'a' person 'b' ko jaanta hai.
    // 'M[a][b] == 1' ka matlab hai 'a' 'b' ko jaanta hai.
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }

    public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // Step 1: Ek stack banao aur sabhi logon ko isme push kar do.
        // Initially, sabhi log potential celebrities hain.
        stack<int> s;
        for(int i=0; i<n; i++) {
            s.push(i);
        }
        
        // Step 2: Stack mein jab tak ek se zyada log hain,
        // do logon ko compare karke ek ko eliminate karo.
        while(s.size() > 1) {
            
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            // Agar 'a' 'b' ko jaanta hai, toh 'a' celebrity nahi ho sakta.
            // 'b' abhi bhi ho sakta hai, isliye 'b' ko wapas push kar do.
            if(knows(M,a,b,n)){
                s.push(b);
            }
            // Agar 'a' 'b' ko nahi jaanta, toh 'b' celebrity nahi ho sakta
            // kyunki celebrity ko sab jaante hain.
            // 'a' abhi bhi ho sakta hai, isliye 'a' ko wapas push kar do.
            else
            {
                s.push(a);
            }
        }
        
        // Step 3: Loop khatam hone ke baad, stack mein sirf ek insaan bachega.
        // Yahi hamara potential celebrity candidate hai.
        int candidate = s.top();
        
        // Step 4: Ab hum is candidate ko verify karenge ki kya woh sach mein celebrity hai.
        
        // Verification 1: Row Check
        // Celebrity kisi ko nahi jaanta. Uski row mein sab zeros hone chahiye.
        int zeroCount = 0;
        for(int i=0; i<n; i++) {
            if(M[candidate][i] == 0)
                zeroCount++;
        }
        
        // Agar zeros ki count n ke barabar nahi hai, toh matlab wo kisi ko jaanta hai.
        // Isliye woh celebrity nahi hai.
        if(zeroCount != n) {
            return -1;
        }
        
        // Verification 2: Column Check
        // Sab log celebrity ko jaante hain. Uski column mein n-1 ones hone chahiye.
        int oneCount = 0;
        for(int i=0; i<n; i++) {
            // Hum M[candidate][candidate] ko check nahi karte, jo hamesha 0 hoga.
            if(M[i][candidate] == 1)
                oneCount++;
        }
        
        // Agar ones ki count n-1 ke barabar nahi hai, toh matlab sab usko nahi jaante.
        // Isliye woh celebrity nahi hai.
        if(oneCount != n-1) {
            return -1;
        }
        
        // Agar dono verification pass ho gaye, toh 'candidate' hi celebrity hai.
        return candidate;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;
    }
}

/*Example Input:

2       // t = 2 (Do test cases hain)

3       // n = 3 (Pehla test case, 3 log)
0 1 0   // M[0][0] = 0, M[0][1] = 1, M[0][2] = 0
0 0 0   // M[1][0] = 0, M[1][1] = 0, M[1][2] = 0
0 1 0   // M[2][0] = 0, M[2][1] = 1, M[2][2] = 0

2       // n = 2 (Dusra test case, 2 log)
0 1
1 0 */



/*Main samajh sakta hoon, yeh do checks thode confusing lag sakte hain. Chalo isko ek simple analogy se samajhte hain.

Imagine ek party chal rahi hai aur aapko ek celebrity dhoondhna hai.

**Celebrity ki 2 khaas baatein hoti hain:**

1.  **Woh kisi ko nahi jaante.** (Doesn't know anyone).
2.  **Sab unko jaante hain.** (Everyone knows them).

Jo matrix `M` hai, usko hum `M[i][j]` se samjhenge, jiska matlab hai **`i` `j` ko jaanta hai**.

-----

### **Verification 1: "Main kisi ko nahi jaanta"**

Yeh code ka pehla hissa hai: `Row Check`.

```cpp
// Verification 1: Row Check
// Celebrity kisi ko nahi jaanta. Uski row mein sab zeros hone chahiye.
int zeroCount = 0;
for(int i=0; i<n; i++) {
    if(M[candidate][i] == 0)
        zeroCount++;
}

// Agar zeros ki count n ke barabar nahi hai, toh matlab wo kisi ko jaanta hai.
// Isliye woh celebrity nahi hai.
if(zeroCount != n) {
    return -1;
}
```

  * **`M[candidate][i]` ka matlab:** Hum potential celebrity (`candidate`) ki row ko check kar rahe hain. `i` yahan har doosre insaan ka index hai.
  * **Logical Meaning:** Agar `M[candidate][i] == 1` hota, toh iska matlab hota ki `candidate` `i` ko jaanta hai. Lekin celebrity ko toh kisi ko nahi jaanna chahiye, isliye uski poori row `0` honi chahiye.
  * **Code ka kaam:** Yeh loop **`candidate` ki poori row** mein ghoomta hai aur count karta hai ki kitne `0` hain.
  * **Final Check:** Agar `zeroCount` `n` ke barabar nahi hai, toh iska matlab us row mein ek ya ek se zyada `1` hain. Agar ek bhi `1` hai, toh `candidate` ne kisi ko jaana, aur woh celebrity nahi ho sakta. Isliye hum `-1` return kar dete hain.

-----

### **Verification 2: "Sab mujhe jaante hain"**

Yeh code ka doosra hissa hai: `Column Check`.

```cpp
// Verification 2: Column Check
// Sab log celebrity ko jaante hain. Uski column mein n-1 ones hone chahiye.
int oneCount = 0;
for(int i=0; i<n; i++) {
    // Hum M[candidate][candidate] ko check nahi karte, jo hamesha 0 hoga.
    if(M[i][candidate] == 1)
        oneCount++;
}
```

  * **`M[i][candidate]` ka matlab:** Hum potential celebrity (`candidate`) ki column ko check kar rahe hain. `i` yahan har doosre insaan ka index hai.
  * **Logical Meaning:** `M[i][candidate] == 1` ka matlab hai **`i` `candidate` ko jaanta hai**. Celebrity ki property hai ki sab log usko jaane, isliye uski poori column (`M[][candidate]`) mein `1`s hone chahiye (sivaaye khud ke).
  * **Code ka kaam:** Yeh loop **`candidate` ki poori column** mein ghoomta hai aur count karta hai ki kitne `1` hain.
  * **Final Check:** `n` log hain. `candidate` khud ko nahi jaanta, isliye `M[candidate][candidate]` hamesha `0` hoga. Baaki `n-1` log usko jaante hain, toh `n-1` `1`s hone chahiye. Agar `oneCount` `n-1` se kam hai, toh matlab sab usko nahi jaante aur woh celebrity nahi hai. Is case mein bhi, hum `-1` return kar dete hain.

Ek image se aur clear ho jayega:

Agar dono conditions (`zeroCount == n` **aur** `oneCount == n-1`) true hoti hain, toh `candidate` hi celebrity hai aur hum uska index return karte hain.*/