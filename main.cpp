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

  for (int i = 0; i < *tutorSize; i++) {
    if (insert) {
      // before insertion
      // compare the strings
      int comp = compareInsensitive(tutors[i].name, newTutor.name);
      switch (comp) {
        // if existing name is before new tutor
        case -1:
          newTutors[i] = tutors[i];
          break;

        // if existing name is equal new tutor
        case 0:
          newTutors[i] = tutors[i];
          newTutors[i+1] = newTutor;
          insert = false;
          break;

        // if existing name is after new tutor
        case 1:
          newTutors[i] = newTutor;
          newTutors[i+1] = tutors[i];
          insert = false;
          break;
      };
    } else {
      // after insertion
      newTutors[i+1] = tutors[i];
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
  int tutorID;
  Tutor found;

  cout << "Tutor ID: ";
  cin >> tutorID;

  for (int i = 0; i < tutorSize; i++) {
    if (tutors[i].tutorID == tutorID) {
      found = tutors[i];
      break;
    };
  };

  if (found.name != "") {
    displayRecord(found);
  } else {
    cout << "No result found" << endl;
  }
};

void searchRating(Tutor *tutors, int rating, int tutorSize, Tutor *searchedTutors);
void searchTuitionName(Tutor *tutors, string tuitionCenterName, int tutorSize, Tutor *searchedTutors);

void sortTutorID(Tutor *tutors, int tutorSize, Tutor *sortedTutors);
void sortPayRate(Tutor *tutors, int tutorSize, Tutor *sortedTutors);
void sortRating(Tutor *tutors, int tutorSize, Tutor *sortedTutors);

void modifyTutor(Tutor *&tutors, int tutorSize);
void deleteTutor(Tutor *&tutors, int *tutorSize);


int main() {
  // initialise
  int select;
  int tutorSize = 2;
  Tutor *tutors;
  tutors = new Tutor[10];

  // dummy data
  // lower limit for time is 1/1/1970, https://docs.microsoft.com/en-us/cpp/atl-mfc-shared/reference/ctime-class
  tutors[0] = Tutor(4, "John", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Sini", "S0001", "Science", 4);
  tutors[1] = Tutor(3, "Susan", 2, 3, 2000, 0, 0, 0, 50, "0123456789", "Somewhere", "C0001", "Taman Sini", "S0001", "Science", 4);
  
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

      default:
        break;
    };

    cout << endl;
  } while (select != 10);

  return 0;
};
