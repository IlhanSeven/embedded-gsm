#include "SerialPortHandler.h"

int error;

struct termios new_port_settings,
       old_port_settings[1];



SerialPortHandler::SerialPortHandler(QObject *parent):QObject(parent)
{

}

int SerialPortHandler::OpenComPort(const char * comport, int baudr)
{

  fileDescriptor = open(comport, O_RDWR | O_NOCTTY | O_NDELAY);
  if(fileDescriptor == -1)
  {
    qDebug() << "unable to open comport ";
    return(1);
  }
  else
  {
      qDebug() << "Serial Port is opened.";
  }

  error = tcgetattr(fileDescriptor, old_port_settings);
  if(error==-1)
  {
    close(fileDescriptor);
    qDebug() << "unable to read portsettings ";
    return(1);
  }
  else
  {
      qDebug() << "Port Setting have been read.";
  }
  memset(&new_port_settings, 0, sizeof(new_port_settings));  /* clear the new struct */

  new_port_settings.c_cflag = baudr | CS8 | CLOCAL | CREAD;
  new_port_settings.c_iflag = IGNPAR;
  new_port_settings.c_oflag = 0;
  new_port_settings.c_lflag = 0;
  new_port_settings.c_cc[VMIN] = 0;      /* block untill n bytes are received */
  new_port_settings.c_cc[VTIME] = 0;     /* block untill a timer expires (n * 100 mSec.) */
  error = tcsetattr(fileDescriptor, TCSANOW, &new_port_settings);
  if(error==-1)
  {
    close(fileDescriptor);
    qDebug() << "unable to adjust portsettings ";
    return(1);
  }
  else
  {
      qDebug() << "Port Settings adjusted.";
  }
  return(0);
}
void SerialPortHandler::CloseComport( void )
{
  close(fileDescriptor);
  tcsetattr(fileDescriptor, TCSANOW, old_port_settings);
}
int SerialPortHandler::SendData( unsigned char *data, int size)
{
    return write(fileDescriptor, data, size);

}
int SerialPortHandler::ReadData( unsigned char *buffer, int size)
{
    return read(fileDescriptor, buffer, size);
}
int SerialPortHandler::WaitingPackageSize()
{
    unsigned int bytes;
    ioctl(fileDescriptor, FIONREAD, &bytes);
    return bytes;
}
void SerialPortHandler::ClearBuffer()
{
    tcflush(fileDescriptor, TCIFLUSH);
}
