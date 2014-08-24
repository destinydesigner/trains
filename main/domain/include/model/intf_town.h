// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-19
// summary: intf_town.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_INTF_TOWN_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_INTF_TOWN_H_
#include <memory>

namespace assignment
{
namespace trains
{
namespace domain
{
class CRoute;
class CRouteList;
class ITown
{
  public:
    virtual ~ITown();
  public:
    virtual long id(void) const = 0;

    /* return the name of this town.
     */
    virtual const std::string name(void) const = 0;

    /* add a adjacent route of this town.
     */
    virtual void addAdjacentRoute(const std::shared_ptr<CRoute> route) = 0;

    /* get all adjacent route of this town.
     */
    virtual CRouteList& getAllAdjacentRoutes(void) const = 0;

    /* get adjacent route by destination.
     */
    virtual const CRoute& getAdjacentRouteByDestination(long dest) const = 0;

    virtual const std::string ToString(void) const = 0;
};

}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_INTF_TOWN_H_
