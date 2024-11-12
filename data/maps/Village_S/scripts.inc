Village_S_MapScripts::
	.byte 0

	@ State descriptions for VAR_VILLAGE_S_STATE
	@ 1: Received Running Shoes
	@ 2: 
	@ 3: 
	@ 4: 

Village_S_EventScript_StartGame::
	setvar VAR_VILLAGE_S_STATE, 1
	setflag FLAG_RECEIVED_RUNNING_SHOES
	return