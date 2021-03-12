

#include "config.h"

CConfig::CConfig():
m_nProgress(0),
m_extractType(EXTRACT_TYPE_AUTO)
{
    m_pattern[0] = _T('\0');
    m_szSrc[0] = _T('\0');
    m_szDst[0] = _T('\0');
}


CConfig::~CConfig() {
}


int CConfig::setPattern(LPCTSTR patt) {
    if (_tcslen(patt) > _countof(m_pattern) - 1) {
        return -1;
    }
    _tcscpy(m_pattern, patt);
    return 0;
}


int CConfig::setSrc(LPCTSTR src) {
    if (_tcslen(src) > _countof(m_szSrc) - 1) {
        return -1;
    }
    _tcscpy(m_szSrc, src);
    return 0;

}


int CConfig::setDst(LPCTSTR dst) {
    if (_tcslen(dst) > _countof(m_szDst) - 1) {
        return -1;
    }
    _tcscpy(m_szDst, dst);
    return 0;
}


LPCTSTR CConfig::getPattern() {
    return m_pattern;
}

LPCTSTR CConfig::getSrc() {
    return m_szSrc;
}

LPCTSTR CConfig::getDst() {
    return m_szDst;
}

int CConfig::getProgress() {
    return m_nProgress;
}

void CConfig::setProgress(int prog) {
    m_nProgress = prog;
}


void CConfig::setExtractType(EExtratType type) {
    m_extractType = type;
}


EExtratType CConfig::getExtractType() {
    return m_extractType;
}