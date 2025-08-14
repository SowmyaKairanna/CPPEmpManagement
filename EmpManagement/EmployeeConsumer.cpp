#include "EmployeeConsumer.h"
#include "EmployeeProducer.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <atomic>
#include "Employee.h"
#include <mutex>;

std::mutex mtx;

void ConsumeEmployeeAsync(std::vector<std::shared_ptr<Employee>>& employees, std::atomic<int>& employeeCounter) 
{


	/*auto t = 4;
	std::atomic<int> employeeCounter(t);*/
	while (employeeCounter.load() < 15)
	{

		// This function is a placeholder for asynchronous employee production logic.
		// In a real-world scenario, it could involve fetching employee data from a database or an API.
		std::cout << "Consuming employee asynchronously..." << std::endl;

		std::cout << " Employee Count: " << employees.size() << std::endl;

		std::cout << " Top employee details: " << std::endl;
		if (!employees.empty()) {
			employees.back()->PrintDetails();
		} else {
			std::cout << "No employees to consume." << std::endl;
		}
		employeeCounter += (int)1;
		// Simulate some delay
		std::this_thread::sleep_for(std::chrono::seconds(1));

		

	}
}