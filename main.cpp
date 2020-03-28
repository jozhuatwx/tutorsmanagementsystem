#include <algorithm>
#include <time.h>
#include <iostream>
using namespace std;

// supplementary functions
time_t intToTime(int day, int month, int year) {
  struct tm *date;

  // set to current time
  time_t currentTime;
  date = localtime(&currentTime);

  // change date to user input date
  date->tm_mday = day;
  date->tm_mon = month - 1; // tm month measures from 0
  date->tm_year = year - 1900; // tm year measures from 1900

  return mktime(date);
};

bool validateDate(int day, int month, int year) {
  // to ensure the date is valid
  if (year >= 1970 && year < 3000 && day >= 1 && month >= 1) {
    // to ensure number of days is valid
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
      if (day <= 31) {
        return true;
      };
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day <= 30) {
        return true;
      };
    } else if (month == 2) {
      // to account for leap years
      if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        if (day <= 29) {
          return true;
        };
      } else {
        if (day <= 28) {
          return true;
        };
      };
    };
  };

  return false;
};

int compareInsensitive(string s1, string s2) {
  // convert s1 and s2 to lower case
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

  // compare
  return s1.compare(s2);
};

size_t findInsensitive(string s1, string s2) {
  // convert s1 and s2 to lower case
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

  // find
  return s1.find(s2);
};

void ltrim(string &str) {
  // erase with whitespaces from the left
  str.erase(0, str.find_first_not_of("\t\n\v\f\r "));
};

void rtrim(string &str) {
  // erase with whitespaces from the right
  str.erase(str.find_last_not_of("\t\n\v\f\r ") + 1);
};

void trim(string &str) {
  ltrim(str);
  rtrim(str);
};

// tutor structure
struct Tutor {
  public:
    int tutorID;
    string name;
    time_t dateJoined;
    time_t dateTerminated;
    double hourlyPayRate;
    string phone;
    string address;
    string tuitionCenterCode;
    string tuitionCenterName;
    string subjectCode;
    string subjectName;
    int rating;

    Tutor() {};

    Tutor(int tutorID, string name, time_t dateJoined, time_t dateTerminated, double hourlyPayRate, string phone, string address, string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, int rating) {
      this->tutorID = tutorID;
      this->name = name;
      this->dateJoined = dateJoined;
      this->dateTerminated = dateTerminated;
      this->hourlyPayRate = hourlyPayRate;
      this->phone = phone;
      this->address = address;
      this->tuitionCenterCode = tuitionCenterCode;
      this->tuitionCenterName = tuitionCenterName;
      this->subjectCode = subjectCode;
      this->subjectName = subjectName;
      this->rating = rating;
    };

    Tutor(int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, int rating) {
      this->tutorID = tutorID;
      this->name = name;
      this->dateJoined = intToTime(dayJoined, monthJoined, yearJoined);
      this->dateTerminated = intToTime(dayTerminated, monthTerminated, yearTerminated);
      this->hourlyPayRate = hourlyPayRate;
      this->phone = phone;
      this->address = address;
      this->tuitionCenterCode = tuitionCenterCode;
      this->tuitionCenterName = tuitionCenterName;
      this->subjectCode = subjectCode;
      this->subjectName = subjectName;
      this->rating = rating;
    };
};


