#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <iostream>

class Exceptions
{
public:
    virtual void print_error();

};

class InvalidUsernameAndPassword : public Exceptions
{
public:
    virtual void print_error();
};

class BadSequenceOfCommands : public Exceptions
{
public:
    virtual void print_error();
};

#endif