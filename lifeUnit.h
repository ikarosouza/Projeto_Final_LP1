#ifndef _LIFEUNIT_H_
#define _LIFEUNIT_H_


class LifeUnit{
  int unit;
  LifeUnit *next;
public:
  LifeUnit();
  int getUnit() { return unit; };
  LifeUnit* getNext() { return next; };
  void setNext(LifeUnit *n){ this->next = n; }
};

#endif

inline LifeUnit::LifeUnit(){
  unit = 1;
  next = NULL;
}