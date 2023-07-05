/*
 *  Program to read the temperature sensor on the ATMega328P
 *  Original code by Joel Jojo
 *
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of MIT Licence.
 *  To view a copy of this license, visit http://opensource.org/licenses/mit-license.php
 */

#ifndef TempReader_h
#define TempReader_h

#include <avr/io.h>
#include <stdbool.h>

class TempReader
{
public:
  int ReadTempinC();
  int ReadTempinF();
};

#endif