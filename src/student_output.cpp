#include "student_output.h"
#include "diagnostics.h"

#include <iostream>
using namespace std;

void generate_diagnostics_report(){
cout<<"=== SYSTEM STATUS ==="<<endl;
cout<<"Engineer: "<<"ZuzannaKozak"<<endl;
cout<<"Branch :"<<get_branch_name()<<endl;
cout<<"Uptime: "<<get_system_uptime()<<endl;
cout<<"Running Processes: "<<get_running_processes()<<endl;
}
