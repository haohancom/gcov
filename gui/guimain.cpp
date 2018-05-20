#include <QApplication>              //所有QT应用程序都要包含QApplication头文件
#include "guiclass.h"                //包含类定义文件yourclass.h
int main(int argc,char * argv[])
{
  QApplication app(argc,argv);        //申明一个QT应用程序对像app
  MyMainWindows w;                      //申明我们实现MyMainWindows窗体对像 w.
  w.show();                                //显示这个w 窗体
  return app.exec();
}
