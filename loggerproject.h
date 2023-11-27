#ifndef LOGGERPROJECT_H
#define LOGGERPROJECT_H

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

class Logger{

public:
    Logger(const QString& logFileName = "logfileSample.txt");

    void logInfo(const QString& message, const QString& modelName);
    void logError(const QString& message, const QString& modelName);
    void logWarning(const QString& message, const QString& modelName);

private:
    QString mLogFilePath;
    QFile mLogFile;

    void log(const QString& level, const QString& message, const QString& modelName);
};

#endif // LOGGERPROJECT_H
