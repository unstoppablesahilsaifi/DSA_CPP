/*

### **Problem Summary**

Hume ek **single array** ka use karke **do stacks** banane hain.

* **Stack1** left side se grow karega (index `0 → n-1` tak).
* **Stack2** right side se grow karega (index `n-1 → 0` tak).

👉 Dono stacks ek hi array share karenge, aur dono tab tak elements le sakte hain jab tak beech m space available hai.

### **Operations**

1. `push1(NUM)` → Stack1 me element add karo (agar jagah hai).
2. `push2(NUM)` → Stack2 me element add karo (agar jagah hai).
3. `pop1()` → Stack1 se element nikalo, warna `-1`.
4. `pop2()` → Stack2 se element nikalo, warna `-1`.

### **Key Points**

* **Overflow** → agar dono stacks ke pointers mil gaye, fir aur push nahi ho sakta.
* **Underflow** → agar stack empty hai to pop `-1` return karega.
* Space ka **efficient use** karna hai, matlab dono stacks dynamically ek hi array ke beech tak grow karte rahenge.

### **Example (Sample Input 1)**

Array size = 3

* push1(3) → \[3, \_, \_]
* push2(4) → \[3, \_, 4]
* push1(5) → \[3, 5, 4]
* pop1() → returns `5` → \[3, \_, 4]
* pop2() → returns `4` → \[3, \_, \_]

Output:

```
5
4
```

---
*/



class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //atleast a empty space present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
       
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        } 
       
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }

};