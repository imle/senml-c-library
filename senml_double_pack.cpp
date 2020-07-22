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
 * pack (document) with double base values
 */


#include <senml_double_pack.h>
#include <senml_helpers.h>


void SenMLDoublePack::setupStreamCtx(Stream *dest, SenMLStreamMethod format) {
  SenMLPack::setupStreamCtx(dest, format);
  _streamCtx->baseValue.baseDouble = this->getBaseValue();
  _streamCtx->baseSum.baseDouble = this->getBaseValue();
  _streamCtx->baseDataType = SENML_TYPE_NR;
}

void SenMLDoublePack::setupStreamCtx(char *dest, int length, SenMLStreamMethod format) {
  SenMLPack::setupStreamCtx(dest, length, format);
  _streamCtx->baseValue.baseDouble = this->getBaseValue();
  _streamCtx->baseSum.baseDouble = this->getBaseValue();
  _streamCtx->baseDataType = SENML_TYPE_NR;
}

void SenMLDoublePack::fieldsToJson() {
  double val;
  SenMLPack::fieldsToJson();
  val = this->getBaseValue();
  if (val != 0) {
    printText(",\"bv\":", 6);
    printDouble(val, SENML_MAX_DOUBLE_PRECISION);
  }

  val = this->getBaseSum();
  if (val != 0) {
    printText(",\"bs\":", 6);
    printDouble(val, SENML_MAX_DOUBLE_PRECISION);
  }

}





