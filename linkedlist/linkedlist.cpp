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
  Tutor *next;
  Tutor *previous;

  public:
  // constructor
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
    this->next = NULL;
    this->previous = NULL;
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
    this->next = NULL;
    this->previous = NULL;
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
  Tutor *getNext() {
    return next;
  };
  void setNext(Tutor *next) {
    this->next = next;
  };
  Tutor *getPrevious() {
    return previous;
  };
  void setPrevious(Tutor *previous) {
    this->previous = previous;
  };
};
struct SearchCache {
  private:
  string name;
  SearchCache *next;

  public:
  // constructors
  SearchCache(string name) {
    this->name = name;
    this->next = NULL;
  };

  // getters and setters
  string getName() {
    return name;
  };
  void setName(string name) {
    this->name = name;
  };
  SearchCache *getNext() {
    return next;
  };
  void setNext(SearchCache *next) {
    this->next = next;
  };
};

// function headers
void generateTutors(Tutor *&head, Tutor *&tail, int *lastID, int *size);
void addTutor(Tutor *&head, Tutor *&tail, int *lastID, int *size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating);
void modifyTutor(Tutor *head, int tutorID);
void terminateTutor(Tutor *head, int tutorID);
void deleteTutor(Tutor *&head, Tutor *&tail, int *size, int tutorID);

void displayRecord(Tutor tutor);
void displayAllRecords(Tutor *head, int size);

void sortTutorID(Tutor *head, int size);
void sortRating(Tutor *head, int size);
void sortPayRate(Tutor *head, int size);

void searchTutorID(Tutor *head, int tutorID);
void searchRating(Tutor *head, int rating);
void searchTuitionName(Tutor *head, int size, string tcName);

// insert
void insertToEnd(Tutor *&head, Tutor *&tail, Tutor tutor);
void insertToEnd(Tutor *&head, Tutor *&tail, int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, string tuitionCentreCode, string tuitionCentreName, string subjectCode, string subjectName, int rating);

// delete
void deleteList(Tutor *head);

// mergesort
void split(Tutor *head, Tutor *&list1, Tutor *&list2);

Tutor *mergeID(Tutor *list1, Tutor *list2);
void mergesortID(Tutor *&head);

Tutor *mergeRating(Tutor *list1, Tutor *list2);
void mergesortRating(Tutor *&head);

Tutor *mergePayRate(Tutor *list1, Tutor *list2);
void mergesortPayRate(Tutor *&head);

Tutor *mergeTCName(Tutor *list1, Tutor *list2, string tcName);
void mergesortTCName(Tutor *&head, string tcName);


int main() {
  // initialise
  int size = 0, lastID = 0;
  Tutor *head = NULL, *tail = NULL;
  int input = 0, subinput = 0;
  char cinput = ' ';

  // generate hardcoded data
  generateTutors(head, tail, &lastID, &size);

  // set cout to always display two decimals for doubles
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  // menu
  do {
    cout << "-----------------------" << endl;
    cout << "Tutor Management System" << endl;
    cout << "-----------------------" << endl;
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
          } while (!validateDate(day, month, year));

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
          addTutor(head, tail, &lastID, &size, name, day, month, year, hourlyPayRate, phone, address, tcCode, tcName, subCode, subName, rating);
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
          modifyTutor(head, tutorID);
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
          terminateTutor(head, tutorID);
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
          deleteTutor(head, tail, &size, tutorID);
          break;
        };

        // display records
      case 5:
        cout << "Display Records (Name (Asc))" << endl;
        cout << "---------------------------------------" << endl;
        displayAllRecords(head, size);
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
            sortTutorID(head, size);
            break;

            // sort by rating
          case 2:
            cout << "Display Records (Rating (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortRating(head, size);
            break;

            // sort by hourly pay rate
          default:
            cout << "Display Records (Hourly Pay Rate (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortPayRate(head, size);
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
              searchTutorID(head, tutorID);
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
              searchRating(head, rating);
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
              searchTuitionName(head, size, tcName);
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


