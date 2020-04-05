#include "stringc.h"
#include "tutor.h"

// constructor
Tutor::Tutor() {
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

Tutor::Tutor(int tutorID, std::string name, time_t dateJoined, time_t dateTerminated, double hourlyPayRate, std::string phone, std::string address, std::string tuitionCentreCode, std::string tuitionCentreName, std::string subjectCode, std::string subjectName, int rating) {
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

Tutor::Tutor(int tutorID, std::string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, std::string phone, std::string address, std::string tuitionCentreCode, std::string tuitionCentreName, std::string subjectCode, std::string subjectName, int rating) {
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
int Tutor::getTutorID() {
  return tutorID;
};

std::string Tutor::getName() {
  return name;
};

time_t Tutor::getDateJoined() {
  return dateJoined;
};

time_t Tutor::getDateTerminated() {
  return dateTerminated;
};

void Tutor::setDateTerminated(time_t dateTerminated) {
  this->dateTerminated = dateTerminated;
};

double Tutor::getHourlyPayRate() {
  return hourlyPayRate;
};

std::string Tutor::getPhone() {
  return phone;
};

void Tutor::setPhone(std::string phone) {
  this->phone = phone;
};

std::string Tutor::getAddress() {
  return address;
};

void Tutor::setAddress(std::string address) {
  this->address = address;
};

std::string Tutor::getTuitionCentreCode() {
  return tuitionCentreCode;
};

std::string Tutor::getTuitionCentreName() {
  return tuitionCentreName;
};

std::string Tutor::getSubjectCode() {
  return subjectCode;
};

std::string Tutor::getSubjectName() {
  return subjectName;
};

int Tutor::getRating() {
  return rating;
};

// binary search
int binarySearchName(Tutor *tutors, int size, std::string name) {
  // initialise
  int low = 0, mid = 0, up = size;
  while (up >= low) {
    // get mid point
    mid = (up - low) / 2 + low;
    // compare strings
    int comp = compareInsensitive(tutors[mid].getName(), name);
    if (comp == 0) {
      // if exising name is same as new name
      while (compareInsensitive(tutors[mid + 1].getName(), name))
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
  std::string lPiv = tutors[low].getName(), rPiv = tutors[up].getName();

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
      /*if (compareInsensitive(tutors[i].getName(), lPiv) < 0) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };*/
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


void dualPivotQuicksortID(Tutor *tutors, int low, int up) {
  if (low < up) {
    int lPivot, rPivot;
    partitionID(tutors, low, up, &lPivot, &rPivot);
    // sort left subarray
    dualPivotQuicksortID(tutors, low, lPivot - 1);
    // sort mid subarray
    dualPivotQuicksortID(tutors, lPivot + 1, rPivot - 1);
    // sort right subarray
    dualPivotQuicksortID(tutors, rPivot + 1, up);
  };
};

void partitionID(Tutor *tutors, int low, int up, int *lPivot, int *rPivot) {
  if (tutors[low].getTutorID() > tutors[up].getTutorID())
    // swap between left and right pivots
    swap(&tutors[low], &tutors[up]);

  // initialise
  int lIndex = low + 1, rIndex = up - 1;
  int lPiv = tutors[low].getTutorID(), rPiv = tutors[up].getTutorID();

  for (int i = lIndex; i <= rIndex; i++) {
    if (tutors[i].getTutorID() < lPiv) {
      // swap elements that are less than the left pivot
      swap(&tutors[i], &tutors[lIndex]);
      lIndex++;
    } else if (tutors[i].getTutorID() >= rPiv) {
      // swap elements are greater than or equal to the right pivot
      while (tutors[rIndex].getTutorID() > rPiv && i < rIndex)
        rIndex--;
      swap(&tutors[i], &tutors[rIndex]);
      rIndex--;
      /*if (tutors[i].getTutorID() < lPiv) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };*/
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
      /*if (tutors[i].getRating() < lPiv) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };*/
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
      /*if (tutors[i].getHourlyPayRate() < lPiv) {
        swap(&tutors[i], &tutors[lIndex]);
        lIndex++;
      };*/
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
