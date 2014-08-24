// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: dijkstra.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_DIJKSTRA_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_DIJKSTRA_H_
#include "model/my_towns_map.h"

namespace assignment
{
namespace trains
{
namespace domain
{
class ITownsMap;
class CDistanceFromSrc
{
  public:
    explicit CDistanceFromSrc(long dest, long distance);
  public:
    long getDistance() const;
    long getDest() const;
  public:
    bool operator<(const CDistanceFromSrc& node) const;
  private:
    long m_dest;
    long m_distance;
};

class CDijkstra
{
  public:
    explicit CDijkstra(const ITownsMap& map);
  public:
    void setMap(const ITownsMap& map);
    long getMinimum(long src, long dest);
  private:
    const ITownsMap* m_pTownMap;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_DIJKSTRA_H_
