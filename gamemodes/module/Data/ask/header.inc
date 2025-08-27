enum askData {
    bool:askExists,
    askType,
    askPlayer,
    askText[128 char]
};
new AskData[MAX_ASKS][askData];