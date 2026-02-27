#include "core/commands/Command.hpp"
#include "game/gta/Natives.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/gta/Stats.hpp"

namespace YimMenu::Features
{
	class NewUnlock : public Command
	{
		using Command::Command;
		virtual void OnCall() override
		{
			if (*Pointers.IsSessionStarted)
			{
				Stats::SetPackedInt(262145, 37394);
				Stats::SetPackedBool(54687, true);
				Stats::SetInt("MPPLY_XMAS22CPAINT0", -1);
				Stats::SetInt("MPPLY_XMAS22CPAINT1", -1);
				Stats::SetInt("MPPLY_SUM23WHEELCPAINT0", -1);
				Stats::SetInt("MPPLY_SUM23WHEELCPAINT1", -1);
				Stats::SetInt("MPPLY_XMAS23_PLATES0", -1);
				Stats::SetInt("MPX_AWD_TRANSPORT", 20);
				Stats::SetBool("MPX_AWD_SECUREDEL", TRUE);
				Stats::SetInt("MPX_AWD_SUNBURNED", 20);
				Stats::SetBool("MPX_AWD_TWOOFAKIND", TRUE);
				Stats::SetInt("MPX_AWD_UNDEADPARTY", 100);
				STATS::STAT_SAVE(0, 0, 3, 0);
			}
		}
	};
	static NewUnlock _NewUnlock{
	    "New_Unlock",
	    "NewUnlock",
	    "New Unlock"};
}
