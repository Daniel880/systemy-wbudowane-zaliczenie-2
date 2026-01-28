#include "student_output.h"
#include "diagnostics.h"
#include <iostream>

void generate_diagnostics_report(){
	std::cout << "===SYSTEM STATUS ===" << std::endl;
	std::cout << "Engineer: " IgorSlowek << std::endl;
	std::cout << "Branch: " << getbranch_name() << std::endl;
	std::cout << "Uptime: " << get_system_uptime() << std::endl;
	std::cout << "Running Processes: " << get_running_processes() << std::endl;
}
