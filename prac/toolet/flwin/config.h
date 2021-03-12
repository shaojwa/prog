#ifndef CONDIG_H
#define CONDIG_H

#include <QString>

class Config {
public:
    static const QString TXT_ATTENTION;
    static const QString TXT_NO_SEARCH_PATH;
    static const QString TXT_INVALID_SEARCH_PATH;
    static const QString TXT_NO_BACKUP_PATH;
    static const QString TXT_INVALID_BACKUP_PATH;
    static const QString TXT_NO_PATTERN;
    static const QString TXT_NO_FOUND_LOGS;
    static const QString TXT_EXCEPTION_ON_FINDING;

    \
    static const QString TXT_BACKUP_INPROCESS;
    static const QString TXT_BACKUP_SUCCESS;
    static const QString TXT_BACKUP_FAILURE;
    static const QString TXT_BACKUP_CANCELED;
};
#endif // CONDIG_H
