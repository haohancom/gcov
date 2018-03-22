CURR_PATH=$(shell pwd)
SEARCH_TARGET_FILE=targetFile
#HTML_FILE_PATH=$(shell find . -name infoCatchTool.cpp.gcov.html)
HTML_FILE_PATH=./infoCatchTool_result$(CURR_PATH)/infoCatchTool.cpp.gcov.html

all:
	g++ -c infoCatchTool.cpp -ftest-coverage -fprofile-arcs
	g++ infoCatchTool.o -o infoCatchTool -fprofile-arcs
	./infoCatchTool 1 2 3 $(SEARCH_TARGET_FILE)
	gcov infoCatchTool.cpp
	lcov -c -o infoCatchTool.info -d .
	genhtml infoCatchTool.info -o infoCatchTool_result
	python htmlParser.py $(HTML_FILE_PATH)
	g++ report.cpp tool/tool.cpp -std=c++11 -g -o report
	./report
clean:
	rm -rf infoCatchTool_result
	rm -f infoCatchTool infoCatchTool.info infoCatchTool.o infoCatchTool.g*
	rm -f lineInfo report
