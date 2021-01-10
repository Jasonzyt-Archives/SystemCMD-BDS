#include "预编译头.h"

using namespace std;

void init()
{
	PR(0, u8"Plugin Loaded! Ver1.0.0 Author:JasonZYT Org:SKYTown");
}

string StrLower(string in)
{
	transform(in.begin(), in.end(), in.begin(), ::tolower);
	return in;
}

std::string getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}

SYMHOOK(onServerCMD, bool, "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", VA _this, std::string* cmd)
{
	string cmdstr = StrLower(*cmd);
	if (cmdstr.find("system ") == 0)
	{
		string scmd = *cmd;
		scmd.replace(0, 7, "");
		system(scmd.c_str());
		PR(0, u8"系统命令已执行!");
		return false;
	}
	original(_this, cmd);
}
