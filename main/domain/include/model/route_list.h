// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: route_list.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_MODEL_ROUTE_LIST_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_MODEL_ROUTE_LIST_H_
#include <memory>
#include <map>
#include "model/route.h"

namespace assignment
{
namespace trains
{
namespace domain
{
class CRouteIterator;
class CRouteList
{
  public:
    /* add a route in route list.
    */
    void add(const std::shared_ptr<CRoute> route);

    /* get route by destination.
    */
    const CRoute& getRouteByDestination(long dest) const;

    /* get a new CRouteIterator which is at the first element position.
    */
    CRouteIterator getIterator(void) const;

    const std::string ToString(void) const;
  private:
    mutable std::map<long, std::shared_ptr<CRoute> > m_oRouteMap;
};

class CRouteIterator
{
  public:
    bool hasNext(void) const;
    const CRoute& next(void) const;
  private:
    /* At creating of a CRouteIterator, must specific which map it iterate on.
     * ctor is private, just firend can invoke.
     */
    explicit CRouteIterator(const std::map<long, std::shared_ptr<CRoute> >& map);
    friend CRouteIterator CRouteList::getIterator(void) const;
  private:
    const std::map<long, std::shared_ptr<CRoute> >& m_rRouteMap;
    mutable std::map<long, std::shared_ptr<CRoute> >::const_iterator m_oIter;

};


}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_MODEL_ROUTE_LIST_H_
