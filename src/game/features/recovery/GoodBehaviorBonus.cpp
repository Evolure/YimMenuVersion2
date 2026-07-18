#include "core/commands/Command.hpp"
#include "game/gta/ScriptGlobal.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/pointers/Pointers.hpp"

namespace YimMenu::Features
{
	class Good_Behavior_Bonus : public Command
	{
		using Command::Command; 
		void OnCall() override
		{
			if (*Pointers.IsSessionStarted)
			{
				*ScriptGlobal(2697091).As<int*>() = 2000; // Money Reward
				*ScriptGlobal(2697090).As<int*>() = 1; // Trigger Good behavior bonus
			}
			else
			{
				Notifications::Show("YimMenuV2","You must be online",NotificationType::Error);
			}
		}
	};

	static Good_Behavior_Bonus _Good_Behavior_Bonus{
	    "Good_Behavior_Bonus",
	    "Good Behavior Bonus",
	    "Good Behavior Bonus"};
}
