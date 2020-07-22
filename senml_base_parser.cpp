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
 * base class for all parsers
 */


#include <senml_base_parser.h>
#include <senml_logging.h>


void SenMLBaseParser::setCurrentPack(String &name) {
  //reset before we start so we indicate that nothing was ound
  this->curPack = NULL;
  //need a ref to the name in case we can't find the pack object
  this->curPackName = name;

  //check the root first, most common probably
  if (name == this->root->getBaseName()) {
    this->curPack = this->root;
    return;
  }
  SenMLBase *found = this->root->getFirst();
  while (found) {
    if (found->isPack() && name == ((SenMLPack *) found)->getBaseName()) {
      this->curPack = (SenMLPack *) found;
      return;
    }
    found = found->getNext();
  }
}

void SenMLBaseParser::checkBaseUnit(String &name) {
  if (!(this->curPack && name == senml_units_names[this->curPack->getBaseUnit()]))
    log_debug("bu different");
}

void SenMLBaseParser::setCurrentRecord(String &name) {
  this->curRec = NULL;
  this->curRecName = name;
  if (this->curPack) {
    SenMLBase *rec = this->curPack->getFirst();
    while (rec) {
      if (rec->isPack() == false && name == ((SenMLRecord *) rec)->getName()) {
        this->curRec = (SenMLRecord *) rec;
        return;
      }
      rec = rec->getNext();
    }
  }
}






