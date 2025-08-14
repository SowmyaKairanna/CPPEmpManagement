// EmpManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>;
#include <memory>
#include "Employee.h";
#include <map>;
#include <numeric>
#include "ISorter.h";
#include "IEmployeeObserver.h"
#include <algorithm>  
#include <math.h>;
#include "EmployeeProducer.h"
#include "EmployeeConsumer.h"
#include <thread>

void AddEmployees(std::vector<std::shared_ptr<Employee>> &employees);
void SortEmployees(std::vector<std::shared_ptr<Employee>>& employees, const ISorter& sorter);

int main()  
{  
  std::cout << "Start Program!\n";     
  
  std::vector<std::shared_ptr<Employee>> employees;
 
  AddEmployees(employees);

  std::cout << "After Add!\n";

  // Display employee details  
  for (auto emp : employees) {
      emp->PrintDetails();
  }

  SalarySorter s;
  SortEmployees(employees,s);

  std::cout << "After Sort by Salary!\n";

  // Display employee details  
  for (auto emp : employees) {
      emp->PrintDetails();
  }

 NameSorter nSorter;
  SortEmployees(employees, nSorter);

 
  std::cout << "After Sort by Name!\n";

  // Display employee details  
  for (auto emp : employees) {
      emp->PrintDetails();
  }

  
  EmployeeChangeNotifier notifier;
  notifier.AddObserver(std::make_shared<HREmployeeObserver>());
  notifier.AddObserver(std::make_shared<LoggerEmployeeObserver>());

  notifier.notifySalaryChange(1, 78000);                  
  


  std::map<int, std::shared_ptr<Employee>> employeeIndex;

  for (const auto& emp : employees) {
      employeeIndex.emplace(emp->getId(), emp);  // raw pointer for demo purpose
  }
 
  auto it = std::find_if(employees.begin(), employees.end(), [](const auto emp) {
      return emp->getDepartment() == Department::Engineering;
  });
  
  if (it != employees.end())
      std::cout << "Engineering Employee: "; (*it)->PrintDetails();

  int result = std::count_if(employees.begin(), employees.end(), [](const auto emp) {
      return emp->getSalary() > 5000;
  });

  std::cout << "Count of salaries: " << result << std::endl;

  //Step 4: Use std::transform() to give salary hike to all
      std::for_each(employees.begin(), employees.end(), [](auto emp) {
      emp->setSalary(emp->getSalary() * 1.10);  // 10% hike
  });
      // Display employee details  
      for (auto emp : employees) {
          emp->PrintDetails();
      }

  for (auto it = employees.rbegin(); it != employees.rend(); ++it) {
          (*it)->PrintDetails();
      }

  //Step 6: Use std::partition() to separate high earners
      auto mid = std::partition(employees.begin(), employees.end(), [](const auto emp) {
      return emp->getSalary() > 60000;
  });
  std::cout << "High Earners:\n";
  std::for_each(employees.begin(), mid, [](const auto emp) { emp->PrintDetails(); });


  double totalSalary = std::accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const auto emp) {
      return sum + emp->getSalary();
  });
  std::cout << "Total Payroll: " << totalSalary << std::endl;


  //Start Produce and Consume Employees
  std::atomic<int> employeeCounter(3);
 /* ProduceEmployeeAsync(employees);
  ConsumeEmployeeAsync(employees);*/
std::thread producerThread(ProduceEmployeeAsync, std::ref(employees),std::ref(employeeCounter));//, employeeCounter);
 std::thread consumerThread(ConsumeEmployeeAsync, std::ref(employees), std::ref(employeeCounter));// , employeeCounter);

 producerThread.join();
  consumerThread.join();
  return 0;
}

void AddEmployees(std::vector<std::shared_ptr<Employee>>& employees) {
   
    employees.emplace_back(std::make_shared<Employee>( 1, "John Doe", 50000, Department::Engineering)); 
   
    employees.emplace_back(std::make_shared<Employee>(2, "Jane Smith", 60000.0, Department::HR));   

    employees.emplace_back(std::make_shared<Employee>(3, "Alice Johnson", 55000.0, Department::Finance));
}

void SortEmployees(std::vector<std::shared_ptr<Employee>>& employees,const ISorter& sorter) {
    sorter.Sort(employees);

}
