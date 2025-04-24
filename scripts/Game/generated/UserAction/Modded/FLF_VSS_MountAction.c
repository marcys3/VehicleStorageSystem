class FLF_VSS_MountAction : ScriptedUserAction
{
	//------------------------------------------------------------------------------------------------
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		
		//SCR_HintManagerComponent.GetInstance().ShowCustomHint("ACTION TEST - DONE", "ACTION TEST", 3.0);
		
		//FLF_VSS_MountAction action = new FLF_VSS_MountAction();
		//string actionName = action.GetActionName();
		
		array<BaseUserAction> ActionArray = {};
		
		//CHYBA ŚLEPA ULICZKA
		//Znajdź na pojeździe komponent ActionsManagerComponent
		ActionsManagerComponent ActionsManager = ActionsManagerComponent.Cast(GetOwner().FindComponent(ActionsManagerComponent));
		
		//Zwróć wszystkie akcje do tablicy
		ActionsManager.GetActionsList(ActionArray);
		
		foreach (BaseUserAction info : ActionArray)
		{

			UIInfo UIInfoClass = info.GetUIInfo();
			if (!UIInfoClass){
			return;
			}
			string slotName = UIInfoClass.GetName();
			//if (!slotName.StartsWith("FLF_VSS_"))
			Print("Nazwa: "+ slotName);	
			//continue;
			
			//if (slotName.StartsWith("FLF_VSS_"))
				//Print("Nazwa: "+ slotName);

		}

		//SCR_HintManagerComponent.GetInstance().ShowCustomHint("ACTION", "ACTION NAME: "+ actionName, 3.0);
		//Print("Nazwa: "+ actionName);
		
	}

	//------------------------------------------------------------------------------------------------
	override bool CanBeShownScript(IEntity user)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------
	override bool CanBePerformedScript(IEntity user)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------
	override bool HasLocalEffectOnlyScript()
	{
		return true;
	}
	
	override bool GetActionNameScript(out string outName) { 
			
		//outName = "DZIALA";
		return false; };
	
	override bool CanBroadcastScript() { return false; };
	
}