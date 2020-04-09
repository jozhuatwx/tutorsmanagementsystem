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
    return this->next;
  };
  void setNext(Tutor *next) {
    this->next = next;
  };
  Tutor *getPrevious() {
    return this->previous;
  };
  void setPrevious(Tutor *previous) {
    this->previous = previous;
  };
};

// function headers
void generateTutors(Tutor *&head, Tutor *&tail, int *lastID, int *size);
void addTutor(Tutor *&head, Tutor *&tail, int *lastID, int *size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating);
void modifyTutor(Tutor *head, int size, int tutorID);
void terminateTutor(Tutor *head, int size, int tutorID);
void deleteTutor(Tutor *head, int *size, int tutorID);

void displayRecord(Tutor tutor);
void displayAllRecords(Tutor *head, Tutor *tail, int size);

void sortTutorID(Tutor *head, int size);
void sortRating(Tutor *head, int size);
void sortPayRate(Tutor *head, int size);

void searchTutorID(Tutor *head, int size, int tutorID);
void searchRating(Tutor *head, int size, int rating);
void searchTuitionName(Tutor *head, int size, string tcName);

// insert
void insertToEnd(Tutor *&head, Tutor *&tail, int *size, int tutorID, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating);


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
          modifyTutor(head, size, tutorID);
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
          terminateTutor(head, size, tutorID);
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
          deleteTutor(head, &size, tutorID);
          break;
        };

        // display records
      case 5:
        cout << "Display Records (Name (Asc))" << endl;
        cout << "---------------------------------------" << endl;
        displayAllRecords(head, tail, size);
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
              searchTutorID(head, size, tutorID);
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
              searchRating(head, size, rating);
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
  *lastID = 13;

  insertToEnd(head, tail, size, 2, "Aaron", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, size, 1, "Bill", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 4, "Charlie", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 3, "Edwin", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 8, "George", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  insertToEnd(head, tail, size, 10, "Jamal", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 5, "Kenny", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 9, "Maria", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 7, "Patricia", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, size, 6, "Shelby", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);

  insertToEnd(head, tail, size, 11, "Maria", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 12, "Patricia", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, size, 13, "Shelby", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
  insertToEnd(head, tail, size, 14, "George", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  insertToEnd(head, tail, size, 15, "Jamal", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 16, "Kenny", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 17, "Aaron", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, size, 18, "Bill", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 19, "Charlie", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 20, "Edwin", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);

  insertToEnd(head, tail, size, 21, "Maria", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 22, "Patricia", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, size, 23, "Shelby", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
  insertToEnd(head, tail, size, 24, "George", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Laksamana", "S0001", "Science", 2);
  insertToEnd(head, tail, size, 25, "Jamal", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0004", "Sri Petaling", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 26, "Kenny", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 3);
  insertToEnd(head, tail, size, 27, "Aaron", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0002", "Bukit Jalil", "S0001", "Science", 5);
  insertToEnd(head, tail, size, 28, "Bill", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 29, "Charlie", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0001", "Taman Durian", "S0001", "Science", 4);
  insertToEnd(head, tail, size, 30, "Edwin", 2, 3, 2000, 50.00, "0123456789", "Somewhere", "C0003", "Bukit Bintang", "S0001", "Science", 4);
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
      // allocate memory
      Tutor *temp = head;

      while (temp->getNext()) {
        if (compareInsensitive(name, temp->getNext()->getName()) < 0)
          // new tutor is before next existing tutor, stop iteration
          break;
        temp = temp->getNext();
      };

      if (temp->getNext())
        // link new tutor to next tutor
        newTutor->setNext(temp->getNext());
      else
        // tail is new tutor
        tail = newTutor;

      // link next tutor to new tutor
      temp->getNext()->setPrevious(newTutor);
      // link current tutor to new tutor
      temp->setNext(newTutor);
      // link new tutor to current tutor
      newTutor->setPrevious(temp);

      // deallocate memory
      delete temp;
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
void modifyTutor(Tutor *head, int size, int tutorID) {};
void terminateTutor(Tutor *head, int size, int tutorID) {};
void deleteTutor(Tutor *head, int *size, int tutorID) {};

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
void displayAllRecords(Tutor *head, Tutor *tail, int size) {
  // initialise
  int page = 1, input = 0;
  Tutor *temp = head;

  // calculate total page numbers
  int total = size / 10;
  if (size % 10 > 0)
    total++;

  // display page
  do {
    if (input != 1) {
      cout << "ID    Name             Pay    Tuition Centre       Rating" << endl;
      cout << "---------------------------------------------------------" << endl;
      for (int i = 0; i < 10 && temp; i++) {
        // print list of tutors
        cout.width(4);
        cout << right << temp->getTutorID() << "  ";
        cout.width(15);
        cout << left << temp->getName() << "  ";
        cout.width(5);
        cout << temp->getHourlyPayRate() << "  ";
        cout.width(19);
        cout << temp->getTuitionCentreName() << "  ";
        cout << temp->getRating() << endl;

        temp = temp->getNext();
      };
      if (!temp)
        temp = tail;
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
          searchTutorID(head, size, tutorID);
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
              for (int i = 0; i < 10 * (oldPage - page + 1) && temp; i++)
                temp = temp->getPrevious();
              if (!temp)
                temp = head;
            } else {
              // go to next tutors
              for (int i = 0; i < 10 * (page - oldPage - 1); i++)
                temp = temp->getNext();
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
        for (int i = 0; i < 20 && temp; i++)
          temp = temp->getPrevious();
        if (!temp)
          temp = head;
        cout << endl;
        break;

      default:
        cout << endl;
        break;
    };
  } while (input != 5);
};

void sortTutorID(Tutor *head, int size) {};
void sortRating(Tutor *head, int size) {};
void sortPayRate(Tutor *head, int size) {};

void searchTutorID(Tutor *head, int size, int tutorID) {};
void searchRating(Tutor *head, int size, int rating) {};
void searchTuitionName(Tutor *head, int size, string tcName) {};

// insert
void insertToEnd(Tutor *&head, Tutor *&tail, int *size, int tutorID, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, string tcCode, string tcName, string subCode, string subName, int rating) {
  Tutor *newTutor = new Tutor(tutorID, name, day, month, year, 0, 0, 0, hourlyPayRate, phone, address, tcCode, tcName, subCode, subCode, rating);

  if (head) {
    // allocate memory
    Tutor *temp = tail;

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

  // increase tutor size
  *size += 1;
};