void generateTutors(Tutor *&head, Tutor *&tail, int *lastID, int *size) {
  *lastID = 10;
  *size = 10;

  insertToEnd(head, tail, 2, "Aaron", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, 1, "Bill", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, 4, "Charlie", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, 3, "Edwin", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);
  insertToEnd(head, tail, 8, "George", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  insertToEnd(head, tail, 10, "Jamal", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  insertToEnd(head, tail, 5, "Kenny", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  insertToEnd(head, tail, 9, "Maria", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  insertToEnd(head, tail, 7, "Patricia", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, 6, "Shelby", 2, 3, 2000, 0, 0, 0, 50.00, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
};
void addTutor(Tutor *&head, Tutor *&tail, int *lastID, int *size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating) {
  // initialise
  int tutorID = *lastID + 1;

  Tutor *newTutor = new Tutor(tutorID, name, day, month, year, 0, 0, 0, hourlyPayRate, phone, address, tcCode, tcName, subCode, subCode, rating);

  // insertion sort
  if (head) {
    if (compareInsensitive(name, head->getName()) < 0) {
      // new tutor is before existing tutors
      // link new tutor to head tutor
      newTutor->setNext(head);
      // link head tutor to new tutor
      head->setPrevious(newTutor);
      // head is new tutor
      head = newTutor;
    } else {
      // initialise
      Tutor *current = head;

      while (current->getNext()) {
        if (compareInsensitive(name, current->getNext()->getName()) < 0)
          // new tutor is before next existing tutor, stop iteration
          break;
        current = current->getNext();
      };

      if (current->getNext()) {
        // link new tutor to next tutor
        newTutor->setNext(current->getNext());
        // link next tutor to new tutor
        current->getNext()->setPrevious(newTutor);
      } else {
        // tail is new tutor
        tail = newTutor;
      };

      // link current tutor to new tutor
      current->setNext(newTutor);
      // link new tutor to current tutor
      newTutor->setPrevious(current);
    };
  } else {
    // insert new tutor as there are no existing tutors
    head = newTutor;
    tail = newTutor;
  };
  // display success message
  cout << "Added Successfully" << endl << endl;
  // increase tutor size
  *size += 1;
  // increase last id
  *lastID += 1;
};
void modifyTutor(Tutor *head, int tutorID) {
  // initialise
  int input = 0;
  string phone = "", address = "";
  bool found = false;
  Tutor *current = head;

  // linear search through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // display record
      displayRecord(*current);

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
        current->setPhone(phone);
      };

      // modify address
      if (input == 2 || input == 3) {
        do {
          cout << "New Address: ";
          getline(cin, address);
          trim(address);
        } while (address == "");
        current->setAddress(address);
      };

      // display success message
      if (input >= 1)
        cout << "Modified Successfully" << endl << endl;

      // set as found
      found = true;
      // stop iteration
      break;
    };
    current = current->getNext();
  };
  // if no results
  if (!found)
    cout << "No results found" << endl << endl;
};
void terminateTutor(Tutor *head, int tutorID) {
  // initialise
  int day = 0, month = 0, year = 0;
  time_t dateTerminated = time(0);
  char sp = ' ', cinput = ' ';
  bool found = false;
  Tutor *current = head;

  // linear search through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // display record
      displayRecord(*current);

      // set as found
      found = true;

      // check if tutor is terminated
      if (current->getDateTerminated() != -1) {
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
      } while (!validateDate(day, month, year) || difftime(dateTerminated, current->getDateJoined()) <= 0);

      // ask for confirmation
      do {
        if (current->getDateTerminated() == -1)
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
          current->setDateTerminated(dateTerminated);
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
    current = current->getNext();
  };
  // if no results
  if (!found)
    cout << "No results found" << endl << endl;
};
void deleteTutor(Tutor *&head, Tutor *&tail, int *size, int tutorID) {
  // initialise
  char cinput = ' ';
  bool found = false;
  Tutor *current = head;

  // linear search through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // display record
      displayRecord(*current);

      // set as found
      found = true;

      // check if tutor is terminated
      if (current->getDateTerminated() == -1) {
        // display not terminated message
        cout << "Tutor has not been terminated" << endl << endl;
        // stop iteration
        break;
      };

      // check if terminated date has reached at least 6 months
      tm tmTerminated;
      time_t dateTerminated = current->getDateTerminated();
      gmtime_s(&tmTerminated, &dateTerminated);

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
          if (current->getNext())
            // link next tutor to previous tutor
            current->getNext()->setPrevious(current->getPrevious());
          else
            // tail is previous tutor
            tail = current->getPrevious();

          if (current->getPrevious())
            // link previous tutor to next tutor
            current->getPrevious()->setNext(current->getNext());
          else
            // head is next tutor
            head = current->getNext();

          // deallocate memory
          delete current;

          // display success message
          cout << "Deleted Successfully" << endl << endl;
          // decrease tutor size
          *size -= 1;
          break;

        // cancel delete
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };

      // stop iteration
      break;
    };
    current = current->getNext();
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
void displayAllRecords(Tutor *head, int size) {
  // initialise
  int page = 1, input = 0, i = 0;
  Tutor *current = head;

  // calculate total page numbers
  int total = size / 10;
  if (size % 10 > 0)
    total++;

  // display page
  do {
    if (input != 1) {
      cout << "ID    Name             Pay    Tuition Centre       Rating" << endl;
      cout << "---------------------------------------------------------" << endl;
      for (i = 0; i < 10; i++) {
        // print list of tutors
        cout.width(4);
        cout << right << current->getTutorID() << "  ";
        cout.width(15);
        cout << left << current->getName() << "  ";
        cout.width(5);
        cout << current->getHourlyPayRate() << "  ";
        cout.width(19);
        cout << current->getTuitionCentreName() << "  ";
        cout << current->getRating() << endl;

        if (current->getNext())
          current = current->getNext();
        else
          // break when last element
          break;
      };
      // display page number
      cout << endl << "Page " << page << endl << endl;
    };

    cout << "(1) View more details" << endl;
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
    } while (input < 1 || input > 5);

    // determine outcome
    switch (input) {
      // view more details
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
          searchTutorID(head, tutorID);
          break;
        };

        // jump to page
      case 2:
        {
          int oldPage = page;

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
            if (oldPage >= page) {
              // go to previous tutors
              for (int x = 0; x < 10 * (oldPage - page + 1) - (10 - i); x++)
                current = current->getPrevious();
            } else {
              // go to next tutors
              for (int x = 0; x < 10 * (page - oldPage - 1); x++)
                current = current->getNext();
            };
          };
          cout << endl;
          break;
        };

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
        // go to previous tutors
        for (int x = 0; x < 10 + i; x++)
          current = current->getPrevious();
        cout << endl;
        break;

      default:
        cout << endl;
        break;
    };
  } while (input != 5);
};

