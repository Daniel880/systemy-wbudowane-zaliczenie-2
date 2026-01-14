#include "student_output.h"
#include "diagnostics.h"

#include <iostream>

void generate_diagnostics_report() {
	std::cout << "==System status==" << std::endl;
	std::cout << "Engineer: " << "LukaszBlajchert" <<std::endl;
	std::cout << "Branch: " << get_branch_name() << std::endl;
	std::cout << "Uptime: " <<get_system_uptime() << std::endl;
	std::cout << "Running Processes: " << get_running_processes() << std::endl;
}
