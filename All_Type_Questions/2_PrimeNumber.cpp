#include <iostream>
using namespace std;
int main()
{
    int n, i, flag = 0;
    cout << "Enter the Number to check Prime: ";
    cin >> n;
    // 2 Prime isliye h kyuki pehle condition check hogi kya hmara i mtlb 2, 2/2 s chota h yani 1 s, nhi na to bhai condition m jayga
    // nhi or output shi aayga
    for (i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {

        cout << "Number is not Prime." << endl;
    }

    else
    {
        cout << "Number is Prime." << endl;
    }
    return 0;
}