void sortTutorID(Tutor *head, int size) {
  // initialise
  Tutor *current = head, *tempHead = NULL, *tempTail = NULL;

  // copy all elements into temporary tutor list
  while (current) {
    insertToEnd(tempHead, tempTail, *current);
    current = current->getNext();
  };

  // sort the temporary tutor list by id
  mergesortID(tempHead);

  // display sorted list
  displayAllRecords(tempHead, size);

  // deallocate memory
  deleteList(tempHead);
};
void sortRating(Tutor *head, int size) {
  // initialise
  Tutor *current = head, *tempHead = NULL, *tempTail = NULL;

  // copy all elements into temporary tutor list
  while (current) {
    insertToEnd(tempHead, tempTail, *current);
    current = current->getNext();
  };

  // sort the temporary tutor list by rating
  mergesortRating(tempHead);

  // display sorted list
  displayAllRecords(tempHead, size);

  // deallocate memory
  deleteList(tempHead);
};
void sortPayRate(Tutor *head, int size) {
  // initialise
  Tutor *current = head, *tempHead = NULL, *tempTail = NULL;

  // copy all elements into temporary tutor list
  while (current) {
    insertToEnd(tempHead, tempTail, *current);
    current = current->getNext();
  };

  // sort the temporary tutor list by id
  mergesortPayRate(tempHead);

  // display sorted list
  displayAllRecords(tempHead, size);

  // deallocate memory
  deleteList(tempHead);
};

