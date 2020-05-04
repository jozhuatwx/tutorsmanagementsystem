#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include "../datec.h"
#include "../digitc.h"
#include "../stringc.h"
using namespace std;

class TuitionCentre {
  private:
  int tuitionCentreCode;
  string tuitionCentreName;
  TuitionCentre *next;
  TuitionCentre *previous;

  public:
  // constructor
  TuitionCentre(int tuitionCentreCode, string tuitionCentreName) {
    this->tuitionCentreCode = tuitionCentreCode;
    this->tuitionCentreName = tuitionCentreName;
    this->next = nullptr;
    this->previous = nullptr;
  };

  // getters and setters
  int getTuitionCentreCode() {
    return tuitionCentreCode;
  };
  void setTuitionCentreCode(int tuitionCentreCode) {
    this->tuitionCentreCode = tuitionCentreCode;
  };
  string getTuitionCentreName() {
    return tuitionCentreName;
  };
  void getTuitionCentreName(string tuitionCentreName) {
    this->tuitionCentreName = tuitionCentreName;
  };
  TuitionCentre *getNext() {
    return next;
  };
  void setNext(TuitionCentre *next) {
    this->next = next;
  };
  TuitionCentre *getPrevious() {
    return previous;
  };
  void setPrevious(TuitionCentre *previous) {
    this->previous = previous;
  };
};
class Subject {
  private:
  int subjectCode;
  string subjectName;
  Subject *next;
  Subject *previous;

  public:
  // constructor
  Subject(int subjectCode, string subjectName) {
    this->subjectCode = subjectCode;
    this->subjectName = subjectName;
    this->next = nullptr;
    this->previous = nullptr;
  };

  // getters and setters
  int getSubjectCode() {
    return subjectCode;
  };
  void setSubjectCode(int subjectCode) {
    this->subjectCode = subjectCode;
  };
  string getSubjectName() {
    return subjectName;
  };
  void getSubjectName(string subjectName) {
    this->subjectName = subjectName;
  };
  Subject *getNext() {
    return next;
  };
  void setNext(Subject *next) {
    this->next = next;
  };
  Subject *getPrevious() {
    return previous;
  };
  void setPrevious(Subject *previous) {
    this->previous = previous;
  };
};
class Tutor {
  private:
  int tutorID;
  string name;
  time_t dateJoined;
  time_t dateTerminated;
  double hourlyPayRate;
  string phone;
  string address;
  int tuitionCentreCode;
  int subjectCode;
  int rating;
  Tutor *next;
  Tutor *previous;

