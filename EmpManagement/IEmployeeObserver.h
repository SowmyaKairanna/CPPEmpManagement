#pragma once
#include <iostream>
#include <vector>;
	

class IEmployeeObserver
{
	public:
	virtual ~IEmployeeObserver() = default;
	// Method to be called when an employee's salary is updated
	virtual void OnSalaryUpdated(int employeeId, double newSalary) = 0;
	// Method to be called when an employee is added
	virtual void OnEmployeeAdded(int employeeId) = 0;
	// Method to be called when an employee is removed
	virtual void OnEmployeeRemoved(int employeeId) = 0;
};

class HREmployeeObserver : public IEmployeeObserver
{
	public:
	void OnSalaryUpdated(int employeeId, double newSalary) override {
		std::cout << "Employee ID: " << employeeId << " has a new salary HR Observer: " << newSalary << std::endl;
	}
	void OnEmployeeAdded(int employeeId) override {
		std::cout << "Employee ID: " << employeeId << " has been added. HR Observer" << std::endl;
	}
	void OnEmployeeRemoved(int employeeId) override {
		std::cout << "Employee ID: " << employeeId << " has been removed. HR Observer" << std::endl;
	}
};


class LoggerEmployeeObserver : public IEmployeeObserver
{
public:
	void OnSalaryUpdated(int employeeId, double newSalary) override {
		std::cout << "Employee ID: " << employeeId << " has a new salary Logger Observer: " << newSalary << std::endl;
	}
	void OnEmployeeAdded(int employeeId) override {
		std::cout << "Employee ID: " << employeeId << " has been added. Logger Observer" << std::endl;
	}
	void OnEmployeeRemoved(int employeeId) override {
		std::cout << "Employee ID: " << employeeId << " has been removed. Logger Observer" << std::endl;
	}
};

class EmployeeChangeNotifier {

	private:
	// You can maintain a list of observers here if needed
	 std::vector<std::shared_ptr<IEmployeeObserver>> observers;

public:
	// Constructor
	EmployeeChangeNotifier() {
		// Initialization code if needed
	};
	// Method to notify about employee changes
	void notifySalaryChange(const int employeeId, const double newSalary);

	// Method to notify about employee Addition
	void notifySalaryAdd(const int employeeId);

	// Method to Add Observers
	void AddObserver(std::shared_ptr<IEmployeeObserver> observer);
};
