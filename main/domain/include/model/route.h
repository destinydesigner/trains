// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: route.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_ROUTE_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_ROUTE_H_
#include <memory>
#include <string>
#include "model/town.h"

//using assignment::trains::domain::CTown;

namespace assignment
{
namespace trains
{
namespace domain
{
class CTown;
class CRoute
{
  public:
    /* this is not a graceful implementation, but it works.
     */
    enum ERouteType {
        STOP,
        DISTANCE
    };
  public:
    CRoute();
    CRoute(long src, long dest, long distance);
    CRoute(
        const std::shared_ptr<CTown> src,
        const std::shared_ptr<CTown> dest,
        long distance);

  public:
    static const CRoute& NullRoute();
    static void setRouteType(enum ERouteType e);

  public:
    /* get the length of the route.
     * if there is no such route, return INFINITE_DISTANCE.
     * if RouteType is STOP, return 1.
     * if RouteType is DISTANCE, return this->distance.
     */
    long getLength(void) const;

    /* return the source town.
     * if this is a null route, return null town.
     */
    const CTown& getSource(void) const;

    /* return the destination town.
     * if this is a null route, return null town.
     */
    const CTown& getDestination(void) const;

    const std::string ToString(void) const;

  private:
    static ERouteType m_routeType;
    long m_distance;
    std::shared_ptr<CTown> m_pSource;
    std::shared_ptr<CTown> m_pDestination;
};

}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_ROUTE_H_
