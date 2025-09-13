#include <iostream>
using namespace std;

int main() {
    string str = "GeeksforGeeks";

    int vCount = 0;
    int cCount = 0;

    for (int i = 0; i < str.size(); i++) {
        char ch = tolower(str[i]); // lowercase me convert, taaki check easy ho

        // sirf alphabets ko consider karo
        if (ch >= 'a' && ch <= 'z') {
            // vowel check
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vCount++;
            } else {
                cCount++;
            }
        }
    }

    cout << "Number of Vowels = " << vCount << endl;
    cout << "Number of Consonants = " << cCount << endl;

    return 0;
}
