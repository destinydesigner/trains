// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: my_trains_service.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_MY_TRAINS_SERVICE_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_MY_TRAINS_SERVICE_H_
#include <memory>
#include "model/intf_towns_map.h"
#include "algorithm/dijkstra.h"
#include "algorithm/depth_first_search.h"
#include "service/trains_service.h"

namespace assignment
{
namespace trains
{
namespace domain
{
class CPath;
class CMyTrainsService
{
  public:
    CMyTrainsService(const ITownsMap& map);
  public:
    /* basic methods
     */

    /* set a different map
     */
    void setMap(const ITownsMap& map);

    /* get the minimum distance(or stop) between source and destination.
     * if there is not path between source and destination, return -1.
     */
    long minimumDistance(long src, long dest);

    /* get the length of path.
     * if there is not such path, return -1.
     */
    long getLength(const CPath& path);

    /* count the path number
     * which from source to destination and length >= min && length <= max
     */
    long countPath(long src, long dest, long min, long max);

  public:
    /* calculate route length by stop or distance.
     */
    void switchToStop();
    void switchToDistance();

  private:
    const ITownsMap* m_pMap;
    std::shared_ptr<CDijkstra> m_pShortestPathAlgorithm;
    std::shared_ptr<CDepthFirstSearch> m_pSearchAlgorithm;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_MY_TRAINS_SERVICE_H_
