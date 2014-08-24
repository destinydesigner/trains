// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-19
// summary: path.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_PATH_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_PATH_H_
#include <memory>
#include <vector>

namespace assignment
{
namespace trains
{
namespace domain
{
class CTown;
class CPath
{
  public:
    /* A path consist of some ordered towns.
     */
    CPath();
  public:
    /* add new town in path
     */
    void add(long stop);

    /* return the first town of the path and put the iterator on first element.
     * if the path is empty, return null town which id is 0.
     */
    const CTown& start(void) const;

    /* Is there has next town in the path?
     */
    bool hasNext(void) const;

    /* return the next town. if there is no town, return null town which id is
     * 0.
     */
    const CTown& next(void) const;

    const std::string ToString(void) const;
  private:
    std::vector<std::shared_ptr<CTown> > m_steps;
    mutable std::vector<std::shared_ptr<CTown> >::const_iterator m_iter;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_PATH_H_
