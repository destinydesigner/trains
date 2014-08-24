// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-19
// summary: towns_map.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_TOWNS_MAP_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_TOWNS_MAP_H_
#include <memory>

namespace assignment
{
namespace trains
{
namespace domain
{
//class ITown;
class CRoute;
class CRouteList;
class CTown;
class CTownList;
class ITownsMap
{
  public:
    virtual ~ITownsMap();

  public:
    /* Get the route between source and destination.
     * If there is not route between source and destination, return NullRoute.
     */
    virtual const CRoute& getRoute(long src, long dest) const = 0;

    /* Add route between source and destination in map.
     * If source does not have adjacent, then make a new CRouteList to source.
     * and add route.
     * If source has adjacent, then make a new route and add in CRouteList.
     */
    virtual void addRoute(
        const std::shared_ptr<CTown> src,
        const std::shared_ptr<CTown> dest,
        long distance) = 0;

    /* get adjacent route of source.
     * return a reference to adjacent of source. client can add new route in
     * this adjacent.
     */
    virtual CRouteList& getAllAdjacentRoutesBySource(long src) const = 0;

    /* get all towns in map
     */
    virtual const CTownList& getAllTowns(void) const = 0;

    virtual const std::string ToString() = 0;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_TOWNS_MAP_H_
