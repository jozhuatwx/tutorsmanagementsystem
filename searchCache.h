#pragma once
#include <string>

class SearchCache {
  private:
    std::string name;
    int index;

  public:
    // constructors
    SearchCache();
    SearchCache(std::string name, int index);

    // getters and setters
    std::string getName();
    void setName(std::string name);
    int getIndex();
    void setIndex(int index);
};

// binary search
bool binarySearchCache(SearchCache *cache, std::string tcName, int size, int *index);