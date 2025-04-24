[ComponentEditorProps(category: "VehicleInventorySystem/Component", description: "TODO")]
class FLF_CreateActionsComponentClass : ScriptComponentClass
{
}

class FLF_CreateActionsComponent : ScriptComponent
{
	
	
	protected override void OnPostInit(IEntity owner)
	{
	Print("======================================================================");
		DebugPrintVSSSlots();
	Print("======================================================================");
	}
	
	//Get SlotManagerComponent from owner entity
	SlotManagerComponent GetSlotManagerComponent()
	{
		protected SlotManagerComponent m_slotManager;
		
		if (!m_slotManager && GetOwner())
		{
			//Rzutowanie na typ SlotManagerComponent, upewnia sie ze zwracany komponent jest typu SlotManagerComponent
			m_slotManager = SlotManagerComponent.Cast(GetOwner().FindComponent(SlotManagerComponent));
		}
		
		return m_slotManager;
		
	}
	
	array<EntitySlotInfo> FindComponentByName (SlotManagerComponent m_slotManager)
	{
		array<EntitySlotInfo> m_slotManagerArray = {};
		array<EntitySlotInfo> m_MatchingSlots = {};
		array<EntitySlotInfo> result = {};
		// array<ref SlotComponent> m_slotManagerArray = m_slotManager.GetSlotInfos();
		if (!m_slotManager)
			return m_slotManagerArray;
		
		
		m_slotManager.GetSlotInfos(m_slotManagerArray);
		
			//Iteracja przez całą tablicę i wyszukanie komponentu który zawiera zdefiniowaną nazwę
		foreach (EntitySlotInfo info : m_slotManagerArray)
		{
			string slotName = info.GetSourceName();
			if (slotName.StartsWith("FLF_VSS_"))
			{
				result.Insert(info);
			}
		}
	return result;
		
	}
	
void DebugPrintVSSSlots()
{
	
	SlotManagerComponent m_slotManager;
		m_slotManager = SlotManagerComponent.Cast(GetOwner().FindComponent(SlotManagerComponent));
		SlotManagerComponent slotManager = m_slotManager;
	if (!slotManager)
	{
		Print("Nie znaleziono SlotManagerComponent!");
		return;
	}

	array<EntitySlotInfo> vssSlots = FindComponentByName(slotManager);

	Print("Znaleziono sloty zaczynające się od 'FLF_VSS_': " + vssSlots.Count());

	foreach (EntitySlotInfo info : vssSlots)
	{
		Print("Slot: " + info.GetSourceName());
	}
}
	
void AddDynamicSlotActions(array <EntitySlotInfo> m_slotManager)
	{
		EntitySlotInfo SelectedSlot;
		IEntity SlotManagerOwner = GetOwner();
		
		ActionsManagerComponent ActionsManagerComponentHandle = ActionsManagerComponent.Cast(GetOwner().FindComponent(ActionsManagerComponent));
		if (!ActionsManagerComponentHandle)
		{
			Print("No ActionsManagerComponent found on the entity");
			return;
		}
		
		SlotManagerComponent slotManager = GetSlotManagerComponent();
		if (!slotManager)
		{
			return;
		}
		
		array<EntitySlotInfo> slotInfos = {};
		slotManager.GetSlotInfos(slotInfos);

		foreach (EntitySlotInfo info : slotInfos)
		{
			string slotName = info.GetSourceName();

			if (!slotName.StartsWith("FLF_VSS_"))
				continue;
			
			if (slotName.StartsWith("FLF_VSS_"))
				SelectedSlot = info;

			//FLF_VSS_MountAction action = new FLF_VSS_MountAction();
			//action.Init(SlotManagerOwner, SelectedSlot);

			//ActionsManagerComponentHandle.InsertAction(action);
			//Print("Dodano akcję montażu dla slota: " + slotName);
		}
		
	}

}