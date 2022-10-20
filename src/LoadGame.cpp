#include "LoadGame.h"
#include "Backoff_Hook.h"
#include "Circling_Hook.h"
#include "CombatRadius_Hook.h"
#include "ConsoleCommands.h"
#include "Fallback_Hook.h"

namespace CombatPathing
{
	void EventCallback(SKSE::MessagingInterface::Message* msg)
	{
		if (msg->type == SKSE::MessagingInterface::kPostLoad) {
			ConsoleCommands::Register();

			CirclingHook::InstallHook();

			CombatRadiusHook::Install();

			FallbackStartHook::InstallHook();
			FallbackUpdateHook::InstallHook();

			BackoffStartHook::InstallHook();
			BackoffChanceHook::InstallHook();

			//Hook_GetOffensive::install();
		}
	}

}
