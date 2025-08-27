#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_SPRAYTAG_MODE)
	{
		if(!response)
			return ShowTagSetup(playerid);

		new id = Tag_Create(playerid);

		if(id == INVALID_ITERATOR_SLOT)
			return ErrorMsg(playerid, "Server ini tidak dapat membuat lagi Tags");


		pData[playerid][pEditing] = id;
		pData[playerid][pEditType] = EDIT_TAG;
		Streamer_Update(playerid, STREAMER_TYPE_OBJECT);

		if(listitem == 0)
		{
			return SyntaxMsg(playerid, "Masih dalam tahap pengembangan");
		}
		if(listitem == 1)
		{
			EditDynamicObject(playerid, TagData[id][tagObject]);
		}
	}
	if(dialogid == DIALOG_SPRAYTAG_TEXT)
	{
		if(response)
		{
			if(isnull(inputtext))
				return callcmd::tag(playerid, inputtext);

			if(strlen(inputtext) > 64)
				return ErrorMsg(playerid, "Text yang anda masukan tidak boleh lebih dari 64 kata");
			callcmd::tag(playerid, inputtext);

			format(TagText[playerid], 64, inputtext);
			ShowTagSetup(playerid);

		}
	}
	if(dialogid == DIALOG_SPRAYTAG_FONT)
	{
		if(!response)
			return ShowTagSetup(playerid);

		if(isnull(inputtext))
			return ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_FONT, DIALOG_STYLE_INPUT, "Tag - Font", "Please input the fontface name:", "Set", "Return");

		if(strlen(inputtext) > 24)
			return ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_FONT, DIALOG_STYLE_INPUT, "Tag - Font", "Please input the fontface name:", "Set", "Return");

		format(TagFont[playerid], 24, inputtext);
		ShowTagSetup(playerid);
	}
	if(dialogid == DIALOG_SPRAYTAG_SIZE)
	{
		if(!response)
			return ShowTagSetup(playerid);

		if(isnull(inputtext))
			return ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_SIZE, DIALOG_STYLE_INPUT, "Tag - Font Size", "Please input the fontsize:\nNote: min 24 max 255!", "Set", "Return");

		if(!IsNumeric(inputtext))
			return ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_SIZE, DIALOG_STYLE_INPUT, "Tag - Font Size", "Please input the fontsize:\nNote: min 24 max 255!", "Set", "Return");

		if(strval(inputtext) < 24 || strval(inputtext) > 255)
			return ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_SIZE, DIALOG_STYLE_INPUT, "Tag - Font Size", "Please input the fontsize:\nNote: min 24 max 255!", "Set", "Return");

		TagSize[playerid] = strval(inputtext);
		ShowTagSetup(playerid);
	}
	if(dialogid == DIALOG_SPRAYTAG_COLOR)
	{
		if(!response)
			return 1;

		if(isnull(inputtext))
			return ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_COLOR, DIALOG_STYLE_INPUT, "Tag - Color", "Please input the color for the tag:\nExample: 0xFFFFFFFF (white)", "Set", "Return");

		TagColor[playerid] = HexToInt(inputtext);
		ShowTagSetup(playerid);
	}
	if(dialogid == DIALOG_SPRAYTAG)
	{
		if(!response)
			return 1;

		if(listitem == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_FONT, DIALOG_STYLE_INPUT, "Tag - Font", "Please input the fontface name:", "Set", "Return");
		}
		if(listitem == 1)
		{
			ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_SIZE, DIALOG_STYLE_INPUT, "Tag - Font Size", "Please input the fontsize:\nNote: min 24 max 255!", "Set", "Return");
		}
		if(listitem == 2)
		{
			if(TagBold[playerid] == 0)
			{
				TagBold[playerid] = 1;
			}
			else
			{
				TagBold[playerid] = 0;
			}
			ShowTagSetup(playerid);
		}
		if(listitem == 3)
		{
			ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_COLOR, DIALOG_STYLE_INPUT, "Tag - Color", "Please input the color for the tag:\nExample: 0xFFFFFFFF (white)", "Set", "Return");
		}
		if(listitem == 4)
		{
			ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_MODE, DIALOG_STYLE_LIST, "Tag - Edit Mode", "TextDraw Click\nClick n Drag", "Select", "Close");
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}