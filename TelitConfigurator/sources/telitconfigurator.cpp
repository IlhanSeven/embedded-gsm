#include "telitconfigurator.h"

TelitConfigurator::TelitConfigurator(QObject *parent) :
    QObject(parent)
{
    SetModemTime();
}

void TelitConfigurator::SetModemTime( void )
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    currentDateTime = currentDateTime.toUTC();
    QString year    =  currentDateTime.date().toString("yy/");
    QString month   =  currentDateTime.date().toString("MM/");
    QString day     =  currentDateTime.date().toString("dd,");
    QString time    = currentDateTime.time().toString("hh:mm:ss+00\"\r");
    QString setString;
    setString = " at+cclk=\""+year+month+day+time; //at+cclk="12/11/01,19:38:00+00"
    qDebug()<<setString;
    serialPort.OpenComPort("/dev/ttyO1", serialPort.BaudRate.BR_115200());
    serialPort.SendData((unsigned char *)setString.toStdString().c_str(),setString.size());
    sleep(2);
    setString = "at#sled=2\r";
    serialPort.SendData((unsigned char *)setString.toStdString().c_str(),setString.size());
    sleep(2);
    setString = "at#sledsav\r";
    serialPort.SendData((unsigned char *)setString.toStdString().c_str(),setString.size());
    sleep(2);
    setString = "at#simdet=1\r";
    serialPort.SendData((unsigned char *)setString.toStdString().c_str(),setString.size());
    sleep(2);
    serialPort.CloseComport();
}
