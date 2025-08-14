#include <iostream>;
#include <string>;
#include "IEmployeeObserver.h"

	// Method to notify about employee changes
	void EmployeeChangeNotifier::notifySalaryChange(const int employeeId, const double newSalary) {
		// Logic to handle the notification of changes
		for(const auto& observer : observers) {
			observer->OnSalaryUpdated(employeeId, newSalary);
		}
	};


	// Method to notify about employee changes
	void EmployeeChangeNotifier::notifySalaryAdd(const int employeeId) {
		// Logic to handle the notification of changes
		for (const auto& observer : observers) {
			observer->OnEmployeeAdded(employeeId);
		}
	};

	void EmployeeChangeNotifier::AddObserver(std::shared_ptr<IEmployeeObserver> observer) {
		// Logic to add observer
		observers.push_back(observer);
	}
