#pragma once
#include <string>
#include "datec.h"

class Tutor {
  private:
    int tutorID;
    std::string name;
    time_t dateJoined;
    time_t dateTerminated;
    double hourlyPayRate;
    std::string phone;
    std::string address;
    std::string tuitionCentreCode;
    std::string tuitionCentreName;
    std::string subjectCode;
    std::string subjectName;
    int rating;

  public:
    // constructors
    Tutor();
    Tutor(int tutorID, std::string name, time_t dateJoined, time_t dateTerminated, double hourlyPayRate, std::string phone, std::string address, std::string tuitionCentreCode, std::string tuitionCentreName, std::string subjectCode, std::string subjectName, int rating);
    Tutor(int tutorID, std::string name, int dayJoined, int monthJoined, int yearJoined, int dayTerminated, int monthTerminated, int yearTerminated, double hourlyPayRate, std::string phone, std::string address, std::string tuitionCentreCode, std::string tuitionCentreName, std::string subjectCode, std::string subjectName, int rating);

    // getters and setters
    int getTutorID();
    std::string getName();
    time_t getDateJoined();
    time_t getDateTerminated();
    void setDateTerminated(time_t dateTerminated);
    double getHourlyPayRate();
    std::string getPhone();
    void setPhone(std::string phone);
    std::string getAddress();
    void setAddress(std::string address);
    std::string getTuitionCentreCode();
    std::string getTuitionCentreName();
    std::string getSubjectCode();
    std::string getSubjectName();
    int getRating();
};

// binary search
int binarySearchName(Tutor *tutors, int size, std::string name);

// dual pivot quicksort
void swap(Tutor *t1, Tutor *t2);

void dualPivotQuicksortName(Tutor *tutors, int low, int up);
void partitionName(Tutor *tutors, int low, int up, int *lp, int *rp);

void dualPivotQuicksortID(Tutor *tutors, int low, int up);
void partitionID(Tutor *tutors, int low, int up, int *lp, int *rp);

void dualPivotQuicksortRating(Tutor *tutors, int low, int up);
void partitionRating(Tutor *tutors, int low, int up, int *lp, int *rp);

void dualPivotQuicksortPayRate(Tutor *tutors, int low, int up);
void partitionPayRate(Tutor *tutors, int low, int up, int *lp, int *rp);
