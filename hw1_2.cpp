/*
 * Title: hw1_2.cpp
 * Abstract: This program reads reads two groups of numbers in which
 *           each group has several integer numbers without duplicates.
 *           The program should display the non-common numbers in both
 *           groups in the descending order.
 * Author: Justin Mello
 * ID: 2002
 * Date: 03/05/2021
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {

    int groupOneAmount = 0;
    int groupTwoAmount = 0;
    bool matchFound = false;

    cin >> groupOneAmount;
    int groupOne[groupOneAmount];

    //Setup array for first group
    for(int i = 0; i < groupOneAmount; i++) {
        cin >> groupOne[i];
    }

    cin >> groupTwoAmount;
    int groupTwo[groupTwoAmount];

    //Setup array for second Group
    for(int j = 0; j < groupTwoAmount; j++) {
        cin >> groupTwo[j];
    }

    //Sort both arrays
    sort(groupOne, groupOne + groupOneAmount);
    sort(groupTwo, groupTwo + groupTwoAmount);

    vector<int> groupThree;


    //Compare 1st array
    for(int i = 0; i < groupOneAmount; i++) {
        for(int j = 0; j < groupTwoAmount; j++) {
            if(groupOne[i] == groupTwo[j]) {
                matchFound = true;
            }
        }
        if(matchFound == false) {
            groupThree.push_back(groupOne[i]);
        }
        matchFound = false;
    }
    //Compare Second Array
    for(int i = 0; i < groupTwoAmount; i++) {
        for(int j = 0; j < groupOneAmount; j++) {
            if(groupTwo[i] == groupOne[j]) {
                matchFound = true;
            }
        }
        if(matchFound == false) {
            groupThree.push_back(groupTwo[i]);
        }
        matchFound = false;
    }

    //Sort vector and display results
    sort(groupThree.begin(), groupThree.end(), greater<int>());

    cout << "Answer: ";

    //If Vector is empty display none
    if(groupThree.size() == 0) {
        cout << "None" << endl;
    }
    //Otherwise display results
    else {
        for (int x = 0; x != groupThree.size(); ++x) {
            cout << groupThree[x] << " ";
        }
    }
    return 0;
}

