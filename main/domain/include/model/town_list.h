// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: town_list.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_TOWN_LIST_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_TOWN_LIST_H_
#include <memory>
#include <string>
#include "model/intf_town.h"

using assignment::trains::domain::ITown;

namespace assignment
{
namespace trains
{
namespace domain
{
class CTownIterator;
class CTownList
{
  public:
    /* add a town in list.
     * if the town already exist in the list, do nothing.
     */
    void addIfNotExist(const std::shared_ptr<ITown> town);
    ITown& getById(long id) const;
    CTownIterator getIterator(void) const;
    const std::string ToString(void) const;
  private:
    mutable std::map<long, std::shared_ptr<ITown> > m_oTownMap;
};

class CTownIterator
{
  public:
    bool hasNext(void) const;
    const ITown& next(void) const;
  private:
    /* At creating of a CTownIterator, must specific which map it iterate on.
     * ctor is private, just firend can invoke.
     */
    explicit CTownIterator(const std::map<long, std::shared_ptr<ITown> >& map);
    friend CTownIterator CTownList::getIterator(void) const;
  private:
    const std::map<long, std::shared_ptr<ITown> >& m_rTownMap;
    mutable std::map<long, std::shared_ptr<ITown> >::const_iterator m_oIter;
};

}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_TOWN_LIST_H_
