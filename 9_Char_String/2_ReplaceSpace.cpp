#include<string>
#include<iostream>
using namespace std;
string replaceSpaces(string &str){
	string temp = "";
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}


// jaha jaha space h vha per @40 daalna tha



// Solution without taking temp

QUES: Replace space in the original string....

SOL:
string replaceSpaces(string &str){
	// Write your code here.
    string s="@40";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
        {
            str.replace(i,1,s);  
        }
    }
    return str;
}