void searchTutorID(Tutor *head, int tutorID) {
  // initialise
  Tutor *current = head;

  // linear seaarch through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // display result
      displayRecord(*current);
      // stop iteration
      break;
    };
    current = current->getNext();
  };

  // if no results
  if (!current)
    cout << "No results found" << endl << endl;
};
void searchRating(Tutor *head, int rating) {
  // initialise
  int tempSize = 0;
  Tutor *current = head, *tempHead = NULL, *tempTail = NULL;

  // linear search through the list
  while (current) {
    // find tutors with searched rating
    if (current->getRating() == rating) {
      // insert to the temporary list
      insertToEnd(tempHead, tempTail, *current);
      // increase temporary list size
      tempSize++;
    };
    current = current->getNext();
  };

  if (tempHead) {
    // display all records
    displayAllRecords(tempHead, tempSize);
    // deallocate memory
    deleteList(tempHead);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void searchTuitionName(Tutor *head, int size, string tcName) {
  // initialise
  Tutor *current = head, *tempHead = NULL, *tempTail = NULL;
  SearchCache *currentName = NULL, *nameHead = NULL;
  int tempSize = 0, input = 0;
  string sinput = "";

  // copy all elements into temporary tutor list
  while (current) {
    insertToEnd(tempHead, tempTail, *current);
    current = current->getNext();
  };

  // sort the temporary tutor list by tuition name
  mergesortTCName(tempHead, tcName);

  // linear search through the list
  current = tempHead;
  while (current) {
    if (nameHead) {
      bool exist = false;
      currentName = nameHead;
      // linear search through the list
      while (currentName) {
        if (compareInsensitive(current->getTuitionCentreName(), currentName->getName()) == 0) {
          // tuition name exists
          exist = true;
          // stop iteration
          break;
        };
        if (currentName->getNext())
          currentName = currentName->getNext();
        else
          // break when last element
          break;
      };
      if (!exist)
        // link tuition name to new tuition name
        currentName->setNext(new SearchCache(current->getTuitionCentreName()));
    } else {
      // insert new tuition name as there are no existing tuition names
      nameHead = new SearchCache(current->getTuitionCentreName());
    };
    current = current->getNext();
  };

  // get user input
  if (nameHead->getNext()) {
    currentName = nameHead;
    int i = 0;
    for (; currentName; i++, currentName = currentName->getNext())
      cout << "(" << i + 1 << ") " << currentName->getName() << endl;
    do {
      cout << "Please input (1-" << i << "): ";
      // ignore enter key
      if (cin.peek() != '\n')
        cin >> input;
      if (!cin)
        // clear error state
        cin.clear();
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (input < 1 || input > i);
  } else if (nameHead) {
    input = 1;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };

  // get tuition name
  currentName = nameHead;
  for (int i = 0; i < input - 1; i++)
    currentName = currentName->getNext();
  sinput = currentName->getName();

  // deallocate non-searched results
  current = tempHead;
  while (current && compareInsensitive(current->getTuitionCentreName(), sinput) != 0) {
    current = current->getNext();
    // deallocate memory
    delete tempHead;
    tempHead = current;
  };
  while (current && compareInsensitive(current->getTuitionCentreName(), sinput) == 0) {
    // increase temporary list size
    tempSize++;
    current = current->getNext();
  };
  while (current) {
    current = current->getNext();
    // deallocate memory
    delete tempHead;
    tempHead = current;
  };

  // display sorted list
  displayAllRecords(tempHead, tempSize);

  // deallocate memory
  deleteList(tempHead);
};

// insert
void insertToEnd(Tutor *&head, Tutor *&tail, Tutor tutor) {
  // initialise
  Tutor *newTutor = new Tutor(tutor.getTutorID(), tutor.getName(), tutor.getDateJoined(), tutor.getDateTerminated(), tutor.getHourlyPayRate(), tutor.getPhone(), tutor.getAddress(), tutor.getTuitionCentreCode(), tutor.getTuitionCentreName(), tutor.getSubjectCode(), tutor.getSubjectName(), tutor.getRating());

  if (head) {
    // link new tutor to tail tutor
    newTutor->setPrevious(tail);
    // link tail tutor to new tutor
    tail->setNext(newTutor);
    // tail is new tutor
    tail = newTutor;
  } else {
    // insert new tutor as there are no existing tutors
    head = newTutor;
    tail = newTutor;
  };
};
void insertToEnd(Tutor *&head, Tutor *&tail, int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, string tuitionCentreCode, string tuitionCentreName, string subjectCode, string subjectName, int rating) {
  // initialise
  Tutor *newTutor = new Tutor(tutorID, name, dayJoined, monthJoined, yearJoined, dayTerminated, monthTerminated, yearTerminated, hourlyPayRate, phone, address, tuitionCentreCode, tuitionCentreName, subjectCode, subjectName, rating);

  if (head) {
    // link new tutor to tail tutor
    newTutor->setPrevious(tail);
    // link tail tutor to new tutor
    tail->setNext(newTutor);
    // tail is new tutor
    tail = newTutor;
  } else {
    // insert new tutor as there are no existing tutors
    head = newTutor;
    tail = newTutor;
  };
};

// delete
void deleteList(Tutor *head) {
  // initialise
  Tutor *current = head;
  while (current) {
    current = current->getNext();
    // deallocate memory
    delete head;
    head = current;
  };
};

// mergesort
void split(Tutor *head, Tutor *&list1, Tutor *&list2) {
  // initialise
  Tutor *fast = head->getNext(), *slow = head;

  // split list alternatively
  while (fast) {
    fast = fast->getNext();
    if (fast) {
      slow = slow->getNext();
      fast = fast->getNext();
    };
  };

  // return the addresses of the sublists
  list1 = head;
  list2 = slow->getNext();
  // split sublist 2 from sublist 1
  slow->setNext(NULL);
};

Tutor *mergeID(Tutor *list1, Tutor *list2) {
  if (!list1)
    // return address of sublist 2 as sublist 1 is empty
    return list2;

  if (!list2)
    // return address of sublist 1 as sublist 2 is empty
    return list1;

  if (list1->getTutorID() < list2->getTutorID()) {
    // link sublist 1 to sublist 2
    list1->setNext(mergeID(list1->getNext(), list2));
    // link sublist 2 to sublist 1
    list1->getNext()->setPrevious(list1);
    list1->setPrevious(NULL);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergeID(list1, list2->getNext()));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(NULL);
    // return address of sublist 2
    return list2;
  };
};
void mergesortID(Tutor *&head) {
  // initialise
  Tutor *current = head, *list1 = NULL, *list2 = NULL;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortID(list1);
    // sort sublist 2
    mergesortID(list2);
    // merge sublists
    head = mergeID(list1, list2);
  };
};

Tutor *mergeRating(Tutor *list1, Tutor *list2) {
  if (!list1)
    // return address of sublist 2 as sublist 1 is empty
    return list2;

  if (!list2)
    // return address of sublist 1 as sublist 2 is empty
    return list1;

  if (list1->getRating() <= list2->getRating()) {
    // link sublist 1 to sublist 2
    list1->setNext(mergeRating(list1->getNext(), list2));
    // link sublist 2 to sublist 1
    list1->getNext()->setPrevious(list1);
    list1->setPrevious(NULL);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergeRating(list1, list2->getNext()));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(NULL);
    // return address of sublist 2
    return list2;
  };
};
void mergesortRating(Tutor *&head) {
  // initialise
  Tutor *current = head, *list1 = NULL, *list2 = NULL;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortRating(list1);
    // sort sublist 2
    mergesortRating(list2);
    // merge sublists
    head = mergeRating(list1, list2);
  };
};

