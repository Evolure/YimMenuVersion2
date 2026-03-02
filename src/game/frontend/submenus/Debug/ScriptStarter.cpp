#include "ScriptStarter.hpp"
#include "core/util/utils.hpp"
#include "core/backend/FiberPool.hpp"
#include "game/gta/Natives.hpp"
#include "game/gta/ScriptGlobal.hpp"
#include "core/util/Joaat.hpp"
#include "game/frontend/items/Items.hpp"
namespace YimMenu::Submenus
{
	std::shared_ptr<Category> BuildScriptStarterMenu()
	{
		auto menu = std::make_shared<Category>("Script Starter");
		auto main = std::make_shared<Group>("Scripts");

		main->AddItem(std::make_unique<ImGuiItem>([]
		{
			if (ImGui::Button("Start Internet"))
			{
				FiberPool::Push([]
				{
					Utils::StartScript("appInternet", 4592);
				});
			}
			
			if (ImGui::Button("Start CEO Computer"))
			{
				FiberPool::Push([]
				{
					Utils::StartScript("appSecuroServ", 1424);
				});
			} if (ImGui::IsItemHovered()) {ImGui::SetTooltip("Must be in your CEO office interior. It will damage the screen if you buy a warehouse");}
			
			if (ImGui::Button("Start Vehicle Cargo Computer"))
			{
				FiberPool::Push([]
				{
					Utils::StartScript("appImportExport", 1424);
				});
			} if (ImGui::IsItemHovered()){ImGui::SetTooltip("Must be in your vehicle warehouse interior");}
		}));
		menu->AddItem(std::move(main));
		return menu;
	}
}//TODO: All businesses