// primary functions
void addTutor(Tutor *&tutors, int *tutorSize) {
  // initialise
  int tutorID = 1, rating, dayJoined, monthJoined, yearJoined;
  string name, phone, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName;
  double hourlyPayRate;
  char separator;

  // create new array
  Tutor newTutors[*tutorSize + 1];

  // generate tutor id
  for (int i = 0; i < *tutorSize; i++) {
    if (tutors[i].tutorID > (tutorID - 1)) {
      tutorID = tutors[i].tutorID + 1;
    };
  };

  // get user input
  do {
    cout << "Name               : ";
    getline(cin, name);
    trim(name);
  } while (name == "");

  do {
    cout << "Date Joined (d/m/y): ";
    // ignore enter key
    if (cin.peek() != '\n') {
      cin >> dayJoined >> separator >> monthJoined >> separator >> yearJoined;
    };

    if (!cin) {
      // clear error state
      cin.clear();
    };

    // clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  } while (!validateDate(dayJoined, monthJoined, yearJoined));

  do {
    cout << "Hourly Pay (40-80) : ";
    // ignore enter key
    if (cin.peek() != '\n') {
      cin >> hourlyPayRate;
    };

    if (!cin) {
      // clear error state
      cin.clear();
    };

    // clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  } while (hourlyPayRate < 40 || hourlyPayRate > 80);

  do {
    cout << "Phone              : ";
    getline(cin, phone);
    trim(phone);
  } while (phone == "");

  do {
    cout << "Address            : ";
    getline(cin, address);
    trim(address);
  } while (address == "");

  do {
    cout << "Tuition Center Code: ";
    getline(cin, tuitionCenterCode);
    trim(tuitionCenterCode);
  } while (tuitionCenterCode == "");

  do {
    cout << "Tuition Center Name: ";
    getline(cin, tuitionCenterName);
    trim(tuitionCenterName);
  } while (tuitionCenterName == "");

  do {
    cout << "Subject Code       : ";
    getline(cin, subjectCode);
    trim(subjectCode);
  } while (subjectCode == "");

  do {
    cout << "Subject Name       : ";
    getline(cin, subjectName);
    trim(subjectName);
  } while (subjectName == "");

  do {
    cout << "Rating (1-5)       : ";
    // ignore enter key
    if (cin.peek() != '\n') {
      cin >> rating;
    };

    if (!cin) {
      // clear error state
      cin.clear();
    };

    // clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  } while (rating < 1 || rating > 5);

  bool insert = true;
  Tutor newTutor(tutorID, name, dayJoined, monthJoined, yearJoined, 0, 0, 0, hourlyPayRate, phone, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, rating);

  // insertion sort
  if (*tutorSize == 0) {
    // insert new tutor as there are no existing tutors
    newTutors[0] = newTutor;
  } else {
    for (int i = 0; i < *tutorSize; i++) {
      if (insert) {
        // before insertion
        // compare the strings
        int comp = compareInsensitive(tutors[i].name, newTutor.name);
        if (comp <= 0) {
          // if existing name is before or same as new tutor
          newTutors[i] = tutors[i];
        } else {
          // if existing name is after new tutor
          newTutors[i] = newTutor;
          newTutors[i + 1] = tutors[i];
          insert = false;
        };

        // if new name is after all existing names
        if (insert && i == *tutorSize - 1) {
          newTutors[i + 1] = newTutor;
        };
      } else {
        // after insertion
        newTutors[i + 1] = tutors[i];
      };
    };
  };

  // increase tutor array by 1
  tutors = new Tutor[*tutorSize + 1];

  // copy all element back into tutor array
  for (int i = 0; i < *tutorSize + 1; i++) {
    tutors[i] = newTutors[i];
  };

  // increase size
  *tutorSize += 1;
};

void displayRecord(Tutor tutor) {
  cout << "ID                 : " << tutor.tutorID << endl;
  cout << "Name               : " << tutor.name << endl;
  struct tm *dateJoined = localtime(&tutor.dateJoined);
  cout << "Date Joined        : " << dateJoined->tm_mday << "/" << dateJoined->tm_mon + 1 << "/" << dateJoined->tm_year + 1900 << endl;
  cout << "Date Terminated    : ";
  if (tutor.dateTerminated != -1) {
    // display date as it is set
    struct tm *dateTerminated = localtime(&tutor.dateTerminated);
    cout << dateTerminated->tm_mday << "/" << dateTerminated->tm_mon + 1 << "/" << dateTerminated->tm_year + 1900 << endl;
  } else {
    // hide date as it is not set
    cout << "-" << endl;
  };
  cout << "Phone              : " << tutor.phone << endl;
  cout << "Address            : " << tutor.address << endl;
  cout << "Tuition Center Code: " << tutor.tuitionCenterCode << endl;
  cout << "Tuition Center Name: " << tutor.tuitionCenterName << endl;
  cout << "Subject Code       : " << tutor.subjectCode << endl;
  cout << "Subject Name       : " << tutor.subjectName << endl;
  cout << "Rating             : " << tutor.rating << endl << endl;
};

void searchTutorID(Tutor *tutors, int tutorSize) {
  int tutorID = 0;
  bool found;

  // get user input
  cout << "Tutor ID: ";
  // ignore enter key
  if (cin.peek() != '\n') {
    cin >> tutorID;
  };

  if (!cin) {
    // clear error state
    cin.clear();
  };

  // clear the input buffer
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    // find tutor with searched id
    if (tutors[i].tutorID == tutorID) {
      // display result
      displayRecord(tutors[i]);
      // set as found
      found = true;
      // stop iteration
      break;
    };
  };

  // if no results
  if (!found) {
    cout << "No result found" << endl;
  };
};

void displayAllRecords(Tutor *tutors, int tutorSize) {
  // initialise
  int select, page = 1, upper;

  // calculate total page numbers
  upper = tutorSize / 10;
  if (tutorSize % 10 > 0) {
    upper++;
  };

  do {
    if (select != 1) {
      cout << "ID   Name     " << endl;
      // display page
      for (int i = (page - 1) * 10; i < page * 10; i++) {
        // if it is the last page, break if page has less than 10
        if (page == upper && i == (page - 1) * 10 + tutorSize % 10 && i != 0) {
          break;
        };
        // spacing
        if (tutors[i].tutorID < 10) {
          cout << " ";
        };
        cout << tutors[i].tutorID << "   " << tutors[i].name << endl;
      };
      
      // display page number
      cout << endl << "Page " << page << endl << endl;
    };

    // get user input
    cout << "1. View more details" << endl;
    cout << "2. Jump to page";
    if (upper == 1) {
      cout << " (disabled)";
    };
    cout << endl << "3. Next page";
    if (page >= upper) {
      cout << " (disabled)";
    };
    cout << endl << "4. Previous page";
    if (page <= 1) {
      cout << " (disabled)";
    };
    cout << endl << "5. Exit" << endl;
    cout << "Please select (1-5):";
    // ignore enter key
    if (cin.peek() != '\n') {
      cin >> select;
    };

    if (!cin) {
      // clear error state
      cin.clear();
    };

    // clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch (select) {
      case 1:
        searchTutorID(tutors, tutorSize);
        cout << endl;
        break;

      case 2:
        if (upper > 1) {
          do {
            cout << "Page (1-" << upper << "): ";
            // ignore enter key
            if (cin.peek() != '\n') {
              cin >> page;
            };

            if (!cin) {
              // clear error state
              cin.clear();
            };

            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
          } while (page < 1 || page > upper);
        };
        cout << endl;
        break;

      case 3:
        if (page < upper) {
          page++;
        };
        cout << endl;
        break;

      case 4:
        if (page > 1) {
          page--;
        };
        cout << endl;
        break;

      default:
        break;
    };
  } while (select != 5);
};

void searchRating(Tutor *tutors, int tutorSize) {
  int rating, tempSize = 0;
  Tutor *tempTutors1, *tempTutors2;
  bool temp1;

  // get user input
  do {
    cout << "Rating: ";
    // ignore enter key
    if (cin.peek() != '\n') {
      cin >> rating;
    };

    if (!cin) {
      // clear error state
      cin.clear();
    };

    // clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  } while (rating < 1 || rating > 5);

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    // find tutors with searched rating
    if (tutors[i].rating == rating) {
      if (tempSize == 0) {
        // allocate memory
        tempTutors1 = new Tutor[1];
        tempTutors1[0] = tutors[i];
        temp1 = true;
        // increase temporary array size
        tempSize++;
      } else {
        if (temp1) {
          // allocate memory
          tempTutors2 = new Tutor[tempSize + 1];
          for (int x = 0; x < tempSize; x++) {
            tempTutors2[x] = tempTutors1[x];
          };
          tempTutors2[tempSize] = tutors[i];
          // deallocate memory
          delete [] tempTutors1;
          temp1 = false;
        } else {
          // allocate memory
          tempTutors1 = new Tutor[tempSize + 1];
          for (int x = 0; x < tempSize; x++) {
            tempTutors1[x] = tempTutors2[x];
          };
          tempTutors1[tempSize] = tutors[i];
          // deallocate memory
          delete [] tempTutors2;
          temp1 = true;
        };
        // increase temporary array size
        tempSize++;
      };
    };
  };

  if (tempSize > 0) {
    // display all records
    if (temp1) {
      displayAllRecords(tempTutors1, tempSize);
      // deallocate memory
      delete [] tempTutors1;
    } else {
      displayAllRecords(tempTutors2, tempSize);
      // deallocate memory
      delete [] tempTutors2;
    };
  } else {
    // if no results
    cout << "No results found" << endl;
  };
};

struct SortCache {
  string value;
  int start;

  SortCache() {};

  SortCache(string value, int start) {
    this->value = value;
    this->start = start;
  };
};

bool binarySearchCache(SortCache *arr, string keyword, int size, int *index) {
  int lower = 0, mid, upper = size - 1;

  while (lower <= upper) {
    // get mid point
    mid = (upper - lower) / 2 + lower;
    // compare strings
    int comp = compareInsensitive(arr[mid].value, keyword);
    if (comp == 0) {
      // if existing name is same as new name
      *index = mid;
      return true;
    };
    if (comp < 0) {
      // if existing name is before new name
      lower = mid + 1;
    } else {
      // if existing name is after new name
      upper = mid - 1;
    };
  };

  // compare strings
  int comp = compareInsensitive(arr[mid].value, keyword);
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

void searchTuitionName(Tutor *tutors, int tutorSize) {
  // initialise
  int tempSize = 0, nameSize = 0, nameIndex, tempIndex, select;
  string tuitionName;
  SortCache *tempNames1, *tempNames2;
  Tutor *tempTutors1, *tempTutors2;
  bool name1, exist, temp1;

  // get user input
  do {
    cout << "Tuition Center Name: ";
    getline(cin, tuitionName);
    trim(tuitionName);
  } while (tuitionName == "");

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    // find tutors with searched tuition name
    if (findInsensitive(tutors[i].tuitionCenterName, tuitionName) != string::npos) {
      // binary insertion sort
      if (nameSize == 0) {
        // allocate memory
        tempNames1 = new SortCache[1];
        // insert new tuition name as there are no existing names
        tempNames1[0] = SortCache(tutors[i].tuitionCenterName, 0);
        // increase name size
        nameSize++;
        // set name 1 as active
        name1 = true;
      } else {
        // binary search if tuition name exists
        if (name1) {
          exist = binarySearchCache(tempNames1, tutors[i].tuitionCenterName, nameSize, &nameIndex);
        } else {
          exist = binarySearchCache(tempNames2, tutors[i].tuitionCenterName, nameSize, &nameIndex);
        };

        if (!exist) {
          // name does not exist
          if (name1) {
            // allocate memory
            tempNames2 = new SortCache[nameSize + 1];
            for (int x = 0; x < nameIndex; x++) {
              tempNames2[x] = tempNames1[x];
            };

            // calculate start value
            int start;
            if (nameIndex == 0) {
              // name is before all existing names
              start = 0;
            } else if (nameIndex == nameSize) {
              // name is after all existing names
              start = tempSize;
            } else {
              // name is in between existing names
              start = tempNames1[nameIndex].start;
            };
            tempNames2[nameIndex] = SortCache(tutors[i].tuitionCenterName, start);

            for (int x = nameIndex + 1; x < nameSize + 1; x++) {
              tempNames2[x].value = tempNames1[x - 1].value;
              tempNames2[x].start = tempNames1[x - 1].start + 1;
            };

            // deallocate memory
            delete [] tempNames1;
            name1 = false;
          } else {
            // allocate memory
            tempNames1 = new SortCache[nameSize + 1];
            for (int x = 0; x < nameIndex; x++) {
              tempNames1[x] = tempNames2[x];
            };

            // calculate start value
            int start;
            if (nameIndex == 0) {
              // name is before all existing names
              start = 0;
            } else if (nameIndex == nameSize) {
              // name is after all existing names
              start = tempSize;
            } else {
              // name is in between existing names
              start = tempNames2[nameIndex].start;
            };
            tempNames1[nameIndex] = SortCache(tutors[i].tuitionCenterName, start);

            for (int x = nameIndex + 1; x < nameSize + 1; x++) {
              tempNames1[x].value = tempNames2[x - 1].value;
              tempNames1[x].value = tempNames2[x - 1].start + 1;
            };

            // deallocate memory
            delete [] tempNames2;
            name1 = true;
          };

          // increase name size
          nameSize++;
        } else {
          // name exists
          // adjust start of all names after the current name
          if (name1) {
            for (int x = nameIndex + 1; x < nameSize; x++) {
              tempNames1[x].start += 1;
            };
          } else {
            for (int x = nameIndex + 1; x < nameSize; x++) {
              tempNames2[x].start += 1;
            };
          };
        };
      };

      if (tempSize == 0) {
        // allocate memory
        tempTutors1 = new Tutor[1];
        // insert tutor as there are no existing tutors
        tempTutors1[0] = tutors[i];
        // increase temporary array size
        tempSize++;
        // set temp 1 as active
        temp1 = true;
      } else {
        // calculate index
        if (nameIndex < nameSize - 1) {
          // name is in between existing names;
          if (name1) {
            tempIndex = tempNames1[nameIndex + 1].start - 1;
          } else {
            tempIndex = tempNames2[nameIndex + 1].start - 1;
          };
        } else {
          tempIndex = tempSize;
        };

        // copy element into temporary array
        if (temp1) {
          // allocate memory
          tempTutors2 = new Tutor[tempSize + 1];

          for (int x = 0; x < tempIndex; x++) {
            tempTutors2[x] = tempTutors1[x];
          };

          tempTutors2[tempIndex] = tutors[i];

          for (int x = tempIndex + 1; x < tempSize + 1; x++) {
            tempTutors2[x] = tempTutors1[x - 1];
          };

          // deallocate memory
          delete [] tempTutors1;
          temp1 = false;
        } else {
          // allocate memory
          tempTutors1 = new Tutor[tempSize + 1];

          for (int x = 0; x < tempIndex; x++) {
            tempTutors1[x] = tempTutors2[x];
          };

          tempTutors1[tempIndex] = tutors[i];

          for (int x = tempIndex + 1; x < tempSize + 1; x++) {
            tempTutors1[x] = tempTutors2[x - 1];
          };

          // deallocate memory
          delete [] tempTutors2;
          temp1 = true;
        };

        // increase temporary array size
        tempSize++;
      };
    };
  };

  // get user input
  if (nameSize == 1) {
    select = 1;
  } else if (nameSize >= 2) {
    for (int i = 0; i < nameSize; i++) {
      cout << i + 1 << ". ";
      if (name1) {
        cout << tempNames1[i].value;
      } else {
        cout << tempNames2[i].value;
      };
      cout << endl;
    };
    do {
      cout << "Please select (1-" << nameSize << "): ";
      // ignore enter key
      if (cin.peek() != '\n') {
        cin >> select;
      };

      if (!cin) {
        // clear error state
        cin.clear();
      };

      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (select < 1 || select > nameSize);
  } else {
    // if no results
    cout << "No results found" << endl;
  };

  // search through a portion of the temporary array
  if (select >= 1) {
    int size, start;
    if (name1) {
      // calculate size
      if (select == 1) {
        if (nameSize == 1) {
          size = tempSize;
        } else {
          size = tempNames1[select].start;
        };
      } else if (select < nameSize) {
        size = tempNames1[select].start - tempNames1[select - 1].start;
      } else {
        size = tempSize - tempNames1[select - 1].start;
      };
      start = tempNames1[select - 1].start;
    } else {
      // calculate size
      if (select == 1) {
        if (nameSize == 1) {
          size = tempSize;
        } else {
          size = tempNames2[select].start;
        };
      } else if (select < nameSize) {
        size = tempNames2[select].start - tempNames2[select - 1].start;
      } else {
        size = tempSize - tempNames2[select - 1].start;
      };
      start = tempNames2[select - 1].start;
    };

    if (temp1) {
      tempTutors2 = new Tutor[size];
      for (int i = 0; i < size; i++) {
        tempTutors2[i] = tempTutors1[start + i];
      };
      delete [] tempTutors1;
      temp1 = false;

      displayAllRecords(tempTutors2, size);
    } else {
      tempTutors1 = new Tutor[size];
      for (int i = 0; i < size; i++) {
        tempTutors1[i] = tempTutors2[start + i];
      };
      delete [] tempTutors2;
      temp1 = true;

      displayAllRecords(tempTutors1, size);
    };

    // deallocate memory
    if (name1) {
      delete [] tempNames1;
    } else {
      delete [] tempNames2;
    };

    if (temp1) {
      delete [] tempTutors1;
    } else {
      delete [] tempTutors2;
    };
  };
};

void sortTutorID(Tutor *tutors, int tutorSize) {};
void sortPayRate(Tutor *tutors, int tutorSize) {};
void sortRating(Tutor *tutors, int tutorSize) {};

void modifyTutor(Tutor *&tutors, int tutorSize) {
  // initialise
  int tutorID, select;
  string phone, address;
  bool found;

  // get user input
  cout << "Tutor ID: ";
  // ignore enter key
  if (cin.peek() != '\n') {
    cin >> tutorID;
  };

  if (!cin) {
    // clear error state
    cin.clear();
  };

  // clear the input buffer
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    // find tutor with searched id
    if (tutors[i].tutorID == tutorID) {
      // get user input
      cout << "Results found. Modify: " << endl;
      cout << "1. Phone" << endl;
      cout << "2. Address" << endl;
      cout << "3. Both" << endl;
      cout << "Please select (1-3): ";
      // ignore enter key
      if (cin.peek() != '\n') {
        cin >> select;
      };

      if (!cin) {
        // clear error state
        cin.clear();
      };

      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(),'\n');

      // modify phone
      if (select == 1 || select == 3) {
        cout << "Current Phone: " << tutors[i].phone << endl;
        do {
          cout << "New Phone: ";
          getline(cin, phone);
          trim(phone);
        } while (phone == "");
      } else {
        phone = tutors[i].phone;
      };

      // modify address
      if (select == 2 || select == 3) {
        cout << "Current Address: " << tutors[i].address << endl;
        do {
          cout << "New Address: ";
          getline(cin, address);
          trim(address);
        } while (address == "");
      } else {
        address = tutors[i].address;
      };

      // modify tutor in tutor array
      tutors[i] = Tutor(tutors[i].tutorID, tutors[i].name, tutors[i].dateJoined, tutors[i].dateTerminated, tutors[i].hourlyPayRate, phone, address, tutors[i].tuitionCenterCode, tutors[i].tuitionCenterName, tutors[i].subjectCode, tutors[i].subjectName, tutors[i].rating);
      // set as found
      found = true;
      // stop iteration
      break;
    };
  };

  // if no results
  if (!found) {
    cout << "No result found" << endl;
  };
};

