## StringConstruction

**StringConstruction** is a utility designed to find the most cost-effective way to build a target string. You can either append characters with a given append cost or clone substrings with a specified clone cost. The tool uses dynamic programming and backtracking to calculate the cheapest construction method.

### Example

- **Target:** "aa", **Append Cost:** 1, **Clone Cost:** 2  
  - Append 'a' (cost 1) → "a"  
  - Append 'a' (cost 1) → "aa"  
  - **Cheapest Cost:** 2

- **Target:** "aaaa", **Append Cost:** 2, **Clone Cost:** 3  
  - Append 'a' (cost 2) → "a"  
  - Append 'a' (cost 2) → "aa"  
  - Clone "aa" (cost 3) → "aaaa"  
  - **Cheapest Cost:** 7

### How to Use

To use the **StringConstruction** utility, include the header file and call the `stringConstruction` function:

```cpp
#include "StringConstruction.h"
#include <iostream>

int main() {
    // Define the target string and costs
    std::string target = "aa";
    int cloneCost = 2;
    int appendCost = 1;

    // Calculate the cheapest cost
    int min_cost = stringConstruction(target, cloneCost, appendCost);

    // Display the result
    std::cout << "Cheapest cost to build the target string: " << min_cost << std::endl;

    return 0;
}
