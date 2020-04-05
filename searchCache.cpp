#include "searchCache.h"
#include "stringc.h"

// constructors
SearchCache::SearchCache() {
  this->name = "";
  this->index = -1;
};

SearchCache::SearchCache(std::string name, int index) {
  this->name = name;
  this->index = index;
};

// getters and setters
std::string SearchCache::getName() {
  return name;
};

void SearchCache::setName(std::string name) {
  this->name = name;
};

int SearchCache::getIndex() {
  return index;
};

void SearchCache::setIndex(int index) {
  this->index = index;
};

// binary search
bool binarySearchCache(SearchCache *cache, std::string tcName, int size, int *index) {
  // initialise
  int low = 0, mid = 0, up = size;

  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare strings
    int comp = compareInsensitive(cache[mid].getName(), tcName);
    if (comp == 0) {
      // if existing name is same as new name
      *index = mid;
      return true;
    };
    if (comp < 0) {
      // if existing name is before new name
      low = mid + 1;
    } else {
      // if existing name is after new name
      up = mid - 1;
    };
  };

  // compare strings
  int comp = compareInsensitive(cache[mid].getName(), tcName);
  if (comp > 0) {
    // if existing name is after new name
    *index = mid;
    return false;
  } else {
    // if existing name is before new name
    *index = mid + 1;
    return false;
  };
};
