# a code coverage tool

## inroduction
**work flow:**
1. compile and run infoCatchTool.cpp
* it's the target program we try to get its code coverage
* This tool is cerated as a mutiple-keyword search tool which can search one or more keywords in a file and you can get lines from target file which includes the keyword(s) you search.
* _how to use it :_
```bash
[root@localhost gcov]# cat targetFile
1 2 3
2 3 4
3 4 5
4 5 6
[root@localhost gcov]# ./infoCatchTool 3 targetFile
filename is : targetFile
1 2 3
2 3 4
3 4 5
```
2. use google __gcov__ and __lcov__ tool to generate a code coverage report
3. run htmlParser.py
* this python program can parse the html report and list the usaful information in a file named lineInfo
4. compile & run report.cpp
* thie tool can parse file created by python program and generate the final report we want.
## makefile
1. use ```make``` to compile & run the programs and generate report automatically
2. use ```make clean``` to remove unwanted intermediate files
## TODO
add a tool which can combine report with gitdiff, so that when someone change the code, the report will refresh.
- complete while loop in diffAnalyse.cpp by class [result] then delete the old version
- change report html file to show changed code coverage situation intuitively 
