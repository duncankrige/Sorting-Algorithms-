/*****************************************************************
 ** FILE: main.cpp
 ** AUTHOR: D.Krige
 ** DATE: 12 Feb 2025
 ** PURPOSE: Main  
 *****************************************************************/
#include <iostream>
#include <fstream>
#include "sort.hpp"
#include "sort.cpp"

using namespace std;
 
int main(int argc, char* argv[]) {                                                                  // Argc (argument count) how many arguments are passed. Argv (argument vector) This helps us except command line arguement 
                                                                                                    // Check if the correct number of arguments are provided
    if (argc < 3) {
        cout << "Project1 <input_file> <algorithm> [-print]\n";           
        return 1;                                                                                   // Exit with error code
    }

                                                                                                    // This helps us read the file name and algorithm
    string inputFile = argv[1];                                                                     // first argument (input file name)
    string algorithm = argv[2];                                                                     // Second argument sorting algorithm to use
    bool printOutput = (argc == 4 && string(argv[3]) == "-print");

                                                                                                    // Printing out the arguments for confirmation and for debugging
    cout << "Input File: " << inputFile << endl;                                                    // Shows the file being read 
    cout << "Sorting Algorithm: " << algorithm << endl;                                                // Shows the selected sorting algothism
    cout << "Print Output: " << (printOutput ? "ON" : "OFF") << endl;                               // This is called a ternary operator it simplfies a if statement, if printout is true it prints on, if printout is fasle it prints off( this is the thrid argument in the instructions) Works when -print is included                                                            // We return 0 to show the program completed successfully


// Open the file

    ifstream infile(inputFile);                                                                     // ifstream is the class which allows us to read FROM files. Infile represents the object of that class
   
    if (!infile)                                                                                    // Checks if file didn't open 
        {
            cout << "There was a error opening the file: " << inputFile << endl;
            return 1;                                                                               // This will EXIT the program if the file didn't open
        }


    cout << "The File was opened successfully!\n";

//Reading Info From Input File 

    int numWords;                                                                                   // Declaring the integer to store the the first number of the input file 
    infile >> numWords;                                                                             // Read the first number from the infput file (number of words to follow or excpect in the file)
    
    if (numWords <= 0)                                                                              // I relized only later that I should put a catch to make sure the number at the start of the file is valid (positive integer)
        {  
            cout << "There is a Invalid number of words (" << numWords << ") in file.\n";
            return 1;                                                                               // Forces an exit and returns the above statement because of the invalid number.  
        }
    else
        {
            cout << "Number Of Words To Expect (" << numWords<< ")\n ";                             //Lets us know how many strings to expect
        }

    vector<string> words;                                                                           //Declaring the vector to store the words fromt the input file  
    string word;                                                                                    // String to hold the each word  

    for (int i = 0; i < numWords; i++)                                                              // Loop through file to read exactly numWords words
        {  
            if (!(infile >> word)) 
                {  
                    cout << "The File Contains Fewer Words Than Expected Or Reading Of A Word Failed.\n";
                    return 1;  
                }
            words.push_back(word);                                                                  //As the loop is going if the word is succefully read it is added to the words vector  
        }
//Closing file 
    infile.close();

//Bubble Sort
    if (algorithm == "bubble") 
        {
            bubbleSort(words);
            cout << "Bubble Sort finished.\n";
        }
//Merge Sort 
    else if (algorithm == "merge") 
        {
            list<string> wordList(words.begin(), words.end());                                      // so since I used a list because it works more efficiently with merge sort. So i need to Convert vector to list
            wordList = mergeSort(wordList);
            words.assign(wordList.begin(), wordList.end());                                         // convert list back to vector .assign() replaces words with the elements from wordList.
            cout << "Merge Sort finished.\n";
        }
//Quick Sort        
    else if (algorithm == "quick")
        {
           quickSort(words);
           cout << " Quick Sort finished.\n";
        }
//heap Sort        
    else if(algorithm == "heap")
    {
        heapSort(words);
        cout<< "Heap sort Finished.\n";
    }
    //system sort    
    else if(algorithm == "system")
    {
        systemSort(words);
        cout<< "System Sort Finished.\n";
    }         
        else 
        {
            cout << "algorithm failed: " << algorithm << endl;
            return 1;
        }

                                                                                                    // Print the sorted words if the user requested it
    if (printOutput) 
        {
            cout << "Sorted Words: \n";
            for (const string& w : words) 
                {
                    cout << w << endl;
                }
        }
 
    return 0;  
}


