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
 * support for int actuators
 */

#include <senml_int_actuator.h>
#include <senml_logging.h>


void SenMLIntActuator::actuate(const void *value, int dataLength, SenMLDataType dataType) {
  if (dataType == SENML_TYPE_NR) {
    this->set((int) *((double *) value));
    if (this->callback)
      this->callback((int) *((double *) value));
  } else log_debug("invalid type");
}






