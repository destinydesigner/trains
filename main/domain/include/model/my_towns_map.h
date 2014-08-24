// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: my_towns_map.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_MY_TOWNS_MAP_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_MY_TOWNS_MAP_H_
#include <memory>
#include <map>
#include <string>
#include "model/intf_towns_map.h"

using assignment::trains::domain::ITownsMap;

namespace assignment
{
namespace trains
{
namespace domain
{
class CRouteList;
class CTownList;
class CMyTownsMap : public ITownsMap
{
  public:
    CMyTownsMap();

  public:
    /* Get the route between source and destination.
     * If there is not route between source and destination, return NullRoute.
     */
    const CRoute& getRoute(long src, long dest) const;

    /* Add route between source and destination in map.
     * If source does not have adjacent, then make a new CRouteList to source.
     * and add route.
     * If source has adjacent, then make a new route and add in CRouteList.
     */
    void addRoute(
        const std::shared_ptr<CTown> src,
        const std::shared_ptr<CTown> dest,
        long distance);
    void addRoute(long src, long dest, long distance);

    /* get adjacent route of source.
     * return a reference to adjacent of source. client can add new route in
     * this adjacent.
     */
    CRouteList& getAllAdjacentRoutesBySource(long src) const;

    /* get all towns in map
     */
    const CTownList& getAllTowns(void) const;

    const std::string ToString();

  private:
    mutable std::shared_ptr<CTownList> m_oAllTowns;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_MY_TOWNS_MAP_H_
