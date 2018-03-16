#!/usr/bin/env python
# coding=utf-8
import bs4
from bs4 import BeautifulSoup

outFileName = "lineInfo"
def writeToFile(str, fileName):
    str = str + '\n'
    with open(fileName, 'a') as f:
        f.write(str)

def getNumFromStr(str):
    strs = str.split(" ")
    for s in strs:
        if(s.isalnum()):
            return s

def saveLineNum(str):
    str = getNumFromStr(str)
    str = "lineNum : " + str
    writeToFile(str, outFileName)

def saveLineCov(str):
    str = getNumFromStr(str)
    str = "lineCov : " + str
    writeToFile(str, outFileName)

inFileName = "./infoCatchTool_result/root/hanhao/gcov/infoCatchTool.cpp.gcov.html"
soup = BeautifulSoup(open(inFileName), "lxml")

with open(outFileName, 'w') as f:
    f.write('')

pre = soup.find("pre", class_ = "source")

for child in pre.children:
    if(type(child) == bs4.element.Tag):
        if (child.has_attr('class')):
            if (child['class'] == ['lineNum']):
                saveLineNum(child.string)
            elif (child['class'] == ['lineCov']):
                saveLineCov(child.string)
        elif (child.has_attr('name')):
            for span in child.find_all("span"):
                if (span['class'] == ['lineNum']):
                    saveLineNum(span.string)
                elif (span['class'] == ['lineCov']):
                    saveLineCov(span.string)
