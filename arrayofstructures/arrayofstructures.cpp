#include <iostream>
#include <string>
#include <time.h>
#include "../datec.h"
#include "../stringc.h"
using namespace std;

struct Tutor {
  private:
  int tutorID;
  string name;
  time_t dateJoined;
  time_t dateTerminated;
  double hourlyPayRate;
  string phone;
  string address;
  string tuitionCentreCode;
  string tuitionCentreName;
  string subjectCode;
  string subjectName;
  int rating;

  public:
  // constructor
  Tutor() {
    this->tutorID = -1;
    this->name = "";
    this->dateJoined = -1;
    this->dateTerminated = -1;
    this->hourlyPayRate = -1.0;
    this->phone = "";
    this->address = "";
    this->tuitionCentreCode = "";
    this->tuitionCentreName = "";
    this->subjectCode = "";
    this->subjectName = "";
    this->rating = -1;
  };
  Tutor(int tutorID, string name, time_t dateJoined, time_t dateTerminated, double hourlyPayRate, string phone, string address, string tuitionCentreCode, string tuitionCentreName, string subjectCode, string subjectName, int rating) {
    this->tutorID = tutorID;
    this->name = name;
    this->dateJoined = dateJoined;
    this->dateTerminated = dateTerminated;
    this->hourlyPayRate = hourlyPayRate;
    this->phone = phone;
    this->address = address;
    this->tuitionCentreCode = tuitionCentreCode;
    this->tuitionCentreName = tuitionCentreName;
    this->subjectCode = subjectCode;
    this->subjectName = subjectName;
    this->rating = rating;
  };
  Tutor(int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, string tuitionCentreCode, string tuitionCentreName, string subjectCode, string subjectName, int rating) {
    this->tutorID = tutorID;
    this->name = name;
    this->dateJoined = intToTime(dayJoined, monthJoined, yearJoined);
    this->dateTerminated = intToTime(dayTerminated, monthTerminated, yearTerminated);
    this->hourlyPayRate = hourlyPayRate;
    this->phone = phone;
    this->address = address;
    this->tuitionCentreCode = tuitionCentreCode;
    this->tuitionCentreName = tuitionCentreName;
    this->subjectCode = subjectCode;
    this->subjectName = subjectName;
    this->rating = rating;
  };

  // getters and setters
  int getTutorID() {
    return tutorID;
  };
  string getName() {
    return name;
  };
  time_t getDateJoined() {
    return dateJoined;
  };
  time_t getDateTerminated() {
    return dateTerminated;
  };
  void setDateTerminated(time_t dateTerminated) {
    this->dateTerminated = dateTerminated;
  };
  double getHourlyPayRate() {
    return hourlyPayRate;
  };
  string getPhone() {
    return phone;
  };
  void setPhone(string phone) {
    this->phone = phone;
  };
  string getAddress() {
    return address;
  };
  void setAddress(string address) {
    this->address = address;
  };
  string getTuitionCentreCode() {
    return tuitionCentreCode;
  };
  string getTuitionCentreName() {
    return tuitionCentreName;
  };
  string getSubjectCode() {
    return subjectCode;
  };
  string getSubjectName() {
    return subjectName;
  };
  int getRating() {
    return rating;
  };
};

// function headers
void generateTutors(Tutor *&tutors, int *lastID, int *size);
void addTutor(Tutor *&tutors, int *lastID, int *size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating);
void modifyTutor(Tutor *&tutors, int size, int tutorID);
void terminateTutor(Tutor *&tutors, int size, int tutorID);
void deleteTutor(Tutor *&tutors, int *size, int tutorID);

void displayRecord(Tutor tutor);
void displayRecordsList(Tutor *tutors, int size, int index);
void displayRecordsDetailed(Tutor *tutors, int size);

void sortTutorID(Tutor *tutors, int size, int lastID);
void sortRating(Tutor *tutors, int size);
void sortPayRate(Tutor *tutors, int size);

void searchTutorID(Tutor *tutors, int size, int tutorID);
void searchRating(Tutor *tutors, int size, int rating);
void searchTuitionName(Tutor *tutors, int size, string tcName);

// binary search
int binarySearchName(Tutor *tutors, int size, string name);
bool binarySearchNames(string *names, int size, string tcName);
void binarySearchTCName(Tutor *tutors, int size, string tcName, int *start, int *end);

// dual pivot quicksort
void swap(Tutor *t1, Tutor *t2);

void dualPivotQuicksortName(Tutor *tutors, int low, int up);
void partitionName(Tutor *tutors, int low, int up, int *lp, int *rp);

void dualPivotQuicksortRating(Tutor *tutors, int low, int up);
void partitionRating(Tutor *tutors, int low, int up, int *lp, int *rp);

void dualPivotQuicksortPayRate(Tutor *tutors, int low, int up);
void partitionPayRate(Tutor *tutors, int low, int up, int *lp, int *rp);

void dualPivotQuicksortTCName(Tutor *tutors, int low, int up);
void partitionTCName(Tutor *tutors, int low, int up, int *lp, int *rp);


