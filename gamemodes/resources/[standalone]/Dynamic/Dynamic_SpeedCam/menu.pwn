SSCANF:SpeedMenu(string[])
{
    if(!strcmp(string, "create", true)) return 1;
    else if(!strcmp(string, "delete", true)) return 2;
    else if(!strcmp(string, "position", true)) return 3;
    else if(!strcmp(string, "speed", true)) return 4;
    return 0;
} 