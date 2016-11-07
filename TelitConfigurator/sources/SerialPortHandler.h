#ifndef SERIAL_PORT_HANDLER_H
#define SERIAL_PORT_HANDLER_H

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <QDebug>
#include <iostream>
#include <QObject>

struct BaudRateList
{
    int BR_50() {return B50;}
    int BR_75() {return B75;}
    int BR_110() {return B110;}
    int BR_134() {return B134;}
    int BR_150() {return B150;}
    int BR_200() {return B200;}
    int BR_300() {return B300;}
    int BR_600() {return B600;}
    int BR_1200() {return B1200;}
    int BR_1800() {return B1800;}
    int BR_2400() {return B2400;}
    int BR_4800() {return B4800;}
    int BR_9600() {return B9600;}
    int BR_19200() {return B19200;}
    int BR_38400() {return B38400;}
    int BR_57600() {return B57600;}
    int BR_115200() {return B115200;}
    int BR_230400() {return B230400;}
    int BR_460800() {return B460800;}
    int BR_500000() {return B500000;}
    int BR_576000() {return B576000;}
    int BR_921600() {return B921600;}
    int BR_1000000() {return B1000000;}
};

class SerialPortHandler : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortHandler(QObject *parent = 0);

    unsigned char *data; // incoming data
    int fileDescriptor;

    int OpenComPort(const char *comport, int baudr);
    void CloseComport(void);
    int ReadData(unsigned char *buffer, int size);
    int SendData( unsigned char *data, int size);
    int WaitingPackageSize();
    void ClearBuffer();
    BaudRateList BaudRate;

signals:

public slots:

};


#endif // SERIAL_PORT_HANDLER_H
