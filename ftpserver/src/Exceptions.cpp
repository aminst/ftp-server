#include "Exceptions.hpp"

using namespace std;

void Exceptions::print_error()
{
    cout << "‫‪500:‬‬ ‫‪Error‬‬" << endl;
}

void InvalidUsernameAndPassword::print_error()
{
    cout << "‫‪430:‬‬ ‫‪Invalid‬‬ ‫‪username‬‬ ‫‪or‬‬ ‫‪password‬‬" << endl;
}

void BadSequenceOfCommands::print_error()
{
    cout << "‫‪‫‪503:‬‬ ‫‪Bad‬‬ ‫‪sequence‬‬ ‫‪of‬‬ ‫‪commands.‬‬" << endl;
}