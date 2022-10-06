#pragma once
#include <iostream>
#include <string>

#define COMMAND_SYSTEM(point, command_system) point + to_string(command_system) +'\n'
#define MODEL(model, calling_convention) ".MODEL " + model + ", " + calling_convention + '\n'
#define INCLUDELIB(lib) "INCLUDELIB " + lib + '\n'
#define STACK(size)".STACK " + to_string(size) +'\n'
#define CONST(stream, type) ".CONST"s + '\n' + printData(stream, type) + '\n'
#define DATA(stream, type) ".DATA"s + '\n' + printData(stream, type) + '\n'
#define CODE ".CODE \nmain PROC \nSTART: "
#define ENDCODE "\nmain ENDP \nend main"
#define INVOKE(func) "\n    INVOKE " + func + ", 0"

#define VARCONSTRUCTOR(charr)  "   "s + types_map[type] + to_string(i + 1) + " BYTE " + '\"' + char(charr) + "\", " + '0' + '\n'; 