void terminateTutor(Tutor *&tutors, int tutorSize) {
  // initialise
  int tutorID, day, month, year ;
  time_t dateTerminated;
  char separator, input;
  bool found;

  // get user input
  cout << "Tutor ID: ";
  // ignore enter key
  if (cin.peek() != '\n') {
    cin >> tutorID;
  };

  if (!cin) {
    // clear error state
    cin.clear();
  };

  // clear the input buffer
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    // find tutor with searched id
    if (tutors[i].tutorID == tutorID) {
      // ask for termination date
      do {
        cout << "Date Terminated (d/m/y): ";
        // ignore enter key
        if (cin.peek() != '\n') {
          cin >> day >> separator >> month >> separator >> year;
          // convert to time
          dateTerminated = intToTime(day, month, year);
        };

        if (!cin) {
          // clear error state
          cin.clear();
        };

        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      } while (!validateDate(day, month, year) || difftime(dateTerminated, tutors[i].dateJoined) <= 0);

      // ask for confirmation
      do {
        cout << "Do you confirmed? (Y/N): ";
        cin >> input;
      } while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

      switch (input) {
        case 'y':
        case 'Y':
          // terminate tutor in tutor array
          tutors[i] = Tutor(tutors[i].tutorID, tutors[i].name, tutors[i].dateJoined, dateTerminated, tutors[i].hourlyPayRate, tutors[i].phone, tutors[i].address, tutors[i].tuitionCenterCode, tutors[i].tuitionCenterName, tutors[i].subjectCode, tutors[i].subjectName, tutors[i].rating);
          break;

        default:
          break;
      };
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      // set as found
      found = true;
      // stop iteration
      break;
    };
  };

  // if no results
  if (!found) {
    cout << "No result found" << endl;
  };
};

