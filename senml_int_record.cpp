/*  _  __  ____    _   _ 
 * | |/ / |  _ \  | \ | |
 * | ' /  | |_) | |  \| |
 * | . \  |  __/  | |\  |
 * |_|\_\ |_|     |_| \_|
 * 
 * (c) 2018 KPN
 * License: MIT License.
 * Author: Jan Bogaerts
 * 
 * support for int sensors
 */

#include <senml_int_record.h>
#include <senml_helpers.h>
#include <senml_int_pack.h>
#include <senml_double_pack.h>


SenMLIntRecord::SenMLIntRecord(const char *name) : SenMLRecordTemplate(name) {
}

SenMLIntRecord::SenMLIntRecord(const char *name, SenMLUnit unit) : SenMLRecordTemplate(name, unit) {
}

int SenMLIntRecord::getAdjustedValue() {
  int adjustedValue = this->get();
  return adjustedValue;
}

double SenMLIntRecord::getAdjustedValueD() {
  double adjustedValue = this->get();
  return adjustedValue;
}

void SenMLIntRecord::fieldsToJson() {
  SenMLRecord::fieldsToJson();
  if (this->asSum())
    printText(",\"s\":", 5);
  else
    printText(",\"v\":", 5);

  //if the parent pack has a base value or base sum of type double, then we need to render a double value.
  printDouble(this->getAdjustedValueD(), SENML_MAX_DOUBLE_PRECISION);
}






