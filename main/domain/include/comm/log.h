// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-22
// summary: log.h
#ifndef _ASSIGNMENT_TRAINS_COMM_LOG_H_
#define _ASSIGNMENT_TRAINS_COMM_LOG_H_
#include <string>

namespace assignment
{
namespace trains
{
namespace comm
{
class CLog
{
  public:
    ~CLog();
    static CLog * instance();
    void setLogFile(const std::string file);
    void log(const char* pszFormat, ...);
  protected:
    CLog();
  private:
    static CLog * m_pInstance;
    FILE * m_pFile;
};
}
}
}

#define MY_LOG CLog::instance()

#endif // _ASSIGNMENT_TRAINS_COMM_LOG_H_
