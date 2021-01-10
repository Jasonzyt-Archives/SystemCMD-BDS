#include "‘§±‡“ÎÕ∑.h"

using namespace std;

string StrLower(string in)
{
	transform(in.begin(), in.end(), in.begin(), ::tolower);
	return in;
}

SYMHOOK(onServerCMD, bool, "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", VA _this, std::string* cmd)
{
	string cmdstr = StrLower(*cmd);
	if (cmdstr.find("system ") == 0)
	{
		string scmd = *cmd;
		scmd.replace(0, 7, "");
		system(scmd.c_str());
	}
	original(_this, cmd);
}
