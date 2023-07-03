/*
 *  Program to read the temperature sensor on the ATMega328P
 *  Original code by Joel Jojo
 *
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of MIT Licence.
 *  To view a copy of this license, visit http://opensource.org/licenses/mit-license.php
 */

// Importing required libraries
#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include "TempReader.h"

// Function to read the temperature sensor
TempReader::ReadTemp()
{

  // Store register values
  uint8_t oldADMUX = ADMUX;
  uint8_t oldADCSRA = ADCSRA;
  uint8_t oldADCSRB = ADCSRB;
  uint8_t oldACSR = ACSR;

  // Configure ADC for reading temperature sensor
  ADMUX |= (1 << REFS0) | (1 << ADLAR) | (1 << REFS1) | (1 << MUX3);
  ADMUX &= ~((1 << MUX2) | (1 << MUX1) | (1 << MUX0));
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
  ADCSRA &= ~((1 << ADSC) | (1 << ADATE) | (1 << ADIF) | (1 << ADIE));
  ADCSRB &= ~((1 << ACME) | (1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0));
  ACSR |= (1 << ACD);

  // Start conversion
  ADCSRA |= (1 << ADSC);

  // Wait for conversion to complete
  uint8_t status = ADCSRA & (1 << ADSC);
  while (!status)
  {
    status = ADCSRA & (1 << ADSC);
  }

  // Read the temperature
  int temp = (ADCL >> 6) | (ADCH << 2);
  temp = int(33 + ((temp - 362) / 1.074));
  return temp;

  // Restore old register values
  ADMUX = oldADMUX;
  ADCSRA = oldADCSRA;
  ADCSRB = oldADCSRB;
  ACSR = oldACSR;
}