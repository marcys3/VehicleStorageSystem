class FLF_VSS_MountAction : ScriptedUserAction
{
	//------------------------------------------------------------------------------------------------
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		Print("MyScriptedUserAction.PerformAction() method reached", LogLevel.NORMAL);
		SCR_HintManagerComponent.GetInstance().ShowCustomHint("ACTION TEST - DONE", "ACTION TEST", 3.0);
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
}