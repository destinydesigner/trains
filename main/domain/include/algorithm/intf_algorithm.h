// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: intf_algorithm.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_INTF_ALGORITHM_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_INTF_ALGORITHM_H_
#include <memory>

namespace assignment
{
namespace trains
{
namespace domain
{
class IResult;
class IAlgorithm
{
  public:
    virtual int doAlgorithm(void) = 0;
    virtual std::shared_ptr<IResult> getResult(void) = 0;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_ALGORITHM_INTF_ALGORITHM_H_
