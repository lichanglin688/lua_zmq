#ifndef MYPRINTF_H
#define MYPRINTF_H
#include <QDebug>

#if 0
#define myPrintf(format,...)  qDebug("[%s, %s:%d] "format, strrchr(__FILE__,'\\')+1,__FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define myPrintf(format,...)
#endif

#define Printf(format,...)  qDebug("[%s, %s:%d] "format, strrchr(__FILE__,'\\')+1,__FUNCTION__, __LINE__, ##__VA_ARGS__)

#endif // MYPRINTF_H
