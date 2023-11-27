#include "loggerproject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Logger* loggerObj = new Logger();

    loggerObj->logInfo("Pen application started.", "ScanningPens");
    loggerObj->logError("Error in Pen application.", "ScanningPens");
    loggerObj->logWarning("Warning in Pen application.", "ScanningPens");

    return a.exec();
}
