stock SendDiscordMessage(channel, const message[]) {
	new DCC_Channel:ChannelId;
	switch(channel)
	{
        // logs pay
		case 0:
		{
			ChannelId = DCC_FindChannelById("1327254733282611230");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
        // logs send kendaraan
		case 1:
		{
			ChannelId = DCC_FindChannelById("1327607806018195487");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
        // logs join leave
		case 2:
		{
			ChannelId = DCC_FindChannelById("1325732946052907009");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
        // logs death 
		case 3:
		{
			ChannelId = DCC_FindChannelById("1333053623021731930");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 4:
		{
			ChannelId = DCC_FindChannelById("927765834032640010");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 5:
		{
			ChannelId = DCC_FindChannelById("1232544162746990602");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 6:
		{
			ChannelId = DCC_FindChannelById("909028255867240449");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 7:
		{
			ChannelId = DCC_FindChannelById("1232544162746990602");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 8:
		{
			ChannelId = DCC_FindChannelById("1225584762664779887");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 9:
		{
			ChannelId = DCC_FindChannelById("1292484368320696320");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 10:
		{
			ChannelId = DCC_FindChannelById("1292486682502893639");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 11:
		{
			ChannelId = DCC_FindChannelById("1300471338896592956");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
		case 12:
		{
			ChannelId = DCC_FindChannelById("1308786637920014396");
			DCC_SendChannelMessage(ChannelId, message);
			return 1;
		}
	}
	return 1;
}