#pragma once
#include <vector>;
#include <memory>;
#include "Employee.h"
#include <algorithm>;


class ISorter
{
public:
	void virtual Sort(std::vector<std::shared_ptr<Employee>>& employees) const = 0;
};

class SalarySorter : public ISorter
{
	public:
	void Sort(std::vector<std::shared_ptr<Employee>>& employees) const override {
		std::sort(employees.begin(), employees.end(), 
			[](const std::shared_ptr<Employee>& a, const std::shared_ptr<Employee>& b) {
			return a->getSalary() < b->getSalary();
		});

		//std::cout << "In Sort by Salary: "  << std::endl;

		//// Display employee details  
		//for (auto emp : employees) {
		//	emp->PrintDetails();
		//}
	}
};

class NameSorter : public ISorter
{
	public:
	void Sort(std::vector<std::shared_ptr<Employee>>& employees) const override {
		std::sort(employees.begin(), employees.end(), 
			[](const std::shared_ptr<Employee>& a, const std::shared_ptr<Employee>& b) {
			return a->getName() < b->getName();
		});

		//std::cout << "In Sort by Name: " << std::endl;

		//// Display employee details  
		//for (auto emp : employees) {
		//	emp->PrintDetails();
		//}
	}
};