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

  public:
  // constructor
  TuitionCentre() {
    this->tuitionCentreCode = -1;
    this->tuitionCentreName = "";
  };
  TuitionCentre(int tuitionCentreCode, string tuitionCentreName) {
    this->tuitionCentreCode = tuitionCentreCode;
    this->tuitionCentreName = tuitionCentreName;
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
};
class Subject {
  private:
  int subjectCode;
  string subjectName;

  public:
  // constructor
  Subject() {
    this->subjectCode = -1;
    this->subjectName = "";
  };
  Subject(int subjectCode, string subjectName) {
    this->subjectCode = subjectCode;
    this->subjectName = subjectName;
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
    this->tuitionCentreCode = -1;
    this->subjectCode = -1;
    this->rating = -1;
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
  string getTuitionCentreName(TuitionCentre *tuitions, int tcSize) {
    // binary search through the array to find the tuition
    int low = 0, mid = 0, up = tcSize - 1;
    while (up >= low) {
      // get mid point
      mid = (up - low) / 2 + low;
      // compare
      int comp = tuitions[mid].getTuitionCentreCode();
      if (comp == tuitionCentreCode) {
        // found searched code
        return tuitions[mid].getTuitionCentreName();
      } else if (comp < tuitionCentreCode) {
        // if existing code is before searched code
        low = mid + 1;
      } else if (comp > tuitionCentreCode) {
        // if existing code is after searched code
        up = mid - 1;
      };
    };
    return "Record missing";
  };
  int getSubjectCode() {
    return subjectCode;
  };
  string getSubjectName(Subject *subjects, int subSize) {
    // binary search through the array to find the subject
    int low = 0, mid = 0, up = subSize - 1;
    while (up >= low) {
      // get mid point
      mid = (up - low) / 2 + low;
      // compare
      int comp = subjects[mid].getSubjectCode();
      if (comp == subjectCode) {
        // found searched code
        return subjects[mid].getSubjectName();
      } else if (comp < subjectCode) {
        // if existing code is before searched code
        low = mid + 1;
      } else if (comp > subjectCode) {
        // if existing code is after searched code
        up = mid - 1;
      };
    };
    return "Record missing";
  };
  int getRating() {
    return rating;
  };
};

// function headers
void generateData(Tutor *&tutors, int &lastID, int &size, TuitionCentre *&tuitions, int &lastTCCode, int &tcSize, Subject *&subjects, int &lastSubCode, int &subSize);
// tutors
void addTutor(Tutor *&tutors, int &lastID, int &size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, int tcCode, int subCode, int rating);
void modifyTutor(Tutor *&tutors, int size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void terminateTutor(Tutor *&tutors, int size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void deleteTutor(Tutor *&tutors, int &size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);

void displayRecord(Tutor tutor, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void displayRecordsList(Tutor *tutors, int size, int index, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void displayRecordsDetailed(Tutor *tutors, int size, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);

void sortTutorID(Tutor *tutors, int size, int lastID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void sortRating(Tutor *tutors, int size, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void sortPayRate(Tutor *tutors, int size, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);

void searchTutorID(Tutor *tutors, int size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void searchRating(Tutor *tutors, int size, int rating, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);
void searchTuitionName(Tutor *tutors, int size, string tcName, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize);

// tuition centres
bool validateTuitionCentre(int tcCode, TuitionCentre *tuitions, int lastTCCode, int tcSize);

void addTuitionCentre(TuitionCentre *&tuitions, int &lastTCCode, int &tcSize, string tcName);
void modifyTuitionCentre(TuitionCentre *&tuitions, int tcSize, int tcCode);
void deleteTuitionCentre(Tutor *tutors, int size, TuitionCentre *&tuitions, int &tcSize, int tcCode);

void displayTC(TuitionCentre tuition);
void displayTCList(TuitionCentre *tuitions, int tcSize);

// subjects
bool validateSubject(int subCode, Subject *subjects, int lastSubCode, int subSize);

void addSubject(Subject *&subjects, int &lastSubCode, int &subSize, string subName);
void modifySubject(Subject *&subjects, int subSize, int subCode);
void deleteSubject(Tutor *tutors, int size, Subject *&subjects, int &subSize, int subCode);

void displaySub(Subject subject);
void displaySubList(Subject *subjects, int subSize);


// binary search
int binarySearchName(Tutor *tutors, int size, string name);

// radix sort with counting sort
void countingSortPayRate(Tutor *&tutors, int size, double place);

// dual pivot quick sort
void swap(TuitionCentre *tc1, TuitionCentre *tc2);

void quickSortTCName(TuitionCentre *tuitions, int low, int up);
void partitionTCName(TuitionCentre *tuitions, int low, int up, int *lp, int *rp);


int main() {
  // initialise
  int size = 0, lastID = 0, tcSize = 0, lastTCCode = 0, subSize = 0, lastSubCode = 0;
  Tutor *tutors = nullptr;
  TuitionCentre *tuitions = nullptr;
  Subject *subjects = nullptr;
  int input = 0, subinput = 0;
  char cinput = ' ';

  // generate hardcoded data
  generateData(tutors, lastID, size, tuitions, lastTCCode, tcSize, subjects, lastSubCode, subSize);

  // set cout to always display two decimals for doubles
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  // menu
  do {
    cout << "---------------------------------------------------" << endl;
    cout << "Tutor Management System (Array of Structures 2.2.4)" << endl;
    cout << "---------------------------------------------------" << endl;
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
            } while (tcCode < 0 || tcCode > lastTCCode || !validateTuitionCentre(tcCode, tuitions, lastTCCode, tcSize));

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
            } while (subCode < 0 || subCode > lastSubCode || !validateSubject(subCode, subjects, lastSubCode, subSize));

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
            addTutor(tutors, lastID, size, name, day, month, year, hourlyPayRate, phone, address, tcCode, subCode, rating);
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
          modifyTutor(tutors, size, tutorID, tuitions, tcSize, subjects, subSize);
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
          terminateTutor(tutors, size, tutorID, tuitions, tcSize, subjects, subSize);
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
          deleteTutor(tutors, size, tutorID, tuitions, tcSize, subjects, subSize);
          break;
        };

        // display records
      case 5:
        cout << "Display Records (Name (Asc))" << endl;
        cout << "---------------------------------------" << endl;
        displayRecordsList(tutors, size, 0, tuitions, tcSize, subjects, subSize);
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
            sortTutorID(tutors, size, lastID, tuitions, tcSize, subjects, subSize);
            break;

            // sort by rating
          case 2:
            cout << "Display Records (Rating (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortRating(tutors, size, tuitions, tcSize, subjects, subSize);
            break;

            // sort by hourly pay rate
          default:
            cout << "Display Records (Hourly Pay Rate (Asc))" << endl;
            cout << "---------------------------------------" << endl;
            sortPayRate(tutors, size, tuitions, tcSize, subjects, subSize);
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
              searchTutorID(tutors, size, tutorID, tuitions, tcSize, subjects, subSize);
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
              searchRating(tutors, size, rating, tuitions, tcSize, subjects, subSize);
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
              searchTuitionName(tutors, size, tcName, tuitions, tcSize, subjects, subSize);
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
              addTuitionCentre(tuitions, lastTCCode, tcSize, tcName);
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
              modifyTuitionCentre(tuitions, tcSize, tcCode);
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
              deleteTuitionCentre(tutors, size, tuitions, tcSize, tcCode);
              break;
            };

            // display tuition centres
          default:
            cout << "Display Tuition Centres" << endl;
            cout << "----------------------------" << endl;
            displayTCList(tuitions, tcSize);
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
              addSubject(subjects, lastSubCode, subSize, subName);
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
              modifySubject(subjects, subSize, subCode);
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
              deleteSubject(tutors, size, subjects, subSize, subCode);
              break;
            };

            // display subjects
          default:
            cout << "Display Subjects" << endl;
            cout << "----------------------------" << endl;
            displaySubList(subjects, subSize);
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

void generateData(Tutor *&tutors, int &lastID, int &size, TuitionCentre *&tuitions, int &lastTCCode, int &tcSize, Subject *&subjects, int &lastSubCode, int &subSize) {
  // generate tuition centres
  tcSize = lastTCCode = 10;
  tuitions = new TuitionCentre[tcSize];

  string tcNames[]{"Bukit Bintang", "Sri Petaling", "Bukit Petaling", "Taman Laksamana", "Taman Durian", "Bukit Jalil", "Taman Mutiara", "Pandan Perdana", "Taman Midah", "Pandan Indah"};

  for (int i = 0; i < tcSize; i++)
    tuitions[i] = TuitionCentre(i + 1, tcNames[i]);
  
  // generate subjects
  subSize = lastSubCode = 10;
  subjects = new Subject[subSize];

  string subNames[]{"Malay", "English", "Mathematics", "Additional Mathematics", "Biology", "Chemistry", "Physics", "Geography", "History", "Accounting", "Economics"};

  for (int i = 0; i < subSize; i++)
    subjects[i] = Subject(i + 1, subNames[i]);

  // generate tutors
  size = lastID = 10;
  tutors = new Tutor[size];

  tutors[0] = Tutor(2, "Aaron", 2, 3, 2000, 0, 0, 0, 79, "0123456789", "Somewhere", 3, 1, 5);
  tutors[1] = Tutor(1, "Bill", 2, 3, 2000, 0, 0, 0, 65.555, "0123456789", "Somewhere", 5, 1, 4);
  tutors[2] = Tutor(4, "Charlie", 2, 3, 2000, 0, 0, 0, 50.5, "0123456789", "Somewhere", 5, 2, 3);
  tutors[3] = Tutor(3, "Edwin", 2, 3, 2000, 0, 0, 0, 65.551, "0123456789", "Somewhere", 2, 1, 4);
  tutors[4] = Tutor(8, "George", 2, 3, 2000, 0, 0, 0, 45, "0123456789", "Somewhere", 4, 1, 2);
  tutors[5] = Tutor(10, "Jamal", 2, 3, 2000, 0, 0, 0, 55.5, "0123456789", "Somewhere", 6, 1, 3);
  tutors[6] = Tutor(5, "Kenny", 2, 3, 2000, 0, 0, 0, 65.559, "0123456789", "Somewhere", 3, 1, 4);
  tutors[7] = Tutor(9, "Maria", 2, 3, 2000, 0, 0, 0, 55.05, "0123456789", "Somewhere", 1, 2, 3);
  tutors[8] = Tutor(7, "Patricia", 2, 3, 2000, 0, 0, 0, 75, "0123456789", "Somewhere", 3, 2, 5);
  tutors[9] = Tutor(6, "Shelby", 2, 3, 2000, 0, 0, 0, 40, "0123456789", "Somewhere", 6, 2, 1);
};
// tutors
void addTutor(Tutor *&tutors, int &lastID, int &size, string name, int day, int month, int year, double hourlyPayRate, string phone, string address, int tcCode, int subCode, int rating) {
  // initialise
  int tutorID = lastID + 1;

  Tutor newTutor(tutorID, name, day, month, year, 0, 0, 0, hourlyPayRate, phone, address, tcCode, subCode, rating);

  // binary insertion sort to insert new tutor
  if (size > 0) {
    // binary search to identify the insertion point of the new tutor
    int index = binarySearchName(tutors, size, name);

    // allocate memory
    Tutor *tempTutors = new Tutor[size + 1];

    // copy elements into temporary tutor array
    for (int i = 0; i < index; i++)
      // copy elements before the insertion point
      tempTutors[i] = tutors[i];

    // insert the new tutor into the temporary array
    tempTutors[index] = newTutor;
    
    for (int i = index + 1; i < size + 1; i++)
      // copy elements after the insertion point
      tempTutors[i] = tutors[i - 1];

    // reallocate memory
    delete[] tutors;
    tutors = tempTutors;
    tempTutors = nullptr;
  } else {
    // insert new tutor as there are no existing tutors
    // reallocate memory
    delete[] tutors;
    tutors = new Tutor[1];
    tutors[0] = newTutor;
  };
  // display success message
  cout << "Added Successfully" << endl << endl;
  // increase tutor size
  size++;
  // increase last id
  lastID++;
};
void modifyTutor(Tutor *&tutors, int size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // initialise
  int index = 0, input = 0;
  string phone = "", address = "";
  bool found = false;

  // linear search through the array to find the tutor to modify
  for (index = 0; index < size; index++)
    // find tutor with searched id
    if (tutors[index].getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };

  // if the tutor is found
  if (found) {
    // display record
    displayRecord(tutors[index], tuitions, tcSize, subjects, subSize);

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
      tutors[index].setPhone(phone);
    };

    // modify address
    if (input == 2 || input == 3) {
      // get user input
      do {
        cout << "New Address: ";
        getline(cin, address);
        trim(address);
      } while (address == "");
      tutors[index].setAddress(address);
    };

    // display success message
    cout << "Modified Successfully" << endl << endl;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void terminateTutor(Tutor *&tutors, int size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // initialise
  int index = 0, day = 0, month = 0, year = 0;
  time_t dateTerminated = time(0);
  char sp = ' ', cinput = ' ';
  bool found = false;

  // linear search through the array to find the tutor to terminate
  for (index = 0; index < size; index++)
    // find tutor with searched id
    if (tutors[index].getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };

  // check if tutor is found
  if (found) {
    // display record
    displayRecord(tutors[index], tuitions, tcSize, subjects, subSize);

    // check if tutor is terminated
    if (tutors[index].getDateTerminated() != -1) {
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
      } while (!validateDate(day, month, year) || difftime(dateTerminated, tutors[index].getDateJoined()) <= 0);

      // ask for confirmation
      do {
        // check if the termination date is not set
        if (tutors[index].getDateTerminated() == -1)
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
          tutors[index].setDateTerminated(dateTerminated);
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
void deleteTutor(Tutor *&tutors, int &size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // initialise
  int index = 0;
  char cinput = ' ';
  bool found = false;

  // linear search through the array to find the tutor to delete
  for (index = 0; index < size; index++)
    // find tutor with searched id
    if (tutors[index].getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };

  // check if the tutor is found
  if (found) {
    // display record
    displayRecord(tutors[index], tuitions, tcSize, subjects, subSize);

    // check if tutor is terminated
    if (tutors[index].getDateTerminated() != -1) {
      // check if terminated date has reached at least 6 months
      tm tmTerminated;
      time_t dateTerminated = tutors[index].getDateTerminated();
      localtime_s(&tmTerminated, &dateTerminated);

      // add 6 months to terminated date
      if (tmTerminated.tm_mon >= 6) {
        // if it is past July, add 1 year and minus 6 months
        tmTerminated.tm_mon -= 6;
        tmTerminated.tm_year += 1;
      } else {
        tmTerminated.tm_mon += 6;
      };

      // check if terminated date plus 6 months is before current date
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
            {
              // initialise
              bool deleted = false;

              // allocate memory
              Tutor *tempTutors = new Tutor[size - 1];

              // copy to temporary tutor array
              for (int x = 0; x < size - 1; x++) {
                if (!deleted && x != index) {
                  // copy elements before the deleted tutor
                  tempTutors[x] = tutors[x];
                } else if (deleted) {
                  // copy elements after the deleted tutor
                  tempTutors[x] = tutors[x + 1];
                } else if (x == index && x != size - 1) {
                  // skip the deleted tutor and copy the next tutor
                  tempTutors[x] = tutors[x + 1];
                  // set as deleted
                  deleted = true;
                };
              };

              // deallocate memory
              delete[] tutors;
              // point to new memory
              tutors = tempTutors;
              tempTutors = nullptr;

              // display success message
              cout << "Deleted Successfully" << endl << endl;
              // decrease tutor size
              size--;
              break;
            };

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

void displayRecord(Tutor tutor, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
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
  cout << "Tuition Centre Name: " << tutor.getTuitionCentreName(tuitions, tcSize) << endl;
  cout << "Subject Code       : " << tutor.getSubjectCode() << endl;
  cout << "Subject Name       : " << tutor.getSubjectName(subjects, subSize) << endl;
  cout << "Rating             : " << tutor.getRating() << endl << endl;
};
void displayRecordsList(Tutor *tutors, int size, int index, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // check if there is tutor
  if (size > 0) {
    // initialise
    int page = 1, input = 0;

    // identify the page of the selected tutor
    for (; index >= 10; index -= 10)
      // increment the page
      page++;

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
      for (int i = (page - 1) * 10; i < page * 10; i++) {
        // print list of tutors
        cout.width(4);
        cout << right << tutors[i].getTutorID() << "  ";
        cout.width(20);
        cout << left << truncate(tutors[i].getName(), 20) << "  ";
        cout.width(5);
        cout << tutors[i].getHourlyPayRate() << "  ";
        cout.width(20);
        cout << truncate(tutors[i].getTuitionCentreName(tuitions, tcSize), 20) << "  ";
        cout << tutors[i].getRating() << endl;
        
        // break when last element
        if (i == size - 1)
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
          if (page > 1)
            // decrement page
            page--;
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 1 && input < 5);

    // detailed view
    if (input == 1)
      displayRecordsDetailed(tutors, size, tuitions, tcSize, subjects, subSize);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void displayRecordsDetailed(Tutor *tutors, int size, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // check if there is tutor
  if (size > 0) {
    // initialise
    int input = 2, tutorID = 0, index = 0;
    bool found = false;

    do {
      // jump to record
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
          } while (tutorID <= 0);

          // linear search through the array to find the tutor to display
          for (index = 0; index < size; index++)
            // find tutor with searched id
            if (tutors[index].getTutorID() == tutorID) {
              // set as found
              found = true;
              // stop iteration
              break;
            };

          // check if the tutor is found
        } while (!found);
      };

      // display result
      cout << "-------------------------------------" << endl;
      displayRecord(tutors[index], tuitions, tcSize, subjects, subSize);

      cout << "(1) List view" << endl;
      
      cout << "(2) Jump to record";
      // disable if there is only 1 tutor
      if (size == 1)
        cout << " (disabled)";
      
      cout << endl << "(3) Next record";
      // disable if there is no next tutor
      if (index >= size - 1)
        cout << " (disabled)";
      
      cout << endl << "(4) Previous record";
      // disable if there is no previous tutor
      if (index <= 0)
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
      } while (input < 1 || input > 5 || (input == 2 && size == 1) || (input == 3 && index >= size - 1) || (input == 4 && index <= 0));

      // determine outcome
      switch (input) {
        // next record
        case 3:
          if (index < size - 1)
            // increment index
            index++;
          break;

          // previous record
        case 4:
          if (index > 0)
            // decrement index
            index--;
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 1 && input < 5);

    // list view
    if (input == 1)
      displayRecordsList(tutors, size, index, tuitions, tcSize, subjects, subSize);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void sortTutorID(Tutor *tutors, int size, int lastID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // check if there is tutor
  if (size > 0) {
    // initialise
    Tutor *tempTutors = nullptr;
    int *count = new int[lastID] {0};

    // counting sort
    for (int i = 0; i < size; i++)
      // count of each id
      count[tutors[i].getTutorID() - 1]++;

    // calculate cumulative sum
    for (int i = 1; i < lastID; i++)
      count[i] += count[i - 1];

    // allocate memory
    tempTutors = new Tutor[size];

    // arrange elements into the correct positions
    for (int i = size - 1; i >= 0; i--) {
      tempTutors[count[tutors[i].getTutorID() - 1] - 1] = tutors[i];
      count[tutors[i].getTutorID() - 1]--;
    };

    // deallocate memory
    delete[] count;

    // display sorted array
    displayRecordsList(tempTutors, size, 0, tuitions, tcSize, subjects, subSize);

    // deallocate memory
    delete[] tempTutors;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void sortRating(Tutor *tutors, int size, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // check if there is tutor
  if (size > 0) {
    // initialise
    Tutor *tempTutors = nullptr;
    int count[5]{0};

    // counting sort
    for (int i = 0; i < size; i++)
      // count of each rating
      count[tutors[i].getRating() - 1]++;

    // calculate cumulative sum
    for (int i = 1; i < 5; i++)
      count[i] += count[i - 1];

    // arrange elements into the correct positions
    tempTutors = new Tutor[size];
    for (int i = size - 1; i >= 0; i--) {
      tempTutors[count[tutors[i].getRating() - 1] - 1] = tutors[i];
      count[tutors[i].getRating() - 1]--;
    };

    // display sorted array
    displayRecordsList(tempTutors, size, 0, tuitions, tcSize, subjects, subSize);

    // deallocate memory
    delete[] tempTutors;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void sortPayRate(Tutor *tutors, int size, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // check if there is tutoor
  if (size > 0) {
    // initialise
    Tutor *tempTutors = nullptr;
    int count[10]{0};

    // lsd radix sort
    for (int i = 0; i < size; i++)
      // count of each digit
      count[((int) (tutors[i].getHourlyPayRate() / 0.001)) % 10]++;

    // calculate cumulative sum
    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];

    // arrange elements into the correct positions
    tempTutors = new Tutor[size];
    for (int i = size - 1; i >= 0; i--) {
      tempTutors[count[((int) (tutors[i].getHourlyPayRate() / 0.001)) % 10] - 1] = tutors[i];
      count[((int) (tutors[i].getHourlyPayRate() / 0.001)) % 10]--;
    };

    // lsd radix sort the temporary tutor array by hourly pay rate
    for (double place = 0.01; place <= 10; place *= 10)
      countingSortPayRate(tempTutors, size, place);

    // display sorted array
    displayRecordsList(tempTutors, size, 0, tuitions, tcSize, subjects, subSize);

    // deallocate memory
    delete[] tempTutors;
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

void searchTutorID(Tutor *tutors, int size, int tutorID, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // initialise
  int index = 0;
  bool found = false;

  // linear search through the array to find the tutor
  for (index = 0; index < size; index++)
    // find tutor with searched id
    if (tutors[index].getTutorID() == tutorID) {
      // set as found
      found = true;
      // stop iteration
      break;
    };

  // check if the tutor is found
  if (found)
    // display result
    displayRecord(tutors[index], tuitions, tcSize, subjects, subSize);
  else
    // if no results
    cout << "No results found" << endl << endl;
};
void searchRating(Tutor *tutors, int size, int rating, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // initialise
  Tutor *tempTutors = nullptr;
  int tutorSize = 0, *indices = new int[size];

  // linear search through the array to find the tutor with the rating
  for (int i = 0; i < size; i++)
    // find tutors with searched rating
    if (tutors[i].getRating() == rating)
      // keep track of the index of the tutor
      indices[tutorSize++] = i;

  // check if the tutor is found
  if (tutorSize > 0) {
    // allocate memory
    tempTutors = new Tutor[tutorSize];

    // copy elements into temporary tutor array
    for (int i = 0; i < tutorSize; i++)
      tempTutors[i] = tutors[indices[i]];

    // deallocate memory
    delete[] indices;

    // display results
    displayRecordsList(tempTutors, tutorSize, 0, tuitions, tcSize, subjects, subSize);

    // deallocate memory
    delete[] tempTutors;
  } else {
    // deallocate memory
    delete[] indices;
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void searchTuitionName(Tutor *tutors, int size, string tcName, TuitionCentre *tuitions, int tcSize, Subject *subjects, int subSize) {
  // initialise
  Tutor *tempTutors = nullptr;
  TuitionCentre *tempTuitions = new TuitionCentre[size];
  int tutorSize = 0, tuitionSize = 0, input = 0, tcCode = 0, *count = new int[tcSize]{0};

  // count each tuition code
  for (int i = 0; i < size; i++)
    // count of each tuition code
    count[tutors[i].getTuitionCentreCode() - 1]++;

  // linear search through the tuition array to create a temporary tuition array
  for (int i = 0; i < tcSize; i++)
    // find tuition with searched tuition name
    if (count[i] > 0 && findInsensitive(tuitions[i].getTuitionCentreName(), tcName) != string::npos)
      // add searched tuitions to a temporary tuition array
      tempTuitions[tuitionSize++] = tuitions[i];

  // quick sort tuition name
  if (tuitionSize > 1)
    quickSortTCName(tempTuitions, 0, tuitionSize - 1);

  // check if there is tuition
  if (tuitionSize > 0) {
    // check if there is more than 1 tuition
    if (tuitionSize > 1) {
      // display list of tuitions
      for (int i = 0; i < tuitionSize; i++)
        cout << "(" << i + 1 << ")" << tempTuitions[i].getTuitionCentreName() << endl;
      // get user input
      do {
        cout << "Please input (1-" << tuitionSize << "): ";
        // ignore enter key
        if (cin.peek() != '\n')
          cin >> input;
        if (!cin)
          // clear error state
          cin.clear();
        // clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (input < 1 || input > tuitionSize);
    } else {
      input = 1;
    };

    // get tutor size from the count array
    tutorSize = count[tempTuitions[input - 1].getTuitionCentreCode() - 1];

    // deallocate memory
    delete[] count;

    // get tuition code from the temporary tuition array
    tcCode = tempTuitions[input - 1].getTuitionCentreCode();

    // deallocate memory
    delete[] tempTuitions;

    // allocate memory
    tempTutors = new Tutor[tutorSize];
    // linear search through the tuition array to find tutors 
    for (int i = 0, x = 0; i < size; i++)
      // find tutor with searched tuition code
      if (tutors[i].getTuitionCentreCode() == tcCode)
        // add searched tutor to a temporary tutor array
        tempTutors[x++] = tutors[i];

    // display sorted array
    displayRecordsList(tempTutors, tutorSize, 0, tuitions, tcSize, subjects, subSize);

    // deallocate memory
    delete[] tempTutors;
  } else {
    // deallocate memory
    delete[] count;
    delete[] tempTuitions;
    // if no results
    cout << "No results found" << endl << endl;
  };
};

// tuition centres
bool validateTuitionCentre(int tcCode, TuitionCentre *tuitions, int lastTCCode, int tcSize) {
  // binary search through the array to find the tuition
  int low = 0, mid, up = tcSize - 1, comp = 0;
  while (up >= low) {
    // get mid point
     mid = (up - low) / 2 + low;
    // compare
    int comp = tuitions[mid].getTuitionCentreCode();
    if (comp == tcCode) {
      // found searched code
      return true;
    } else if (comp < tcCode) {
      // if existing code is before searched code
      low = mid + 1;
    } else if (comp > tcCode) {
      // if existing code is after searched code
      up = mid - 1;
    };
  };
  return false;
};

void addTuitionCentre(TuitionCentre *&tuitions, int &lastTCCode, int &tcSize, string tcName) {
  // initialise
  int tcCode = lastTCCode + 1;
  int index = 0;
  bool exist = false;

  // linear search through the array to find the tuition
  for (index = 0; index < tcSize; index++)
    // find tuition with new tuition name
    if (compareInsensitive(tuitions[index].getTuitionCentreName(), tcName) == 0) {
      // set as exist
      exist = true;
      // stop iteration
      break;
    };

  // check if tuition name exists
  if (!exist) {
    TuitionCentre newTC(tcCode, tcName);

    if (tcSize > 0) {
      // allocate memory
      TuitionCentre *tempTuitions = new TuitionCentre[tcSize + 1];

      // copy elements into temporary tuition array
      for (int i = 0; i < tcSize; i++)
        tempTuitions[i] = tuitions[i];

      // insert new tuition into temporary tuition array
      tempTuitions[tcSize] = newTC;

      // reallocate memory
      delete[] tuitions;
      // point to new memory
      tuitions = tempTuitions;
      tempTuitions = nullptr;
    } else {
      // insert new tuition as there are no existing tuitions
      // reallocate memory
      delete[] tuitions;
      tuitions = new TuitionCentre[1];
      tuitions[0] = newTC;
    };

    // display success message
    cout << "Added Successfully" << endl << endl;
    // increase tuitions size
    tcSize++;
    // increase last tuition code
    lastTCCode++;
  } else {
    cout << endl;
    // display record
    displayTC(tuitions[index]);
    // display exist message
    cout << "Tuition centre already exists" << endl << endl;
  };
};
void modifyTuitionCentre(TuitionCentre *&tuitions, int tcSize, int tcCode) {
  // initialise
  int index = 0, input = 0;
  string tcName = "";
  bool found = false;

  // binary search through the array to find the tuition
  int low = 0, up = tcSize - 1, comp = 0;
  while (up >= low) {
    // get mid point
    index = (up - low) / 2 + low;
    // compare
    int comp = tuitions[index].getTuitionCentreCode();
    if (comp == tcCode) {
        // set as found
        found = true;
        // stop iteration
        break;
    } else if (comp < tcCode) {
      // if existing code is before searched code
      low = index + 1;
    } else if (comp > tcCode) {
      // if existing code is after searched code
      up = index - 1;
    };
  };

  // check if the tuition is found
  if (found) {
    // display record
    displayTC(tuitions[index]);

    // modify tuition name
    // get user input
    do {
      cout << "New Tuition Name: ";
      getline(cin, tcName);
      trim(tcName);
    } while (tcName == "");

    int temp = 0;
    bool exist = false;

    // linear search through the array to find tuition
    for (temp = 0; temp < tcSize; temp++)
      // find tuition with new tuition name
      if (compareInsensitive(tuitions[temp].getTuitionCentreName(), tcName) == 0) {
        // set as found
        exist = true;
        // stop iteration
        break;
      };

    // check if tuition name exists or if the existing tuition is same as current tuition
    if (!exist || temp == index) {
      tuitions[index].setTuitionCentreName(tcName);
      // display success message
      cout << "Modified Successfully" << endl << endl;
    } else {
      // display failed message
      cout << "Modification Failed" << endl << endl;
      // display record
      displayTC(tuitions[temp]);
      // display exist message
      cout << "Tuition centre already exists" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void deleteTuitionCentre(Tutor *tutors, int size, TuitionCentre *&tuitions, int &tcSize, int tcCode) {
  // initialise
  int index = 0;
  char cinput = ' ';
  bool found = false;

  // binary search through the array to find the tuition
  int low = 0, up = tcSize - 1, comp = 0;
  while (up >= low) {
    // get mid point
    index = (up - low) / 2 + low;
    // compare
    int comp = tuitions[index].getTuitionCentreCode();
    if (comp == tcCode) {
      // set as found
      found = true;
      // stop iteration
      break;
    } else if (comp < tcCode) {
      // if existing code is before searched code
      low = index + 1;
    } else if (comp > tcCode) {
      // if existing code is after searched code
      up = index - 1;
    };
  };

  // check if the tuition is found
  if (found) {
    // display record
    displayTC(tuitions[index]);

    bool inUse = false;
    // linear search through the array to find the tutor
    for (int i = 0; i < size; i++)
      // find the tutor with tuition code
      if (tutors[i].getTuitionCentreCode() == tcCode) {
        // set as in use
        inUse = true;
        // stop iteration
        break;
      };

    // check if record is in use
    if (!inUse) {
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
          {
            // initialise
            bool deleted = false;

            // allocate memory
            TuitionCentre *tempTuitions = new TuitionCentre[tcSize - 1];

            // copy to temporary tuition array
            for (int x = 0; x < tcSize - 1; x++) {
              if (!deleted && x != index) {
                // copy elements before the deleted tutor
                tempTuitions[x] = tuitions[x];
              } else if (deleted) {
                // copy elements after the deleted tutor
                tempTuitions[x] = tuitions[x + 1];
              } else if (x == index && x != tcSize - 1) {
                // skip the deleted tuition and copy the next tuition
                tempTuitions[x] = tuitions[x + 1];
                // set as deleted
                deleted = true;
              };
            };

            // deallocate memory
            delete[] tuitions;
            // point to new memory
            tuitions = tempTuitions;
            tempTuitions = nullptr;

            // display success message
            cout << "Deleted Successfully" << endl << endl;
            // decrease tutor size
            tcSize--;
            break;
          };

          // cancel delete
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };
    } else {
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
void displayTCList(TuitionCentre *tuitions, int tcSize) {
  // check if there is tuition
  if (tcSize > 0) {
    // initialise
    int page = 1, input = 0;

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
      for (int i = (page - 1) * 10; i < page * 10; i++) {
        // print list of tuitions
        cout.width(6);
        cout << right << tuitions[i].getTuitionCentreCode() << "  ";
        cout.width(30);
        cout << left << truncate(tuitions[i].getTuitionCentreName(), 30) << endl;

        // break when last element
        if (i == tcSize - 1)
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
          if (page > 1)
            // deccrement page
            page--;
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 0 && input < 4);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};

// subjects
bool validateSubject(int subCode, Subject *subjects, int lastSubCode, int subSize) {
  // binary search through the array to find the subject
  int low = 0, mid = 0, up = subSize - 1;
  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare
    int comp = subjects[mid].getSubjectCode();
    if (comp == subCode) {
      // found searched code
      return true;
    } else if (comp < subCode) {
      // if existing code is before searched code
      low = mid + 1;
    } else if (comp > subCode) {
      // if existing code is after searched code
      up = mid - 1;
    };
  };
  return false;
};

void addSubject(Subject *&subjects, int &lastSubCode, int &subSize, string subName) {
  // initialise
  int subCode = lastSubCode + 1;
  int index = 0;
  bool exist = false;

  // linear search through the array to find the subject
  for (index = 0; index < subSize; index++)
    // find subjects with new subject name
    if (compareInsensitive(subjects[index].getSubjectName(), subName) == 0) {
      // set as found
      exist = true;
      // stop iteration
      break;
    };

  if (!exist) {
    Subject newSub(subCode, subName);

    if (subSize > 0) {
      // allocate memory
      Subject *tempSubjects = new Subject[subSize + 1];

      // copy elements into temporary subject array
      for (int i = 0; i < subSize; i++)
        tempSubjects[i] = subjects[i];
      
      // insert new subject into temporary subject array
      tempSubjects[subSize] = newSub;

      // reallocate memory
      delete[] subjects;
      // point to new memory
      subjects = tempSubjects;
      tempSubjects = nullptr;
    } else {
      // insert new subject as there are no existing subjects
      // reallocate memory
      delete[] subjects;
      subjects = new Subject[1];
      subjects[0] = newSub;
    };

    // display success message
    cout << "Added Successfully" << endl << endl;
    // increase subjects size
    subSize++;
    // increase last subject code
    lastSubCode++;
  } else {
    cout << endl;
    // display record
    displaySub(subjects[index]);
    // display exist message
    cout << "Subject already exists" << endl << endl;
  };
};
void modifySubject(Subject *&subjects, int subSize, int subCode) {
  // initialise
  int index = 0, input = 0;
  string subName = "";
  bool found = false;

  // binary search through the array to find the subject
  int low = 0, up = subSize - 1, comp = 0;
  while (up >= low) {
    // get mid point
    index = (up - low) / 2 + low;
    // compare
    int comp = subjects[index].getSubjectCode();
    if (comp == subCode) {
      // set as found
      found = true;
      // stop iteration
      break;
    } else if (comp < subCode) {
      // if existing code is before searched code
      low = index + 1;
    } else if (comp > subCode) {
      // if existing code is after searched code
      up = index - 1;
    };
  };

  if (found) {
    // display record
    displaySub(subjects[index]);

    // modify subject name
    do {
      cout << "New Subject Name: ";
      getline(cin, subName);
      trim(subName);
    } while (subName == "");

    int temp = 0;
    bool exist = false;

    // linear search through the array to find subject
    for (temp = 0; temp < subSize; temp++)
      // find subjects with new subject name
      if (compareInsensitive(subjects[temp].getSubjectName(), subName) == 0) {
        // set as found
        exist = true;
        // stop iteration
        break;
      };

    // check if subject name exists or if the existing subject is same as current subject
    if (!exist || temp == index) {
      subjects[index].setSubjectName(subName);
      // display success message
      cout << "Modified Successfully" << endl << endl;
    } else {
      // display failed message
      cout << "Modification Failed" << endl << endl;
      // display record
      displaySub(subjects[temp]);
      // display exist message
      cout << "Subject already exists" << endl << endl;
    };
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};
void deleteSubject(Tutor *tutors, int size, Subject *&subjects, int &subSize, int subCode) {
  // initialise
  int index = 0;
  char cinput = ' ';
  bool found = false;

  // binary search through the array to find the subject
  int low = 0, up = subSize - 1, comp = 0;
  while (up >= low) {
    // get mid point
    index = (up - low) / 2 + low;
    // compare
    int comp = subjects[index].getSubjectCode();
    if (comp == subCode) {
      // set as found
      found = true;
      // stop iteration
      break;
    } else if (comp < subCode) {
      // if existing code is before searched code
      low = index + 1;
    } else if (comp > subCode) {
      // if existing code is after searched code
      up = index - 1;
    };
  };

  // check if the subject is found
  if (found) {
    // display record
    displaySub(subjects[index]);

    bool inUse = false;
    // linear search through the array to find subject
    for (int i = 0; i < size; i++)
      // find subject with subject code
      if (tutors[i].getSubjectCode() == subCode) {
        // set as in use
        inUse = true;
        // stop iteration
        break;
      };

    // check if record is in use
    if (!inUse) {
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
          {
            // initialise
            bool deleted = false;

            // allocate memory
            Subject *tempSubjects = new Subject[subSize - 1];

            // copy to temporary subject array
            for (int x = 0; x < subSize - 1; x++) {
              if (!deleted && x != index) {
                // copy elements before the deleted subject
                tempSubjects[x] = subjects[x];
              } else if (deleted) {
                // copy elements before the deleted subject
                tempSubjects[x] = subjects[x + 1];
              } else if (x == index && x != subSize - 1) {
                // skip the subject and copy the next subject
                tempSubjects[x] = subjects[x + 1];
                // set as deleted
                deleted = true;
              };
            };

            // deallocate memory
            delete[] subjects;
            // point to new memory
            subjects = tempSubjects;
            tempSubjects = nullptr;

            // display success message
            cout << "Deleted Successfully" << endl << endl;
            // decrease tutor size
            subSize--;
            break;
          };

          // cancel delete
        default:
          // display cancelled message
          cout << "Cancelled" << endl << endl;
          break;
      };
    } else {
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
void displaySubList(Subject *subjects, int subSize) {
  // check if there is subject
  if (subSize > 0) {
    // initialise
    int page = 1, input = 0;

    // calculate total page numbers
    int total = subSize / 10;
    // check if there are remainders
    if (subSize % 10 > 0)
      // increment total pages
      total++;

    // display page
    do {
      cout << "Code    Subject Name                    " << endl;
      cout << "----------------------------------------" << endl;
      for (int i = (page - 1) * 10; i < page * 10; i++) {
        // print list of subjects
        cout.width(6);
        cout << right << subjects[i].getSubjectCode() << "  ";
        cout.width(30);
        cout << left << truncate(subjects[i].getSubjectName(), 30) << endl;

        // break when last element
        if (i == subSize - 1)
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
          if (page > 1)
            // decrement page
            page--;
          break;

          // do nothing
        default:
          break;
      };
      cout << endl;
    } while (input > 0 && input < 4);
  } else {
    // if no results
    cout << "No results found" << endl << endl;
  };
};


// binary search
int binarySearchName(Tutor *tutors, int size, string name) {
  // binary search through the array to find the insertion point
  int low = 0, mid = 0, up = size - 1, comp = 0;
  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare strings
    int comp = compareInsensitive(tutors[mid].getName(), name);
    if (comp == 0) {
      // if exising name is same as new name
      while (mid + 1 <= up && compareInsensitive(tutors[mid + 1].getName(), name) == 0)
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
  comp = compareInsensitive(tutors[mid].getName(), name);
  if (comp > 0) {
    // if existing name is after new name
    return mid;
  } else {
    // if existing name is before new name
    return mid + 1;
  };
};

// lsd radix sort
void countingSortPayRate(Tutor *&tutors, int size, double place) {
  // initialise
  int count[10]{0};
  Tutor *output = new Tutor[size];

  // count of each digit
  for (int i = 0; i < size; i++)
    count[((int) (tutors[i].getHourlyPayRate() / place)) % 10]++;

  // calculate cumulative sum
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // arrange elements into the correct positions
  for (int i = size - 1; i >= 0; i--) {
    output[count[((int) (tutors[i].getHourlyPayRate() / place)) % 10] - 1] = tutors[i];
    count[((int) (tutors[i].getHourlyPayRate() / place)) % 10]--;
  };

  // deallocate memory
  delete[] tutors;
  // point to new memory
  tutors = output;
  output = nullptr;
};

// dual pivot quick sort
void swap(TuitionCentre *tc1, TuitionCentre *tc2) {
  // swap the elements' position
  TuitionCentre temp = *tc1;
  *tc1 = *tc2;
  *tc2 = temp;
};

void quickSortTCName(TuitionCentre *tuitions, int low, int up) {
  if (low < up) {
    int lPivot, rPivot;
    partitionTCName(tuitions, low, up, &lPivot, &rPivot);
    // sort left subarray
    quickSortTCName(tuitions, low, lPivot - 1);
    // sort mid subarray
    quickSortTCName(tuitions, lPivot + 1, rPivot - 1);
    // sort right subarray
    quickSortTCName(tuitions, rPivot + 1, up);
  };
};
void partitionTCName(TuitionCentre *tuitions, int low, int up, int *lPivot, int *rPivot) {
  if (compareInsensitive(tuitions[low].getTuitionCentreName(), tuitions[up].getTuitionCentreName()) > 0)
    // swap between left and right pivots
    swap(&tuitions[low], &tuitions[up]);

  // initialise
  int lIndex = low + 1, rIndex = up - 1;
  string lPiv = tuitions[low].getTuitionCentreName(), rPiv = tuitions[up].getTuitionCentreName();

  for (int i = lIndex; i <= rIndex; i++) {
    if (compareInsensitive(tuitions[i].getTuitionCentreName(), lPiv) < 0) {
      // swap elements that are less than the left pivot
      swap(&tuitions[i], &tuitions[lIndex]);
      // increment left index
      lIndex++;
    } else if (compareInsensitive(tuitions[i].getTuitionCentreName(), rPiv) >= 0) {
      // swap elements are greater than or equal to the right pivot
      while (compareInsensitive(tuitions[rIndex].getTuitionCentreName(), rPiv) > 0 && i < rIndex)
        // decrement right index
        rIndex--;
      // swap elements that are more or equal to right pivot
      swap(&tuitions[i], &tuitions[rIndex]);
      // decrement right index
      rIndex--;

      // check if element is less than left pivot
      if (compareInsensitive(tuitions[i].getTuitionCentreName(), lPiv) < 0) {
        // swap elements that are less than left pivot
        swap(&tuitions[i], &tuitions[lIndex]);
        // increment left index
        lIndex++;
      };
    };
  };
  // decrement left index
  lIndex--;
  // increment right index
  rIndex++;

  // swap pivots to their new positions
  swap(&tuitions[low], &tuitions[lIndex]);
  swap(&tuitions[up], &tuitions[rIndex]);

  // return the indices of the pivots
  *lPivot = lIndex;
  *rPivot = rIndex;
};