  public:
  // constructor
  Tutor(int tutorID, string name, time_t dateJoined, time_t dateTerminated, double hourlyPayRate, string phone, string address, int tuitionCentreCode, int subjectCode, int rating) {
    this->tutorID = tutorID;
    this->name = name;
    this->dateJoined = dateJoined;
    this->dateTerminated = dateTerminated;
    this->hourlyPayRate = hourlyPayRate;
    this->phone = phone;
    this->address = address;
    this->tuitionCentreCode = tuitionCentreCode;
    this->subjectCode = subjectCode;
    this->rating = rating;
    this->next = nullptr;
    this->previous = nullptr;
  };
  Tutor(int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, int tuitionCentreCode, int subjectCode, int rating) {
    this->tutorID = tutorID;
    this->name = name;
    this->dateJoined = intToTime(dayJoined, monthJoined, yearJoined);
    this->dateTerminated = intToTime(dayTerminated, monthTerminated, yearTerminated);
    this->hourlyPayRate = hourlyPayRate;
    this->phone = phone;
    this->address = address;
    this->tuitionCentreCode = tuitionCentreCode;
    this->subjectCode = subjectCode;
    this->rating = rating;
    this->next = nullptr;
    this->previous = nullptr;
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
  int getTuitionCentreCode() {
    return tuitionCentreCode;
  };
  string getTuitionCentreName(TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
    // initialise
    TuitionCentre *current = nullptr;
    // guess which end is faster
    if (tuitionCentreCode < lastTCCode / 2) {
      // linear search from beginning
      current = tcHead;
      for (int i = 0; i < tcSize - 1; i++, current = current->getNext())
        if (current->getTuitionCentreCode() == tuitionCentreCode)
          break;
    } else {
      // linear search from end
      current = tcTail;
      for (int i = tcSize - 1; i >= 0; i--, current = current->getPrevious())
        if (current->getTuitionCentreCode() == tuitionCentreCode)
          break;
    };
    return current->getTuitionCentreName();
  };
  int getSubjectCode() {
    return subjectCode;
  };
  string getSubjectName(Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
    // initialise
    Subject *current = nullptr;
    // guess which end is faster
    if (subjectCode < lastSubCode / 2) {
      // linear search from beginning
      current = subHead;
      for (int i = 0; i < subSize - 1; i++, current = current->getNext())
        if (current->getSubjectCode() == subjectCode)
          break;
    } else {
      // linear search from end
      current = subTail;
      for (int i = subSize - 1; i >= 0; i--, current = current->getPrevious())
        if (current->getSubjectCode() == subjectCode)
          break;
    };
    return current->getSubjectName();
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

// function headers
bool validateTuitionCentre(int tcCode, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize);
bool validateSubject(int subCode, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);

void generateTutors(Tutor *&head, Tutor *&tail, int &lastID, int &size, TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize);
void addTutor(Tutor *&head, Tutor *&tail, int &lastID, int &size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, int tcCode, int subCode, int rating);
void modifyTutor(Tutor *head, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void terminateTutor(Tutor *head, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void deleteTutor(Tutor *&head, Tutor *&tail, int &size, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);

void displayRecord(Tutor tutor, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void displayRecordsList(Tutor *head, int size, int index, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void displayRecordsDetailed(Tutor *tutors, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);

void sortTutorID(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void sortRating(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void sortPayRate(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);

void searchTutorID(Tutor *head, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void searchRating(Tutor *head, int rating, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);
void searchTuitionName(Tutor *head, int size, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);

// insert
void insertTCToEnd(TuitionCentre *&tcHead, TuitionCentre *&tcTail, int tcCode, string tcName);
void insertSubToEnd(Subject *&subHead, Subject *&subTail, int subCode, string subName);
void insertTutorToEnd(Tutor *&head, Tutor *&tail, Tutor tutor);
void insertTutorToEnd(Tutor *&head, Tutor *&tail, int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, int tuitionCentreCode, int subjectCode, int rating);

// delete
void deleteList(Tutor *head);

// mergesort
void split(Tutor *head, Tutor *&list1, Tutor *&list2);

void mergesortID(Tutor *&head);
Tutor *mergeID(Tutor *list1, Tutor *list2);

void mergesortRating(Tutor *&head);
Tutor *mergeRating(Tutor *list1, Tutor *list2);

void mergesortPayRate(Tutor *&head);
Tutor *mergePayRate(Tutor *list1, Tutor *list2);

void mergesortTCName(Tutor *&head, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize);
Tutor *mergeTCName(Tutor *list1, Tutor *list2, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize);


int main() {
  // initialise
  int size = 0, lastID = 0, tcSize = 0, lastTCCode = 0, subSize = 0, lastSubCode = 0;
  Tutor *head = nullptr, *tail = nullptr;
  TuitionCentre *tcHead = nullptr, *tcTail = nullptr;
  Subject *subHead = nullptr, *subTail = nullptr;
  int input = 0, subinput = 0;
  char cinput = ' ';

  // generate hardcoded data
  generateTutors(head, tail, lastID, size, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

  // set cout to always display two decimals for doubles
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  // menu
  do {
    cout << "-------------------------------------------" << endl;
    cout << "Tutor Management System (Linked List 2.0.2)" << endl;
    cout << "-------------------------------------------" << endl;
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

          if (tcSize > 0 && subSize > 0) {
            // initialise
            string name = "", phone = "", address = "";
            int day = 0, month = 0, year = 0, rating = 0, tcCode = 0, subCode = 0;
            double hourlyPayRate = 0.0;
            char sp = ' ';
            int tcDigits = countDigits(lastTCCode);
            int subDigits = countDigits(lastSubCode);

            int width = 24 + max(tcDigits, subDigits - 7);

            // get tutor details
            // name
            do {
              cout.width(width);
              cout << left << "Name" << ": ";
              getline(cin, name);
              trim(name);
            } while (name == "");

            // date joined
            do {
              cout.width(width);
              cout << left << "Date Joined (d/m/y)" << ": ";
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
              cout.width(width);
              cout << left << "Hourly Pay (40-80)" << ": ";
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
              cout.width(width);
              cout << left << "Phone" << ": ";
              getline(cin, phone);
              trim(phone);
            } while (phone == "");

            // address
            do {
              cout.width(width);
              cout << left << "Address" << ": ";
              getline(cin, address);
              trim(address);
            } while (address == "");

            // tuition centre code
            do {
              cout << "Tuition Centre Code (1-" << lastTCCode << ")";
              cout.width(width - (__int64) 24 - tcDigits + (__int64) 2);
              cout << right << ": ";
              // ignore enter key
              if (cin.peek() != '\n')
                cin >> tcCode;
              // clear error state
              if (!cin)
                cin.clear();
              // clear the input buffer
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (tcCode < 0 || !validateTuitionCentre(tcCode, tcHead, tcTail, lastTCCode, tcSize));

            // subject code
            do {
              cout << "Subject Code (1-" << lastSubCode << ")";
              cout.width(width - (__int64) 17 - subDigits + (__int64) 2);
              cout << right << ": ";
              // ignore enter key
              if (cin.peek() != '\n')
                cin >> subCode;
              // clear error state
              if (!cin)
                cin.clear();
              // clear the input buffer
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (subCode < 0 || !validateSubject(subCode, subHead, subTail, lastSubCode, subSize));

            // rating
            do {
              cout.width(width);
              cout << left << "Rating (1-5)" << ": ";
              // ignore enter key
              if (cin.peek() != '\n')
                cin >> rating;
              // clear error state
              if (!cin)
                cin.clear();
              // clear the input buffer
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (rating < 1 || rating > 5);
            addTutor(head, tail, lastID, size, name, day, month, year, hourlyPayRate, phone, address, tcCode, subCode, rating);
          } else {
            if (tcSize <= 0)
              cout << "No tuition centres found" << endl;
            if (subSize <= 0)
              cout << "No subjects found" << endl;
            cout << endl;
          };
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
          modifyTutor(head, tutorID, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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
          terminateTutor(head, tutorID, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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
          deleteTutor(head, tail, size, tutorID, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
          break;
        };

        // display records
      case 5:
        cout << "Display Records (Name (Asc))" << endl;
        cout << "---------------------------------------" << endl;
        displayRecordsList(head, size, 0, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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
            sortTutorID(head, size, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
            break;

            // sort by rating
          case 2:
            cout << "Display Records (Rating (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortRating(head, size, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
            break;

            // sort by hourly pay rate
          default:
            cout << "Display Records (Hourly Pay Rate (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortPayRate(head, size, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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
              searchTutorID(head, tutorID, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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
              searchRating(head, rating, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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
              searchTuitionName(head, size, tcName, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
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

bool validateTuitionCentre(int tcCode, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
  // initialise
  TuitionCentre *current = nullptr;
  // guess which end is faster
  if (tcCode < lastTCCode / 2) {
    // linear search from beginning
    current = tcHead;
    for (int i = 0; i < tcSize - 1; i++, current = current->getNext())
      if (current->getTuitionCentreCode() == tcCode)
        return true;
  } else {
    // linear search from end
    current = tcTail;
    for (int i = tcSize; i > 0; i--, current = current->getPrevious())
      if (current->getTuitionCentreCode() == tcCode)
        return true;
  };
  return false;
};
bool validateSubject(int subCode, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  Subject *current = nullptr;
  // guess which end is faster
  if (subCode < lastSubCode / 2) {
    // linear search from beginning
    current = subHead;
    for (int i = 0; i < subSize - 1; i++, current = current->getNext())
      if (current->getSubjectCode() == subCode)
        return true;
  } else {
    // linear search from end
    current = subTail;
    for (int i = subSize; i > 0; i--, current = current->getPrevious())
      if (current->getSubjectCode() == subCode)
        return true;
  };
  return false;
};

void generateTutors(Tutor *&head, Tutor *&tail, int &lastID, int &size, TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize) {
  // generate tuition centres
  tcSize = lastTCCode = 6;

  string tcNames[]{"Bukit Bintang", "Sri Petaling", "Bukit Petaling", "Taman Laksamana", "Taman Durian", "Bukit Jalil", "Taman Mutiara", "Pandan Perdana", "Taman Midah", "Pandan Indah"};

  for (int i = 0; i < tcSize; i++)
    insertTCToEnd(tcHead, tcTail, i + 1, tcNames[i]);
  
  // generate subjects
  subSize = lastSubCode = 2;

  string subNames[]{"Malay", "English", "Mathematics", "Additional Mathematics", "Biology", "Chemistry", "Physics", "Geography", "History", "Accounting", "Economics"};

  for (int i = 0; i < subSize; i++)
    insertSubToEnd(subHead, subTail, i + 1, subNames[i]);

  // generate tutors
  lastID = size = 10;

  insertTutorToEnd(head, tail, 2, "Aaron", 2, 3, 2000, 0, 0, 0, 79, "0123456789", "Somewhere", 3, 1, 5);
  insertTutorToEnd(head, tail, 1, "Bill", 2, 3, 2000, 0, 0, 0, 65.555, "0123456789", "Somewhere", 5, 1, 4);
  insertTutorToEnd(head, tail, 4, "Charlie", 2, 3, 2000, 0, 0, 0, 50.5, "0123456789", "Somewhere", 5, 2, 3);
  insertTutorToEnd(head, tail, 3, "Edwin", 2, 3, 2000, 0, 0, 0, 65.551, "0123456789", "Somewhere", 2, 1, 4);
  insertTutorToEnd(head, tail, 8, "George", 2, 3, 2000, 0, 0, 0, 45, "0123456789", "Somewhere", 4, 1, 2);
  insertTutorToEnd(head, tail, 10, "Jamal", 2, 3, 2000, 0, 0, 0, 55.5, "0123456789", "Somewhere", 6, 1, 3);
  insertTutorToEnd(head, tail, 5, "Kenny", 2, 3, 2000, 0, 0, 0, 65.559, "0123456789", "Somewhere", 3, 1, 4);
  insertTutorToEnd(head, tail, 9, "Maria", 2, 3, 2000, 0, 0, 0, 55.05, "0123456789", "Somewhere", 1, 2, 3);
  insertTutorToEnd(head, tail, 7, "Patricia", 2, 3, 2000, 0, 0, 0, 75, "0123456789", "Somewhere", 3, 2, 5);
  insertTutorToEnd(head, tail, 6, "Shelby", 2, 3, 2000, 0, 0, 0, 40, "0123456789", "Somewhere", 6, 2, 1);
};
void addTutor(Tutor *&head, Tutor *&tail, int &lastID, int &size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, int tcCode, int subCode, int rating) {
  // initialise
  int tutorID = lastID + 1;

  Tutor *newTutor = new Tutor(tutorID, name, day, month, year, 0, 0, 0, hourlyPayRate, phone, address, tcCode, subCode, rating);

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

      current = nullptr;
    };
  } else {
    // insert new tutor as there are no existing tutors
    head = newTutor;
    tail = newTutor;
  };
  // display success message
  cout << "Added Successfully" << endl << endl;
  // increase tutor size
  size++;
  // increase last id
  lastID++;
};
void modifyTutor(Tutor *head, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  int input = 0;
  string phone = "", address = "";
  bool found = false;
  Tutor *current = head;

  // linear search through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };
    current = current->getNext();
  };

  if (found) {
    // display record
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

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
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
  current = nullptr;
};
void terminateTutor(Tutor *head, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
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
      // set as found
      found = true;
      // stop iteration
      break;
    };
    current = current->getNext();
  };

  if (found) {
    // display record
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // check if tutor is terminated
    if (current->getDateTerminated() != -1) {
      do {
        cout << "Tutor is already terminated. Modify termination date? (Y/N): ";
        cin >> cinput;
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');
    } else {
      cinput = 'y';
    };

    // cancel termination
    if (cinput == 'y' || cinput == 'Y') {
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
    } else {
      // display cancelled message
      cout << "Cancelled" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void deleteTutor(Tutor *&head, Tutor *&tail, int &size, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  char cinput = ' ';
  bool found = false;
  Tutor *current = head;

  // linear search through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };
    current = current->getNext();
  };

  if (found) {
    // display record
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // check if tutor is terminated
    if (current->getDateTerminated() != -1) {
      // check if terminated date has reached at least 6 months
      tm tmTerminated;
      time_t dateTerminated = current->getDateTerminated();
      localtime_s(&tmTerminated, &dateTerminated);

      // add 6 months to terminated date
      if (tmTerminated.tm_mon > 6) {
        tmTerminated.tm_mon -= 6;
        tmTerminated.tm_year += 1;
      } else {
        tmTerminated.tm_mon += 6;
      };

      // compare terminated date plus 6 months to current date
      if (difftime(mktime(&tmTerminated), time(0)) <= 0) {
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
            size--;
            break;

            // cancel delete
          default:
            // display cancelled message
            cout << "Cancelled" << endl << endl;
            break;
        };
      } else {
        // display not passed 6 months message
        cout << "Tutor has not been terminated at least 6 months ago" << endl << endl;
      };
    } else {
      // display not terminated message
      cout << "Tutor has not been terminated" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void displayRecord(Tutor tutor, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
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
  cout << "Tuition Centre Name: " << tutor.getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize) << endl;
  cout << "Subject Code       : " << tutor.getSubjectCode() << endl;
  cout << "Subject Name       : " << tutor.getSubjectName(subHead, subTail, lastSubCode, subSize) << endl;
  cout << "Rating             : " << tutor.getRating() << endl << endl;
};
void displayRecordsList(Tutor *head, int size, int index, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  if (size > 0) {
    // initialise
    int page = 1, input = 0, i = 0;
    Tutor *current = head;

    for (; index >= 10; index -= 10) {
      for (int i = 0; i < 10; i++)
        current = current->getNext();
      page++;
    };

    // calculate total page numbers
    int total = size / 10;
    if (size % 10 > 0)
      total++;

    // display page
    do {
      if (input != 1) {
        cout << "ID    Name                  Pay    Tuition Centre        Rating" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (i = 0; i < 10; i++) {
          // print list of tutors
          cout.width(4);
          cout << right << current->getTutorID() << "  ";
          cout.width(20);
          cout << left << truncate(current->getName(), 20) << "  ";
          cout.width(5);
          cout << current->getHourlyPayRate() << "  ";
          cout.width(20);
          cout << truncate(current->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), 20) << "  ";
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
            break;
          };

          // next page
        case 3:
          if (page < total)
            page++;
          break;

          // previous page
        case 4:
          if (page > 1)
            page--;
          // go to previous tutors
          for (int x = 0; x < 10 + i; x++)
            current = current->getPrevious();
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 1 && input < 5);

    current = nullptr;

    // detailed view
    if (input == 1)
      displayRecordsDetailed(head, size, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void displayRecordsDetailed(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  if (size > 0) {
    // initialise
    Tutor *current = nullptr;
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
          current = head;
          for (index = 0; current; index++) {
            // find tutor with searched id
            if (current->getTutorID() == tutorID) {
              // set as found
              found = true;
              // stop iteration
              break;
            };
            current = current->getNext();
          };
        } while (!found);
      };

      // display result
      cout << "-------------------------------------" << endl;
      displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

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
          if (index < size - 1) {
            current = current->getNext();
            index++;
          };
          break;

          // previous record
        case 4:
          if (index > 0) {
            current = current->getPrevious();
            index--;
          };
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 1 && input < 5);

    current = nullptr;

    // list view
    if (input == 1)
      displayRecordsList(head, size, index, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void sortTutorID(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  if (size > 0) {
    // initialise
    Tutor *current = head, *tempHead = nullptr, *tempTail = nullptr;

    // copy all elements into temporary tutor list
    while (current) {
      insertTutorToEnd(tempHead, tempTail, *current);
      current = current->getNext();
    };

    // sort the temporary tutor list by id
    mergesortID(tempHead);

    // display sorted list
    displayRecordsList(tempHead, size, 0, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // deallocate memory
    deleteList(tempHead);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void sortRating(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  if (size > 0) {
    // initialise
    Tutor *current = head, *tempHead = nullptr, *tempTail = nullptr;

    // copy all elements into temporary tutor list
    while (current) {
      insertTutorToEnd(tempHead, tempTail, *current);
      current = current->getNext();
    };

    // sort the temporary tutor list by rating
    mergesortRating(tempHead);

    // display sorted list
    displayRecordsList(tempHead, size, 0, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // deallocate memory
    deleteList(tempHead);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void sortPayRate(Tutor *head, int size, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  if (size > 0) {
    // initialise
    Tutor *current = head, *tempHead = nullptr, *tempTail = nullptr;

    // copy all elements into temporary tutor list
    while (current) {
      insertTutorToEnd(tempHead, tempTail, *current);
      current = current->getNext();
    };

    // sort the temporary tutor list by id
    mergesortPayRate(tempHead);

    // display sorted list
    displayRecordsList(tempHead, size, 0, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // deallocate memory
    deleteList(tempHead);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void searchTutorID(Tutor *head, int tutorID, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  Tutor *current = head;
  bool found = false;

  // linear seaarch through the list
  while (current) {
    // find tutor with searched id
    if (current->getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };
    current = current->getNext();
  };

  // if no results
  if (found)
    // display result
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
  else
    cout << "No results found" << endl << endl;
  current = nullptr;
};
void searchRating(Tutor *head, int rating, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  int tempSize = 0;
  Tutor *current = head, *tempHead = nullptr, *tempTail = nullptr;

  // linear search through the list
  while (current) {
    // find tutors with searched rating
    if (current->getRating() == rating) {
      // insert to the temporary list
      insertTutorToEnd(tempHead, tempTail, *current);
      // increase temporary list size
      tempSize++;
    };
    current = current->getNext();
  };

  if (tempHead) {
    // display all records
    displayRecordsList(tempHead, tempSize, 0, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
    // deallocate memory
    deleteList(tempHead);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void searchTuitionName(Tutor *head, int size, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  Tutor *current = head, *tempHead = nullptr, *tempTail = nullptr;
  TuitionCentre *tempTuitions = nullptr, *tempTCHead = nullptr;
  int tempSize = 0, input = 0;

  // copy all elements into temporary tutor list
  while (current) {
    insertTutorToEnd(tempHead, tempTail, *current);
    current = current->getNext();
  };

  // sort the temporary tutor list by tuition name
  mergesortTCName(tempHead, tcName, tcHead, tcTail, lastTCCode, tcSize);

  // linear search through the list
  current = tempHead;
  while (current) {
    if (tempTCHead) {
      bool exist = false;
      tempTuitions = tempTCHead;
      // linear search through the list
      while (tempTuitions) {
        if (current->getTuitionCentreCode() == tempTuitions->getTuitionCentreCode()) {
          // tuition name exists
          exist = true;
          // stop iteration
          break;
        };
        if (tempTuitions->getNext())
          tempTuitions = tempTuitions->getNext();
        else
          // break when last element
          break;
      };
      if (!exist)
        // link tuition name to new tuition name
        tempTuitions->setNext(new TuitionCentre(current->getTuitionCentreCode(), current->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize)));
    } else {
      // insert new tuition name as there are no existing tuition names
      tempTCHead = new TuitionCentre(current->getTuitionCentreCode(), current->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize));
    };
    current = current->getNext();
  };

  // get user input
  if (tempTCHead) {
    if (tempTCHead->getNext()) {
      tempTuitions = tempTCHead;
      int i = 0;
      for (; tempTuitions; i++, tempTuitions = tempTuitions->getNext())
        cout << "(" << i + 1 << ") " << tempTuitions->getTuitionCentreName() << endl;
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
    } else {
      input = 1;
    };
    
    // get tuition code
    tempTuitions = tempTCHead;
    for (int i = 0; i < input - 1; i++)
      tempTuitions = tempTuitions->getNext();

    // deallocate non-searched results
    current = tempHead;
    while (current && current->getTuitionCentreCode() != tempTuitions->getTuitionCentreCode()) {
      current = current->getNext();
      // deallocate memory
      delete tempHead;
      tempHead = current;
    };
    while (current && current->getTuitionCentreCode() == tempTuitions->getTuitionCentreCode()) {
      // increase temporary list size
      tempSize++;
      current = current->getNext();
    };
    if (current) {
      // unlink list from to be deleted list
      current->getPrevious()->setNext(nullptr);
      
      // deallocate memory
      deleteList(current);
    };

    // display sorted list
    displayRecordsList(tempHead, tempSize, 0, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // deallocate memory
    deleteList(tempHead);
  } else {
    // deallocate memory
    deleteList(tempHead);
    // if no results
    cout << "No results found" << endl << endl;
  };
};

// insert
void insertTCToEnd(TuitionCentre *&tcHead, TuitionCentre *&tcTail, int tcCode, string tcName) {
  // initialise
  TuitionCentre *newTuition = new TuitionCentre(tcCode, tcName);

  if (tcHead) {
    // link new tutor to tail tutor
    newTuition->setPrevious(tcTail);
    // link tail tutor to new tutor
    tcTail->setNext(newTuition);
    // tail is new tutor
    tcTail = newTuition;
  } else {
    // insert new tutor as there are no existing tutors
    tcHead = newTuition;
    tcTail = newTuition;
  };
};
void insertSubToEnd(Subject *&subHead, Subject *&subTail, int subCode, string subName) {
  // initialise
  Subject *newSubject = new Subject(subCode, subName);

  if (subHead) {
    // link new tutor to tail tutor
    newSubject->setPrevious(subTail);
    // link tail tutor to new tutor
    subTail->setNext(newSubject);
    // tail is new tutor
    subTail = newSubject;
  } else {
    // insert new tutor as there are no existing tutors
    subHead = newSubject;
    subTail = newSubject;
  };
};
void insertTutorToEnd(Tutor *&head, Tutor *&tail, Tutor tutor) {
  // initialise
  Tutor *newTutor = new Tutor(tutor.getTutorID(), tutor.getName(), tutor.getDateJoined(), tutor.getDateTerminated(), tutor.getHourlyPayRate(), tutor.getPhone(), tutor.getAddress(), tutor.getTuitionCentreCode(), tutor.getSubjectCode(), tutor.getRating());

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
void insertTutorToEnd(Tutor *&head, Tutor *&tail, int tutorID, string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, string phone, string address, int tuitionCentreCode, int subjectCode, int rating) {
  // initialise
  Tutor *newTutor = new Tutor(tutorID, name, dayJoined, monthJoined, yearJoined, dayTerminated, monthTerminated, yearTerminated, hourlyPayRate, phone, address, tuitionCentreCode, subjectCode, rating);

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
  slow->setNext(nullptr);
};

void mergesortID(Tutor *&head) {
  // initialise
  Tutor *current = head, *list1 = nullptr, *list2 = nullptr;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortID(list1);
    // sort sublist 2
    mergesortID(list2);
    // merge sublists
    head = mergeID(list1, list2);
  };
  current = nullptr;
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
    list1->setPrevious(nullptr);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergeID(list1, list2->getNext()));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(nullptr);
    // return address of sublist 2
    return list2;
  };
};

void mergesortRating(Tutor *&head) {
  // initialise
  Tutor *current = head, *list1 = nullptr, *list2 = nullptr;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortRating(list1);
    // sort sublist 2
    mergesortRating(list2);
    // merge sublists
    head = mergeRating(list1, list2);
  };
  current = nullptr;
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
    list1->setPrevious(nullptr);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergeRating(list1, list2->getNext()));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(nullptr);
    // return address of sublist 2
    return list2;
  };
};

void mergesortPayRate(Tutor *&head) {
  // initialise
  Tutor *current = head, *list1 = nullptr, *list2 = nullptr;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortPayRate(list1);
    // sort sublist 2
    mergesortPayRate(list2);
    // merge sublists
    head = mergePayRate(list1, list2);
  };
  current = nullptr;
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
    list1->setPrevious(nullptr);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergePayRate(list1, list2->getNext()));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(nullptr);
    // return address of sublist 2
    return list2;
  };
};

void mergesortTCName(Tutor *&head, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
  // initialise
  Tutor *current = head, *list1 = nullptr, *list2 = nullptr;

  if (current && current->getNext()) {
    split(current, list1, list2);
    // sort sublist 1
    mergesortTCName(list1, tcName, tcHead, tcTail, lastTCCode, tcSize);
    // sort sublist 2
    mergesortTCName(list2, tcName, tcHead, tcTail, lastTCCode, tcSize);
    // merge sublists
    head = mergeTCName(list1, list2, tcName, tcHead, tcTail, lastTCCode, tcSize);
  };
  current = nullptr;
};
Tutor *mergeTCName(Tutor *list1, Tutor *list2, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
  if (list1) {
    // find tutors with searched tuition name
    if (findInsensitive(list1->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
      // deallocate memory
      deleteList(list1);
      if (list2 && findInsensitive(list2->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
        deleteList(list2);
        list2 = nullptr;
      };
      return list2;
    };
  } else {
    // return address of sublist 2 as sublist 1 is empty
    return list2;
  };

  if (list2) {
    // find tutors with searched tuition name
    if (findInsensitive(list2->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
      // deallocate memory
      deleteList(list2);
      if (list1 && findInsensitive(list1->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
        deleteList(list1);
        list1 = nullptr;
      };
      return list1;
    };
  } else {
    // return address of sublist 1 as sublist 2 is empty
    return list1;
  };

  if (compareInsensitive(list1->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), list2->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize)) <= 0) {
    // link sublist 1 to sublist 2
    list1->setNext(mergeTCName(list1->getNext(), list2, tcName, tcHead, tcTail, lastTCCode, tcSize));
    // link sublist 2 to sublist 1
    list1->getNext()->setPrevious(list1);
    list1->setPrevious(nullptr);
    // return address of sublist 1
    return list1;
  } else {
    // link sublist 2 to sublist 1
    list2->setNext(mergeTCName(list1, list2->getNext(), tcName, tcHead, tcTail, lastTCCode, tcSize));
    // link sublist 1 to sublist 2
    list2->getNext()->setPrevious(list2);
    list2->setPrevious(nullptr);
    // return address of sublist 2
    return list2;
  };
};