void deleteTutor(Tutor *&tutors, int *tutorSize) {
  // initialise
  int tutorID;
  char separated, input;
  bool found;

  // create new array
  Tutor newTutors[*tutorSize - 1];

  // get user input
  cout << "Tutor ID: ";
  // ignore enter key
  if (cin.peek() != '\n') {
    cin >> tutorID;
  };

  if (!cin) {
    // clear error state
    cin.clear();
  };

  // clear the input buffer
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  // search through the array
  for (int i = 0; i < *tutorSize; i++) {
    // find tutor with searched id
    if (tutors[i].tutorID == tutorID) {
      // print tutor details
      displayRecord(tutors[i]);

      if (tutors[i].dateTerminated == -1) {
        break;
      };

      // check if tutor is terminated 6 months ago
      struct tm *dateTerminated = localtime(&tutors[i].dateTerminated);

      if (dateTerminated->tm_mon > 6) {
        dateTerminated->tm_mon -= 6;
        dateTerminated->tm_year += 1;
      } else {
        dateTerminated->tm_mon += 6;
      };

      if (difftime(mktime(dateTerminated), time(NULL)) > 0) {
        break;
      };

      // ask for confirmation
      do {
        cout << "Do you confirmed? (Y/N): ";
        cin >> input;
      } while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

      bool insert = true;

      switch (input) {
        case 'y':
        case 'Y':
          // copy to temporary array
          for (int x = 0; x < *tutorSize - 1; x++) {
            if (insert && x != i) {
              newTutors[x] = tutors[x];
            } else if (x == i && x != *tutorSize - 1) {
              newTutors[x] = tutors[x + 1];
              insert = false;
            } else if (!insert) {
              newTutors[x] = tutors[x + 1];
            };
          };

          // decrease tutor array by 1
          tutors = new Tutor[*tutorSize - 1];

          // copy all element back into tutor array
          for (int x = 0; x < *tutorSize - 1; x++) {
            tutors[x] = newTutors[x];
          };

          // decrease size
          *tutorSize -= 1;
          break;

        default:
          break;
      };
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      // set as found
      found = true;
      // stop iteration
      break;
    };
  };

  // if no results
  if (!found) {
    cout << "No result found" << endl;
  };
};


