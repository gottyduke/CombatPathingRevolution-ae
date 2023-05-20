#include "Util.h"

namespace CombatPathing
{
	using namespace RE;

	bool IsMeleeOnly(Actor* a_actor)
	{
		using TYPE = CombatInventoryItem::TYPE;

		if (!a_actor)
			return false;

		auto combatCtrl = a_actor->GetActorRuntimeData().combatController;
		auto CombatInv = combatCtrl ? combatCtrl->inventory : nullptr;
		if (CombatInv) {
			for (const auto item : CombatInv->equippedItems) {
				if (item.item) {
					switch (item.item->GetType()) {
					case TYPE::kMagic:
					case TYPE::kRanged:
					case TYPE::kScroll:
					case TYPE::kStaff:
						return false;

					default:
						break;
					}
				}
			}

			return true;
		}

		return false;
	}

	float GetEquippementRange(CombatInventory* a_inv, bool a_full)
	{
		if (a_inv) {
			return a_full ? a_inv->maximumRange : a_inv->optimalRange;
		}

		return 0.f;
	}

	std::optional<float> GetGameSettingFloat(const std::string a_name)
	{
		std::optional<float> result;

		auto setting = GameSettingCollection::GetSingleton()->GetSetting(a_name.c_str());
		if (setting) {
			result.emplace(setting->GetFloat());
		}

		return result;
	}

	void SetGameSettingFloat(const std::string a_name, float a_value)
	{
		auto setting = GameSettingCollection::GetSingleton()->GetSetting(a_name.c_str());
		if (setting) {
			setting->data.f = a_value;
		}
	}

	const float RescaleValue(float a_mult, float a_min, float a_max)
	{
		return a_min + a_mult * (a_max - a_min);
	}

	// Unused

	NodeArray& wrap_to_valuenode_13(NodeArray& a, const char* name, TreeCtors_extradata* extradata, CombatBehaviorTreeNode* node)
	{
		// 1407DA290
		return _generic_foo<46736, NodeArray&, NodeArray&, const char*, TreeCtors_extradata*, CombatBehaviorTreeNode*>(a, name, extradata, node);
	}

	// Used

	NodeArray& wrap_to_conditional_2(NodeArray& a, const char* name, TreeCtors_extradata* extradata, CombatBehaviorTreeNode* node)
	{
		// SkyrimSE.exe+7da060
		return _generic_foo<46732, NodeArray&, NodeArray&, const char*, void*, CombatBehaviorTreeNode*>(a, name, extradata, node);
	}

	// Unused

	NodeArray& init_withNode_withname(NodeArray& array, const char* name, CombatBehaviorTreeNode* node)
	{
		return _generic_foo_rel<46261, 47516, NodeArray&, NodeArray&, const char*, CombatBehaviorTreeNode*>(array, name, node);
	}

	// Used

	NodeArray& pushback_parentof(NodeArray& array, NodeArray& cont_node)
	{
		return _generic_foo_rel<46255, 47510, NodeArray&, NodeArray&, NodeArray&>(array, cont_node);
	}

	// Used

	Character* CombatAI__get_he()
	{
		return _generic_foo_rel<46265, 47520, Character*>();  // SkyrimSE.exe+7c7b20
	}

	// Used

	Character* CombatAI__get_me()
	{
		return _generic_foo_rel<46264, 47519, Character*>();  // SkyrimSE.exe+7C7A40
	}

}