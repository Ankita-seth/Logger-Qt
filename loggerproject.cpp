#include "loggerproject.h"

Logger::Logger(const QString& logFileName)
    : mLogFilePath(logFileName), mLogFile(mLogFilePath)
{
    if (!mLogFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to Open log File";
    }
}

void Logger::logInfo(const QString& message, const QString& modelName)
{
    log("INFO", message, modelName);
}

void Logger::logError(const QString& message, const QString& modelName)
{
    log("ERROR", message, modelName);
}

void Logger::logWarning(const QString& message, const QString& modelName)
{
    log("WARNING", message, modelName);
}

void Logger::log(const QString& level, const QString& message, const QString& modelName)
{
    if (!mLogFile.isOpen())
    {
        qDebug() << "Log File is not open.";
        return;
    }

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QTextStream stream(&mLogFile);
    stream << currentDateTime.toString("MMM d yyyy, hh:mm:ss : ")
            <<   level << ": " << modelName
            << " |File: " << __FILE__
            << " |Function: " << __FUNCTION__
            << " | " << message << "\n";
}




