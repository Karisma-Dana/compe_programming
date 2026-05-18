#include <bits/stdc++.h>
using namespace std;

// There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
// Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
// What is the minimum number of gondolas needed for the children?
// Input
// The first input line contains two integers n and x: the number of children and the maximum allowed weight.
// The next line contains n integers p_1,p_2,\ldots,p_n: the weight of each child.
// Output
// Print one integer: the minimum number of gondolas.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x \le 10^9
// 1 \le p_i \le x

// Example
// Input:
// 4 10
// 7 2 3 9

// Output:
// 3
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    cin >> x;

    int childernWeight[n];
    for (auto &x : childernWeight){
        cin >> x;
    }

    sort(childernWeight, childernWeight + n);
    int i = 0;
    int j = n - 1;
    int result = 0;

    while (i <= j)
    {
        if(childernWeight[i] + childernWeight[j] <= x){
            result++;
            i++;
            j--;
        }else{
            result++;
            j--;
        }
        
    }
    cout <<result<<"\n";
    







}
