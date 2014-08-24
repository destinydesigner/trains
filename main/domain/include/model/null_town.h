// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-24
// summary: null_town.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_MODEL_NULL_TOWN_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_MODEL_NULL_TOWN_H_
#include <memory>
#include <string>
#include <map>
#include "model/intf_town.h"

using assignment::trains::domain::ITown;

namespace assignment
{
namespace trains
{
namespace domain
{
class CRoute;
class CNullTown : public ITown
{
  public:
    static ITown& NullTown();
  public:
    /* return the identify number of this town.
     */
    long id(void) const;

    /* return the name of this town.
     */
    const std::string name(void) const;

    /* add a adjacent route of this town.
     */
    void addAdjacentRoute(const std::shared_ptr<CRoute> route);

    /* get all adjacent route of this town.
     */
    CRouteList& getAllAdjacentRoutes(void) const;

    /* get adjacent route by destination.
     */
    const CRoute& getAdjacentRouteByDestination(long dest) const;

    const std::string ToString(void) const;

  private:
    CNullTown();

  private:
    std::shared_ptr<CRouteList> m_adjacent;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_MODEL_TOWN_H_
