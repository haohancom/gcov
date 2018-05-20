#ifndef GUICLASS_H_
#define GUICLASS_H_

#include <QWidget>
#include <QPushButton>
#include <stdio.h>
#include <string.h>
#include <qtextedit.h>
#include <QVBoxLayout>

void shell(std::string cmd);

class MyMainWindows:public QWidget
{                                                         
Q_OBJECT
public:                                                   
    MyMainWindows();
public slots:
    void slotClicked();
    void slotAnalyse(QTextEdit* QTextPtr);
private:
    QPushButton * pb;
    QTextEdit* textPtr;
signals:
    void sigAnalyse(QTextEdit* ptr);
};

#endif
