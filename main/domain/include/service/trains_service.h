// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: trains_service.h
#ifndef _ASSIGNMENT_TRAINS_DOMAIN_TRAINS_SERVICE_H_
#define _ASSIGNMENT_TRAINS_DOMAIN_TRAINS_SERVICE_H_

namespace assignment
{
namespace trains
{
namespace domain
{
class IResult;
class IPath;
class ITrainsService
{
  public:
    virtual const IResult minimumDistance(int src, int dest) = 0;
    virtual const IResult getLength(const IPath& path) = 0;
    virtual const IResult searchPath(void) = 0;
};
}
}
}

#endif // _ASSIGNMENT_TRAINS_DOMAIN_TRAINS_SERVICE_H_
