#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::unordered_map;


unordered_map<int, int> costMemo;
string targetStr;
int appendCost, cloneCost;


int findMaxCloneLength(int startIndex) {
    int maxClone = 1;
    int matchCount = 0;
    int rightIndex = 0;

    string suffix = targetStr.substr(startIndex); 

    for (int i = 0; i < startIndex; i++) {
        
        if (targetStr[i] == suffix[rightIndex]) {
            matchCount++;
            rightIndex++;
            maxClone = std::max(matchCount, maxClone);
        } else {
            if (maxClone > startIndex - i) {
                break; 
            }
            rightIndex = 0; 
            matchCount = 0; 

            
            if (targetStr[i] == suffix[rightIndex]) {
                matchCount++;
                rightIndex++;
            }
        }
    }
    return maxClone; 
}


int calculateConstructionCost(int index) {
    if (index >= targetStr.size()) {
        return 0; 
    }
    
    if (costMemo.count(index)) {
        return costMemo[index]; 
    }

    
    int costWithClone = cloneCost + calculateConstructionCost(index + findMaxCloneLength(index));
    int costWithAppend = appendCost + calculateConstructionCost(index + 1);

    
    costMemo[index] = std::min(costWithClone, costWithAppend);
    return costMemo[index]; 
}


int stringConstruction(string target, int cloneCost, int appendCost) {
    costMemo.clear(); 
    targetStr = target; 
    ::cloneCost = cloneCost; 
    ::appendCost = appendCost; 
    return calculateConstructionCost(0); 
}

#endif
