#include "EmployeeProducer.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <atomic>
#include "Employee.h"
#include <mutex>;


	void ProduceEmployeeAsync(std::vector<std::shared_ptr<Employee>>& employees, std::atomic<int>& employeeCounter) // std::atomic<int>& employeeCounter)
{
		std::lock_guard<std::mutex> lock(mtx);
	//	auto t = 4;
	//std::atomic<int> employeeCounter(t);
	while (employeeCounter.load()<15)
	{

		// This function is a placeholder for asynchronous employee production logic.
		// In a real-world scenario, it could involve fetching employee data from a database or an API.
		std::cout << "Producing employee asynchronously..." << std::endl;

		employees.emplace_back(std::make_shared<Employee>(employeeCounter.load(), "John Doe"+ employeeCounter.load(), 50000, Department::Engineering));
		employeeCounter += (int)1;
		// Simulate some delay
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "Employee production completed." << std::endl;

	}
}