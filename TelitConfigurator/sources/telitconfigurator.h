#ifndef TELITCONFIGURATOR_H
#define TELITCONFIGURATOR_H

#include <QObject>
#include <QDateTime>
#include <QDebug>

#include "SerialPortHandler.h"

class TelitConfigurator : public QObject
{
    Q_OBJECT
public:
    explicit TelitConfigurator(QObject *parent = 0);
    SerialPortHandler serialPort;
    void SetModemTime( void );
signals:
    
public slots:
    
};

#endif // TELITCONFIGURATOR_H
