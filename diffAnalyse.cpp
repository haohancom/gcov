/*************************************************************************
	> File Name: diffAnalyse.cpp
	> Created Time: Wed 21 Mar 2018 08:11:20 AM GMT
 ************************************************************************/

#include<iostream>
using namespace std;
// TODO : analyse git diff and change coverage report file.



/* example
 *--- a/infoCatchTool.cpp
 *+++ b/infoCatchTool.cpp
 *@@ -50,12 +50,12 @@ bool searchStrInLine(vector<string> v, string sLine){
 *
 * int main(int argc, char** argv){
 *     vector<string> vInfo;
 *+    // add a line
 *     getInfo(vInfo, argv);
 *     // At least 2 string;
 *-    // the last one is name of the file which you want to search in;
 *
 *     string sFilename = "";
 *-    getFilename(sFilename, vInfo);
 *+    getFilename(sFilename, vInfo);
 *        
 *     ifstream file;
 *     file.open(sFilename.c_str(), ios::in);
 *diff --git a/report.cpp b/report.cpp
 *index e260dd8..1b0f80a 100644
 *--- a/report.cpp
 *+++ b/report.cpp
 *@@ -1,14 +1,8 @@
 * #include<iostream>
 * #include<string>
 * #include<fstream>
 * +#include"tool/tool.h"
 *                          
 *    }
 *}
 */
int main(){
    return 0;
}
