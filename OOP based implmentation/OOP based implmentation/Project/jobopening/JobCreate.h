#pragma once

#include <string>

class JobCreate {
private:
    int jobid;
    std::string jobname;
    std::string jobdetails;
    float mintest;
    int offeredctc;

public:
    JobCreate(int jobid, std::string jobname, std::string jobdetails, float mintest, int offeredctc);

    static void applyToJob(int jobid1, const std::string &rollNumber);
    static void dispDetail(int jobid);
    static void shortlistStudents(int jobId, int n);
    static void viewShortlisted(int jobId);
    static void hireStudent(int jobId, const std::string &rollNumber, double ctc);

private:
    void saveJobDetails();
};


