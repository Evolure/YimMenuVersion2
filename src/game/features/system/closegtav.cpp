#include "core/commands/Command.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	class CloseGTAV : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			MISC::QUIT_GAME();
		}
	};

	static CloseGTAV _CloseGTAV{"closegtav", "Close GTAV", "Closing GTA V and GTA Online"};
}
