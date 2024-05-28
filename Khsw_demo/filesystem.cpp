#include "filesystem.h"
#include "QFile"
#include "QDir"

fileSystem::fileSystem()
{
    QString basePath = QDir::currentPath();
    scpiPath = basePath;
}
