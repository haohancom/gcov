#include "guiclass.h"

MyMainWindows::MyMainWindows()
{
  setGeometry(90,90,300,200);

  pb = new QPushButton("slotAnalyse", this);
  textPtr = new QTextEdit("input your file name");

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(textPtr);
  layout->addWidget(pb);
  setLayout(layout);

  connect(pb, SIGNAL(clicked()) ,this ,SLOT(slotClicked()));
  connect(this,SIGNAL(sigAnalyse(QTextEdit*)),this,SLOT(slotAnalyse(QTextEdit*)));   
}


void shell(std::string cmd){
    cmd.append(" 2>&1");
    popen(cmd.c_str(), "r");
}

void MyMainWindows::slotAnalyse(QTextEdit* QTextPtr)
{
    std::string strText = QTextPtr->toPlainText().toStdString();
    shell("firefox ../infoCatchTool_result/root/hanhao/gcov/infoCatchTool.cpp.gcov.html");
}

void MyMainWindows::slotClicked(){
    emit sigAnalyse(textPtr);
}
