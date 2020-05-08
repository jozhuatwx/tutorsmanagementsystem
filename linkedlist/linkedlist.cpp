#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include "../datec.h"
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
  void setTuitionCentreName(string tuitionCentreName) {
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
  void setSubjectName(string subjectName) {
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
      current = tcHead;
      // linear search from beginning to find tuition
      for (int i = 0; i < tcSize - 1 && current; i++, current = current->getNext())
        // find tuition with tuition code
        if (current->getTuitionCentreCode() == tuitionCentreCode)
          return current->getTuitionCentreName();
    } else {
      current = tcTail;
      // linear search from end to find tuition
      for (int i = tcSize - 1; i >= 0 && current; i--, current = current->getPrevious())
        // find tuition with tuition code
        if (current->getTuitionCentreCode() == tuitionCentreCode)
          return current->getTuitionCentreName();
    };
    return "Record missing";
  };
  int getSubjectCode() {
    return subjectCode;
  };
  string getSubjectName(Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
    // initialise
    Subject *current = nullptr;
    // guess which end is faster
    if (subjectCode < lastSubCode / 2) {
      current = subHead;
      // linear search from beginning to find subject
      for (int i = 0; i < subSize - 1 && current; i++, current = current->getNext())
        // find subject with subject code
        if (current->getSubjectCode() == subjectCode)
          return current->getSubjectName();
    } else {
      current = subTail;
      // linear search from end to find subject
      for (int i = subSize - 1; i >= 0 && current; i--, current = current->getPrevious())
        // find subject with subject code
        if (current->getSubjectCode() == subjectCode)
          return current->getSubjectName();
    };
    return "Record missing";
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
void generateData(Tutor *&head, Tutor *&tail, int &lastID, int &size, TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize);
// tutors
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

// tuition centres
bool validateTuitionCentre(int tcCode, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize);

void addTuitionCentre(TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, string tcName);
void modifyTuitionCentre(TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, int tcCode);
void deleteTuitionCentre(Tutor *head, TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, int tcCode);

void displayTC(TuitionCentre tuition);
void displayTCList(TuitionCentre *tcHead, int tcSize);

// subjects
bool validateSubject(int subCode, Subject *subHead, Subject *subTail, int lastSubCode, int subSize);

void addSubject(Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize, string subName);
void modifySubject(Subject *subHead, Subject *subTail, int lastSubCode, int subSize, int subCode);
void deleteSubject(Tutor *head, Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize, int subCode);

void displaySub(Subject subject);
void displaySubList(Subject *subHead, int subSize);


// delete
void deleteList(Tutor *head);

// mergesort
void split(Tutor *head, Tutor *&listHead1, Tutor *&listHead2);

void mergesortID(Tutor *&head);
Tutor *mergeID(Tutor *listHead1, Tutor *listHead2);

void mergesortRating(Tutor *&head);
Tutor *mergeRating(Tutor *listHead1, Tutor *listHead2);

void mergesortPayRate(Tutor *&head);
Tutor *mergePayRate(Tutor *listHead1, Tutor *listHead2);

void mergesortTCName(Tutor *&head, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize);
Tutor *mergeTCName(Tutor *listHead1, Tutor *listHead2, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize);


int main() {
  // initialise
  int size = 0, lastID = 0, tcSize = 0, lastTCCode = 0, subSize = 0, lastSubCode = 0;
  Tutor *head = nullptr, *tail = nullptr;
  TuitionCentre *tcHead = nullptr, *tcTail = nullptr;
  Subject *subHead = nullptr, *subTail = nullptr;
  int input = 0, subinput = 0;
  char cinput = ' ';

  // generate hardcoded data
  generateData(head, tail, lastID, size, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

  // set cout to always display two decimals for doubles
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  // menu
  do {
    cout << "-------------------------------------------" << endl;
    cout << "Tutor Management System (Linked List 2.2.4)" << endl;
    cout << "-------------------------------------------" << endl;
    cout << " (1) Add Tutor" << endl;
    cout << " (2) Modify Tutor" << endl;
    cout << " (3) Terminate Tutor" << endl;
    cout << " (4) Delete Tutor" << endl;
    cout << " (5) Display Records" << endl;
    cout << " (6) Sort and Display Records" << endl;
    cout << " (7) Search Tutors" << endl;
    cout << " (8) Manage Tuition Centres" << endl;
    cout << " (9) Manage Subjects" << endl;
    cout << "(10) Exit" << endl;

    // get user input
    do {
      cout << "Select function (1-10): ";
      // ignore enter key
      if (cin.peek() != '\n')
        cin >> input;
      // clear error state
      if (!cin)
        cin.clear();
      // clear the input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (input < 1 || input > 10);
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
            int width = 19;

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
              cout.width(width);
              cout << left << "Tuition Centre Code" << ": ";
              // ignore enter key
              if (cin.peek() != '\n')
                cin >> tcCode;
              // clear error state
              if (!cin)
                cin.clear();
              // clear the input buffer
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (tcCode < 0 || tcCode > lastTCCode || !validateTuitionCentre(tcCode, tcHead, tcTail, lastTCCode, tcSize));

            // subject code
            do {
              cout.width(width);
              cout << left << "Subject Code" << ": ";
              // ignore enter key
              if (cin.peek() != '\n')
                cin >> subCode;
              // clear error state
              if (!cin)
                cin.clear();
              // clear the input buffer
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (subCode < 0 || subCode > lastSubCode || !validateSubject(subCode, subHead, subTail, lastSubCode, subSize));

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
          } while (tutorID <= 0);
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
          } while (tutorID <= 0);
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
          } while (tutorID <= 0);
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
              } while (tutorID <= 0);
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

        // manage tuition centres
      case 8:
        cout << "(1) Add Tuition Centre" << endl;
        cout << "(2) Modify Tuition Centre" << endl;
        cout << "(3) Delete Tuition Centre" << endl;
        cout << "(4) Display Tuition Centres" << endl;
        cout << "(5) Exit" << endl;

        // get user input
        do {
          cout << "Select function (1-5): ";
          // ignore enter key
          if (cin.peek() != '\n')
            cin >> subinput;
          // clear error state
          if (!cin)
            cin.clear();
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (subinput < 1 || subinput > 5);
        cout << endl;

        // determine outcome
        switch (subinput) {
            // add tuition centre
          case 1:
            {
              cout << "Add Tuition Centre" << endl;
              cout << "----------------------------" << endl;

              // initialise
              string tcName = "";

              // get user input
              do {
                cout << "Tuition Centre Name: ";
                getline(cin, tcName);
                trim(tcName);
              } while (tcName == "");
              addTuitionCentre(tcHead, tcTail, lastTCCode, tcSize, tcName);
              break;
            };

            // modify tuition centre
          case 2:
            {
              // initialise
              int tcCode = 0;
              // get user input
              do {
                cout << "Modify Tuition Centre (Code): ";
                // ignore enter key
                if (cin.peek() != '\n')
                  cin >> tcCode;
                // clear error state
                if (!cin)
                  cin.clear();
                // clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              } while (tcCode < 0);
              cout << "----------------------------" << endl;
              modifyTuitionCentre(tcHead, tcTail, lastTCCode, tcSize, tcCode);
              break;
            };

            // delete tuition centre
          case 3:
            {
              // initialise
              int tcCode = 0;
              // get user input
              do {
                cout << "Delete Tuition Centre (Code): ";
                // ignore enter key
                if (cin.peek() != '\n')
                  cin >> tcCode;
                // clear error state
                if (!cin)
                  cin.clear();
                // clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              } while (tcCode < 0);
              cout << "----------------------------" << endl;
              deleteTuitionCentre(head, tcHead, tcTail, lastTCCode, tcSize, tcCode);
              break;
            };

            // display tuition centres
          default:
            cout << "Display Tuition Centres" << endl;
            cout << "----------------------------" << endl;
            displayTCList(tcHead, tcSize);
            break;
        };
        break;

        // manage subjects
      case 9:
        cout << "(1) Add Subject" << endl;
        cout << "(2) Modify Subject" << endl;
        cout << "(3) Delete Subject" << endl;
        cout << "(4) Display Subjects" << endl;
        cout << "(5) Exit" << endl;

        // get user input
        do {
          cout << "Select function (1-5): ";
          // ignore enter key
          if (cin.peek() != '\n')
            cin >> subinput;
          // clear error state
          if (!cin)
            cin.clear();
          // clear the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (subinput < 1 || subinput > 5);
        cout << endl;

        // determine outcome
        switch (subinput) {
            // add subject
          case 1:
            {
              cout << "Add Subject" << endl;
              cout << "----------------------------" << endl;

              // initialise
              string subName = "";

              // get user input
              do {
                cout << "Subject Name: ";
                getline(cin, subName);
                trim(subName);
              } while (subName == "");
              addSubject(subHead, subTail, lastSubCode, subSize, subName);
              break;
            };

            // modify subject
          case 2:
            {
              // initialise
              int subCode = 0;
              // get user input
              do {
                cout << "Modify Subject (Code): ";
                // ignore enter key
                if (cin.peek() != '\n')
                  cin >> subCode;
                // clear error state
                if (!cin)
                  cin.clear();
                // clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              } while (subCode < 0);
              cout << "----------------------------" << endl;
              modifySubject(subHead, subTail, lastSubCode, subSize, subCode);
              break;
            };

            // delete subject
          case 3:
            {
              // initialise
              int subCode = 0;
              // get user input
              do {
                cout << "Delete Subject (Code): ";
                // ignore enter key
                if (cin.peek() != '\n')
                  cin >> subCode;
                // clear error state
                if (!cin)
                  cin.clear();
                // clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              } while (subCode < 0);
              cout << "----------------------------" << endl;
              deleteSubject(head, subHead, subTail, lastSubCode, subSize, subCode);
              break;
            };

            // display subjects
          default:
            cout << "Display Subjects" << endl;
            cout << "----------------------------" << endl;
            displaySubList(subHead, subSize);
            break;
        };
        break;

        // exit program
      case 10:
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
  } while (input != 10);
  return 0;
};

void generateData(Tutor *&head, Tutor *&tail, int &lastID, int &size, TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize) {
  // generate tuition centres
  tcSize = lastTCCode = 10;

  string tcNames[]{"Bukit Bintang", "Sri Petaling", "Bukit Petaling", "Taman Laksamana", "Taman Durian", "Bukit Jalil", "Taman Mutiara", "Pandan Perdana", "Taman Midah", "Pandan Indah"};

  for (int i = 0; i < tcSize; i++)
    insertTCToEnd(tcHead, tcTail, i + 1, tcNames[i]);

  // generate subjects
  subSize = lastSubCode = 10;

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
// tutors
void addTutor(Tutor *&head, Tutor *&tail, int &lastID, int &size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, int tcCode, int subCode, int rating) {
  // initialise
  int tutorID = lastID + 1;

  Tutor *newTutor = new Tutor(tutorID, name, day, month, year, 0, 0, 0, hourlyPayRate, phone, address, tcCode, subCode, rating);

  // insertion sort to insert new tutor
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

      // linear search to identify the insertion point of the new tutor 
      for (; current->getNext(); current = current->getNext())
        if (compareInsensitive(name, current->getNext()->getName()) < 0)
          // new tutor is before next existing tutor, stop iteration
          break;

      // check if current is not last tutor
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
  Tutor *current = head;

  // linear search through the list to find the tutor to modify
  for (; current; current = current->getNext())
    // find tutor with searched id
    if (current->getTutorID() == tutorID)
      // stop iteration
      break;

  // check if the tutor is found
  if (current) {
    // display record
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // get user input
    cout << "Modify:" << endl;
    cout << "(1) Phone" << endl;
    cout << "(2) Address" << endl;
    cout << "(3) Both" << endl;
    do {
      cout << "Select function (1-3): ";
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
      // get user input
      do {
        cout << "New Phone: ";
        getline(cin, phone);
        trim(phone);
      } while (phone == "");
      current->setPhone(phone);
    };

    // modify address
    if (input == 2 || input == 3) {
      // get user input
      do {
        cout << "New Address: ";
        getline(cin, address);
        trim(address);
      } while (address == "");
      current->setAddress(address);
    };

    // display success message
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
  Tutor *current = head;

  // linear search through the list to find the tutor to terminate
  for (; current; current = current->getNext())
    // find tutor with searched id
    if (current->getTutorID() == tutorID)
      // stop iteration
      break;

  // check if tutor is found
  if (current) {
    // display record
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // check if tutor is terminated
    if (current->getDateTerminated() != -1) {
      // get user input
      do {
        cout << "Tutor is already terminated. Modify termination date? (Y/N): ";
        cin >> cinput;
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');
    } else {
      cinput = 'y';
    };

    // check if terminate the tutor
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
        // check if the termination date is not set
        if (current->getDateTerminated() == -1)
          cout << "Terminate tutor? (Y/N): ";
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
  Tutor *current = head;

  // linear search through the list to find the tutor to delete
  for (; current; current = current->getNext())
    // find tutor with searched id
    if (current->getTutorID() == tutorID)
      // stop iteration
      break;

  // check if the tutor is found
  if (current) {
    // display record
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

    // check if tutor is terminated
    if (current->getDateTerminated() != -1) {
      // check if terminated date has reached at least 6 months
      tm tmTerminated;
      time_t dateTerminated = current->getDateTerminated();
      localtime_s(&tmTerminated, &dateTerminated);

      // add 6 months to terminated date
      if (tmTerminated.tm_mon >= 6) {
        // if it is past July, add 1 year and minus 6 months
        tmTerminated.tm_mon -= 6;
        tmTerminated.tm_year += 1;
      } else {
        tmTerminated.tm_mon += 6;
      };

      // check if terminated date plus 6 months before current date
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
            // check if current is not last tutor
            if (current->getNext())
              // link next tutor to previous tutor
              current->getNext()->setPrevious(current->getPrevious());
            else
              // tail is previous tutor
              tail = current->getPrevious();

            // check if current is not first tutor
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
  // display a tutor record
  cout << "ID                 : " << tutor.getTutorID() << endl;
  cout << "Name               : " << tutor.getName() << endl;
  tm tmJoined;
  time_t dateJoined = tutor.getDateJoined();
  localtime_s(&tmJoined, &dateJoined);
  cout << "Date Joined        : " << tmJoined.tm_mday << "/" << tmJoined.tm_mon + 1 << "/" << tmJoined.tm_year + 1900 << endl;
  cout << "Date Terminated    : ";
  // check if the tutor is terminated
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
  // check if there is tutor
  if (head) {
    // initialise
    int page = 1, input = 0, i = 0;
    Tutor *current = head;

    // identify the page of the selected tutor
    for (; index >= 10; index -= 10) {
      // transverse 10 nodes
      for (int i = 0; i < 10; i++)
        current = current->getNext();
      // increment the page
      page++;
    };

    // calculate total page numbers
    int total = size / 10;
    // check if there are remainders
    if (size % 10 > 0)
      // increment total pages
      total++;

    // display page
    do {
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

        // check if current is not last tutor
        if (current->getNext())
          current = current->getNext();
        else
          // break when last element
          break;
      };
      // display page number
      cout << endl << "Page " << page << endl << endl;

      cout << "(1) Detailed view" << endl;
      
      cout << "(2) Jump to page";
      // disable if there is only 1 page
      if (total == 1)
        cout << " (disabled)";
      
      cout << endl << "(3) Next page";
      // disable if there is no next page
      if (page >= total)
        cout << " (disabled)";
      
      cout << endl << "(4) Previous page";
      // disable if there is no previous page
      if (page <= 1)
        cout << " (disabled)";
      
      cout << endl << "(5) Exit" << endl;
      
      // get user input
      do {
        cout << "Select function (1-5): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        // clear error state
        if (!cin)
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > 5 || (input == 2 && total == 1) || (input == 3 && page >= total) || (input == 4 && page <= 1));

      // determine outcome
      switch (input) {
        // jump to page
        case 2:
          if (total > 1) {
            int oldPage = page;

            // get user input
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

            // check if page is before or equal to new page
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

          // next page
        case 3:
          if (page < total)
            // increment page
            page++;
          break;

          // previous page
        case 4:
          if (page > 1) {
            // go to previous tutors
            for (int x = 0; x < 10 + i; x++)
              current = current->getPrevious();
            // decrement page
            page--;
          };
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
  // check if there is tutor
  if (head) {
    // initialise
    Tutor *current = nullptr;
    int input = 2, tutorID = 0, index = 0;

    do {
      // jump to record
      if (input == 2) {
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
          } while (tutorID <= 0);

          // linear search through the list to find the tutor to display
          for (current = head, index = 0; current; index++, current = current->getNext())
            // find tutor with searched id
            if (current->getTutorID() == tutorID)
              // stop iteration
              break;

          // check if the tutor is found
        } while (!current);
      };

      // display result
      cout << "-------------------------------------" << endl;
      displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);

      cout << "(1) List view" << endl;

      cout << "(2) Jump to record";
      // disable if there is only 1 tutor
      if (size == 1)
        cout << " (disabled)";
      
      cout << endl << "(3) Next record";
      // disable if there is no next tutor
      if (!current->getNext())
        cout << " (disabled)";
      
      cout << endl << "(4) Previous record";
      // disable if there is no previous tutor
      if (!current->getPrevious())
        cout << " (disabled)";
      
      cout << endl << "(5) Exit" << endl;
      
      // get user input
      do {
        cout << "Select function (1-5): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        // clear error state
        if (!cin)
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > 5 || (input == 2 && size == 1) || (input == 3 && !current->getNext()) || (input == 4 && !current->getPrevious()));

      // determine outcome
      switch (input) {
        // next record
        case 3:
          if (current->getNext()) {
            // go to next record
            current = current->getNext();
            // increment index
            index++;
          };
          break;

          // previous record
        case 4:
          if (current->getPrevious()) {
            // go to previous record
            current = current->getPrevious();
            // decrement index
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
  // check if there is tutor
  if (head) {
    // initialise
    Tutor *tempHead = nullptr, *tempTail = nullptr;

    // copy all elements into temporary tutor list
    for (Tutor *current = head; current; current = current->getNext())
      insertTutorToEnd(tempHead, tempTail, *current);

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
  // check if there is tutor
  if (head) {
    // initialise
    Tutor *tempHead = nullptr, *tempTail = nullptr;

    // copy all elements into temporary tutor list
    for (Tutor *current = head; current; current = current->getNext())
      insertTutorToEnd(tempHead, tempTail, *current);

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
  // check if there is tutor
  if (head) {
    // initialise
    Tutor *tempHead = nullptr, *tempTail = nullptr;

    // copy all elements into temporary tutor list
    for (Tutor *current = head; current; current = current->getNext())
      insertTutorToEnd(tempHead, tempTail, *current);

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

  // linear seaarch through the list to find the tutor
  for (; current; current = current->getNext())
    // find tutor with searched id
    if (current->getTutorID() == tutorID)
      // stop iteration
      break;

  // check if the tutor is found
  if (current)
    // display result
    displayRecord(*current, tcHead, tcTail, lastTCCode, tcSize, subHead, subTail, lastSubCode, subSize);
  else
    // if no results
    cout << "No results found" << endl << endl;
  current = nullptr;
};
void searchRating(Tutor *head, int rating, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  int tempSize = 0;
  Tutor *current = head, *tempHead = nullptr, *tempTail = nullptr;

  // linear search through the list to find the tutor with the rating
  for (; current; current = current->getNext())
    // find tutors with searched rating
    if (current->getRating() == rating) {
      // insert tutor to the end of the temporary tutor list
      insertTutorToEnd(tempHead, tempTail, *current);
      // increase temporary list size
      tempSize++;
    };

  // check if the tutor is found
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
  for (; current; current = current->getNext())
    insertTutorToEnd(tempHead, tempTail, *current);

  // sort the temporary tutor list by tuition name and find tuition with searched tuition name
  mergesortTCName(tempHead, tcName, tcHead, tcTail, lastTCCode, tcSize);

  // linear search through the list to create a temporary tuition list
  for (current = tempHead; current; current = current->getNext())
    // check if the temporary tuition list is empty
    if (tempTCHead) {
      bool exist = false;
      tempTuitions = tempTCHead;

      // linear search through the temporary tuition list to find the tuition
      while (tempTuitions) {
        // find tuition with tuition code
        if (current->getTuitionCentreCode() == tempTuitions->getTuitionCentreCode()) {
          // tuition name exists
          exist = true;
          // stop iteration
          break;
        };

        // check if current is not last tuition in the temporary tuition list
        if (tempTuitions->getNext())
          tempTuitions = tempTuitions->getNext();
        else
          // break when last element
          break;
      };

      // check if the tuition from the temporary tutor list exists in the temporary tuition list
      if (!exist)
        // link tuition name to new tuition name
        tempTuitions->setNext(new TuitionCentre(current->getTuitionCentreCode(), current->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize)));
    } else {
      // insert new tuition name as there are no existing tuition names
      tempTCHead = new TuitionCentre(current->getTuitionCentreCode(), current->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize));
    };

  // check if there is tuition
  if (tempTCHead) {
    // check if there is more than 1 tuition
    if (tempTCHead->getNext()) {
      tempTuitions = tempTCHead;
      int i = 0;
      // display list of tuitions
      for (; tempTuitions; i++, tempTuitions = tempTuitions->getNext())
        cout << "(" << i + 1 << ") " << tempTuitions->getTuitionCentreName() << endl;
      // get user input
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
    
    // get tuition code from the temporary tuition list
    tempTuitions = tempTCHead;
    for (int i = 0; i < input - 1; i++)
      tempTuitions = tempTuitions->getNext();

    current = tempHead;
    // deallocate non-searched results
    while (current && current->getTuitionCentreCode() != tempTuitions->getTuitionCentreCode()) {
      current = current->getNext();
      // deallocate memory
      delete tempHead;
      tempHead = current;
    };
    
    // count total number of tutors
    for (; current && current->getTuitionCentreCode() == tempTuitions->getTuitionCentreCode(); current = current->getNext())
      // increase temporary list size
      tempSize++;

    // check if current is not last tutor
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

// tuition centres
bool validateTuitionCentre(int tcCode, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
  // initialise
  TuitionCentre *current = nullptr;
  // guess which end is faster
  if (tcCode < lastTCCode / 2) {
    current = tcHead;
    // linear search from beginning to find tuition
    for (int i = 0; i < tcSize - 1; i++, current = current->getNext())
      // find tuitions with tuition code
      if (current->getTuitionCentreCode() == tcCode)
        return true;
  } else {
    current = tcTail;
    // linear search from end to find tuition
    for (int i = tcSize; i > 0; i--, current = current->getPrevious())
      // find tuitions with tuition code
      if (current->getTuitionCentreCode() == tcCode)
        return true;
  };
  return false;
};

void addTuitionCentre(TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, string tcName) {
  // initialise
  int tcCode = lastTCCode + 1;

  TuitionCentre *current = tcHead;

  // linear search through the list to find the tuition
  for (; current; current = current->getNext())
    // find tuitions with new tuition name
    if (compareInsensitive(current->getTuitionCentreName(), tcName) == 0)
      // stop iteration
      break;

  // check if tuition name exists
  if (!current) {
    // insert tuition to the end of the list
    insertTCToEnd(tcHead, tcTail, tcCode, tcName);
    // display success message
    cout << "Added Successfully" << endl << endl;
    // increase tuition size
    tcSize++;
    // increase last tuition code
    lastTCCode++;
  } else {
    cout << endl;
    // display record
    displayTC(*current);
    // display exist message
    cout << "Tuition centre already exists" << endl << endl;
  };
};
void modifyTuitionCentre(TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize, int tcCode) {
  // initialise
  int input = 0;
  string tcName = "";
  TuitionCentre *current = nullptr;

  // guess which end is faster
  if (tcCode < lastTCCode / 2) {
    current = tcHead;
    // linear search from beginning to find the tuition
    for (int i = 0; i < tcSize - 1 && current; i++, current = current->getNext())
      // find tuitions with tuition code
      if (current->getTuitionCentreCode() == tcCode)
        // stop iteration
        break;
  } else {
    current = tcTail;
    // linear search from end to find the tuition
    for (int i = tcSize - 1; i >= 0 && current; i--, current = current->getPrevious())
      // find tuitions with tuition code
      if (current->getTuitionCentreCode() == tcCode)
        // stop iteration
        break;
  };

  // check if the tuition is found
  if (current) {
    // display record
    displayTC(*current);

    // modify tuition name
    // get user input
    do {
      cout << "New Tuition Name: ";
      getline(cin, tcName);
      trim(tcName);
    } while (tcName == "");

    TuitionCentre *temp = tcHead;

    // linear search through the list to find tuition
    for (; temp; temp = temp->getNext())
      // find tuition with new tuition name
      if (compareInsensitive(temp->getTuitionCentreName(), tcName) == 0)
        // stop iteration
        break;

    // check if tuition name exists or if the existing tuition is same as current tuition
    if (!temp || temp->getTuitionCentreCode() == current->getTuitionCentreCode()) {
      current->setTuitionCentreName(tcName);
      // display success message
      cout << "Modified Successfully" << endl << endl;
    } else {
      // display failed message
      cout << "Modification Failed" << endl << endl;
      // display record
      displayTC(*temp);
      // display exist message
      cout << "Tuition centre already exists" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
  current = nullptr;
};
void deleteTuitionCentre(Tutor *head, TuitionCentre *&tcHead, TuitionCentre *&tcTail, int &lastTCCode, int &tcSize, int tcCode) {
  // initialise
  char cinput = ' ';
  TuitionCentre *current = tcHead;

  // guess which end is faster
  if (tcCode < lastTCCode / 2) {
    current = tcHead;
    // linear search from beginning to find tuition
    for (int i = 0; i < tcSize - 1 && current; i++, current = current->getNext())
      // find tuition with tuition code
      if (current->getTuitionCentreCode() == tcCode)
        // stop iteration
        break;
  } else {
    current = tcTail;
    // linear search from end to find tuition
    for (int i = tcSize - 1; i >= 0 && current; i--, current = current->getPrevious())
      // find tuition with tuition code
      if (current->getTuitionCentreCode() == tcCode)
        // stop iteration
        break;
  };

  // check if the tuition is found
  if (current) {
    // display record
    displayTC(*current);

    Tutor *temp = head;
    // linear search through the list to find the tutor
    for (; temp; temp = temp->getNext())
      // find tutor with tuition code
      if (temp->getTuitionCentreCode() == tcCode)
        // stop iteration
        break;

    // check if record is in use
    if (!temp) {
      // ask for confirmation
      do {
        cout << "Permanently delete tuition? (Y/N): ";
        cin >> cinput;
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');

      // determine outcome
      switch (cinput) {
        // delete tutor
        case 'y':
        case 'Y':
          // check if current is not last tuition
          if (current->getNext())
            // link next tuition to previous tuition
            current->getNext()->setPrevious(current->getPrevious());
          else
            // tail is previous tuition
            tcTail = current->getPrevious();

          // check if current is not first tuition
          if (current->getPrevious())
            // link previous tuition to next tuition
            current->getPrevious()->setNext(current->getNext());
          else
            // head is next tuition
            tcHead = current->getNext();

          // deallocate memory
          delete current;

          // display success message
          cout << "Deleted Successfully" << endl << endl;
          // decrease tuition size
          tcSize--;
          break;

          // cancel delete
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };
    } else {
      temp = nullptr;
      // display in use message
      cout << "Tuition centre has tutor(s), please delete tutor(s) first" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void displayTC(TuitionCentre tuition) {
  // display a tuition record
  cout << "Tuition Centre Code: " << tuition.getTuitionCentreCode() << endl;
  cout << "Tuition Centre Name: " << tuition.getTuitionCentreName() << endl;
};
void displayTCList(TuitionCentre *tcHead, int tcSize) {
  // check if there is tuition
  if (tcHead) {
    // initialise
    int page = 1, input = 0, i = 0;
    TuitionCentre *current = tcHead;

    // calculate total page numbers
    int total = tcSize / 10;
    // check if there are remainders
    if (tcSize % 10 > 0)
      // increment total pages
      total++;

    // display page
    do {
      cout << "Code    Tuition Centre Name             " << endl;
      cout << "----------------------------------------" << endl;
      for (i = 0; i < 10; i++) {
        // print list of tuitions
        cout.width(6);
        cout << right << current->getTuitionCentreCode() << "  ";
        cout.width(30);
        cout << left << truncate(current->getTuitionCentreName(), 30) << endl;
        
        // check if current is not last tutor
        if (current->getNext())
          current = current->getNext();
        else
          // break when last element
          break;
      };
      // display page number
      cout << endl << "Page " << page << endl << endl;

      cout << "(1) Jump to page";
      // disable if there is only 1 page
      if (total == 1)
        cout << " (disabled)";
      
      cout << endl << "(2) Next page";
      // disable if there is no next page
      if (page >= total)
        cout << " (disabled)";
      
      cout << endl << "(3) Previous page";
      // disable if there is no previous page
      if (page <= 1)
        cout << " (disabled)";
      
      cout << endl << "(4) Exit" << endl;
      
      // get user input
      do {
        cout << "Select function (1-4): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        // clear error state
        if (!cin)
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > 4 || (input == 1 && total == 1) || (input == 2 && page >= total) || (input == 3 && page <= 1));

      // determine outcome
      switch (input) {
        // jump to page
        case 1:
          if (total > 1) {
            int oldPage = page;

            // get user input
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

            // check if page is before or equal to new page
            if (oldPage >= page) {
              // go to previous tuitions
              for (int x = 0; x < 10 * (oldPage - page + 1) - (10 - i); x++)
                current = current->getPrevious();
            } else {
              // go to next tuitions
              for (int x = 0; x < 10 * (page - oldPage - 1); x++)
                current = current->getNext();
            };
          };
          break;

          // next page
        case 2:
          if (page < total)
            // increment page
            page++;
          break;

          // previous page
        case 3:
          if (page > 1) {
            // go to previous tuitions
            for (int x = 0; x < 10 + i; x++)
              current = current->getPrevious();
            // decrement page
            page--;
          };
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 0 && input < 4);
    current = nullptr;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

// subjects
bool validateSubject(int subCode, Subject *subHead, Subject *subTail, int lastSubCode, int subSize) {
  // initialise
  Subject *current = nullptr;
  // guess which end is faster
  if (subCode < lastSubCode / 2) {
    current = subHead;
    // linear search from beginning to find subject
    for (int i = 0; i < subSize - 1; i++, current = current->getNext())
      // find subject with subject code
      if (current->getSubjectCode() == subCode)
        return true;
  } else {
    current = subTail;
    // linear search from end to find subject
    for (int i = subSize; i > 0; i--, current = current->getPrevious())
      // find subject with subject code
      if (current->getSubjectCode() == subCode)
        return true;
  };
  return false;
};

void addSubject(Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize, string subName) {
  // initialise
  int subCode = lastSubCode + 1;

  Subject *current = subHead;

  // linear search through the list
  for (; current; current = current->getNext())
    if (compareInsensitive(current->getSubjectName(), subName) == 0)
      // stop iteration
      break;

  // check if the subject is found
  if (!current) {
    // insert subject to the end of the list
    insertSubToEnd(subHead, subTail, subCode, subName);
    // display success message
    cout << "Added Successfully" << endl << endl;
    // increase subject size
    subSize++;
    // increase last subject code
    lastSubCode++;
  } else {
    cout << endl;
    // display record
    displaySub(*current);
    // display exist message
    cout << "Subject already exists" << endl << endl;
  };
};
void modifySubject(Subject *subHead, Subject *subTail, int lastSubCode, int subSize, int subCode) {
  // initialise
  int input = 0;
  string subName = "";
  Subject *current = nullptr;

  // guess which end is faster
  if (subCode < lastSubCode / 2) {
    current = subHead;
    // linear search from beginning to find subject
    for (int i = 0; i < subSize - 1 && current; i++, current = current->getNext())
      // find subject with subject code
      if (current->getSubjectCode() == subCode)
        // stop iteration
        break;
  } else {
    current = subTail;
    // linear search from end to find subject
    for (int i = subSize - 1; i >= 0 && current; i--, current = current->getPrevious())
      // find subject with subject code
      if (current->getSubjectCode() == subCode)
        // stop iteration
        break;
  };

  // check if the subject is found
  if (current) {
    // display record
    displaySub(*current);

    // modify subject name
    // get user input
    do {
      cout << "New Subject Name: ";
      getline(cin, subName);
      trim(subName);
    } while (subName == "");

    Subject *temp = subHead;

    // linear search through the list to find subject
    for (; temp; temp = temp->getNext())
      // find subject with new subject name
      if (compareInsensitive(temp->getSubjectName(), subName) == 0)
        // stop iteration
        break;

    // check if subject name exists or if the existing subject is same as current subject
    if (!temp || temp->getSubjectCode() == current->getSubjectCode()) {
      current->setSubjectName(subName);
      // display success message
      cout << "Modified Successfully" << endl << endl;
    } else {
      // display failed message
      cout << "Modification Failed" << endl << endl;
      // display record
      displaySub(*temp);
      // display exist message
      cout << "Subject already exists" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
  current = nullptr;
};
void deleteSubject(Tutor *head, Subject *&subHead, Subject *&subTail, int &lastSubCode, int &subSize, int subCode) {
  // initialise
  char cinput = ' ';
  Subject *current = subHead;

  // guess which end is faster
  if (subCode < lastSubCode / 2) {
    current = subHead;
    // linear search from beginning to find subject
    for (int i = 0; i < subSize - 1 && current; i++, current = current->getNext())
      // find subject with subject code
      if (current->getSubjectCode() == subCode)
        // stop iteration
        break;
  } else {
    current = subTail;
    // linear search from end to find subject
    for (int i = subSize - 1; i >= 0 && current; i--, current = current->getPrevious())
      // find subject with subject code
      if (current->getSubjectCode() == subCode)
        // stop iteration
        break;
  };

  // check if the subject is found
  if (current) {
    // display record
    displaySub(*current);

    Tutor *temp = head;
    // linear search through the list to find the subject
    for (; temp; temp = temp->getNext())
      // find the subject with subject code
      if (temp->getSubjectCode() == subCode)
        // stop iteration
        break;

    // check if record is in use
    if (!temp) {
      // ask for confirmation
      do {
        cout << "Permanently delete subject? (Y/N): ";
        cin >> cinput;
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (cinput != 'y' && cinput != 'Y' && cinput != 'n' && cinput != 'N');

      // determine outcome
      switch (cinput) {
        // delete tutor
        case 'y':
        case 'Y':
          // check if current is not last subject
          if (current->getNext())
            // link next subject to previous subject
            current->getNext()->setPrevious(current->getPrevious());
          else
            // tail is previous subject
            subTail = current->getPrevious();

          // check if current is not first subject
          if (current->getPrevious())
            // link previous subject to next subject
            current->getPrevious()->setNext(current->getNext());
          else
            // head is next subject
            subHead = current->getNext();

          // deallocate memory
          delete current;

          // display success message
          cout << "Deleted Successfully" << endl << endl;
          // decrease subject size
          subSize--;
          break;

          // cancel delete
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };
    } else {
      temp = nullptr;
      // display in use message
      cout << "Subject has tutor(s), please delete tutor(s) first" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void displaySub(Subject subject) {
  // display a subject record
  cout << "Subject Code: " << subject.getSubjectCode() << endl;
  cout << "Subject Name: " << subject.getSubjectName() << endl;
};
void displaySubList(Subject *subHead, int subSize) {
  // check if there is subject
  if (subHead) {
    // initialise
    int page = 1, input = 0, i = 0;
    Subject *current = subHead;

    // calculate total page numbers
    int total = subSize / 10;
    // check if there are remainders
    if (subSize % 10 > 0)
      // increment toal pages
      total++;

    // display page
    do {
      cout << "Code    Subject Name                    " << endl;
      cout << "----------------------------------------" << endl;
      for (i = 0; i < 10; i++) {
        // print list of subjects
        cout.width(6);
        cout << right << current->getSubjectCode() << "  ";
        cout.width(30);
        cout << left << truncate(current->getSubjectName(), 30) << endl;

        // check if current is not last tutor
        if (current->getNext())
          current = current->getNext();
        else
          // break when last element
          break;
      };
      // display page number
      cout << endl << "Page " << page << endl << endl;

      cout << "(1) Jump to page";
      // disable if there is only 1 page
      if (total == 1)
        cout << " (disabled)";

      cout << endl << "(2) Next page";
      // disable if there is no next page
      if (page >= total)
        cout << " (disabled)";

      cout << endl << "(3) Previous page";
      // disable if there is no previous page
      if (page <= 1)
        cout << " (disabled)";

      cout << endl << "(4) Exit" << endl;

      // get user input
      do {
        cout << "Select function (1-4): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        // clear error state
        if (!cin)
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > 4 || (input == 1 && total == 1) || (input == 2 && page >= total) || (input == 3 && page <= 1));

      // determine outcome
      switch (input) {
        // jump to page
        case 1:
          if (total > 1) {
            int oldPage = page;

            // get user input
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

            // check if page is before or equal to new page
            if (oldPage >= page) {
              // go to previous subjects
              for (int x = 0; x < 10 * (oldPage - page + 1) - (10 - i); x++)
                current = current->getPrevious();
            } else {
              // go to next subjects
              for (int x = 0; x < 10 * (page - oldPage - 1); x++)
                current = current->getNext();
            };
          };
          break;

          // next page
        case 2:
          if (page < total)
            // increment page
            page++;
          break;

          // previous page
        case 3:
          if (page > 1) {
            // go to previous subjects
            for (int x = 0; x < 10 + i; x++)
              current = current->getPrevious();
            // decrement page
            page--;
          };          
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 0 && input < 4);
    current = nullptr;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};


// insert
void insertTCToEnd(TuitionCentre *&tcHead, TuitionCentre *&tcTail, int tcCode, string tcName) {
  // initialise
  TuitionCentre *newTuition = new TuitionCentre(tcCode, tcName);

  if (tcHead) {
    // link new tuition to tail tuition
    newTuition->setPrevious(tcTail);
    // link tail tuition to new tuition
    tcTail->setNext(newTuition);
    // tail is new tuition
    tcTail = newTuition;
  } else {
    // insert new tuition as there are no existing tuitions
    tcHead = newTuition;
    tcTail = newTuition;
  };
};
void insertSubToEnd(Subject *&subHead, Subject *&subTail, int subCode, string subName) {
  // initialise
  Subject *newSubject = new Subject(subCode, subName);

  if (subHead) {
    // link new subject to tail subject
    newSubject->setPrevious(subTail);
    // link tail subject to new subject
    subTail->setNext(newSubject);
    // tail is new subject
    subTail = newSubject;
  } else {
    // insert new subject as there are no existing subjects
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
void split(Tutor *head, Tutor *&listHead1, Tutor *&listHead2) {
  // initialise
  Tutor *fast = head->getNext(), *slow = head;

  // split list into half
  while (fast) {
    fast = fast->getNext();
    if (fast) {
      slow = slow->getNext();
      fast = fast->getNext();
    };
  };

  // return the addresses of the sublists
  listHead1 = head;
  listHead2 = slow->getNext();
  // split sublist 2 from sublist 1
  slow->setNext(nullptr);
};

void mergesortID(Tutor *&head) {
  // initialise
  Tutor *current = head, *listHead1 = nullptr, *listHead2 = nullptr;

  if (current && current->getNext()) {
    split(current, listHead1, listHead2);
    // sort sublist 1
    mergesortID(listHead1);
    // sort sublist 2
    mergesortID(listHead2);
    // merge sublists
    head = mergeID(listHead1, listHead2);
  };
  current = nullptr;
};
Tutor *mergeID(Tutor *listHead1, Tutor *listHead2) {
  if (!listHead1)
    // return address of sublist 2 as sublist 1 is empty
    return listHead2;

  if (!listHead2)
    // return address of sublist 1 as sublist 2 is empty
    return listHead1;

  if (listHead1->getTutorID() < listHead2->getTutorID()) {
    // link sublist 1 to sublist 2
    listHead1->setNext(mergeID(listHead1->getNext(), listHead2));
    // link sublist 2 to sublist 1
    listHead1->getNext()->setPrevious(listHead1);
    listHead1->setPrevious(nullptr);
    // return address of sublist 1
    return listHead1;
  } else {
    // link sublist 2 to sublist 1
    listHead2->setNext(mergeID(listHead1, listHead2->getNext()));
    // link sublist 1 to sublist 2
    listHead2->getNext()->setPrevious(listHead2);
    listHead2->setPrevious(nullptr);
    // return address of sublist 2
    return listHead2;
  };
};

void mergesortRating(Tutor *&head) {
  // initialise
  Tutor *current = head, *listHead1 = nullptr, *listHead2 = nullptr;

  if (current && current->getNext()) {
    split(current, listHead1, listHead2);
    // sort sublist 1
    mergesortRating(listHead1);
    // sort sublist 2
    mergesortRating(listHead2);
    // merge sublists
    head = mergeRating(listHead1, listHead2);
  };
  current = nullptr;
};
Tutor *mergeRating(Tutor *listHead1, Tutor *listHead2) {
  if (!listHead1)
    // return address of sublist 2 as sublist 1 is empty
    return listHead2;

  if (!listHead2)
    // return address of sublist 1 as sublist 2 is empty
    return listHead1;

  if (listHead1->getRating() <= listHead2->getRating()) {
    // link sublist 1 to sublist 2
    listHead1->setNext(mergeRating(listHead1->getNext(), listHead2));
    // link sublist 2 to sublist 1
    listHead1->getNext()->setPrevious(listHead1);
    listHead1->setPrevious(nullptr);
    // return address of sublist 1
    return listHead1;
  } else {
    // link sublist 2 to sublist 1
    listHead2->setNext(mergeRating(listHead1, listHead2->getNext()));
    // link sublist 1 to sublist 2
    listHead2->getNext()->setPrevious(listHead2);
    listHead2->setPrevious(nullptr);
    // return address of sublist 2
    return listHead2;
  };
};

void mergesortPayRate(Tutor *&head) {
  // initialise
  Tutor *current = head, *listHead1 = nullptr, *listHead2 = nullptr;

  if (current && current->getNext()) {
    split(current, listHead1, listHead2);
    // sort sublist 1
    mergesortPayRate(listHead1);
    // sort sublist 2
    mergesortPayRate(listHead2);
    // merge sublists
    head = mergePayRate(listHead1, listHead2);
  };
  current = nullptr;
};
Tutor *mergePayRate(Tutor *listHead1, Tutor *listHead2) {
  if (!listHead1)
    // return address of sublist 2 as sublist 1 is empty
    return listHead2;

  if (!listHead2)
    // return address of sublist 1 as sublist 2 is empty
    return listHead1;

  if (listHead1->getHourlyPayRate() <= listHead2->getHourlyPayRate()) {
    // link sublist 1 to sublist 2
    listHead1->setNext(mergePayRate(listHead1->getNext(), listHead2));
    // link sublist 2 to sublist 1
    listHead1->getNext()->setPrevious(listHead1);
    listHead1->setPrevious(nullptr);
    // return address of sublist 1
    return listHead1;
  } else {
    // link sublist 2 to sublist 1
    listHead2->setNext(mergePayRate(listHead1, listHead2->getNext()));
    // link sublist 1 to sublist 2
    listHead2->getNext()->setPrevious(listHead2);
    listHead2->setPrevious(nullptr);
    // return address of sublist 2
    return listHead2;
  };
};

void mergesortTCName(Tutor *&head, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
  // initialise
  Tutor *current = head, *listHead1 = nullptr, *listHead2 = nullptr;

  if (current && current->getNext()) {
    split(current, listHead1, listHead2);
    // sort sublist 1
    mergesortTCName(listHead1, tcName, tcHead, tcTail, lastTCCode, tcSize);
    // sort sublist 2
    mergesortTCName(listHead2, tcName, tcHead, tcTail, lastTCCode, tcSize);
    // merge sublists
    head = mergeTCName(listHead1, listHead2, tcName, tcHead, tcTail, lastTCCode, tcSize);
  };
  current = nullptr;
};
Tutor *mergeTCName(Tutor *listHead1, Tutor *listHead2, string tcName, TuitionCentre *tcHead, TuitionCentre *tcTail, int lastTCCode, int tcSize) {
  if (listHead1) {
    // find tutors with searched tuition name
    if (findInsensitive(listHead1->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
      // deallocate memory
      deleteList(listHead1);
      if (listHead2 && findInsensitive(listHead2->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
        deleteList(listHead2);
        listHead2 = nullptr;
      };
      return listHead2;
    };
  } else {
    // return address of sublist 2 as sublist 1 is empty
    return listHead2;
  };

  if (listHead2) {
    // find tutors with searched tuition name
    if (findInsensitive(listHead2->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
      // deallocate memory
      deleteList(listHead2);
      if (listHead1 && findInsensitive(listHead1->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), tcName) == string::npos) {
        deleteList(listHead1);
        listHead1 = nullptr;
      };
      return listHead1;
    };
  } else {
    // return address of sublist 1 as sublist 2 is empty
    return listHead1;
  };

  if (compareInsensitive(listHead1->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize), listHead2->getTuitionCentreName(tcHead, tcTail, lastTCCode, tcSize)) <= 0) {
    // link sublist 1 to sublist 2
    listHead1->setNext(mergeTCName(listHead1->getNext(), listHead2, tcName, tcHead, tcTail, lastTCCode, tcSize));
    // link sublist 2 to sublist 1
    listHead1->getNext()->setPrevious(listHead1);
    listHead1->setPrevious(nullptr);
    // return address of sublist 1
    return listHead1;
  } else {
    // link sublist 2 to sublist 1
    listHead2->setNext(mergeTCName(listHead1, listHead2->getNext(), tcName, tcHead, tcTail, lastTCCode, tcSize));
    // link sublist 1 to sublist 2
    listHead2->getNext()->setPrevious(listHead2);
    listHead2->setPrevious(nullptr);
    // return address of sublist 2
    return listHead2;
  };
};
