#include <iostream>
#include <diagnostics.h>
#include <student_output.h>

void generate_diagnostics_report(){
std::cout << "=== SYSTEM STATUS ===" << std::endl;
std::cout << "Engineer: " << "WiktorFolerzynski" <<std:: endl;
std::cout << "Branch: " << get_branch_name() << std::endl;
std::cout << "Uptime: " << get_system_uptime() << std::endl;
std::cout << "Running Processes: " << get_running_processes() << std::endl;
}
