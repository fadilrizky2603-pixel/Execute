JobPrice_Save()
{
    new str[3048];

    format(str, sizeof(str), "UPDATE jobprice SET sjforklift='%d', sjmower='%d', sjsweeper='%d', sjbus='%d', sjtrashmaster='%d', jobpizza='%d', jobbutcher='%d', jobpemerassusu='%d', jobreflenish='%d', jobtrucker='%d', drugdealer1='%d', drugdealer2='%d', drugdealer3='%d', jobminer='%d', production1='%d', production2='%d', production3='%d', hauling1='%d', hauling2='%d', hauling3='%d', factionprice='%d' WHERE id=0",
    sjforklift,
    sjmower, 
    sjsweeper, 
    sjbus,
    sjtrashmaster,
    jobpizzaprice, 
    jobbutcherprice, 
    jobpemerahprice,
    jobreflenishprice,
    jobtruckerprice, 
    drugdealerprice1,
    drugdealerprice2,
    drugdealerprice3,
    jobminerprice,
    productprice1, 
    productprice2, 
    productprice3,
    haulingprice1,
    haulingprice2,
    haulingprice3,
    factionprice
    );

    return mysql_tquery(g_SQL, str);
}