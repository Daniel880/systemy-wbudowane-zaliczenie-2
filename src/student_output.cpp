#include "student_output.h"
#include "diagnostics.h"
#include <string>

#include <iostream>
using namespace std;

void generate_diagnostics_report(){
string branch = get_branch_name();
string prefix = "Zaliczenie2-";

if(branch.find(prefix)==0){
branch.erase(0,prefix.length());
}

cout<<"=== SYSTEM STATUS ==="<<endl;
cout<<"Engineer: "<<"ZuzannaKozak"<<endl;
cout<<"Branch :"<<branch<<endl;
cout<<"Uptime: "<<get_system_uptime()<<endl;
cout<<"Running Processes: "<<get_running_processes()<<endl;
}
