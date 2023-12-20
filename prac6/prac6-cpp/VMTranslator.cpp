#include <string>

#include "VMTranslator.h"

using namespace std;

/**
 * VMTranslator constructor
 */
VMTranslator::VMTranslator() {
    // Your code here
}

/**
 * VMTranslator destructor
 */
VMTranslator::~VMTranslator() {
    // Your code here
}

/** Generate Hack Assembly code for a VM push operation */
string VMTranslator::vm_push(string segment, int offset){
    string trans = "";
    trans += "// push " + segment + to_string(offset) + "\n";
    if (segment == "constant") {
        trans += "@" + to_string(offset) + "\n";
        trans += "D=A\n"; 
        trans += "@SP\n"; 
        trans += "A=M\n"; 
        trans += "M=D\n"; 
        trans += "@SP\n"; 
        trans += "M=M+1\n"; 
    } else if (segment == "static") {
        trans += "@" + to_string(offset + 16) + "\n";
        trans += "D=M\n";
        trans += "@SP\n";
        trans += "A=M\n"; 
        trans += "M=D\n";
        trans += "@SP\n";
        trans += "M=M+1\n";
    } else {
        trans += "@" + to_string(offset) + "\n";
        trans += "D=A\n";
        
        if (segment == "this") {
            trans += "@THIS\n";
            trans += "A=M+D\n";
        } else if (segment == "that") {
            trans += "@THAT\n";
            trans += "A=M+D\n";
        } else if (segment == "argument") {
            trans += "@ARG\n";
            trans += "A=M+D\n";
        } else if (segment == "local") {
            trans += "@LCL\n";
            trans += "A=M+D\n";
        } else if (segment == "temp") {
            trans += "@5\n";
            trans += "A=A+D\n";
        } else if (segment == "pointer") {
            trans += "@3\n";
            trans += "A=A+D\n";
        }

        trans += "D=M\n";
        trans += "@SP\n";
        trans += "A=M\n";
        trans += "M=D\n";
        trans += "@SP\n";
        trans += "M=M+1\n";
}

/** Generate Hack Assembly code for a VM pop operation */
string VMTranslator::vm_pop(string segment, int offset){    
    string trans = "";
    trans += "// pop " + segment + to_string(offset) + "\n";
    if (segment == "static") {
        trans += "@SP\n"; // pop value into D
        trans += "AM=M-1\n";
        trans += "D=M\n";
        trans += "@" + to_string(16 + offset) + "\n";
        trans += "M=D\n";
    } else {
        trans += "@" + to_string(offset) + "\n"; // get address into R13
        trans += "D=A\n";

        if (segment == "this") {
            trans += "@THIS\n";
            trans += "D=M+D\n";
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "that") {
            trans += "@THAT\n";
            trans += "D=M+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "argument") {
            trans += "@ARG\n";
            trans += "D=M+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "local") {
            trans += "@LCL\n";
            trans += "D=M+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "pointer") {
            trans += "@3\n";
            trans += "D=A+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "temp") {
            trans += "@5\n";
            trans += "D=A+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        }
    }

    return trans;
}

/** Generate Hack Assembly code for a VM add operation */
string VMTranslator::vm_add(){
    return "";
}

/** Generate Hack Assembly code for a VM sub operation */
string VMTranslator::vm_sub(){
    return "";
}

/** Generate Hack Assembly code for a VM neg operation */
string VMTranslator::vm_neg(){
    return "";
}

/** Generate Hack Assembly code for a VM eq operation */
string VMTranslator::vm_eq(){
    return "";
}

/** Generate Hack Assembly code for a VM gt operation */
string VMTranslator::vm_gt(){
    return "";
}

/** Generate Hack Assembly code for a VM lt operation */
string VMTranslator::vm_lt(){
    return "";
}

/** Generate Hack Assembly code for a VM and operation */
string VMTranslator::vm_and(){
    return "";
}

/** Generate Hack Assembly code for a VM or operation */
string VMTranslator::vm_or(){
    return "";
}

/** Generate Hack Assembly code for a VM not operation */
string VMTranslator::vm_not(){
    return "";
}

/** Generate Hack Assembly code for a VM label operation */
string VMTranslator::vm_label(string label){
    return "";
}

/** Generate Hack Assembly code for a VM goto operation */
string VMTranslator::vm_goto(string label){
    return "";
}

/** Generate Hack Assembly code for a VM if-goto operation */
string VMTranslator::vm_if(string label){
    return "";
}

/** Generate Hack Assembly code for a VM function operation */
string VMTranslator::vm_function(string function_name, int n_vars){
    return "";
}

/** Generate Hack Assembly code for a VM call operation */
string VMTranslator::vm_call(string function_name, int n_args){
    return "";
}

/** Generate Hack Assembly code for a VM return operation */
string VMTranslator::vm_return(){
    return "";
}