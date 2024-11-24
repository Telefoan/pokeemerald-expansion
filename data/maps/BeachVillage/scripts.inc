BeachVillage_MapScripts::
	.byte 0

	@ State descriptions for VAR_VILLAGE_S_STATE
	@ 1: Received Running Shoes
	@ 2: 
	@ 3: 
	@ 4: 

LittlerootTown_EventScript_Mom::
	lock
	faceplayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	hideobjectat LOCALID_MOM, MAP_BEACH_VILLAGE
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetReceivedRunningShoes::
	removeobject LOCALID_MOM
	setflag FLAG_SYS_B_DASH
	setvar VAR_BEACH_VILLAGE_STATE, 4
	release
	end

BeachVillage_EventScript_GiveRunningShoes::
	msgbox BeachVillage_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BeachVillage_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox BeachVillage_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox BeachVillage_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	delay 30
	return


BeachVillage_Text_WearTheseRunningShoes:
	.string "MOM: {PLAYER}! {PLAYER}! Are you\n"
	.string "going out into the woods?\p"
	.string "You are?\n"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

BeachVillage_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

BeachVillage_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

BeachVillage_Text_ComeHomeIfAnythingHappens:
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"