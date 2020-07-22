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
 * support for float sensors
 */


#include <senml_float_record.h>
#include <senml_helpers.h>
#include <senml_double_pack.h>
#include <senml_int_pack.h>


SenMLFloatRecord::SenMLFloatRecord(const char *name) : SenMLRecordTemplate(name) {
}

SenMLFloatRecord::SenMLFloatRecord(const char *name, SenMLUnit unit) : SenMLRecordTemplate(name, unit) {
}

float SenMLFloatRecord::getAdjustedValue() {
  float adjustedValue = this->get();
  return adjustedValue;
}

void SenMLFloatRecord::fieldsToJson() {
  SenMLRecord::fieldsToJson();
  if (this->asSum())
    printText(",\"s\":", 5);
  else
    printText(",\"v\":", 5);
  printDouble(this->getAdjustedValue(), SENML_MAX_DOUBLE_PRECISION);
}






