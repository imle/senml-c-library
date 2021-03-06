
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
 * base class for all senml objects header
 */

#ifndef SENMLBASE
#define SENMLBASE

#ifdef __MBED__
#include "mbed.h"
#include "sstream"
#else
#include <Arduino.h>


#endif
#include <senml_enums.h>
#include <math.h>


/**
 * the base class for all objects that can be used in the senml data tree.
 */
class SenMLBase {
  friend class SenMLPack;

  friend class SenMLRecord;

  friend class SenMLJsonListener;

  friend class SenMLBaseParser;

 public:
  SenMLBase();
  ~SenMLBase();

  /** get the next item in the list.
   * @returns: a pointer to the next SenMLBase object in the list or NULL when at the end of the list.
   */
  SenMLBase *getNext() { return this->_next; };

  /**
   * Get the root object of this list. Usually, this is a SenMLPack object.
   * The root object is defined as the first item in the list.
   * @returns: a pointer to the first SenMLBase object in the list or NULL when there is none.
   */
  SenMLBase *getRoot();

  //This function is called by the root SenMLPack object to indicate that the object
  //should adjust it's time info relative to the new base time (if applicable)
  //doesn't do anything by default
  //params: prev: previous base time
  //        time: new base time
  virtual void adjustToBaseTime(double prev, double time) {};

  /**
   * renders all the fields to json, without the starting and ending brackets.
   * Inheriters can extend this function if they want to add extra fields to the json output
   * note: this is public so that custom implementations for the record object can use other objects
   * internally and render to json using this function (ex: coordinatesRecord using 3 floatRecrods for lat, lon & alt.
   * @returns: None
  */
  virtual void fieldsToJson() = 0;

 protected:

  /*
  renders all the fields to json, with the starting and ending brackets.
  Inheriters can extend this function if they want to add extra fields to the json output
  note: tihs is public so that custom implementations for the record object can use other objects internally and render to json using this function (ex: coordinatesRecord using 3 floatRecrods for lat, lon & alt.
  */
  virtual void contentToJson() = 0;

  //assign the element in the list that this object points to.
  void setNext(SenMLBase *value);

  //assign the previous element in the list that thisobject points to.
  void setPrev(SenMLBase *value);
  //assign the previous element in the list that thisobject points to.
  SenMLBase *getPrev();

  //derived classes can use this function to see if the root object (getRoot) is a SenMLPack
  //class or not.
  virtual bool isPack() { return false; }

  //calculates the nr of fields that this object will produce.
  virtual int getFieldLength() = 0;

 private:
  SenMLBase *_next;                               //reference to the next element in the list.
  SenMLBase *_prev;                               //reference to the previous element, needed for deletion of record
};

#endif // SENMLBASE






