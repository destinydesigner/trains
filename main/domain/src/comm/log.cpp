// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-22
// summary: log.cpp
#include <stdio.h>
#include <string>
#include "comm/log.h"

static const uint32_t MAX_FORMAT_BUFFER_SIZE = 1024;

using assignment::trains::comm::CLog;

CLog * CLog::m_pInstance = NULL;

CLog::CLog():
    m_pFile(fopen("default.log", "w+"))
{
}

CLog::~CLog()
{
    fflush(m_pFile);
    fclose(m_pFile);
}

CLog * CLog::instance()
{
    if ( m_pInstance == NULL )
    {
        m_pInstance = new CLog();
    }
    return m_pInstance;
}

void CLog::setLogFile(const std::string file)
{
    m_pFile = fopen(file.c_str(), "w+");
}

void CLog::log(const char* pszFormat, ...)
{
    char szBuff[MAX_FORMAT_BUFFER_SIZE] = {0};

    va_list ap;
    va_start(ap, pszFormat);
    vsnprintf(szBuff, sizeof(szBuff), pszFormat, ap);
    va_end(ap);

    fprintf(m_pFile, "%s", std::string(szBuff).c_str());
    fflush(m_pFile);
}



