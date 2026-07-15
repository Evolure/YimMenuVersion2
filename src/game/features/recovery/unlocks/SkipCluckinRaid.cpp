#include "core/commands/Command.hpp"
#include "game/gta/Natives.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/gta/Stats.hpp"
#include "game/gta/ScriptGlobal.hpp"
namespace YimMenu::Features
{
	class SkipCluckinBell : public Command
	{
		using Command::Command;
		virtual void OnCall() override
		{
			if (*Pointers.IsSessionStarted)
			{
				Stats::SetInt("MPX_SALV23_INST_PROG", 31);
				/*BTEA Needs more testing
				*ScriptGlobal(262145).At(36725).As<int*>() = 500000;// Farm Raid Payout
				*ScriptGlobal(262145).At(36726).As<int*>() = 50000;// Farm Raid Associate Payout
				*/
				STATS::STAT_SAVE(0, 0, 3, 0);
			}
			else
			{
				Notifications::Show("YimMenuV2", "You Must be Online", NotificationType::Error);
			}
		}
	};
	static SkipCluckinBell _SkipCluckinBell{
	    "SkipCluckinBellRaid",
	    "Skip Cluckin Bell",
	    "Skip Cluckin Bell"};

}

