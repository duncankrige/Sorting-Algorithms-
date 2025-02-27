/*****************************************************************
 ** FILE: sort.cpp
 ** AUTHOR: D.Krige
 ** DATE: 12 Feb 2025
 ** PURPOSE: Header file  
 *****************************************************************/
#include "sort.hpp"

void bubbleSort(vector<string>& words) 
{
    int n = words.size();                                                                           // Get the number of words in the data file 
    bool swapped;                                                                                   // This is to track any swapping if it happend in the pass

    for (int i = 0; i < n - 1; i++)                                                                 // When creating the loop we set n to n-1 because the last element will automatically be sorted.  
        {
            swapped = false;                                                                        // Reset the track at the beggining of each pass. 

            for (int j = 0; j < n - i - 1; j++)                                                     // We set it at n-i-1 because after each pass the last alphabetical element is pushed back  
                {
                    if (words[j] > words[j + 1])                                                    // This compares the adjecent element int the data file in alphabetical order
                        {                                                                           
                            swap(words[j], words[j + 1]);                                           // Swaps the words if they are out of order
                            swapped = true;
                        }
                }
            if (!swapped) break;                                                                    // If no swaps, the list is sorted
        }
}

list<string> merge(const list<string>& A, const list<string>& B)                                      //merge functions takes the two sorted lists A and B and gives us S             
{                                                                                                     // the reason i used lists insted of vectors because easier for spliting list inot two halfs (updating pointers)
    list<string> S;                                                                                   // storing 
    auto itA = A.begin();                                                                             // auto helps determine list<string> which we learnt in class. iterators to the first elemnt of A and B 
    auto itB = B.begin();                                                                             // S ← empty sequence stroing merge sorted list
    
    while(itA != A.end() && itB != B.end())                                                           // psuedo code itA = !A.empty() && itB = !B.empty() - runs as long as both lists have elemnts  
    {
        if(*itA < * itB)                                                                              // if element in A is smaller i add to S and then move itA froward. [ pcode if A.front() < B.front()]
        {
            S.push_back(*itA);                                                                        // S.addBack(A.front()); A.eraseFront();
            itA++;
        }
        else                                                                                          //otherwise add elemnt from B to S and move itB forward 
        { 
            S.push_back(*itB);
            itB++;
        }
    }

    while(itA != A.end())                                                                             // while !A.empty() - if one of the list finishes before the other add the remaining elemnts 
    {
        S.push_back(*itA);                                                                            //S.addBack(A.front()); A.eraseFront(); -  add the left over elemnts from A to S 
        itA++;
    }
    

    while(itB != B.end())                                                                             //while !B.empty()
    {
        S.push_back(*itB);                                                                            //S.addBack(B.front()); B.eraseFront();
        itB++;
    }
    return S;

}

