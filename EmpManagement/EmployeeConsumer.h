#pragma once
#include <vector>
#include <memory>
#include "Employee.h"
#include <atomic>

void ConsumeEmployeeAsync(std::vector<std::shared_ptr<Employee>>& employees, std::atomic<int>& employeeCounter);// , std::atomic<int>& employeeCounter);
