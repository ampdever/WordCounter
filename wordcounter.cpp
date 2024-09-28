#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

// I initially had the code below in the while loop that reads in the text file line
// by line, but I figured since it was being run every loop I could just make a function.
// the isalnum function is part of the standard library that checks if the character that
// is passed through is an alphnumberic value and will return 1 if true and 0 if false.
// this will take each word and make sure there are no commas, periods, or other characters
// next to the word. I initially didn't have this and would get 3 different versions of the
// word "them" -> them | them. | them -> for example
string noPuncutation (string word) {
    string noPunc;
    for (char c : word) {
        if(isalnum(c)) {
            noPunc += c;
        }
    }
    return noPunc;
}

int main() {
    //This is reading in the file. The ifstream allows us to call a file, in this case
    //test.txt, and "open" it so to speak. If there is no file that matches it will
    //result in an error
    ifstream file("pride.txt");
    if (!file) {
        cout << "File could not be opened!";
        return 1;
    }
    
    // Declaring string variables that I will use while I parse through the text file
    string eachLine;
    string eachWord;
    // Here I'm declarding a map where I'm going to store each word and the count
    // the key is the word and the value is the number of occurrences
    map<string, int> allWords;

    // using a stringstream, which allows you to split strings into words, we take
    // we read in each line and then word by word. Stringstreams are really nice
    // because you don't have to worry about splitting anything by space, it handles
    // that for you. However, I learned that with this project specifically the 
    // punctuation was a problem.
    while (getline(file, eachLine)) {
        stringstream ss(eachLine);
        while (ss >> eachWord) {
            string justTheWord;
            justTheWord = noPuncutation(eachWord);
            ++allWords[justTheWord];
        }
    }

    // using the iterator for the map structure in C++ I started with the first item in the map
    // and then when through and displayed every key and value until the iterator pointed to the
    // last value of the map.
    for (map<string, int>::iterator iter = allWords.begin(); iter != allWords.end(); ++iter) {
        cout << iter->first << ": " << iter->second << endl;
    }
    
    file.close();
    return 0;
}