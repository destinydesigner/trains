// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: depth_first_search.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_DEPTH_FIRST_SEARCH_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_DEPTH_FIRST_SEARCH_H_
#include "model/my_towns_map.h"

namespace assignment
{
namespace trains
{
namespace domain
{
class ITownsMap;
class CDepthFirstSearch
{
  public:
    explicit CDepthFirstSearch(const ITownsMap& map);

  public:
    void setMap(const ITownsMap& map);
    long countPath(long src, long dest, long min, long max);

  private:
    long countAgreedPath(long current, long dest, long minDistance, long maxDistance, long currentDistance);

  private:
    const ITownsMap* m_pTownMap;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_DEPTH_FIRST_SEARCH_H_