int main() {
  // initialise
  int select, subselect;
  int tutorSize = 10;
  Tutor *tutors;
  tutors = new Tutor[tutorSize];

  // dummy data
  // lower limit for time is 1/1/1970, https://docs.microsoft.com/en-us/cpp/atl-mfc-shared/reference/ctime-class
  tutors[0] = Tutor(2, "Aaron", 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  tutors[1] = Tutor(1, "Bill", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  tutors[2] = Tutor(4, "Charlie", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  tutors[3] = Tutor(3, "Edwin", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);
  tutors[4] = Tutor(10, "George", 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  tutors[5] = Tutor(8, "Jamal", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  tutors[6] = Tutor(5, "Kenny", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  tutors[7] = Tutor(9, "Maria", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  tutors[8] = Tutor(7, "Patricia", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  tutors[9] = Tutor(6, "Shelby", 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);

  do {
    cout << "Tutor Management System" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Add Tutor" << endl;
    cout << "2. Display All Tutors" << endl;
    cout << "3. Search Tutors" << endl;
    cout << "4. Sort and Display Tutors" << endl;
    cout << "5. Modify Tutor" << endl;
    cout << "6. Terminate Tutor" << endl;
    cout << "7. Delete Tutor" << endl;
    cout << "8. Exit" << endl;

    do {
      cout << "Please select function: ";
      // ignore enter key
      if (cin.peek() != '\n') {
        cin >> select;
      };

      if (!cin) {
        // clear error state
        cin.clear();
      };

      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (select < 1 || select > 8);
    cout << endl;

    switch (select) {
      // add tutor
      case 1:
        cout << "Add New Tutor" << endl;
        cout << "-------------" << endl;
        addTutor(tutors, &tutorSize);
        break;

      // display all records
      case 2:
        cout << "All Tutor Records" << endl;
        cout << "-----------------" << endl;
        displayAllRecords(tutors, tutorSize);
        break;

      // search records
      case 3:
        cout << "1. Tutor ID" << endl;
        cout << "2. Rating" << endl;
        cout << "3. Tuition Center Name" << endl;

        do {
          cout << "Search by (1-3): ";
          // ignore enter key
          if (cin.peek() != '\n') {
            cin >> subselect;
          };

          if (!cin) {
            // clear error state
            cin.clear();
          };

          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        } while (subselect < 1 || subselect > 3);

        switch (subselect) {
          // search by tutor id
          case 1:
            cout << "Search by Tutor ID" << endl;
            cout << "------------------" << endl;
            searchTutorID(tutors, tutorSize);
            break;

          // search by rating
          case 2:
            cout << "Search by Rating" << endl;
            cout << "----------------" << endl;
            searchRating(tutors, tutorSize);
            break;

          // search by tuition center name
          case 3:
            cout << "Search by Tuition Center Name" << endl;
            cout << "_____________________________" << endl;
            searchTuitionName(tutors, tutorSize);
            break;

          default:
            break;
        };
        break;

      // sort and display records
      case 4:
        cout << "1. Tutor ID (Ascending)" << endl;
        cout << "2. Hourly Pay Rate (Ascending)" << endl;
        cout << "3. Rating (Ascending)" << endl;

        do {
          cout << "Sort and Display by (1-3): ";
          // ignore enter key
          if (cin.peek() != '\n') {
            cin >> subselect;
          };

          if (!cin) {
            // clear error state
            cin.clear();
          };

          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        } while (subselect < 1 || subselect > 3);

        switch (subselect) {
          // sort and display by tutor id
          case 1:
            cout << "Sort and Display by Tutor ID" << endl;
            cout << "----------------------------" << endl;
            sortTutorID(tutors, tutorSize);
            break;

          // sort and display by hourly pay rate
          case 2:
            cout << "Sort and Display by Hourly Pay Rate" << endl;
            cout << "-----------------------------------" << endl;
            sortPayRate(tutors, tutorSize);
            break;

          // sort and display by rating
          case 3:
            cout << "Sort and Display by Rating" << endl;
            cout << "--------------------------" << endl;
            sortRating(tutors, tutorSize);
            break;

          default:
            break;
        };
        break;

      // modify tutor
      case 5:
        cout << "Modify Tutor" << endl;
        cout << "------------" << endl;
        modifyTutor(tutors, tutorSize);
        break;

      // terminate tutor
      case 6:
        cout << "Terminate Tutor" << endl;
        cout << "---------------" << endl;
        terminateTutor(tutors, tutorSize);
        break;

      // delete tutor
      case 7:
        cout << "Delete Tutor" << endl;
        cout << "------------" << endl;
        deleteTutor(tutors, &tutorSize);
        break;

      default:
        break;
    };

    cout << endl;
  } while (select != 8);

  return 0;
};
