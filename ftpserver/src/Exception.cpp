#include "Exception.hpp"

using namespace std;

void Exception::print_error()
{
    cout << error << endl;
}

int Exception::get_num()
{
    return number;
}

void InvalidUsernameAndPassword::print_error()
{
    cout << msg << endl;
}

int InvalidUsernameAndPassword::get_num()
{
    return num;
}

void BadSequenceOfCommands::print_error()
{
    cout << msg << endl;
}


int BadSequenceOfCommands::get_num()
{
    return num;
}

void SyntaxErrorInParametersOrArguments::print_error()
{
    cout << msg << endl;
}


int SyntaxErrorInParametersOrArguments::get_num()
{
    return num;
}

void NeedAccountForLogin::print_error()
{
    cout << msg << endl;
}


int NeedAccountForLogin::get_num()
{
    return num;
}

void FileUnavailable::print_error()
{
    cout << msg << endl;
}


int FileUnavailable::get_num()
{
    return num;
}