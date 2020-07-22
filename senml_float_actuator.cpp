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
 * support for float actuators
 */

#include <senml_float_actuator.h>
#include <senml_logging.h>


void SenMLFloatActuator::actuate(const void *value, int dataLength, SenMLDataType dataType) {
  if (dataType == SENML_TYPE_NR) {
    this->set((float) *((double *) value));
    if (this->callback)
      this->callback((float) *((double *) value));
  } else log_debug("invalid type");
}






