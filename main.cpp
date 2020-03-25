#include <algorithm>
#include <time.h>
#include <iostream>

using namespace std;

// supplementary functions
time_t intToTime(int day, int month, int year) {
  struct tm * date;

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
    cin >> name;
  } while (name == "");

  do {
    cout << "Date Joined (d/m/y): ";
    cin >> dayJoined >> separator >> monthJoined >> separator >> yearJoined;
  } while (!validateDate(dayJoined, monthJoined, yearJoined));

  do {
    cout << "Hourly Pay (40-80) : ";
    cin >> hourlyPayRate;
  } while (hourlyPayRate < 40 || hourlyPayRate > 80);
  
  do {
    cout << "Phone              : ";
    cin >> phone;
  } while (phone == "");

  do {
    cout << "Address            : ";
    cin >> address;
  } while (address == "");

  do {
    cout << "Tuition Center Code: ";
    cin >> tuitionCenterCode;
  } while (tuitionCenterCode == "");

  do {
    cout << "Tuition Center Name: ";
    cin >> tuitionCenterName;
  } while (tuitionCenterName == "");

  do {
    cout << "Subject Code       : ";
    cin >> subjectCode;
  } while (subjectCode == "");

  do {
    cout << "Subject Name       : ";
    cin >> subjectName;
  } while (subjectName == "");

  do {
    cout << "Rating (1-5)       : ";
    cin >> rating;
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
        if (comp < 0) {
          // if existing name is before new tutor
          newTutors[i] = tutors[i];
        } else if (comp == 0) {
          // if existing name is equal new tutor
          newTutors[i] = tutors[i];
          newTutors[i + 1] = newTutor;
          insert = false;
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
  struct tm * dateJoined = localtime(&tutor.dateJoined);
  cout << "Date Joined        : " << dateJoined->tm_mday << "/" << dateJoined->tm_mon + 1 << "/" << dateJoined->tm_year + 1900 << endl;
  cout << "Date Terminated    : ";
  if (tutor.dateTerminated != -1) {
    // display date as it is set
    struct tm * dateTerminated = localtime(&tutor.dateTerminated);
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

void displayAllRecords(Tutor *tutors, int tutorSize) {
  for (int i = 0; i < tutorSize; i ++) {
    displayRecord(tutors[i]);
  };
};


void searchTutorID(Tutor *tutors, int tutorSize) {
  int tutorID = 0;
  bool found;

  // get user input
  cout << "Tutor ID: ";
  cin >> tutorID;

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

void searchRating(Tutor *tutors, int tutorSize) {
  int rating;
  bool found;

  // get user input
  do {
    cout << "Rating: ";
    cin >> rating;
  } while (rating < 1 || rating > 5);

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    // find tutors with searched rating
    if (tutors[i].rating == rating) {
      // display result
      displayRecord(tutors[i]);
      // set as found
      found = true;
    };
  };

  // if no results
  if (!found) {
    cout << "No results found" << endl;
  }
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

void searchTuitionName(Tutor *tutors, int tutorSize) {
  // initialise
  string tuitionCenterName;
  bool found, secondList;
  SortCache *tuitionNames1, *tuitionNames2;
  Tutor *tempTutors = new Tutor[tutorSize];
  int nameSize = 0, tempSize = 0, select;

  // get user input
  do {
    cout << "Tuition Center Name: ";
    cin >> tuitionCenterName;
  } while (tuitionCenterName == "");

  // search through the array
  for (int i = 0; i < tutorSize; i++) {
    size_t found = findInsensitive(tutors[i].tuitionCenterName, tuitionCenterName);
    if (found != string::npos) {
      // insertion sort
      if (nameSize == 0) {
        // insert new name as there are no existing names
        tuitionNames1 = new SortCache[1];
        secondList = false;
        // add to tuition name list
        tuitionNames1[0] = SortCache(tutors[i].tuitionCenterName, 0);
        // increment name size;
        nameSize++;
      } else {
        if (secondList) {
          tuitionNames1 = new SortCache[nameSize + 1];
        } else {
          tuitionNames2 = new SortCache[nameSize + 1];
        };

        bool insert = true;
        // find if name added, if not, add it
        for (int x = 0, length = nameSize; x < length; x++) {
          // before insertion
          // compare the strings
          if (insert) {
            int comp = 0;
            if (secondList) {
              comp = compareInsensitive(tuitionNames2[x].value, tutors[i].tuitionCenterName);
            } else {
              comp = compareInsensitive(tuitionNames1[x].value, tutors[i].tuitionCenterName);
            };

            if (comp < 0) {
              // if existing name is before new name
              if (secondList) {
                tuitionNames1[x] = tuitionNames2[x];
              } else {
                tuitionNames2[x] = tuitionNames1[x];
              };
            } else if (comp == 0) {
              // stop iteration
              break;
            } else {
              // if existing name is after new name
              if (secondList) {
                tuitionNames1[x].value = tutors[i].tuitionCenterName;
                tuitionNames1[x].start = 0;
                tuitionNames1[x + 1] = tuitionNames2[x];
              } else {
                tuitionNames2[x].value = tutors[i].tuitionCenterName;
                tuitionNames2[x].start = 0;
                tuitionNames2[x + 1] = tuitionNames1[x];
              };

              // increment name size;
              nameSize++;
              insert = false;
            };

            // if new name is after all existing names
            if (insert && x == length - 1) {
              if (secondList) {
                tuitionNames1[x + 1].value = tutors[i].tuitionCenterName;
                tuitionNames1[x + 1].start = 0;
              } else {
                tuitionNames2[x + 1].value = tutors[i].tuitionCenterName;
                tuitionNames2[x + 1].start = 0;
              };

              // increment name size;
              nameSize++;
              insert = false;
            };
          } else {
            // after insertion
            if (secondList) {
              tuitionNames1[x + 1] = tuitionNames2[x];
            } else {
              tuitionNames2[x + 1] = tuitionNames1[x];
            };
          };

          if (!insert && secondList) {
            delete [] tuitionNames2;
            secondList = false;
          } else {
            delete [] tuitionNames1;
            secondList = true;
          };
        };
      };
    };
  };

  // get user input
  for (int i = 0; i < nameSize; i++) {
    cout << i+1 << ". ";
    if (secondList) {
      cout << tuitionNames2[i].value;
    } else {
      cout << tuitionNames1[i].value;
    };
    cout << endl;
  };
  cout << "Please select: ";
  cin >> select;

  // search through the a portion of temporary array


  // if no results
  if (!found) {
    cout << "No results found" << endl;
  };

  if (secondList) {
    delete [] tuitionNames2;
  } else {
    delete [] tuitionNames1;
  };
};


void sortTutorID(Tutor *tutors, int tutorSize, Tutor *sortedTutors);
void sortPayRate(Tutor *tutors, int tutorSize, Tutor *sortedTutors);
void sortRating(Tutor *tutors, int tutorSize, Tutor *sortedTutors);


void modifyTutor(Tutor *&tutors, int tutorSize);
void deleteTutor(Tutor *&tutors, int *tutorSize);


int main() {
  // initialise
  int select;
  int tutorSize = 10;
  Tutor *tutors;
  tutors = new Tutor[tutorSize];

  // dummy data
  // lower limit for time is 1/1/1970, https://docs.microsoft.com/en-us/cpp/atl-mfc-shared/reference/ctime-class
  tutors[0] = Tutor(2, "Aaron", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  tutors[1] = Tutor(1, "Bill", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  tutors[2] = Tutor(4, "Charlie", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  tutors[3] = Tutor(3, "Edwin", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);
  tutors[4] = Tutor(10, "George", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  tutors[5] = Tutor(8, "Jamal", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  tutors[6] = Tutor(5, "Kenny", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  tutors[7] = Tutor(9, "Maria", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  tutors[8] = Tutor(7, "Patricia", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  tutors[9] = Tutor(6, "Shelby", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 1);
  
  do {
    cout << "Please select function: ";
    cin >> select;
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
      
      // search by tutor id
      case 3:
        cout << "Search by Tutor ID" << endl;
        cout << "------------------" << endl;
        searchTutorID(tutors, tutorSize);
        break;

      // search by rating
      case 4:
        cout << "Search by Rating" << endl;
        cout << "----------------" << endl;
        searchRating(tutors, tutorSize);
        break;

      // search by tuition center name
      case 5:
        cout << "Search by Tuition Center Name" << endl;
        cout << "_____________________________" << endl;
        searchTuitionName(tutors, tutorSize);
        break;

      default:
        break;
    };

    cout << endl;
  } while (select != 10);

  return 0;
};