list<string> mergeSort(list<string>& words)                                                         //Algorithm mergeSort(S)
{
    if (words.size() <=1)                                                                           //if S.size() <= 1   base case
    {
        return words;                                                                                
    }
       int mid = words.size() / 2;                                                                  //middle index 
                                                                                                    //recursivle didvide each list down to one element then merge them back together 
       list<string> S1(words.begin(), next(words.begin(), mid));                                    //(S 1, S 2 ) ← partition(S, S.size()/2)  s1 is the first half and s2 the second 
       list<string> S2(next(words.begin(),mid), words.end());

       S1 = mergeSort(S1);                                                                          //recirsively sorts s1 and 2
       S2 = mergeSort(S2);
       words = merge(S1, S2);                                                                       //mergeSort(S 1)
       return words;                                                                                //mergeSort(S 2)
                                                                                                    //S ← merge(S 1, S 2)
    
}
/*
void parting(vector<string>& words,vector<string>& L, vector<string>& E, vector<string>& G)         // quick sort is also a divide and conquer sorting algorithm where we pick a elemeent in the array and sort the array with elemnts less the piviot go to the left and greater than go to the right. 3 steps choose the piviot , partonion the array in L E G then recursively sort  
{   
    string pivot = words[words.size()/2];                                                           // selecting the piviot to start in the middle 
    
    for(const string& word : words)
        {
            if(word < pivot)                                                                        // if the word is greater than piviot we push it int G
            {
                L.push_back(word);
            }
            else if (word > pivot)                                                                 // if word is greater than piviot then push back to L
            {
                G.push_back(word);
            }
            else                                                                                    // if word is equall to piviot then we push it to E 
            {
                E.push_back(word);                              
            }
        }
}
*/
void quickSort(vector<string>& words)
{
                                                                                                    //cout << "QuickSort called. Vector size: " << words.size() << endl;
    if(words.size() <=1 )                                                                           // base case 
    {
        return;
    }
                                                                                                    /*
                                                                                                    // Debugging- CheckI if the words vector has valid data
                                                                                                    cout << "QuickSort - Words vector size: " << words.size() << endl;
                                                                                                    */
    string pivot = words[words.size()/2] ;                                                          //where the pivot starts in the middle
    vector<string> L, E, G;                                                                         // storing as vectors 

                                                                                                    // Debugging: Show pivot value
                                                                                                    //cout << "Pivot= " << pivot << endl;

    for(const string& word : words)                                                                 // this loops through all the elements. const declares word as a constant reference to each element in words so its not modied aswell and we use a refrence to words so there isnt unessary copies .
        {
            if(word < pivot)                                                                        // if the word is greater than piviot we push it int G
            {
                L.push_back(word);
            }
            else if (word > pivot)                                                                 // if word is greater than piviot then push back to L
            {
                G.push_back(word);
            }
            else                                                                                    // if word is equall to piviot then we push it to E 
            {
                E.push_back(word);                              
            }
        }
                                                                                               

    quickSort(L);                                                                                   //recursive calls 
    quickSort(G);
    
    words.clear();                                                                                  //removes all elemnts from words before reinserting the sorted ones 

    words.insert(words.end(), L.begin(), L.end());                                                  //inserst all the elemnts in L into words but since all words are less than the piviot they must 
    words.insert(words.end(), E.begin(), E.end());
    words.insert(words.end(), G.begin(), G.end());
}
void swap(string &a, string &b)                                                                     // swap function swaps two values of a string by reference 
{
    string temp = a;
    a = b;
    b = temp;
}
void downHeap( vector<string> & words, int i, int n )                                               // down heaping ensures min heap is maintianed that the smallest value is at the root 
{
    int root = i;                                                                                   // starts off assuming the current node is the root(smallest)
    int leftNode = 2*i +1 ;                                                                         //index of left and right node- leanrt in class because heaps are sorted squenquially  
    int rightNode = 2 * i +2 ;

    if(leftNode < n && words[leftNode] < words[root])                                               //first chicking if left node is in the range and if its current vlaue is less than the root if so update root 
    {
        root = leftNode;
    }
    if(rightNode < n && words[rightNode] < words[root])
    {
        root = rightNode;
    }
    if(root != i)                                                                                   //if the root was changed we swap the parent(i) with the child (root) and we call downheap recursively to maintain the min heap properties 
    {
        swap(words[i], words[root]);
        downHeap(words, root, n);
    }

}
void removeRoot(vector<string>&words,int &n)
{
    if(n <=0)                                                                                       //base case 
    {
    return;
    }
    //for (int i = n - 1; i > 0; i--)                                                                 // looping through to swap the last element with the first and romeving the root 
    //{
    //    swap(words[0], words[i]);
    //}
    swap(words[0], words[n-1]);
    n--;
    downHeap(words,0,n);                                                                            // have to call down heap because the last elment might not satisfiy the min heap principle

}

void makeHeap(vector<string>&words)                                                                 // builds a heap from the unsorted strings
{
    int n = words.size();                                                                            
    for(int i = n/2-1; i>=0; i--)                                                                   //loop starts at the bottom and moves up but we start at n/2-1 because the leaf nodes do not have chilrdern and therefore dont need to be sorted 
    {
        downHeap(words, i, n);
    }

}

void heapSort(vector<string>&words)
{
    int n = words.size();
    makeHeap(words);                                                                                
    while(n>0)                                                                                       // loop will run as long as there are elemnts to remove 
    {
        removeRoot(words,n);
    }
    reverse(words.begin(), words.end());                                                             // only relizeed this after that the look come out backwards so we need to reverse the the sorted words 
}

void systemSort(vector<string> &words)
{
   sort(words.begin(), words.end());
}