int main() {
  // initialise
  int size = 0, lastID = 0;
  Tutor *tutors = NULL;
  int input = 0, subinput = 0;
  char cinput = ' ';

  // generate hardcoded data
  generateTutors(tutors, &lastID, &size);

  // set cout to always display two decimals for doubles
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  // menu
  do {
    cout << "---------------------------------------------------" << endl;
    cout << "Tutor Management System (Array of Structures 1.0.1)" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "(1) Add Tutor" << endl;
    cout << "(2) Modify Tutor" << endl;
    cout << "(3) Terminate Tutor" << endl;
    cout << "(4) Delete Tutor" << endl;
    cout << "(5) Display Records" << endl;
    cout << "(6) Sort and Display Records" << endl;
    cout << "(7) Search Tutors" << endl;
    cout << "(8) Exit" << endl;

    // get user input
    do {
      cout << "Select function (1-8): ";
      cin >> input;
      // ignore enter key
      if (cin.peek() != '\n')
        cin >> input;
      // clear error state
      if (!cin)
        cin.clear();
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (input < 1 || input > 8);
    cout << endl;

    // determine outcome
    switch (input) {
      // add tutor
      case 1:
        {
          cout << "Add Tutor" << endl;
          cout << "---------------" << endl;

          // initialise
          string name = "", phone = "", address = "", tcCode = "", tcName = "", subCode = "", subName = "";
          int day = 0, month = 0, year = 0, rating = 0;
          double hourlyPayRate = 0.0;
          char sp = ' ';

          // get tutor details
          // name
          do {
            cout << "Name               : ";
            getline(cin, name);
            trim(name);
          } while (name == "");

          // date joined
          do {
            cout << "Date Joined (d/m/y): ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> day >> sp >> month >> sp >> year;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (!validateDate(day, month, year) || difftime(intToTime(day, month, year), time(0)) > 0);

          // hourly pay rate
          do {
            cout << "Hourly Pay (40-80) : ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> hourlyPayRate;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (hourlyPayRate < 40 || hourlyPayRate > 80);

          // phone
          do {
            cout << "Phone              : ";
            getline(cin, phone);
            trim(phone);
          } while (phone == "");

          // address
          do {
            cout << "Address            : ";
            getline(cin, address);
            trim(address);
          } while (address == "");

          // tuition centre code
          do {
            cout << "Tuition Centre Code: ";
            getline(cin, tcCode);
            trim(tcCode);
          } while (tcCode == "");

          // tuition centre name
          do {
            cout << "Tuition Centre Name: ";
            getline(cin, tcName);
            trim(tcName);
          } while (tcName == "");

          // subject code
          do {
            cout << "Subject Code       : ";
            getline(cin, subCode);
            trim(subCode);
          } while (subCode == "");

          // subject name
          do {
            cout << "Subject Name       : ";
            getline(cin, subName);
            trim(subName);
          } while (subName == "");

          // rating
          do {
            cout << "Rating (1-5)       : ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> rating;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (rating < 1 || rating > 5);
          addTutor(tutors, &lastID, &size, name, day, month, year, hourlyPayRate, phone, address, tcCode, tcName, subCode, subName, rating);
          break;
        };

        // modify tutor
      case 2:
        {
          // initialise
          int tutorID = 0;
          // get user input
          do {
            cout << "Modify Tutor (ID): ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> tutorID;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (tutorID < 0);
          cout << "---------------" << endl;
          modifyTutor(tutors, size, tutorID);
          break;
        };

        // terminate tutor
      case 3:
        {
          // initialise
          int tutorID = 0;
          // get user input
          do {
            cout << "Terminate Tutor (ID): ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> tutorID;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (tutorID < 0);
          cout << "---------------" << endl;
          terminateTutor(tutors, size, tutorID);
          break;
        };

        // delete tutor
      case 4:
        {
          // initialise
          int tutorID = 0;
          // get user input
          do {
            cout << "Delete Tutor (ID): ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> tutorID;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (tutorID < 0);
          cout << "---------------" << endl;
          deleteTutor(tutors, &size, tutorID);
          break;
        };

        // display records
      case 5:
        cout << "Display Records (Name (Asc))" << endl;
        cout << "---------------------------------------" << endl;
        displayRecordsList(tutors, size, 0);
        break;

        // sort and display records
      case 6:
        cout << "(1) Tutor ID (Ascending)" << endl;
        cout << "(2) Rating (Ascending)" << endl;
        cout << "(3) Hourly Pay Rate (Ascending)" << endl;
        // get user input
        do {
          cout << "Sort by (1-3): ";
          // ignore enter key
          if (cin.peek() != '\n')
            cin >> subinput;
          // clear error state
          if (!cin)
            cin.clear();
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (subinput < 1 || subinput > 3);
        cout << endl;

        // determine outcome
        switch (subinput) {
          // sort by tutor id
          case 1:
            cout << "Display Records (Tutor ID (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortTutorID(tutors, size, lastID);
            break;

            // sort by rating
          case 2:
            cout << "Display Records (Rating (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortRating(tutors, size);
            break;

            // sort by hourly pay rate
          default:
            cout << "Display Records (Hourly Pay Rate (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortPayRate(tutors, size);
            break;
        };
        break;

        // search tutors
      case 7:
        cout << "(1) Tutor ID" << endl;
        cout << "(2) Rating" << endl;
        cout << "(3) Tuition Centre Name" << endl;
        // get user input
        do {
          cout << "Search by (1-3): ";
          if (cin.peek() != '\n')
            cin >> subinput;
          if (!cin)
            // clear error state
            cin.clear();
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (subinput < 1 || subinput > 3);
        cout << endl;

        // determine outcome
        switch (subinput) {
          // search by tutor id
          case 1:
            {
              // initialise
              int tutorID = 0;
              // get user input
              do {
                cout << "Tutor ID: ";
                // ignore enter key
                if (cin.peek() != '\n')
                  cin >> tutorID;
                // clear error state
                if (!cin)
                  cin.clear();
                // clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              } while (tutorID < 0);
              cout << "-------------------------------------" << endl;
              searchTutorID(tutors, size, tutorID);
              break;
            };

            // search by rating
          case 2:
            {
              // initialise
              int rating = 0;
              // get user input
              do {
                cout << "Rating (1-5): ";
                // ignore enter key
                if (cin.peek() != '\n')
                  cin >> rating;
                // clear error state
                if (!cin)
                  cin.clear();
                // clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              } while (rating < 1 || rating > 5);
              cout << "-------------------------------------" << endl;
              searchRating(tutors, size, rating);
              break;
            };

            // search by tuition centre name
          default:
            {
              // initialise
              string tcName;
              // get user input
              do {
                cout << "Tuition Centre Name: ";
                getline(cin, tcName);
                trim(tcName);
              } while (tcName == "");
              cout << "-------------------------------------" << endl;
              searchTuitionName(tutors, size, tcName);
              break;
            };
        };
        break;

        // exit program
      case 8:
        // ask for confirmation
        do {
          cout << "Exit program? (Y/N): ";
          cin >> cinput;
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');

        // determine outcome
        switch (cinput) {
          // exit program
          case 'y':
          case 'Y':
            // display success message
            cout << "Exited Successfully";
            break;

            // return to menu
          default:
            // display cancelled message
            cout << "Cancelled" << endl << endl;
            input = 0;
            break;
        };
        break;
    };
  } while (input != 8);
  return 0;
};


void generateTutors(Tutor *&tutors, int *lastID, int *size) {
  *size = 10;
  tutors = new Tutor[*size];
  *lastID = 10;

  tutors[0] = Tutor(2, "Aaron", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  tutors[1] = Tutor(1, "Bill", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  tutors[2] = Tutor(4, "Charlie", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  tutors[3] = Tutor(3, "Edwin", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);
  tutors[4] = Tutor(8, "George", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  tutors[5] = Tutor(10, "Jamal", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  tutors[6] = Tutor(5, "Kenny", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  tutors[7] = Tutor(9, "Maria", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  tutors[8] = Tutor(7, "Patricia", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  tutors[9] = Tutor(6, "Shelby", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
};
void addTutor(Tutor *&tutors, int *lastID, int *size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating) {
  // initialise
  int tutorID = *lastID + 1;

  Tutor newTutor(tutorID, name, day, month, year, 0, 0, 0, hourlyPayRate, phone, address, tcCode, tcName, subCode, subName, rating);

  // binary insertion sort
  if (*size > 0) {
    // binary search
    int index = binarySearchName(tutors, *size, name);

    // allocate memory
    Tutor *tempTutors = new Tutor[*size + 1];

    // copy elements into temporary tutor array
    for (int i = 0; i < index; i++)
      tempTutors[i] = tutors[i];
    tempTutors[index] = newTutor;
    for (int i = index + 1; i < *size + 1; i++)
      tempTutors[i] = tutors[i - 1];

    // reallocate memory
    tutors = new Tutor[*size + 1];

    // copy all elements into tutor array
    for (int i = 0; i < *size + 1; i++)
      tutors[i] = tempTutors[i];

    // deallocate memory
    delete[] tempTutors;
  } else {
    // insert new tutor as there are no existing tutors
    // reallocate memory
    tutors = new Tutor[1];
    tutors[0] = newTutor;
  };
  // display success message
  cout << "Added Successfully" << endl << endl;
  // increase tutor size
  *size += 1;
  // increase last id
  *lastID += 1;
};
void modifyTutor(Tutor *&tutors, int size, int tutorID) {
  // initialise
  int input = 0;
  string phone = "", address = "";
  bool found = false;

  // linear search through the array
  for (int i = 0; i < size; i++) {
    // find tutor with searched id
    if (tutors[i].getTutorID() == tutorID) {
      // display record
      displayRecord(tutors[i]);

      // get user input
      cout << "Modify:" << endl;
      cout << "(1) Phone" << endl;
      cout << "(2) Address" << endl;
      cout << "(3) Both" << endl;
      do {
        cout << "Sort by (1-3): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        // clear error state
        if (!cin)
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > 3);

      // modify phone
      if (input == 1 || input == 3) {
        do {
          cout << "New Phone: ";
          getline(cin, phone);
          trim(phone);
        } while (phone == "");
        tutors[i].setPhone(phone);
      };

      // modify address
      if (input == 2 || input == 3) {
        do {
          cout << "New Address: ";
          getline(cin, address);
          trim(address);
        } while (address == "");
        tutors[i].setAddress(address);
      };

      // display success message
      if (input >= 1)
        cout << "Modified Successfully" << endl << endl;

      // set as found
      found = true;
      // stop iteration
      break;
    };
  };
  // if no results
  if (!found)
    cout << "No results found" << endl << endl;
};
void terminateTutor(Tutor *&tutors, int size, int tutorID) {
  // initialise
  int day = 0, month = 0, year = 0;
  time_t dateTerminated = time(0);
  char sp = ' ', cinput = ' ';
  bool found = false;

  // linear search through the array
  for (int i = 0; i < size; i++) {
    // find tutor with searched id
    if (tutors[i].getTutorID() == tutorID) {
      // display record
      displayRecord(tutors[i]);

      // set as found
      found = true;

      // check if tutor is terminated
      if (tutors[i].getDateTerminated() != -1) {
        do {
          cout << "Tutor is already terminated. Modify termination date? (Y/N): ";
          cin >> cinput;
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');

        // cancel termination
        if (cinput == 'n' || cinput == 'N') {
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
        };
      };

      // get user input
      do {
        cout << "Date Terminated (d/m/y): ";
        // ignore enter key
        if (cin.peek() != '\n') {
          cin >> day >> sp >> month >> sp >> year;
          // convert to time
          dateTerminated = intToTime(day, month, year);
        };
        // clear error state
        if (!cin)
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (!validateDate(day, month, year) || difftime(dateTerminated, tutors[i].getDateJoined()) <= 0);

      // ask for confirmation
      do {
        if (tutors[i].getDateTerminated() == -1)
          cout << "Terminate user? (Y/N): ";
        else
          cout << "Modify terminated date? (Y/N): ";
        cin >> cinput;
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');

      // determine outcome
      switch (cinput) {
        // terminate tutor
        case 'y':
        case 'Y':
          tutors[i].setDateTerminated(dateTerminated);
          // display success message
          cout << "Terminated Successfully" << endl << endl;
          break;

          // cancel termination
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };

      // stop iteration
      break;
    };
  };
  // if no results
  if (!found)
    cout << "No results found" << endl << endl;
};
void deleteTutor(Tutor *&tutors, int *size, int tutorID) {
  // initialise
  char cinput = ' ';
  bool found = false;

  // linear search through the array
  for (int i = 0; i < *size; i++) {
    // find tutor with searched id
    if (tutors[i].getTutorID() == tutorID) {
      // display record
      displayRecord(tutors[i]);

      // set as found
      found = true;

      // check if tutor is terminated
      if (tutors[i].getDateTerminated() == -1) {
        // display not terminated message
        cout << "Tutor has not been terminated" << endl << endl;
        // stop iteration
        break;
      };

      // check if terminated date has reached at least 6 months
      tm tmTerminated;
      time_t dateTerminated = tutors[i].getDateTerminated();
      localtime_s(&tmTerminated, &dateTerminated);

      if (tmTerminated.tm_mon > 6) {
        tmTerminated.tm_mon -= 6;
        tmTerminated.tm_year += 1;
      } else {
        tmTerminated.tm_mon += 6;
      };

      if (difftime(mktime(&tmTerminated), time(0)) > 0) {
        // display not passed 6 months message
        cout << "Tutor has not been terminated at least 6 months ago" << endl << endl;
        // stop iteration
        break;
      };

      // ask for confirmation
      do {
        cout << "Permanently delete tutor? (Y/N): ";
        cin >> cinput;
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');

      // determine outcome
      switch (cinput) {
        // delete tutor
        case 'y':
        case 'Y':
          {
            // initialise
            bool deleted = false;

            // allocate memory
            Tutor *tempTutors = new Tutor[*size + 1];

            // copy to temporary tutor array
            for (int x = 0; x < *size - 1; x++) {
              if (!deleted && x != i) {
                tempTutors[x] = tutors[x];
              } else if (deleted) {
                tempTutors[x] = tutors[x + 1];
              } else if (x == i && x != *size - 1) {
                tempTutors[x] = tutors[x + 1];
                deleted = true;
              };
            };

            // reallocate memory
            tutors = new Tutor[*size - 1];

            // copy all elements into tutor array
            for (int x = 0; x < *size - 1; x++) {
              tutors[x] = tempTutors[x];
            };

            // deallocate memory
            delete[] tempTutors;

            // display success message
            cout << "Deleted Successfully" << endl << endl;
            // decrease tutor size
            *size -= 1;
            break;
          };

          // cancel delete
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };
    };
  };
  // if no results
  if (!found)
    cout << "No results found" << endl << endl;
};

void displayRecord(Tutor tutor) {
  cout << "ID                 : " << tutor.getTutorID() << endl;
  cout << "Name               : " << tutor.getName() << endl;
  tm tmJoined;
  time_t dateJoined = tutor.getDateJoined();
  localtime_s(&tmJoined, &dateJoined);
  cout << "Date Joined        : " << tmJoined.tm_mday << "/" << tmJoined.tm_mon + 1 << "/" << tmJoined.tm_year + 1900 << endl;
  cout << "Date Terminated    : ";
  if (tutor.getDateTerminated() != -1) {
    // display date as it is set
    tm tmTerminated;
    time_t dateTerminated = tutor.getDateTerminated();
    localtime_s(&tmTerminated, &dateTerminated);
    cout << tmTerminated.tm_mday << "/" << tmTerminated.tm_mon + 1 << "/" << tmTerminated.tm_year + 1900 << endl;
  } else {
    // hide date as it is not set
    cout << "-" << endl;
  };
  cout << "Hourly Pay Rate    : " << tutor.getHourlyPayRate() << endl;
  cout << "Phone              : " << tutor.getPhone() << endl;
  cout << "Address            : " << tutor.getAddress() << endl;
  cout << "Tuition Centre Code: " << tutor.getTuitionCentreCode() << endl;
  cout << "Tuition Centre Name: " << tutor.getTuitionCentreName() << endl;
  cout << "Subject Code       : " << tutor.getSubjectCode() << endl;
  cout << "Subject Name       : " << tutor.getSubjectName() << endl;
  cout << "Rating             : " << tutor.getRating() << endl << endl;
};
void displayRecordsList(Tutor *tutors, int size, int index) {
  // initialise
  int page = 1, input = 0;

  for (; index >= 10; index -= 10)
    page++;

  // calculate total page numbers
  int total = size / 10;
  if (size % 10 > 0)
    total++;

  // display page
  do {
    if (input != 1) {
      cout << "ID    Name             Pay    Tuition Centre       Rating" << endl;
      cout << "---------------------------------------------------------" << endl;
      for (int i = (page - 1) * 10; i < page * 10; i++) {
        // print list of tutors
        cout.width(4);
        cout << right << tutors[i].getTutorID() << "  ";
        cout.width(15);
        cout << left << tutors[i].getName() << "  ";
        cout.width(5);
        cout << tutors[i].getHourlyPayRate() << "  ";
        cout.width(19);
        cout << tutors[i].getTuitionCentreName() << "  ";
        cout << tutors[i].getRating() << endl;
        // break when last element
        if (i == size - 1)
          break;
      };
      // display page number
      cout << endl << "Page " << page << endl << endl;
    };

    cout << "(1) Detailed view" << endl;
    cout << "(2) Jump to page";
    if (total == 1)
      cout << " (disabled)";
    cout << endl << "(3) Next page";
    if (page >= total)
      cout << " (disabled)";
    cout << endl << "(4) Previous page";
    if (page <= 1)
      cout << " (disabled)";
    cout << endl << "(5) Exit" << endl;
    // get user input
    do {
      cout << "Please select (1-5): ";
      // ignore enter key
      if (cin.peek() != '\n')
        cin >> input;
      // clear error state
      if (!cin)
        cin.clear();
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (input < 1 || input > 5 || (total == 1 && input == 2) || (page >= total && input == 3) || (page <= 1 && input == 4));

    // determine outcome
    switch (input) {
        // jump to page
      case 2:
        if (total > 1) {
          do {
            cout << "Page (1-" << total << "): ";
            // ignore enter key
            if (cin.peek() != '\n')
              cin >> page;
            // clear error state
            if (!cin)
              cin.clear();
            // clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } while (page < 1 || page > total);
        };
        cout << endl;
        break;

        // next page
      case 3:
        if (page < total)
          page++;
        cout << endl;
        break;

        // previous page
      case 4:
        if (page > 1)
          page--;
        cout << endl;
        break;

      default:
        cout << endl;
        break;
    };
  } while (input > 1 && input < 5);
  
  // detailed view
  if (input == 1)
    displayRecordsDetailed(tutors, size);
};
void displayRecordsDetailed(Tutor *tutors, int size) {
  // initialise
  int input = 2, tutorID = 0, index = 0;
  bool found = false;

  do {
    if (input == 2) {
      found = false;
      // get user input
      do {
        do {
          cout << "Tutor ID: ";
          // ignore enter key
          if (cin.peek() != '\n')
            cin >> tutorID;
          // clear error state
          if (!cin)
            cin.clear();
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (tutorID < 0);

        // linear search through the array
        for (index = 0; index < size; index++)
          // find tutor with searched id
          if (tutors[index].getTutorID() == tutorID) {
            // set as found
            found = true;
            // stop iteration
            break;
          };
      } while (!found);
    };

    // display result
    cout << "-------------------------------------" << endl;
    displayRecord(tutors[index]);

    cout << "(1) List view" << endl;
    cout << "(2) Jump to record";
    if (size == 1)
      cout << " (disabled)";
    cout << endl << "(3) Next record";
    if (index >= size - 1)
      cout << " (disabled)";
    cout << endl << "(4) Previous record";
    if (index <= 0)
      cout << " (disabled)";
    cout << endl << "(5) Exit" << endl;
    // get user input
    do {
      cout << "Please select (1-5): ";
      // ignore enter key
      if (cin.peek() != '\n')
        cin >> input;
      // clear error state
      if (!cin)
        cin.clear();
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (input < 1 || input > 5 || (size == 1 && input == 2) || (index >= size - 1 && input == 3) || (index <= 0 && input == 4));

    // determine outcome
    switch (input) {
        // next record
      case 3:
        if (index < size - 1)
          index++;
        cout << endl;
        break;

        // previous record
      case 4:
        if (index > 0)
          index--;
        cout << endl;
        break;

      default:
        cout << endl;
        break;
    }
  } while (input > 1 && input < 5);

  // list view
  if (input == 1)
    displayRecordsList(tutors, size, index);
};

void sortTutorID(Tutor *tutors, int size, int lastID) {
  // initialise
  Tutor *tempTutors = new Tutor[size];
  int *count = new int[lastID]{0};

  // counting sort
  // count of each rating
  for (int i = 0; i < size; i++)
    count[tutors[i].getTutorID() - 1]++;

  // calculate cumulative sum
  for (int i = 1; i < lastID; i++)
    count[i] += count[i - 1];

  // arrange elements into the correct positions
  for (int i = size - 1; i >= 0; i--) {
    tempTutors[count[tutors[i].getTutorID() - 1] - 1] = tutors[i];
    count[tutors[i].getTutorID() - 1]--;
  };

  // deallocate memory
  delete[] count;

  // display sorted array
  displayRecordsList(tempTutors, size, 0);

  // deallocate memory
  delete[] tempTutors;
};
void sortRating(Tutor *tutors, int size) {
  // allocate memory
  Tutor *tempTutors = new Tutor[size];

  // copy all elements into temporary tutor array
  for (int i = 0; i < size; i++)
    tempTutors[i] = tutors[i];

  // sort the temporary tutor array by rating
  dualPivotQuicksortRating(tempTutors, 0, size - 1);

  // sort the temporary tutor array by name
  for (int i = 0; i < size - 1; i++) {
    if (i + 1 <= size && tempTutors[i].getRating() == tempTutors[i + 1].getRating()) {
      int low = i, up = i + 1;
      while (i + 2 <= size && tempTutors[i + 1].getRating() == tempTutors[i + 2].getRating()) {
        up++;
        i++;
      };
      dualPivotQuicksortName(tempTutors, low, up);
    };
  };

  // display sorted array
  displayRecordsList(tempTutors, size, 0);

  // deallocate memory
  delete[] tempTutors;
};
void sortPayRate(Tutor *tutors, int size) {
  // allocate memory
  Tutor *tempTutors = new Tutor[size];

  // copy all elements into temporary tutor array
  for (int i = 0; i < size; i++)
    tempTutors[i] = tutors[i];

  // sort the temporary tutor array by hourly pay rate
  dualPivotQuicksortPayRate(tempTutors, 0, size - 1);

  // sort the temporary tutor array by name
  for (int i = 0; i < size - 1; i++) {
    if (i + 1 <= size && tempTutors[i].getHourlyPayRate() == tempTutors[i + 1].getHourlyPayRate()) {
      int low = i, up = i + 1;
      while (i + 2 <= size && tempTutors[i + 1].getHourlyPayRate() == tempTutors[i + 2].getHourlyPayRate()) {
        up++;
        i++;
      };
      dualPivotQuicksortName(tempTutors, low, up);
    };
  };

  // display sorted array
  displayRecordsList(tempTutors, size, 0);

  // deallocate memory
  delete[] tempTutors;
};

void searchTutorID(Tutor *tutors, int size, int tutorID) {
  // initialise
  bool found = false;

  // linear search through the array
  for (int i = 0; i < size; i++)
    // find tutor with searched id
    if (tutors[i].getTutorID() == tutorID) {
      // display result
      displayRecord(tutors[i]);
      // set as found
      found = true;
      // stop iteration
      break;
    };

  // if no results
  if (!found)
    cout << "No results found" << endl << endl;
};
void searchRating(Tutor *tutors, int size, int rating) {
  // initialise
  int tutorSize = 0;
  Tutor *tempTutors1 = NULL, *tempTutors2 = NULL;
  bool tutor1 = true, found = false;

  // linear search through the array
  for (int i = 0; i < size; i++) {
    // find tutors with searched rating
    if (tutors[i].getRating() == rating) {
      if (tutorSize > 0) {
        if (tutor1) {
          // allocate memory
          tempTutors2 = new Tutor[tutorSize + 1];
          // copy all elements into temporary tutor array 2
          for (int x = 0; x < tutorSize; x++)
            tempTutors2[x] = tempTutors1[x];
          tempTutors2[tutorSize] = tutors[i];
          // deallocate memory
          delete[] tempTutors1;
          // set tutor 1 as inactive
          tutor1 = false;
        } else {
          // allocate memory
          tempTutors1 = new Tutor[tutorSize + 1];
          // copy all elements into temporary tutor array 1
          for (int x = 0; x < tutorSize; x++)
            tempTutors1[x] = tempTutors2[x];
          tempTutors1[tutorSize] = tutors[i];
          // deallocate memory
          delete[] tempTutors2;
          // set tutor 1 as active
          tutor1 = true;
        };
        // increase temporary tutor array size
        tutorSize++;
      } else {
        // allocate memory
        tempTutors1 = new Tutor[1];
        tempTutors1[0] = tutors[i];
        // set tutor 1 as active
        tutor1 = true;
        // increase temporary tutor size
        tutorSize++;
      };
    };
  };

  if (tutorSize > 0) {
    // display all records
    if (tutor1) {
      displayRecordsList(tempTutors1, tutorSize, 0);
      // deallocate memory
      delete[] tempTutors1;
    } else {
      displayRecordsList(tempTutors2, tutorSize, 0);
      // deallocate memory
      delete[] tempTutors2;
    };
  } else {
    // if no results
    cout << "No results found" << endl;
  };
};
void searchTuitionName(Tutor *tutors, int size, string tcName) {
  // initialise
  Tutor *sortTutors = new Tutor[size], *tempTutors = NULL;
  string *tempNames1 = NULL, *tempNames2 = NULL, sinput = "";
  int nameSize = 0, tutorSize = 0, input = 0, startIndex = 0, endIndex = 0;
  bool name1 = false;
  
  // copy all elements into temporary tutor array
  for (int i = 0; i < size; i++)
    sortTutors[i] = tutors[i];

  // sort the temporary tutor array by tuition name
  dualPivotQuicksortTCName(sortTutors, 0, size - 1);

  // linear search through the array
  for (int i = 0; i < size; i++) {
    // find tutors with searched tuition name
    if (findInsensitive(sortTutors[i].getTuitionCentreName(), tcName) != string::npos) {
      if (nameSize > 0) {
        if (name1) {
          // binary search through the array
          if (!binarySearchNames(tempNames1, nameSize, sortTutors[i].getTuitionCentreName())) {
            // allocate memory
            tempNames2 = new string[nameSize + 1];
            // copy all elements into temporary name array
            for (int x = 0; x < nameSize; x++)
              tempNames2[x] = tempNames1[x];
            // copy new tuition name into temporary name array
            tempNames2[nameSize] = sortTutors[i].getTuitionCentreName();
            // deallocate memory
            delete[] tempNames1;
            // increase name size
            nameSize++;
            // set name 1 as inactive
            name1 = false;
          };
        } else {
          // binary search through the array
          if (!binarySearchNames(tempNames2, nameSize, sortTutors[i].getTuitionCentreName())) {
            // allocate memory
            tempNames1 = new string[nameSize + 1];
            // copy all elements into temporary name array
            for (int x = 0; x < nameSize; x++)
              tempNames1[x] = tempNames2[x];
            // copy new tuition name into temporary name array
            tempNames1[nameSize] = sortTutors[i].getTuitionCentreName();
            // deallocate memory
            delete[] tempNames2;
            // increase name size
            nameSize++;
            // set name 1 as active
            name1 = true;
          };
        };
      } else {
        // insert new tuition name as there are no existing tuition names
        // allocate memory
        tempNames1 = new string[1];
        tempNames1[0] = sortTutors[i].getTuitionCentreName();
        // increase name size
        nameSize = 1;
        // set name 1 as active
        name1 = true;
      };
    };
  };

  // get user input
  if (nameSize > 0) {
    if (nameSize > 1) {
      for (int i = 0; i < nameSize; i++) {
        cout << "(" << i + 1 << ") ";
        if (name1)
          cout << tempNames1[i];
        else
          cout << tempNames2[i];
        cout << endl;
      };
      do {
        cout << "Please input (1-" << nameSize << "): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        if (!cin)
          // clear error state
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > nameSize);
    } else {
      input = 1;
    };

    // get tuition name
    if (name1)
      sinput = tempNames1[input - 1];
    else
      sinput = tempNames2[input - 1];

    // binary search through a portion of the temporary tutor array
    binarySearchTCName(sortTutors, size, sinput, &startIndex, &endIndex);

    // allocate memory
    tutorSize = endIndex - startIndex + 1;
    tempTutors = new Tutor[tutorSize];

    // copy elements into temporary tutor array
    for (int i = 0, x = startIndex; x < endIndex + 1; i++, x++)
      tempTutors[i] = sortTutors[x];

    // deallocate memory
    delete[] sortTutors;

    // sort temporary tutor array by name
    for (int i = 0; i < tutorSize - 1; i++) {
      if (i + 1 < tutorSize && compareInsensitive(tempTutors[i].getTuitionCentreName(), tempTutors[i + 1].getTuitionCentreName()) == 0) {
        int low = i, up = i + 1;
        while (i + 2 < tutorSize && compareInsensitive(tempTutors[i + 1].getTuitionCentreName(), tempTutors[i + 2].getTuitionCentreName()) == 0) {
          up++;
          i++;
        };
        dualPivotQuicksortName(tempTutors, low, up);
      };
    };

    // display sorted array
    displayRecordsList(tempTutors, tutorSize, 0);

    // deallocate memory
    delete[] tempTutors;
  } else {
    // deallocate memory
    delete[] sortTutors;
    // if no results
    cout << "No results found" << endl << endl;
  };
};

// binary search
int binarySearchName(Tutor *tutors, int size, string name) {
  // initialise
  int low = 0, mid = 0, up = size - 1;
  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare strings
    int comp = compareInsensitive(tutors[mid].getName(), name);
    if (comp == 0) {
      // if exising name is same as new name
      while (mid + 1 <= up && compareInsensitive(tutors[mid + 1].getName(), name))
        mid++;
      return mid + 1;
    } else if (comp < 0) {
      // if existing name is before new name
      low = mid + 1;
    } else {
      // if existing name is after new name
      up = mid - 1;
    };
  };

  // compare strings
  int comp = compareInsensitive(tutors[mid].getName(), name);
  if (comp > 0) {
    // if existing name is after new name
    return mid;
  } else {
    // if existing name is before new name
    return mid + 1;
  };
};
bool binarySearchNames(string *names, int size, string tcName) {
  // initialise
  int low = 0, mid = 0, up = size - 1;
  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare strings
    int comp = compareInsensitive(names[mid], tcName);
    if (comp == 0) {
      // if exising name is same as new name
      return true;
    } else if (comp < 0) {
      // if existing name is before new name
      low = mid + 1;
    } else {
      // if existing name is after new name
      up = mid - 1;
    };
  };
  // new name does not exist
  return false;
};
void binarySearchTCName(Tutor *tutors, int size, string tcName, int *start, int *end) {
  // initialise
  int low = 0, mid = 0, up = size - 1;
  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare strings
    int comp = compareInsensitive(tutors[mid].getTuitionCentreName(), tcName);
    if (comp == 0) {
      // if exising name is same as new name
      *start = mid;
      *end = mid;
      while (*start - 1 >= low && compareInsensitive(tutors[*start - 1].getTuitionCentreName(), tcName) == 0)
        *start -= 1;

      while (*end + 1 <= up && compareInsensitive(tutors[*end + 1].getTuitionCentreName(), tcName) == 0)
        *end += 1;

      // stop iteration
      break;
    } else if (comp < 0) {
      // if existing name is before new name
      low = mid + 1;
    } else {
      // if existing name is after new name
      up = mid - 1;
    };
  };
}


// dual pivot quicksort
void swap(Tutor *t1, Tutor *t2) {
  // swap the elements' position
  Tutor temp = *t1;
  *t1 = *t2;
  *t2 = temp;
};

void dualPivotQuicksortName(Tutor *tutors, int low, int up) {
  if (low < up) {
    int lPivot, rPivot;
    partitionName(tutors, low, up, &lPivot, &rPivot);
    // sort left subarray
    dualPivotQuicksortName(tutors, low, lPivot - 1);
    // sort mid subarray
    dualPivotQuicksortName(tutors, lPivot + 1, rPivot - 1);
    // sort right subarray
    dualPivotQuicksortName(tutors, rPivot + 1, up);
  };
};
void partitionName(Tutor *tutors, int low, int up, int *lPivot, int *rPivot) {
  if (compareInsensitive(tutors[low].getName(), tutors[up].getName()) > 0)
    // swap between left and right pivots
    swap(&tutors[low], &tutors[up]);

  // initialise
  int lIndex = low + 1, rIndex = up - 1;
  string lPiv = tutors[low].getName(), rPiv = tutors[up].getName();

  for (int i = lIndex; i <= rIndex; i++) {
    if (compareInsensitive(tutors[i].getName(), lPiv) < 0) {
      // swap elements that are less than the left pivot
      swap(&tutors[i], &tutors[lIndex]);
      lIndex++;
    } else if (compareInsensitive(tutors[i].getName(), rPiv) >= 0) {
      // swap elements are greater than or equal to the right pivot
      while (compareInsensitive(tutors[rIndex].getName(), rPiv) > 0 && i < rIndex)
        rIndex--;
      swap(&tutors[i], &tutors[rIndex]);
      rIndex--;
      if (compareInsensitive(tutors[i].getName(), lPiv) < 0) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };
    };
  };
  // decrement left index
  lIndex--;
  // increment right index
  rIndex++;

  // swap pivots to their new positions
  swap(&tutors[low], &tutors[lIndex]);
  swap(&tutors[up], &tutors[rIndex]);

  // return the indices of the pivots
  *lPivot = lIndex;
  *rPivot = rIndex;
};

void dualPivotQuicksortRating(Tutor *tutors, int low, int up) {
  if (low < up) {
    int lPivot, rPivot;
    partitionRating(tutors, low, up, &lPivot, &rPivot);
    // sort left subarray
    dualPivotQuicksortRating(tutors, low, lPivot - 1);
    // sort mid subarray
    dualPivotQuicksortRating(tutors, lPivot + 1, rPivot - 1);
    // sort right subarray
    dualPivotQuicksortRating(tutors, rPivot + 1, up);
  };
};
void partitionRating(Tutor *tutors, int low, int up, int *lPivot, int *rPivot) {
  if (tutors[low].getRating() > tutors[up].getRating())
    // swap between left and right pivots
    swap(&tutors[low], &tutors[up]);

  // initialise
  int lIndex = low + 1, rIndex = up - 1;
  int lPiv = tutors[low].getRating(), rPiv = tutors[up].getRating();

  for (int i = lIndex; i <= rIndex; i++) {
    if (tutors[i].getRating() < lPiv) {
      // swap elements that are less than the left pivot
      swap(&tutors[i], &tutors[lIndex]);
      lIndex++;
    } else if (tutors[i].getRating() >= rPiv) {
      // swap elements are greater than or equal to the right pivot
      while (tutors[rIndex].getRating() > rPiv && i < rIndex)
        rIndex--;
      swap(&tutors[i], &tutors[rIndex]);
      rIndex--;
      if (tutors[i].getRating() < lPiv) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };
    };
  };
  // decrement left index
  lIndex--;
  // increment right index
  rIndex++;

  // swap pivots to their new positions
  swap(&tutors[low], &tutors[lIndex]);
  swap(&tutors[up], &tutors[rIndex]);

  // return the indices of the pivots
  *lPivot = lIndex;
  *rPivot = rIndex;
};

void dualPivotQuicksortPayRate(Tutor *tutors, int low, int up) {
  if (low < up) {
    int lPivot, rPivot;
    partitionPayRate(tutors, low, up, &lPivot, &rPivot);
    // sort left subarray
    dualPivotQuicksortPayRate(tutors, low, lPivot - 1);
    // sort mid subarray
    dualPivotQuicksortPayRate(tutors, lPivot + 1, rPivot - 1);
    // sort right subarray
    dualPivotQuicksortPayRate(tutors, rPivot + 1, up);
  };
};
void partitionPayRate(Tutor *tutors, int low, int up, int *lPivot, int *rPivot) {
  if (tutors[low].getHourlyPayRate() > tutors[up].getHourlyPayRate())
    // swap between left and right pivots
    swap(&tutors[low], &tutors[up]);

  // initialise
  int lIndex = low + 1, rIndex = up - 1;
  double lPiv = tutors[low].getHourlyPayRate(), rPiv = tutors[up].getHourlyPayRate();

  for (int i = lIndex; i <= rIndex; i++) {
    if (tutors[i].getHourlyPayRate() < lPiv) {
      // swap elements that are less than the left pivot
      swap(&tutors[i], &tutors[lIndex]);
      lIndex++;
    } else if (tutors[i].getHourlyPayRate() >= rPiv) {
      // swap elements are greater than or equal to the right pivot
      while (tutors[rIndex].getHourlyPayRate() > rPiv && i < rIndex)
        rIndex--;
      swap(&tutors[i], &tutors[rIndex]);
      rIndex--;
      if (tutors[i].getHourlyPayRate() < lPiv) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };
    };
  };
  // decrement left index
  lIndex--;
  // increment right index
  rIndex++;

  // swap pivots to their new positions
  swap(&tutors[low], &tutors[lIndex]);
  swap(&tutors[up], &tutors[rIndex]);

  // return the indices of the pivots
  *lPivot = lIndex;
  *rPivot = rIndex;
};

void dualPivotQuicksortTCName(Tutor *tutors, int low, int up) {
  if (low < up) {
    int lPivot, rPivot;
    partitionTCName(tutors, low, up, &lPivot, &rPivot);
    // sort left subarray
    dualPivotQuicksortTCName(tutors, low, lPivot - 1);
    // sort mid subarray
    dualPivotQuicksortTCName(tutors, lPivot + 1, rPivot - 1);
    // sort right subarray
    dualPivotQuicksortTCName(tutors, rPivot + 1, up);
  };
};
void partitionTCName(Tutor *tutors, int low, int up, int *lPivot, int *rPivot) {
  if (compareInsensitive(tutors[low].getTuitionCentreName(), tutors[up].getTuitionCentreName()) > 0)
    // swap between left and right pivots
    swap(&tutors[low], &tutors[up]);

  // initialise
  int lIndex = low + 1, rIndex = up - 1;
  string lPiv = tutors[low].getTuitionCentreName(), rPiv = tutors[up].getTuitionCentreName();

  for (int i = lIndex; i <= rIndex; i++) {
    if (compareInsensitive(tutors[i].getTuitionCentreName(), lPiv) < 0) {
      // swap elements that are less than the left pivot
      swap(&tutors[i], &tutors[lIndex]);
      lIndex++;
    } else if (compareInsensitive(tutors[i].getTuitionCentreName(), rPiv) >= 0) {
      // swap elements are greater than or equal to the right pivot
      while (compareInsensitive(tutors[rIndex].getTuitionCentreName(), rPiv) > 0 && i < rIndex)
        rIndex--;
      swap(&tutors[i], &tutors[rIndex]);
      rIndex--;
      if (compareInsensitive(tutors[i].getTuitionCentreName(), lPiv) < 0) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };
    };
  };
  // decrement left index
  lIndex--;
  // increment right index
  rIndex++;

  // swap pivots to their new positions
  swap(&tutors[low], &tutors[lIndex]);
  swap(&tutors[up], &tutors[rIndex]);

  // return the indices of the pivots
  *lPivot = lIndex;
  *rPivot = rIndex;
};
