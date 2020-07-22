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
 * support for string sensors
 */


#include <senml_string_record.h>
#include <senml_helpers.h>


void SenMLStringRecord::fieldsToJson() {
  SenMLRecord::fieldsToJson();
  printText(",\"vs\":\"", 7);
  String val = this->get();
  printText(val.c_str(), val.length());
  printText("\"", 1);
}





