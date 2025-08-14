#include "Employee.h"
#include <iostream>
#include <atomic>



// Constructor implementation
Employee::Employee(int idParam, const std::string& nameParam, int salaryParam, Department departmentParam)
    : id(idParam), name(nameParam), salary(salaryParam), department(departmentParam) {
    std::cout << "Employee with ID: " << id << " is being constructed." << std::endl;
};

// Destructor implementation  
Employee::~Employee() {  
   // Destructor implementation (if needed)  
   std::cout << "Employee with ID: " << id << " is being destroyed." << std::endl;  
}
// Getter implementations
int Employee::getId() const { return id; }
std::string Employee::getName() const { return name; }
int Employee::getSalary() const { return salary; }
void Employee::setSalary(double sl) { salary=sl; }
Department Employee::getDepartment() const { return department; }

// PrintDetails implementation
void Employee::PrintDetails() const
{
    std::cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary
        << ", Department: " << (department == HR ? "HR" : department == Finance ? "Finance" :
            department == Engineering ? "Engineering" : "Marketing") << std::endl;
}