Tutor *mergePayRate(Tutor *list1, Tutor *list2) {
  if (!list1)
    // return address of sublist 2 as sublist 1 is empty
    return list2;

  if (!list2)
    // return address of sublist 1 as sublist 2 is empty
    return list1;

  if (list1->getHourlyPayRate() <= list2->getHourlyPayRate()) {
    // link sublist 1 to sublist 2
    list1->setNext(mergePayRate(list1->getNext(), list2));
    // link sublist 2 to sublist 1
    list1->getNext()->setPrevious(list1);
    list1->setPrevious(NULL);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergePayRate(list1, list2->getNext()));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(NULL);
    // return address of sublist 2
    return list2;
  };
};
void mergesortPayRate(Tutor *&head) {
  // initialise
  Tutor *current = head, *list1 = NULL, *list2 = NULL;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortPayRate(list1);
    // sort sublist 2
    mergesortPayRate(list2);
    // merge sublists
    head = mergePayRate(list1, list2);
  };
};

Tutor *mergeTCName(Tutor *list1, Tutor *list2, string tcName) {
  if (list1) {
    if (findInsensitive(list1->getTuitionCentreName(), tcName) == string::npos) {
      // deallocate memory
      delete list1;
      return list2;
    };
  } else {
    // return address of sublist 2 as sublist 1 is empty
    return list2;
  };

  if (list2) {
    if (findInsensitive(list2->getTuitionCentreName(), tcName) == string::npos) {
      // deallocate memory
      delete list2;
      return list1;
    };
  } else {
    // return address of sublist 1 as sublist 2 is empty
    return list1;
  };

  if (compareInsensitive(list1->getTuitionCentreName(), list2->getTuitionCentreName()) <= 0) {
    // link sublist 1 to sublist 2
    list1->setNext(mergeTCName(list1->getNext(), list2, tcName));
    // link sublist 2 to sublist 1
    list1->getNext()->setPrevious(list1);
    list1->setPrevious(NULL);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergeTCName(list1, list2->getNext(), tcName));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(NULL);
    // return address of sublist 2
    return list2;
  };
};
void mergesortTCName(Tutor *&head, string tcName) {
  // initialise
  Tutor *current = head, *list1 = NULL, *list2 = NULL;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortTCName(list1, tcName);
    // sort sublist 2
    mergesortTCName(list2, tcName);
    // merge sublists
    head = mergeTCName(list1, list2, tcName);
  };
};
