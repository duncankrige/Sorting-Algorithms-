/*****************************************************************
 ** FILE: sort.hpp
 ** AUTHOR: D.Krige
 ** DATE: 12 Feb 2025
 ** PURPOSE: Header file 
 *****************************************************************/
#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void bubbleSort(vector<string>& words);
list<string> merge(const list<string>& A, const list<string>& B);
list<string> mergeSort(list<string>& S);
void parting(vector<string>& words,vector<string>& L, vector<string>& E, vector<string>& G);
void quickSort(vector<string>& words);
void downHeap( vector<string> & words, int i, int n );
void removeRoot(vector<string>&words,int &n);
void makeHeap(vector<string>&words);
void heapSort(vector<string>&words);
void systemSort(vector<string> &words);

#endif
