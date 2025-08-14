#pragma once
#include <string>
#include "Department.h"
#include <iostream>



class Employee
{
private:
    int id;
    std::string name;
    double salary;
    Department department;

public:
    Employee(int idParam, const std::string& nameParam, int salaryParam, Department departmentParam);
	~Employee();

    int getId() const;
    std::string getName() const;
    int getSalary() const;
    Department getDepartment() const;
    void setSalary(double sl);

    void PrintDetails() const;
};