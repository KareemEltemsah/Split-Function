// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 3 - problem 5(p.14 in page 504)
// purpose: Create string spliter function
// Author:  Kareem Ahmed Eltemsah 20170195
// Date:    8 October 2018
// Version: 1.0

#include <iostream>
#include <vector>

using namespace std;
vector<string> split(string target , string delimiter);
int n=0;
int main()
{
    string text,delimiter;
    cout << "Enter the text you want to split" << endl;
    getline(cin,text);
    for (int i=0 ; i<text.length() ; i++)
    {
        if ((text[i]<48 || text[i]>57) && (text[i]<65 || text[i]>90) && (text[i]<97 || text[i]>122))
        {//not a number nor letter
            delimiter=text[i];
            n++;//number of delimiters it benefits us because it means there is (n+1) pieces
            while ((text[i+1]<48 || text[i+1]>57) && (text[i+1]<65 || text[i+1]>90) && (text[i+1]<97 || text[i+1]>122))
                text.erase(i+1,1);
                //while the following char is a delimiter too delete it and count only one
        }
    }
    while ((text[0]<48 || text[0]>57) && (text[0]<65 || text[0]>90) && (text[0]<97 || text[0]>122))
    {//not a number nor letter on the first of the text
        text.erase(0,1);
        n--;//we counted a wrong delimiter
    }
    while ((text[text.length()-1]<48 || text[text.length()-1]>57) && (text[text.length()-1]<65 || text[text.length()-1]>90) && (text[text.length()-1]<97 || text[text.length()-1]>122))
    {//not a number nor letter on the end of the text
        text.erase(text.length()-1,1);
        n--;//we counted a wrong delimiter
    }
    vector<string> splitText=split(text,delimiter);
    for (int i=0 ; i<n+1 ; i++)
    {
        cout << "\"" << splitText[i] << "\"";
        if (i<n)//don't print "," in the last time
            cout << ",";
    }
    return 0;
}
vector<string> split(string target , string delimiter)
{
    vector<string> newT(n+1);
    string test;
    int j=0;
    for (int i=0 ; i<target.length() ; i++)
    {
        if(target[i]!=delimiter[0])
            test+=target[i];
        if(target[i]==delimiter[0] || i==target.length()-1)
        {//if there is a delimiter or it's the end of the text it means "text" stored some word or number
            newT[j]=test;
            test.erase();
            j++;//number of pieces
        }
    }
    return newT;
}
