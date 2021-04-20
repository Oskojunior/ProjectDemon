#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <utime.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>
#include <linux/fs.h>

off_t getSize(char* path);
mode_t getChmod(char* path);
time_t getLastModificationTime(char* path);
time_t getLastAccesTime(char* path);
void logHandler();
//compare and delete target
//void clearCatalogs(char* sourcePath, char* targetPath);
void clearCatalogs(char* sourcePath, char* targetPath,char* currentFile ,bool recurSync);
//compare and fill target 
void compareCatalogs(char* sourcePath, char* targetPath, int threshold, bool recurSync);
//updates content source->target 
void updateFile(char* sourcePath, char* targetPath,int threshold);
//sets time of last modification source->target 
int updateLastModFileTime(char* sourcePath, char* targetPath);
int updateFileChmod(char* sourcePath, char* targetPath);
char* pathToFile(char* sourcePath, char* file);
char* changeCatalogs(char* newPath, char* sourcePath);
bool isFileUpToDate(char* sourceFilePath, char* targetFilePath);
bool compareFiles(char* fileNameSource, char* fileNameTarget, char* sourceFilePath, char* targetFilePath, int threshold);
bool isCatalogExist(char* sourceCatalogName, char* targetDirectory);