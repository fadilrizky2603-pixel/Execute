-- --------------------------------------------------------
-- Host:                         localhost
-- Server version:               10.3.39-MariaDB-0ubuntu0.20.04.2 - Ubuntu 20.04
-- Server OS:                    debian-linux-gnu
-- HeidiSQL Version:             12.8.0.6908
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for s1130_localprime_samp
CREATE DATABASE IF NOT EXISTS `hostarcity` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci */;
USE `hostarcity`;

-- Dumping structure for table s1130_localprime_samp.911calls
CREATE TABLE IF NOT EXISTS `911calls` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `IssuerName` varchar(24) NOT NULL,
  `IssuerID` int(12) NOT NULL DEFAULT 0,
  `Reason` varchar(64) NOT NULL,
  `Type` int(3) NOT NULL DEFAULT 0,
  `Sector` int(3) NOT NULL DEFAULT 0,
  `Number` int(5) NOT NULL DEFAULT 0,
  `Time` int(12) NOT NULL DEFAULT 0,
  `Location` varchar(32) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.911calls: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.actors
CREATE TABLE IF NOT EXISTS `actors` (
  `id` int(11) NOT NULL,
  `name` varchar(54) NOT NULL DEFAULT 'None',
  `skinid` int(11) NOT NULL DEFAULT 10,
  `bizid` tinyint(3) NOT NULL DEFAULT -1,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posa` float DEFAULT 0,
  `vuln` int(11) NOT NULL DEFAULT 10,
  `interior` int(11) NOT NULL DEFAULT 10,
  `world` int(11) NOT NULL DEFAULT 10,
  `anim` int(11) NOT NULL DEFAULT 10,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.actors: 2 rows
/*!40000 ALTER TABLE `actors` DISABLE KEYS */;
INSERT INTO `actors` (`id`, `name`, `skinid`, `bizid`, `posx`, `posy`, `posz`, `posa`, `vuln`, `interior`, `world`, `anim`) VALUES
	(0, 'None', 4, -1, 2116.1, -1740.85, 13.5666, 347.696, 1, 0, 0, 5),
	(1, 'Tuan Rhomad', 7, -1, 1688.06, -2265.47, 13.4775, 86.9156, 1, 0, 0, 13);
/*!40000 ALTER TABLE `actors` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.atms
CREATE TABLE IF NOT EXISTS `atms` (
  `id` int(11) NOT NULL,
  `posx` float NOT NULL,
  `posy` float NOT NULL,
  `posz` float NOT NULL,
  `posrx` float NOT NULL,
  `posry` float NOT NULL,
  `posrz` float NOT NULL,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `stock` int(11) NOT NULL DEFAULT 50000,
  `status` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.atms: 20 rows
/*!40000 ALTER TABLE `atms` DISABLE KEYS */;
INSERT INTO `atms` (`id`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `interior`, `world`, `stock`, `status`) VALUES
	(1, 573.273, -1813.55, 6.37251, 0, 0, -90.2, 0, 0, 50000, 0),
	(3, 2330.68, -1142.21, 1050.49, 0, 0, -89.7, 12, 1, 50000, 0),
	(14, 1680.84, -2335.78, 13.5269, 0, 0, 179.1, 0, 0, 50000, 0),
	(5, 1180.73, -1342.15, 14.0965, 0, 0, 178.9, 0, 0, 50000, 0),
	(6, 253.003, 111.664, 1003.34, 0, 0, -90.3, 10, 0, 50000, 0),
	(0, 1250.26, -2006.99, 60.0442, 0, 0, 86.8, 0, 0, 50000, 0),
	(8, 1555.5, -2176.41, 13.5569, 0, 0, -0.400018, 0, 0, 50000, 0),
	(9, 2720.62, -2385.45, 13.7401, -0.199998, 0, 88.5, 0, 0, 50000, 0),
	(10, 119.789, -198.118, 1.54916, 0, 0, -90.5, 0, 0, 50000, 0),
	(11, 1950.25, -1964.59, 14.0277, 0, 0, 0, 0, 0, 50000, 0),
	(12, 2121.99, -2134.73, 13.7866, 0, 0, 68.6, 0, 0, 50000, 0),
	(13, -1756.89, 1106.05, -48.9885, 0, 0, -90.3, 0, 0, 50000, 0),
	(4, -78.0099, -1593.49, 2.7125, 0, 0, -66.5, 0, 0, 50000, 0),
	(15, 1712.09, 911.088, 11.0135, -2.20001, -0.600003, 178, 0, 0, 50000, 0),
	(16, 1586.61, -1682.63, 13.5667, 0, 0, -91, 0, 0, 50000, 0),
	(17, 2514.1, -1531.32, 24.488, -0.299998, 0, -178.4, 0, 0, 50000, 0),
	(2, 1469.31, 713.175, 11.1325, 0, 0, 0, 0, 0, 50000, 0),
	(7, 1087.67, -1776.41, 13.513, 0, 0, -91.2, 0, 0, 50000, 0),
	(18, 942.629, -1683.18, 13.7877, 0, 0, -175.9, 0, 0, 50000, 0),
	(19, 1690.97, -2237.39, 13.4469, 0, 0, 0, 0, 0, 50000, 0);
/*!40000 ALTER TABLE `atms` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.banneds
CREATE TABLE IF NOT EXISTS `banneds` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(24) DEFAULT 'None',
  `ip` varchar(24) DEFAULT 'None',
  `longip` int(11) DEFAULT 0,
  `ban_expire` bigint(16) DEFAULT 0,
  `ban_date` bigint(16) DEFAULT 0,
  `last_activity_timestamp` bigint(16) DEFAULT 0,
  `admin` varchar(40) DEFAULT 'Server',
  `reason` varchar(128) DEFAULT 'None',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.banneds: 0 rows
/*!40000 ALTER TABLE `banneds` DISABLE KEYS */;
/*!40000 ALTER TABLE `banneds` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.bill
CREATE TABLE IF NOT EXISTS `bill` (
  `bid` int(11) NOT NULL,
  `type` int(11) NOT NULL DEFAULT -1,
  `name` varchar(128) NOT NULL DEFAULT 'None',
  `oname` varchar(128) NOT NULL DEFAULT 'None',
  `targetname` varchar(128) NOT NULL DEFAULT 'None',
  `target` int(11) NOT NULL DEFAULT -1,
  `ammount` int(11) NOT NULL DEFAULT 0,
  `time` int(12) NOT NULL DEFAULT 0,
  `phonetarget` int(5) NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.bill: 0 rows
/*!40000 ALTER TABLE `bill` DISABLE KEYS */;
/*!40000 ALTER TABLE `bill` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.bisnis
CREATE TABLE IF NOT EXISTS `bisnis` (
  `ID` int(11) NOT NULL,
  `owner` varchar(40) NOT NULL DEFAULT '-',
  `ownerid` int(11) NOT NULL DEFAULT -1,
  `name` varchar(40) NOT NULL DEFAULT 'Bisnis',
  `price` int(11) NOT NULL DEFAULT 500000,
  `type` int(11) NOT NULL DEFAULT 1,
  `locked` int(11) NOT NULL DEFAULT 1,
  `money` int(11) NOT NULL DEFAULT 0,
  `prod` int(11) NOT NULL DEFAULT 50,
  `bprice0` int(11) NOT NULL DEFAULT 500,
  `bprice1` int(11) NOT NULL DEFAULT 500,
  `bprice2` int(11) NOT NULL DEFAULT 500,
  `bprice3` int(11) NOT NULL DEFAULT 500,
  `bprice4` int(11) NOT NULL DEFAULT 500,
  `bprice5` int(11) NOT NULL DEFAULT 500,
  `bprice6` int(11) NOT NULL DEFAULT 500,
  `bprice7` int(11) NOT NULL DEFAULT 500,
  `bprice8` int(11) NOT NULL DEFAULT 500,
  `bprice9` int(11) NOT NULL DEFAULT 500,
  `extposx` float NOT NULL DEFAULT 0,
  `extposy` float NOT NULL DEFAULT 0,
  `extposz` float NOT NULL DEFAULT 0,
  `extposa` float NOT NULL DEFAULT 0,
  `visit` bigint(16) NOT NULL DEFAULT 0,
  `restock` int(11) NOT NULL DEFAULT 0,
  `song_url` varchar(254) NOT NULL DEFAULT '-',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.bisnis: 2 rows
/*!40000 ALTER TABLE `bisnis` DISABLE KEYS */;
INSERT INTO `bisnis` (`ID`, `owner`, `ownerid`, `name`, `price`, `type`, `locked`, `money`, `prod`, `bprice0`, `bprice1`, `bprice2`, `bprice3`, `bprice4`, `bprice5`, `bprice6`, `bprice7`, `bprice8`, `bprice9`, `extposx`, `extposy`, `extposz`, `extposa`, `visit`, `restock`, `song_url`) VALUES
	(0, 'Escee_Uhuy', 1, 'Xeno Clothes', 5, 5, 0, 1535, 986, 100, 1000, 50, 50, 50, 50, 50, 0, 0, 0, 1687.42, -2265.76, 13.4793, 320.849, 1742631915, 1, '-'),
	(1, 'WhoIsGeats', 1, 'Willowfield', 1, 3, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2115.94, -1916.58, 13.5777, 177.117, 1743554311, 0, '-');
/*!40000 ALTER TABLE `bisnis` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.carstorage
CREATE TABLE IF NOT EXISTS `carstorage` (
  `ID` int(12) DEFAULT 0,
  `itemID` int(12) NOT NULL AUTO_INCREMENT,
  `itemName` varchar(32) DEFAULT NULL,
  `itemModel` int(12) DEFAULT 0,
  `itemQuantity` int(12) DEFAULT 0,
  PRIMARY KEY (`itemID`)
) ENGINE=InnoDB AUTO_INCREMENT=131 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.carstorage: ~4 rows (approximately)
INSERT INTO `carstorage` (`ID`, `itemID`, `itemName`, `itemModel`, `itemQuantity`) VALUES
	(1, 126, 'Batu Cucian', 2936, 10),
	(1, 128, 'Batu', 3929, 10),
	(1, 129, 'Component', 19627, 412),
	(4, 130, 'Portable Radio', 18868, 1);

-- Dumping structure for table s1130_localprime_samp.dealer
CREATE TABLE IF NOT EXISTS `dealer` (
  `id` int(11) NOT NULL,
  `owner` varchar(40) NOT NULL DEFAULT '-',
  `name` varchar(40) NOT NULL DEFAULT 'None',
  `price` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posa` float DEFAULT 0,
  `posint` int(11) NOT NULL DEFAULT 0,
  `posvw` int(11) NOT NULL DEFAULT 0,
  `vehx` float DEFAULT 0,
  `vehy` float DEFAULT 0,
  `vehz` float DEFAULT 0,
  `veha` float DEFAULT 0,
  `vehint` bigint(11) NOT NULL DEFAULT 0,
  `vehvw` int(11) NOT NULL DEFAULT 0,
  `locked` int(11) NOT NULL DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `stock` int(11) NOT NULL DEFAULT 0,
  `visit` bigint(16) NOT NULL DEFAULT 0,
  `vehprice0` int(11) NOT NULL DEFAULT 0,
  `vehprice1` int(11) NOT NULL DEFAULT 0,
  `vehprice2` int(11) NOT NULL DEFAULT 0,
  `vehprice3` int(11) NOT NULL DEFAULT 0,
  `vehprice4` int(11) NOT NULL DEFAULT 0,
  `vehprice5` int(11) NOT NULL DEFAULT 0,
  `vehprice6` int(11) NOT NULL DEFAULT 0,
  `vehprice7` int(11) NOT NULL DEFAULT 0,
  `vehprice8` int(11) NOT NULL DEFAULT 0,
  `vehprice9` int(11) NOT NULL DEFAULT 0,
  `vehprice10` int(11) NOT NULL DEFAULT 0,
  `vehprice11` int(11) NOT NULL DEFAULT 0,
  `vehprice12` int(11) NOT NULL DEFAULT 0,
  `vehprice13` int(11) NOT NULL DEFAULT 0,
  `vehprice14` int(11) NOT NULL DEFAULT 0,
  `vehprice15` int(11) NOT NULL DEFAULT 0,
  `vehprice16` int(11) NOT NULL DEFAULT 0,
  `vehprice17` int(11) NOT NULL DEFAULT 0,
  `vehprice18` int(11) NOT NULL DEFAULT 0,
  `vehprice19` int(11) NOT NULL DEFAULT 0,
  `vehprice20` int(11) NOT NULL DEFAULT 0,
  `vehprice21` int(11) NOT NULL DEFAULT 0,
  `vehprice22` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.dealer: 0 rows
/*!40000 ALTER TABLE `dealer` DISABLE KEYS */;
/*!40000 ALTER TABLE `dealer` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.doors
CREATE TABLE IF NOT EXISTS `doors` (
  `ID` int(11) NOT NULL,
  `name` varchar(50) DEFAULT 'None',
  `password` varchar(50) DEFAULT '',
  `icon` int(11) DEFAULT 19130,
  `locked` int(11) NOT NULL DEFAULT 0,
  `admin` int(11) NOT NULL DEFAULT 0,
  `vip` int(11) NOT NULL DEFAULT 0,
  `faction` int(11) NOT NULL DEFAULT 0,
  `family` int(11) NOT NULL DEFAULT -1,
  `garage` tinyint(3) NOT NULL DEFAULT 0,
  `custom` int(11) NOT NULL DEFAULT 0,
  `extvw` int(11) DEFAULT 0,
  `extint` int(11) DEFAULT 0,
  `extposx` float DEFAULT 0,
  `extposy` float DEFAULT 0,
  `extposz` float DEFAULT 0,
  `extposa` float DEFAULT 0,
  `intvw` int(11) DEFAULT 0,
  `intint` int(11) NOT NULL DEFAULT 0,
  `intposx` float DEFAULT 0,
  `intposy` float DEFAULT 0,
  `intposz` float DEFAULT 0,
  `intposa` float DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.doors: 7 rows
/*!40000 ALTER TABLE `doors` DISABLE KEYS */;
INSERT INTO `doors` (`ID`, `name`, `password`, `icon`, `locked`, `admin`, `vip`, `faction`, `family`, `garage`, `custom`, `extvw`, `extint`, `extposx`, `extposy`, `extposz`, `extposa`, `intvw`, `intint`, `intposx`, `intposy`, `intposz`, `intposa`) VALUES
	(0, 'city hall', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1483.15, -1761.95, 13.8969, 174.59, 0, 0, 1424.02, 1525.22, 3010.83, 194.416),
	(1, 'airport', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1705.35, -2237.86, 13.5396, 44.1401, 0, 0, 1643.83, -2319.54, 1020.33, 15.1879),
	(2, 'hospital', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, 2033.92, -1402.38, 17.2924, 346.071, 0, 0, -2166.64, 1922.51, 1192.1, 189.591),
	(3, 'disnaker', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1123.9, -2037.01, 69.8857, 89.7021, 0, 0, 1334.47, 1558.18, 1113.3, 198.553),
	(4, 'tambang', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, -844.836, -2251.61, 22.2408, 294.783, 0, 0, -2374.99, -2062.15, 52.1411, 230.904),
	(5, 'kantor penjahit', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1983, -2069.55, 13.5352, 185.643, 0, 0, 1935.37, -2106.75, 1013.47, 92.0583),
	(6, 'localnews', '', 19606, 0, 0, 0, 0, -1, 0, 0, 0, 0, 648.434, -1357.38, 13.5705, 264.043, 0, 0, 1370.48, -19.991, 1001, 85.0236);
/*!40000 ALTER TABLE `doors` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.dropped
CREATE TABLE IF NOT EXISTS `dropped` (
  `ID` int(12) NOT NULL AUTO_INCREMENT,
  `itemName` varchar(32) NOT NULL,
  `itemPlayer` varchar(24) DEFAULT NULL,
  `itemModel` int(12) DEFAULT 0,
  `itemQuantity` int(12) DEFAULT 0,
  `itemAmmo` int(64) DEFAULT 0,
  `itemWeapon` int(12) DEFAULT 0,
  `itemX` float NOT NULL DEFAULT 0,
  `itemY` float NOT NULL DEFAULT 0,
  `itemZ` float NOT NULL DEFAULT 0,
  `itemInt` int(11) unsigned NOT NULL DEFAULT 0,
  `itemWorld` int(11) unsigned NOT NULL DEFAULT 0,
  `itemTime` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.dropped: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.faction_vehpoint
CREATE TABLE IF NOT EXISTS `faction_vehpoint` (
  `id` int(11) NOT NULL,
  `owner` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posa` float DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.faction_vehpoint: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.familys
CREATE TABLE IF NOT EXISTS `familys` (
  `ID` int(11) NOT NULL,
  `name` varchar(50) NOT NULL DEFAULT 'None',
  `leader` varchar(50) NOT NULL DEFAULT 'None',
  `motd` varchar(100) NOT NULL DEFAULT 'None',
  `color` int(11) DEFAULT 0,
  `extposx` float DEFAULT 0,
  `extposy` float DEFAULT 0,
  `extposz` float DEFAULT 0,
  `extposa` float DEFAULT 0,
  `intposx` float DEFAULT 0,
  `intposy` float DEFAULT 0,
  `intposz` float DEFAULT 0,
  `intposa` float DEFAULT 0,
  `fint` int(11) NOT NULL DEFAULT 0,
  `Weapon1` int(11) NOT NULL DEFAULT 0,
  `Ammo1` int(11) NOT NULL DEFAULT 0,
  `Weapon2` int(11) NOT NULL DEFAULT 0,
  `Ammo2` int(11) NOT NULL DEFAULT 0,
  `Weapon3` int(11) NOT NULL DEFAULT 0,
  `Ammo3` int(11) NOT NULL DEFAULT 0,
  `Weapon4` int(11) NOT NULL DEFAULT 0,
  `Ammo4` int(11) NOT NULL DEFAULT 0,
  `Weapon5` int(11) NOT NULL DEFAULT 0,
  `Ammo5` int(11) NOT NULL DEFAULT 0,
  `Weapon6` int(11) NOT NULL DEFAULT 0,
  `Ammo6` int(11) NOT NULL DEFAULT 0,
  `Weapon7` int(11) NOT NULL DEFAULT 0,
  `Ammo7` int(11) NOT NULL DEFAULT 0,
  `Weapon8` int(11) NOT NULL DEFAULT 0,
  `Ammo8` int(11) NOT NULL DEFAULT 0,
  `Weapon9` int(11) NOT NULL DEFAULT 0,
  `Ammo9` int(11) NOT NULL DEFAULT 0,
  `Weapon10` int(11) NOT NULL DEFAULT 0,
  `Ammo10` int(11) NOT NULL DEFAULT 0,
  `safex` float DEFAULT 0,
  `safey` float DEFAULT 0,
  `safez` float DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `marijuana` int(11) NOT NULL DEFAULT 0,
  `component` int(11) NOT NULL DEFAULT 0,
  `material` int(11) NOT NULL DEFAULT 0,
  `Weapon11` int(11) NOT NULL DEFAULT 0,
  `Ammo11` int(11) NOT NULL DEFAULT 0,
  `Weapon12` int(11) NOT NULL DEFAULT 0,
  `Ammo12` int(11) NOT NULL DEFAULT 0,
  `Weapon13` int(11) NOT NULL DEFAULT 0,
  `Ammo13` int(11) NOT NULL DEFAULT 0,
  `Weapon14` int(11) NOT NULL DEFAULT 0,
  `Ammo14` int(11) NOT NULL DEFAULT 0,
  `Weapon15` int(11) NOT NULL DEFAULT 0,
  `Ammo15` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.familys: 0 rows
/*!40000 ALTER TABLE `familys` DISABLE KEYS */;
/*!40000 ALTER TABLE `familys` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.garkot
CREATE TABLE IF NOT EXISTS `garkot` (
  `id` int(11) NOT NULL,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posa` float DEFAULT 0,
  `spawnx` float DEFAULT 0,
  `spawny` float DEFAULT 0,
  `spawnz` float DEFAULT 0,
  `spawna` float DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.garkot: 26 rows
/*!40000 ALTER TABLE `garkot` DISABLE KEYS */;
INSERT INTO `garkot` (`id`, `posx`, `posy`, `posz`, `posa`, `spawnx`, `spawny`, `spawnz`, `spawna`, `interior`, `world`) VALUES
	(0, 1062.52, -1758.07, 13.4174, 91.6616, 1062.16, -1749.03, 13.4506, 270.665, 0, 0),
	(12, -368.838, 1155.28, 19.7422, 272.013, -349.163, 1180.7, 19.7422, 186.973, 0, 0),
	(5, 1917.9, -1143.42, 24.9314, 100.86, 1910.15, -1143.69, 24.7379, 44.3389, 0, 0),
	(13, 2102.56, -1778.32, 13.4909, 277.523, 2117.4, -1782.19, 13.4884, 277.523, 0, 0),
	(3, -52.1679, -1554.22, 2.71115, 132.432, -62.9686, -1589.52, 2.61072, 223.962, 0, 0),
	(15, 2487.94, -1518.84, 23.9922, 0.753293, 2476.74, -1550.41, 24.0117, 96.3816, 0, 0),
	(6, 1547.74, -2348.51, 13.5469, 226.964, 1523.73, -2351.41, 13.5469, 270.067, 0, 0),
	(7, 1259.57, -2031.04, 59.4317, 90.1484, 1259.61, -2020.01, 59.433, 320.496, 0, 0),
	(2, 381.021, -2044.9, 7.83594, 45.929, 370.425, -2045.63, 7.67188, 359.869, 0, 0),
	(14, 500.873, -1766.63, 5.55887, 92.1729, 478.478, -1766.29, 5.53683, 89.5977, 0, 0),
	(10, 1241.01, -1815.23, 13.4235, 245.533, 1278.55, -1829.92, 13.3856, 90.5995, 0, 0),
	(11, 295.338, -1541.04, 24.5938, 55.296, 303.071, -1485.78, 24.5938, 235.984, 0, 0),
	(4, 1555.41, -1027.24, 23.9062, 161.872, 1547.14, -1024.21, 23.9062, 161.872, 0, 0),
	(16, 558.646, 892.771, -43.1438, 9.32162, 570.607, 893.583, -43.3312, 1.29241, 0, 0),
	(9, 2174.39, -2266.86, 13.3798, 48.5729, 2166.78, -2275.31, 13.387, 44.9695, 0, 0),
	(8, 1706.71, 922.371, 10.8335, 0.507834, 1743.94, 929.795, 10.8286, 1.79155, 0, 0),
	(1, 1180.15, -1358.21, 14.2813, 263.542, 1179.92, -1364.45, 14.2813, 268.125, 0, 0),
	(17, -1031.43, -1034.47, 129.219, 260.16, -1048.65, -1054.61, 129.212, 88.4322, 0, 0),
	(20, 315.047, 1134.85, 8.69467, 268.671, 338.29, 1152.97, 8.31027, 183.977, 0, 0),
	(21, 1640.23, -1523.19, 13.5853, 1.30341, 1633.9, -1540.34, 13.6116, 270.79, 0, 0),
	(19, 759.033, -1120.65, 24.4507, 94.1091, 760.441, -1131.45, 24.2385, 250.249, 0, 0),
	(18, -539.596, 2608.52, 53.4154, 264.039, -540.526, 2595.56, 53.4154, 276.071, 0, 0),
	(22, 751.217, -1341.96, 13.8414, 70.2951, 774.317, -1343.97, 13.8414, 180.863, 0, 0),
	(23, 2067.69, -2059.4, 13.5469, 91.984, 2080.62, -2059.72, 13.5469, 265.644, 0, 0),
	(24, 1103.63, -819.477, 86.9453, 130.797, 1097.11, -820.059, 86.9453, 86.8804, 0, 0),
	(25, 1433.12, -1776.9, 13.5469, 239.223, 1418.15, -1755.42, 13.5469, 26.5044, 0, 0);
/*!40000 ALTER TABLE `garkot` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.gates
CREATE TABLE IF NOT EXISTS `gates` (
  `ID` int(11) NOT NULL,
  `model` int(11) NOT NULL DEFAULT 0,
  `password` varchar(36) NOT NULL DEFAULT '',
  `admin` tinyint(3) NOT NULL DEFAULT 0,
  `vip` tinyint(3) NOT NULL DEFAULT 0,
  `faction` tinyint(3) NOT NULL DEFAULT 0,
  `family` int(10) NOT NULL DEFAULT -1,
  `speed` float NOT NULL DEFAULT 2,
  `cX` float NOT NULL,
  `cY` float NOT NULL,
  `cZ` float NOT NULL,
  `cRX` float NOT NULL,
  `cRY` float NOT NULL,
  `cRZ` float NOT NULL,
  `oX` float NOT NULL,
  `oY` float NOT NULL,
  `oZ` float NOT NULL,
  `oRX` float NOT NULL,
  `oRY` float NOT NULL,
  `oRZ` float NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.gates: 0 rows
/*!40000 ALTER TABLE `gates` DISABLE KEYS */;
/*!40000 ALTER TABLE `gates` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.gstations
CREATE TABLE IF NOT EXISTS `gstations` (
  `id` int(11) NOT NULL DEFAULT 0,
  `stock` int(11) NOT NULL DEFAULT 10000,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.gstations: 30 rows
/*!40000 ALTER TABLE `gstations` DISABLE KEYS */;
INSERT INTO `gstations` (`id`, `stock`, `posx`, `posy`, `posz`) VALUES
	(0, 7440, -98.2705, -1173.5, 2.39535),
	(1, 8585, -93.136, -1161.42, 2.21086),
	(4, 1555, 1942.96, -1774.31, 13.3828),
	(5, 10255, -89.1682, -1176.95, 2.12799),
	(6, 3250, 1007.47, -939.927, 42.1797),
	(7, 9160, 1000.57, -933.849, 42.1797),
	(2, 765, 653.034, -569.04, 16.3359),
	(3, 890, 659.08, -559.794, 16.3359),
	(8, 10105, -1605.56, -2714.4, 48.5391),
	(9, 1085, 2205.29, 2474.48, 10.8203),
	(10, 1065, 2195.15, 2474.17, 10.8203),
	(11, 1030, 2115.34, 922.522, 10.8203),
	(12, 1155, 2115.12, 911.409, 10.8203),
	(13, 1070, 1596.66, 2196.43, 10.8203),
	(14, 1115, 1596.22, 2207.29, 10.8203),
	(15, 1095, -1327.71, 2683.28, 50.0625),
	(16, 1050, -1328.66, 2672.09, 50.0625),
	(17, 1085, -1478.1, 1863.15, 32.6328),
	(18, 1110, -1466.77, 1864.02, 32.6328),
	(19, 10100, 1381.25, 457.612, 19.9428),
	(20, 1100, -1674.6, 412.403, 7.17969),
	(21, 1120, -1681.74, 418.613, 7.17969),
	(22, 1130, 622.205, 1679.58, 6.99219),
	(23, 1115, 615.111, 1689.98, 6.99219),
	(24, 1045, 608.028, 1700.27, 6.99219),
	(25, 1100, -2244.71, -2561.46, 31.5266),
	(26, 10375, 1942.95, -1767.15, 13.3828),
	(27, 10295, 1942.95, -1771.4, 13.3828),
	(28, 10440, 1942.95, -1778.58, 13.3828),
	(29, 10245, -84.2777, -1165.49, 2.23513);
/*!40000 ALTER TABLE `gstations` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.houses
CREATE TABLE IF NOT EXISTS `houses` (
  `ID` int(11) NOT NULL,
  `owner` varchar(50) NOT NULL DEFAULT '-',
  `owner2` varchar(50) NOT NULL DEFAULT '-',
  `address` varchar(50) DEFAULT 'None',
  `price` int(11) NOT NULL DEFAULT 500000,
  `type` int(11) NOT NULL DEFAULT 1,
  `locked` int(11) NOT NULL DEFAULT 1,
  `money` int(11) NOT NULL DEFAULT 0,
  `component` int(11) NOT NULL DEFAULT 0,
  `material` int(11) NOT NULL DEFAULT 0,
  `marijuana` int(11) NOT NULL DEFAULT 0,
  `ephedrine` int(11) NOT NULL DEFAULT 0,
  `cocaine` int(11) NOT NULL DEFAULT 0,
  `meth` int(11) NOT NULL DEFAULT 0,
  `houseint` int(11) NOT NULL DEFAULT 0,
  `extposx` float NOT NULL DEFAULT 0,
  `extposy` float NOT NULL DEFAULT 0,
  `extposz` float NOT NULL DEFAULT 0,
  `extposa` float NOT NULL DEFAULT 0,
  `intposx` float NOT NULL DEFAULT 0,
  `intposy` float NOT NULL DEFAULT 0,
  `intposz` float NOT NULL DEFAULT 0,
  `intposa` float NOT NULL DEFAULT 0,
  `visit` bigint(16) DEFAULT 0,
  `houseWeapon1` int(12) DEFAULT 0,
  `houseAmmo1` int(12) DEFAULT 0,
  `houseWeapon2` int(12) DEFAULT 0,
  `houseAmmo2` int(12) DEFAULT 0,
  `houseWeapon3` int(12) DEFAULT 0,
  `houseAmmo3` int(12) DEFAULT 0,
  `houseWeapon4` int(12) DEFAULT 0,
  `houseAmmo4` int(12) DEFAULT 0,
  `houseWeapon5` int(12) DEFAULT 0,
  `houseAmmo5` int(12) DEFAULT 0,
  `houseWeapon6` int(12) DEFAULT 0,
  `houseAmmo6` int(12) DEFAULT 0,
  `houseWeapon7` int(12) DEFAULT 0,
  `houseAmmo7` int(12) DEFAULT 0,
  `houseWeapon8` int(12) DEFAULT 0,
  `houseAmmo8` int(12) DEFAULT 0,
  `houseWeapon9` int(12) DEFAULT 0,
  `houseAmmo9` int(12) DEFAULT 0,
  `houseWeapon10` int(12) DEFAULT 0,
  `houseAmmo10` int(12) DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.houses: 0 rows
/*!40000 ALTER TABLE `houses` DISABLE KEYS */;
/*!40000 ALTER TABLE `houses` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.inventory
CREATE TABLE IF NOT EXISTS `inventory` (
  `ID` int(12) DEFAULT 0,
  `invID` int(11) NOT NULL AUTO_INCREMENT,
  `invItem` varchar(32) DEFAULT NULL,
  `invModel` int(12) DEFAULT 0,
  `invSlot` int(12) DEFAULT -1,
  `invQuantity` int(12) DEFAULT 0,
  `invWeapon` int(12) DEFAULT 0,
  `invAmmo` int(64) DEFAULT 0,
  PRIMARY KEY (`invID`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.inventory: ~11 rows (approximately)
INSERT INTO `inventory` (`ID`, `invID`, `invItem`, `invModel`, `invSlot`, `invQuantity`, `invWeapon`, `invAmmo`) VALUES
	(1, 2, 'Portable Radio', 18868, 1, 2, 0, 0),
	(1, 3, 'Boombox', 2226, 2, 1, 0, 0),
	(1, 10, 'Phone', 18866, 0, 2, 0, 0),
	(1, 16, 'Pakaian', 2705, 5, 5, 0, 0),
	(1, 20, 'Susu', 19570, 6, 1, 0, 0),
	(1, 21, 'Susu Olah', 19570, 7, 2, 0, 0),
	(3, 28, 'Benang', 1901, 1, 25, 0, 0),
	(3, 29, 'Phone', 18866, 2, 1, 0, 0),
	(1, 30, 'Component', 19627, 6, 1824, 0, 0),
	(1, 31, 'Repair Kit', 920, 7, 2, 0, 0),
	(1, 32, 'Benang', 1901, 8, 10, 0, 0);

-- Dumping structure for table s1130_localprime_samp.itemstorage
CREATE TABLE IF NOT EXISTS `itemstorage` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(24) NOT NULL,
  `Model` int(8) NOT NULL DEFAULT 0,
  `Quantity` int(8) NOT NULL DEFAULT 0,
  `StorageID` int(8) NOT NULL DEFAULT -1,
  `ExtraID` int(8) NOT NULL DEFAULT -1,
  `Type` int(3) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.itemstorage: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.jobprice
CREATE TABLE IF NOT EXISTS `jobprice` (
  `id` int(11) NOT NULL DEFAULT 0,
  `sjforklift` int(11) NOT NULL DEFAULT 10,
  `sjmower` int(11) NOT NULL DEFAULT 10,
  `sjsweeper` int(11) NOT NULL DEFAULT 10,
  `sjbus` int(11) NOT NULL DEFAULT 10,
  `sjtrashmaster` int(11) NOT NULL DEFAULT 10,
  `jobpizza` int(11) NOT NULL DEFAULT 10,
  `jobbutcher` int(11) NOT NULL DEFAULT 10,
  `jobpemerassusu` int(11) NOT NULL DEFAULT 10,
  `jobreflenish` int(11) NOT NULL DEFAULT 10,
  `jobtrucker` int(11) NOT NULL DEFAULT 10,
  `drugdealer1` int(11) NOT NULL DEFAULT 500,
  `drugdealer2` int(11) NOT NULL DEFAULT 500,
  `drugdealer3` int(11) NOT NULL DEFAULT 500,
  `jobminer` int(11) NOT NULL DEFAULT 10,
  `production1` int(11) NOT NULL DEFAULT 10,
  `production2` int(11) NOT NULL DEFAULT 10,
  `production3` int(11) NOT NULL DEFAULT 10,
  `hauling1` int(11) NOT NULL DEFAULT 10,
  `hauling2` int(11) NOT NULL DEFAULT 10,
  `hauling3` int(11) NOT NULL DEFAULT 10,
  `factionprice` int(11) NOT NULL DEFAULT 10,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.jobprice: 1 rows
/*!40000 ALTER TABLE `jobprice` DISABLE KEYS */;
INSERT INTO `jobprice` (`id`, `sjforklift`, `sjmower`, `sjsweeper`, `sjbus`, `sjtrashmaster`, `jobpizza`, `jobbutcher`, `jobpemerassusu`, `jobreflenish`, `jobtrucker`, `drugdealer1`, `drugdealer2`, `drugdealer3`, `jobminer`, `production1`, `production2`, `production3`, `hauling1`, `hauling2`, `hauling3`, `factionprice`) VALUES
	(0, 950, 950, 500, 700, 800, 950, 1000, 450, 850, 500, 1000, 1000, 1000, 890, 800, 800, 800, 900, 900, 900, 1000);
/*!40000 ALTER TABLE `jobprice` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.lockers
CREATE TABLE IF NOT EXISTS `lockers` (
  `id` int(11) NOT NULL,
  `type` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `money` int(11) DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.lockers: 2 rows
/*!40000 ALTER TABLE `lockers` DISABLE KEYS */;
INSERT INTO `lockers` (`id`, `type`, `posx`, `posy`, `posz`, `interior`, `money`) VALUES
	(0, 6, 221.435, -223.88, 9.19893, 0, 0),
	(1, 2, 1412.82, 1563.17, 3010.83, 0, 0);
/*!40000 ALTER TABLE `lockers` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.logpay
CREATE TABLE IF NOT EXISTS `logpay` (
  `player` varchar(40) NOT NULL DEFAULT 'None',
  `playerid` int(11) NOT NULL DEFAULT 0,
  `toplayer` varchar(40) NOT NULL DEFAULT 'None',
  `toplayerid` int(11) NOT NULL DEFAULT 0,
  `ammount` int(11) NOT NULL DEFAULT 0,
  `time` bigint(15) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.logpay: 0 rows
/*!40000 ALTER TABLE `logpay` DISABLE KEYS */;
/*!40000 ALTER TABLE `logpay` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.logstaff
CREATE TABLE IF NOT EXISTS `logstaff` (
  `command` varchar(50) NOT NULL,
  `admin` varchar(50) NOT NULL,
  `adminid` int(11) NOT NULL,
  `player` varchar(50) NOT NULL DEFAULT '*',
  `playerid` int(11) NOT NULL DEFAULT -1,
  `str` varchar(50) NOT NULL DEFAULT '*',
  `time` bigint(15) unsigned NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.logstaff: 19 rows
/*!40000 ALTER TABLE `logstaff` DISABLE KEYS */;
INSERT INTO `logstaff` (`command`, `admin`, `adminid`, `player`, `playerid`, `str`, `time`) VALUES
	('SETVIP', 'Escee_Uhuy(WhoIsGeats)', 1, 'Escee_Uhuy', 1, '3(0 days)', 1739974408),
	('SETMONEY', 'Escee_Uhuy(WhoIsGeats)', 1, 'Escee_Uhuy', 1, '10000', 1740186015),
	('SETMONEY', 'Escee_Uhuy(WhoIsGeats)', 1, 'Escee_Uhuy', 1, '10000', 1740186065),
	('SETMONEY', 'Escee_Uhuy(WhoIsGeats)', 1, 'Escee_Uhuy', 1, '100000', 1740186071),
	('SETFACTION', 'Escee_Uhuy(WhoIsGeats)', 1, 'Escee_Uhuy', 1, '6(6 rank)', 1740271222),
	('SETVIP', 'Xeno_Gerad(X)', 1, 'Xeno_Gerad', 1, '3(0 days)', 1741501440),
	('SETMONEY', 'Xeno_Gerad(X)', 1, 'Xeno_Gerad', 1, '10000', 1741501485),
	('SETMONEY', 'Xeno_Gerad(X)', 1, 'Xeno_Gerad', 1, '100000', 1741509866),
	('SETFACTION', 'Xeno_Gerad(X)', 1, 'Xeno_Gerad', 1, '6(6 rank)', 1741509979),
	('SETFACTION', 'Xeno_Gerad(X)', 1, 'Xeno_Gerad', 1, '4(6 rank)', 1741531895),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '1(6 rank)', 1741536274),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '2(6 rank)', 1741536467),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '1(6 rank)', 1741536480),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '2(6 rank)', 1741536494),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '3(6 rank)', 1741536507),
	('SETFACTION', 'Xeno_Gerad(X)', 1, 'Xeno_Tadasi', 3, '6(6 rank)', 1741564705),
	('SETFACTION', 'Xeno_Gerad(X)', 1, 'Xeno_Gerad', 1, '6(6 rank)', 1741564716),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '0(3 rank)', 1741742622),
	('SETFACTION', 'Xeno_Tadasi(X2)', 3, 'Xeno_Tadasi', 3, '3(6 rank)', 1741742629);
/*!40000 ALTER TABLE `logstaff` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.mappingingame
CREATE TABLE IF NOT EXISTS `mappingingame` (
  `id` int(11) NOT NULL,
  `objectmodel` int(8) NOT NULL DEFAULT 0,
  `posx` float NOT NULL,
  `posy` float NOT NULL,
  `posz` float NOT NULL,
  `posrx` float NOT NULL,
  `posry` float NOT NULL,
  `posrz` float NOT NULL,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.mappingingame: 0 rows
/*!40000 ALTER TABLE `mappingingame` DISABLE KEYS */;
/*!40000 ALTER TABLE `mappingingame` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.matext
CREATE TABLE IF NOT EXISTS `matext` (
  `id` int(11) NOT NULL,
  `text` varchar(254) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'None',
  `size` int(11) NOT NULL DEFAULT 0,
  `color` int(11) NOT NULL DEFAULT 0,
  `bold` int(11) NOT NULL DEFAULT 0,
  `x` float DEFAULT 0,
  `y` float DEFAULT 0,
  `z` float DEFAULT 0,
  `rx` float DEFAULT 0,
  `ry` float DEFAULT 0,
  `rz` float DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.matext: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.notes
CREATE TABLE IF NOT EXISTS `notes` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `from` varchar(24) NOT NULL DEFAULT 'Unkonow',
  `text` varchar(24) NOT NULL DEFAULT 'No text',
  `x` float DEFAULT 0,
  `y` float DEFAULT 0,
  `z` float DEFAULT 0,
  `int` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.notes: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.npcfamily
CREATE TABLE IF NOT EXISTS `npcfamily` (
  `id` int(11) NOT NULL,
  `owner` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posa` float DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `material` int(11) NOT NULL DEFAULT 0,
  `marijuana` int(11) NOT NULL DEFAULT 0,
  `cocaine` int(11) NOT NULL DEFAULT 0,
  `meth` int(11) NOT NULL DEFAULT 0,
  `price0` int(11) NOT NULL DEFAULT 0,
  `price1` int(11) NOT NULL DEFAULT 0,
  `price2` int(11) NOT NULL DEFAULT 0,
  `price3` int(11) NOT NULL DEFAULT 0,
  `price4` int(11) NOT NULL DEFAULT 0,
  `price5` int(11) NOT NULL DEFAULT 0,
  `price6` int(11) NOT NULL DEFAULT 0,
  `price7` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.npcfamily: 0 rows
/*!40000 ALTER TABLE `npcfamily` DISABLE KEYS */;
/*!40000 ALTER TABLE `npcfamily` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.payphone
CREATE TABLE IF NOT EXISTS `payphone` (
  `id` int(11) NOT NULL,
  `status` int(11) NOT NULL DEFAULT 0,
  `price` int(11) NOT NULL DEFAULT 0,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posrx` float DEFAULT 0,
  `posry` float DEFAULT 0,
  `posrz` float DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.payphone: 0 rows
/*!40000 ALTER TABLE `payphone` DISABLE KEYS */;
/*!40000 ALTER TABLE `payphone` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.pedagang
CREATE TABLE IF NOT EXISTS `pedagang` (
  `id` int(11) NOT NULL,
  `type` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `gandum` int(11) NOT NULL DEFAULT 0,
  `daging` int(11) NOT NULL DEFAULT 0,
  `susuolah` int(11) NOT NULL DEFAULT 0,
  `burger` int(11) NOT NULL DEFAULT 0,
  `roti` int(11) NOT NULL DEFAULT 0,
  `steak` int(11) NOT NULL DEFAULT 0,
  `milk` int(11) NOT NULL DEFAULT 0,
  `kentang` int(11) NOT NULL,
  `orange` int(11) NOT NULL,
  `food` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.pedagang: ~0 rows (approximately)

-- Dumping structure for table s1130_localprime_samp.phonebook
CREATE TABLE IF NOT EXISTS `phonebook` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `owner` int(11) DEFAULT 0,
  `cname` varchar(46) DEFAULT '',
  `cnumber` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.phonebook: 1 rows
/*!40000 ALTER TABLE `phonebook` DISABLE KEYS */;
INSERT INTO `phonebook` (`id`, `owner`, `cname`, `cnumber`) VALUES
	(1, 1, 'Xeno_Tadasi', 3877);
/*!40000 ALTER TABLE `phonebook` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.plants
CREATE TABLE IF NOT EXISTS `plants` (
  `id` int(11) NOT NULL,
  `type` int(11) NOT NULL DEFAULT 0,
  `time` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.plants: 0 rows
/*!40000 ALTER TABLE `plants` DISABLE KEYS */;
/*!40000 ALTER TABLE `plants` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.players
CREATE TABLE IF NOT EXISTS `players` (
  `reg_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(24) NOT NULL DEFAULT '',
  `ucp_name` varchar(24) NOT NULL DEFAULT '',
  `discordid` varchar(30) NOT NULL DEFAULT '',
  `adminname` varchar(24) NOT NULL DEFAULT 'None',
  `twittername` varchar(24) NOT NULL DEFAULT 'None',
  `twitterbio` varchar(24) NOT NULL DEFAULT 'None',
  `ip` varchar(24) NOT NULL DEFAULT '',
  `password` char(64) NOT NULL DEFAULT '',
  `salt` char(16) NOT NULL DEFAULT '',
  `email` varchar(40) NOT NULL DEFAULT 'None',
  `admin` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `helper` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `level` int(11) unsigned NOT NULL DEFAULT 1,
  `levelup` int(11) unsigned NOT NULL DEFAULT 0,
  `vip` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `vip_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  `reg_date` varchar(30) NOT NULL DEFAULT '',
  `last_login` varchar(30) NOT NULL DEFAULT '',
  `money` int(11) NOT NULL DEFAULT 0,
  `bmoney` int(11) NOT NULL DEFAULT 0,
  `brek` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `phone` mediumint(11) unsigned NOT NULL DEFAULT 0,
  `phonecredit` int(11) unsigned NOT NULL DEFAULT 0,
  `phonebook` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `gpsins` int(11) NOT NULL DEFAULT 0,
  `twtins` int(11) NOT NULL DEFAULT 0,
  `aonains` int(11) NOT NULL DEFAULT 0,
  `wt` int(11) unsigned NOT NULL DEFAULT 0,
  `hours` int(11) unsigned NOT NULL DEFAULT 0,
  `minutes` int(11) unsigned NOT NULL DEFAULT 0,
  `seconds` int(11) unsigned NOT NULL DEFAULT 0,
  `paycheck` int(11) unsigned NOT NULL DEFAULT 0,
  `skin` smallint(5) unsigned NOT NULL DEFAULT 0,
  `facskin` smallint(5) unsigned NOT NULL DEFAULT 0,
  `gender` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `age` varchar(30) NOT NULL DEFAULT '',
  `indoor` mediumint(8) NOT NULL DEFAULT -1,
  `inbiz` mediumint(8) NOT NULL DEFAULT -1,
  `inhouse` mediumint(8) NOT NULL DEFAULT -1,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `posa` float NOT NULL DEFAULT 0,
  `interior` int(11) unsigned NOT NULL DEFAULT 0,
  `world` int(11) unsigned NOT NULL DEFAULT 0,
  `health` float NOT NULL DEFAULT 100,
  `armour` float NOT NULL DEFAULT 0,
  `hunger` smallint(5) NOT NULL DEFAULT 100,
  `energy` smallint(5) NOT NULL DEFAULT 100,
  `stress` smallint(5) NOT NULL DEFAULT 0,
  `sick` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `hospital` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `injured` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `duty` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `dutytime` int(11) unsigned NOT NULL DEFAULT 0,
  `faction` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `factionrank` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `factionlead` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `family` tinyint(3) NOT NULL DEFAULT -1,
  `familyrank` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `workshop` tinyint(3) NOT NULL DEFAULT -1,
  `workshoprank` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `jail` int(11) unsigned NOT NULL DEFAULT 0,
  `jail_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `rehab` int(11) unsigned NOT NULL DEFAULT 0,
  `rehab_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `robbing` int(11) unsigned NOT NULL DEFAULT 0,
  `robbing_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `arrest` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `arrest_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `warn` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `job` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `job2` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `jobtime` bigint(16) unsigned NOT NULL DEFAULT 0,
  `sidejobtime` bigint(16) unsigned NOT NULL DEFAULT 0,
  `exitjob` bigint(16) unsigned NOT NULL DEFAULT 0,
  `taxitime` bigint(16) unsigned NOT NULL DEFAULT 0,
  `mask` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `helmet` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `fightingstyle` tinyint(3) unsigned NOT NULL DEFAULT 4,
  `gps` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `food` mediumint(8) NOT NULL DEFAULT 0,
  `seed` mediumint(8) NOT NULL DEFAULT 0,
  `potato` mediumint(8) NOT NULL DEFAULT 0,
  `wheat` mediumint(8) NOT NULL DEFAULT 0,
  `orange` mediumint(8) NOT NULL DEFAULT 0,
  `price1` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `price2` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `price3` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `price4` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `plant` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `plant_time` int(11) unsigned NOT NULL DEFAULT 0,
  `fishtool` tinyint(3) NOT NULL DEFAULT 0,
  `fish` mediumint(8) NOT NULL DEFAULT 0,
  `worm` mediumint(8) NOT NULL DEFAULT 0,
  `idcard` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `idcard_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `drivelic` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `drivelic_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `trucklic` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `trucklic_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `lumberlic` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `lumberlic_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `weaponlic` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `weaponlic_time` bigint(16) unsigned NOT NULL DEFAULT 0,
  `spawn_tdtime` int(11) NOT NULL DEFAULT 0,
  `hbemode` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `togpm` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `toglog` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `togads` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `togwt` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `daging` mediumint(8) NOT NULL DEFAULT 0,
  `gandum` mediumint(8) NOT NULL DEFAULT 0,
  `susu` mediumint(8) NOT NULL DEFAULT 0,
  `susuolah` mediumint(8) NOT NULL DEFAULT 0,
  `staterpack` mediumint(8) NOT NULL DEFAULT 0,
  `Gun1` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun2` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun3` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun4` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun5` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun6` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun7` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun8` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun9` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun10` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun11` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun12` int(11) unsigned NOT NULL DEFAULT 0,
  `Gun13` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo1` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo2` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo3` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo4` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo5` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo6` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo7` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo8` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo9` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo10` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo11` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo12` int(11) unsigned NOT NULL DEFAULT 0,
  `Ammo13` int(11) unsigned NOT NULL DEFAULT 0,
  `beratbagasi` float unsigned NOT NULL DEFAULT 0,
  `togreport` tinyint(3) NOT NULL DEFAULT 0,
  `togask` tinyint(3) NOT NULL DEFAULT 0,
  `togadminchat` tinyint(3) NOT NULL DEFAULT 0,
  `togspeedcam` tinyint(3) NOT NULL DEFAULT 0,
  `kepala` mediumint(8) NOT NULL DEFAULT 0,
  `perut` mediumint(8) NOT NULL DEFAULT 0,
  `tkanan` mediumint(8) NOT NULL DEFAULT 0,
  `tkiri` mediumint(8) NOT NULL DEFAULT 0,
  `kkanan` mediumint(8) NOT NULL DEFAULT 0,
  `kkiri` mediumint(8) NOT NULL DEFAULT 0,
  `asktime` bigint(16) NOT NULL DEFAULT 0,
  `suspect` mediumint(8) NOT NULL DEFAULT 0,
  `getloctimer` bigint(16) NOT NULL DEFAULT 0,
  `phonestatus` mediumint(8) NOT NULL DEFAULT 0,
  `waktuduty` bigint(16) NOT NULL DEFAULT 0,
  `robdelay` bigint(16) NOT NULL DEFAULT 0,
  `boost` mediumint(8) NOT NULL DEFAULT 0,
  `boost_time` bigint(16) NOT NULL DEFAULT 0,
  `accent` mediumint(8) NOT NULL DEFAULT 0,
  `usedrug` mediumint(8) NOT NULL DEFAULT 0,
  `weapskill` mediumint(8) NOT NULL DEFAULT 0,
  `streamer` int(11) NOT NULL DEFAULT 1000,
  PRIMARY KEY (`reg_id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.players: 2 rows
/*!40000 ALTER TABLE `players` DISABLE KEYS */;
INSERT INTO `players` (`reg_id`, `username`, `ucp_name`, `discordid`, `adminname`, `twittername`, `twitterbio`, `ip`, `password`, `salt`, `email`, `admin`, `helper`, `level`, `levelup`, `vip`, `vip_time`, `gold`, `reg_date`, `last_login`, `money`, `bmoney`, `brek`, `phone`, `phonecredit`, `phonebook`, `gpsins`, `twtins`, `aonains`, `wt`, `hours`, `minutes`, `seconds`, `paycheck`, `skin`, `facskin`, `gender`, `age`, `indoor`, `inbiz`, `inhouse`, `posx`, `posy`, `posz`, `posa`, `interior`, `world`, `health`, `armour`, `hunger`, `energy`, `stress`, `sick`, `hospital`, `injured`, `duty`, `dutytime`, `faction`, `factionrank`, `factionlead`, `family`, `familyrank`, `workshop`, `workshoprank`, `jail`, `jail_time`, `rehab`, `rehab_time`, `robbing`, `robbing_time`, `arrest`, `arrest_time`, `warn`, `job`, `job2`, `jobtime`, `sidejobtime`, `exitjob`, `taxitime`, `mask`, `helmet`, `fightingstyle`, `gps`, `food`, `seed`, `potato`, `wheat`, `orange`, `price1`, `price2`, `price3`, `price4`, `plant`, `plant_time`, `fishtool`, `fish`, `worm`, `idcard`, `idcard_time`, `drivelic`, `drivelic_time`, `trucklic`, `trucklic_time`, `lumberlic`, `lumberlic_time`, `weaponlic`, `weaponlic_time`, `spawn_tdtime`, `hbemode`, `togpm`, `toglog`, `togads`, `togwt`, `daging`, `gandum`, `susu`, `susuolah`, `staterpack`, `Gun1`, `Gun2`, `Gun3`, `Gun4`, `Gun5`, `Gun6`, `Gun7`, `Gun8`, `Gun9`, `Gun10`, `Gun11`, `Gun12`, `Gun13`, `Ammo1`, `Ammo2`, `Ammo3`, `Ammo4`, `Ammo5`, `Ammo6`, `Ammo7`, `Ammo8`, `Ammo9`, `Ammo10`, `Ammo11`, `Ammo12`, `Ammo13`, `beratbagasi`, `togreport`, `togask`, `togadminchat`, `togspeedcam`, `kepala`, `perut`, `tkanan`, `tkiri`, `kkanan`, `kkiri`, `asktime`, `suspect`, `getloctimer`, `phonestatus`, `waktuduty`, `robdelay`, `boost`, `boost_time`, `accent`, `usedrug`, `weapskill`, `streamer`) VALUES
	(3, 'Xeno_Tadasi', 'XenoX', '', 'X2', 'None', 'peler', '140.213.227.131', '', '', 'None', 8, 0, 100, 1, 0, 0, 0, '2025-03-09 21:32:43', '2025-03-15 21:40:43', 835, 500, 200798, 3877, 19, 1, 0, 0, 0, 0, 1, 38, 9, 5889, 117, 0, 1, '02/02/2000', -1, -1, -1, 1124.37, -1694.95, 21.5499, 176.914, 0, 0, 100, 0, 95, 95, 0, 0, 0, 0, 0, 0, 3, 6, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1742829478, 0, 0, 0, 0, 0, 0, 0, 0, 1742053243, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2000),
	(1, 'Xeno_Gerad', 'Xeno', '887808633717551195', 'X', 'XenoX', 'Aku dewa lunar', '255.255.255.255', '', '', 'None', 8, 0, 100, 3, 3, 0, 0, '2025-03-08 17:07:30', '2025-03-17 11:57:28', 23410, 500, 827310, 6584, 17, 0, 0, 0, 0, 0, 3, 31, 3, 12663, 18, 268, 1, '12/02/2000', -1, -1, -1, 1983, -2069.55, 14.3352, 185.643, 0, 0, 90, 0, 83, 83, 0, 0, 0, 0, 1, 13167, 6, 6, 0, -1, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1742795709, 0, 0, 0, 0, 0, 0, 0, 0, 1742191048, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 100, 98, 99, 98, 99, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2000);
/*!40000 ALTER TABLE `players` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.privatefarm
CREATE TABLE IF NOT EXISTS `privatefarm` (
  `id` int(11) NOT NULL,
  `owner` varchar(40) NOT NULL DEFAULT '-',
  `price` int(11) NOT NULL DEFAULT 500000,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posa` float DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `seeds` int(11) NOT NULL DEFAULT 0,
  `potato` int(11) NOT NULL DEFAULT 0,
  `orange` int(11) NOT NULL DEFAULT 0,
  `wheat` int(11) NOT NULL DEFAULT 0,
  `visit` bigint(16) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.privatefarm: 0 rows
/*!40000 ALTER TABLE `privatefarm` DISABLE KEYS */;
/*!40000 ALTER TABLE `privatefarm` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.rental
CREATE TABLE IF NOT EXISTS `rental` (
  `id` int(11) NOT NULL,
  `type` int(11) NOT NULL DEFAULT 0,
  `price` int(11) NOT NULL DEFAULT 0,
  `extposx` float DEFAULT 0,
  `extposy` float DEFAULT 0,
  `extposz` float DEFAULT 0,
  `extposa` float DEFAULT 0,
  `vehposx` float DEFAULT 0,
  `vehposy` float DEFAULT 0,
  `vehposz` float DEFAULT 0,
  `vehposa` float DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.rental: ~5 rows (approximately)
INSERT INTO `rental` (`id`, `type`, `price`, `extposx`, `extposy`, `extposz`, `extposa`, `vehposx`, `vehposy`, `vehposz`, `vehposa`) VALUES
	(0, 1, 25, 1675.87, -2311.94, 13.5425, 187.648, 1677.18, -2316.04, 13.3828, 82.2615),
	(1, 2, 350, 2941.3, -2051.65, 3.54804, 274.504, 2960.43, -2052.5, -0.721022, 267.486),
	(2, 1, 25, 2799.9, -2438.59, 13.6927, 267.58, 2794.7, -2433.71, 13.6947, 87.5912),
	(3, 1, 25, 819.161, -1336.2, 13.5469, 0.125114, 818.893, -1330.96, 13.4129, 90.1258),
	(4, 2, 300, 125.052, -1905.09, 2.25502, 84.0819, 110.575, -1905.69, -0.467547, 89.9726);

-- Dumping structure for table s1130_localprime_samp.salary
CREATE TABLE IF NOT EXISTS `salary` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `owner` int(11) DEFAULT 0,
  `info` varchar(46) DEFAULT '',
  `money` int(11) NOT NULL DEFAULT 0,
  `date` varchar(36) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.salary: 1 rows
/*!40000 ALTER TABLE `salary` DISABLE KEYS */;
INSERT INTO `salary` (`id`, `owner`, `info`, `money`, `date`) VALUES
	(1, 1, 'Sweeper (SIDE JOB)', 250, '2025-03-09 15:39:45');
/*!40000 ALTER TABLE `salary` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.server
CREATE TABLE IF NOT EXISTS `server` (
  `id` int(11) NOT NULL DEFAULT 0,
  `servermoney` int(11) DEFAULT 0,
  `material` int(11) NOT NULL DEFAULT 500,
  `materialprice` int(11) NOT NULL DEFAULT 10,
  `lumberprice` int(11) NOT NULL DEFAULT 800,
  `component` int(11) NOT NULL DEFAULT 500,
  `componentprice` int(11) NOT NULL DEFAULT 10,
  `metalprice` int(11) NOT NULL DEFAULT 500,
  `coalprice` int(11) NOT NULL DEFAULT 500,
  `product` int(11) NOT NULL DEFAULT 500,
  `productprice` int(11) NOT NULL DEFAULT 20,
  `apotek` int(11) NOT NULL DEFAULT 500,
  `medicineprice` int(11) NOT NULL DEFAULT 300,
  `medkitprice` int(11) NOT NULL DEFAULT 500,
  `food` int(11) NOT NULL DEFAULT 500,
  `foodprice` int(11) NOT NULL DEFAULT 100,
  `seedprice` int(11) NOT NULL DEFAULT 10,
  `potatoprice` int(11) NOT NULL DEFAULT 10,
  `gandum` int(11) NOT NULL DEFAULT 500,
  `gandumprice` int(11) NOT NULL DEFAULT 100,
  `wheatprice` int(11) NOT NULL DEFAULT 10,
  `orangeprice` int(11) NOT NULL DEFAULT 10,
  `marijuana` int(11) NOT NULL DEFAULT 500,
  `marijuanaprice` int(11) NOT NULL DEFAULT 10,
  `ephedrine` int(11) NOT NULL DEFAULT 50,
  `ephedrineprice` int(11) NOT NULL DEFAULT 50,
  `cocaine` int(11) NOT NULL DEFAULT 50,
  `cocaineprice` int(11) NOT NULL DEFAULT 50,
  `fishprice` int(11) NOT NULL DEFAULT 100,
  `gstationprice` int(11) NOT NULL DEFAULT 100,
  `firstspawnprice` int(11) NOT NULL DEFAULT 10,
  `daging` int(11) NOT NULL DEFAULT 100,
  `dagingprice` int(11) NOT NULL DEFAULT 10,
  `susu` int(11) NOT NULL DEFAULT 100,
  `susuprice` int(11) NOT NULL DEFAULT 10,
  `milkprice` int(11) NOT NULL DEFAULT 7,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.server: 1 rows
/*!40000 ALTER TABLE `server` DISABLE KEYS */;
INSERT INTO `server` (`id`, `servermoney`, `material`, `materialprice`, `lumberprice`, `component`, `componentprice`, `metalprice`, `coalprice`, `product`, `productprice`, `apotek`, `medicineprice`, `medkitprice`, `food`, `foodprice`, `seedprice`, `potatoprice`, `gandum`, `gandumprice`, `wheatprice`, `orangeprice`, `marijuana`, `marijuanaprice`, `ephedrine`, `ephedrineprice`, `cocaine`, `cocaineprice`, `fishprice`, `gstationprice`, `firstspawnprice`, `daging`, `dagingprice`, `susu`, `susuprice`, `milkprice`) VALUES
	(0, 511569478, 900, 45, 300, 16105, 11, 20, 15, 1000, 40, 500, 0, 0, 1001, 5, 10, 10, 0, 5, 30, 10, 100, 500, 61, 0, 2000, 200, 75, 50, 1000, 466, 10, 1419, 300, 7);
/*!40000 ALTER TABLE `server` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.sigenal
CREATE TABLE IF NOT EXISTS `sigenal` (
  `id` int(11) NOT NULL,
  `status` int(11) NOT NULL DEFAULT 0,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posrx` float DEFAULT 0,
  `posry` float DEFAULT 0,
  `posrz` float DEFAULT 0,
  `interior` int(11) NOT NULL,
  `world` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.sigenal: 0 rows
/*!40000 ALTER TABLE `sigenal` DISABLE KEYS */;
/*!40000 ALTER TABLE `sigenal` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.speedcam
CREATE TABLE IF NOT EXISTS `speedcam` (
  `ID` int(11) NOT NULL,
  `camx` float DEFAULT 0,
  `camy` float DEFAULT 0,
  `camz` float DEFAULT 0,
  `camrx` float DEFAULT 0,
  `camry` float DEFAULT 0,
  `camrz` float DEFAULT 0,
  `camworld` int(11) NOT NULL DEFAULT 10,
  `camint` int(11) NOT NULL DEFAULT 10,
  `camspeed` int(11) NOT NULL DEFAULT 10,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.speedcam: 33 rows
/*!40000 ALTER TABLE `speedcam` DISABLE KEYS */;
INSERT INTO `speedcam` (`ID`, `camx`, `camy`, `camz`, `camrx`, `camry`, `camrz`, `camworld`, `camint`, `camspeed`) VALUES
	(6, 1797.34, 1284.84, 5.56311, 0, 0, 0, 0, 0, 100),
	(5, 2323.97, -1742.33, 12.4568, 0, 0, 90.9001, 0, 0, 100),
	(4, 1964.51, -1507.79, 2.13375, 0, 0, -89.8001, 0, 0, 100),
	(3, 1211.95, -2440.33, 8.70676, 0, 0, 66.1, 0, 0, 100),
	(2, 729.302, -1766.63, 13.2964, 0, 0, -105.2, 0, 0, 150),
	(1, 1349.87, -1418.69, 12.3269, 0, 0, 0, 0, 0, 120),
	(0, 1207.19, -1412.12, 12.3854, 0, 0, 90.7, 0, 0, 120),
	(7, 2074.54, 843.098, 5.63312, 0, 0, 92.4, 0, 0, 100),
	(8, 2057.36, 1183.63, 10.0019, 0, 0, 0, 0, 0, 100),
	(9, 1660.67, 295.842, 29.0904, 0, 0, 161.4, 0, 0, 120),
	(10, 1661.01, -977.201, 62.4984, 0, 0, 173.9, 0, 0, 120),
	(11, 1074.39, -943.579, 41.7955, 0, 0, -80.6, 0, 0, 100),
	(12, 760.14, -1389.59, 12.4961, 0, 0, -87.6, 0, 0, 120),
	(13, 1486.45, -1866.57, 12.4369, 0, 0, -90.1, 0, 0, 80),
	(14, 1255.31, -1133.09, 22.5362, 0, 0, -129.3, 0, 0, 120),
	(15, 1841.43, -1377.55, 12.3625, 0, 0, 0, 0, 0, 100),
	(16, -62.9033, 1270.37, 10.0059, 0, 0, -176.4, 0, 0, 80),
	(17, 416.629, 755.006, 4.8711, 0, 0, 63, 0, 0, 120),
	(18, 611.79, 319.073, 18.7742, 0, 0, 0, 0, 0, 80),
	(19, 1777.66, 843.087, 9.51526, 0, 0, -87.6, 0, 0, 100),
	(20, 1846.61, -1758.53, 12.5269, 0, 0, 0, 0, 0, 80),
	(21, -121.567, -1457.01, 1.10196, 0, 0, 123.3, 0, 0, 100),
	(22, 535.702, -149.957, 36.6503, 0, 0, 0, 0, 0, 120),
	(23, 201.953, 1061.86, 19.5564, 0, 0.399999, 97.4, 0, 0, 100),
	(24, -289.51, 822.901, 12.9346, 0, 0, 146.9, 0, 0, 100),
	(25, 2183.92, -1114.91, 23.7261, 0, 0, -111.2, 0, 0, 80),
	(26, -506.965, -1018.03, 23.4486, 0, 0, -120.3, 0, 0, 80),
	(27, -890.888, -1124.07, 98.0509, 0, 0, -7.39999, 0, 0, 80),
	(28, -1227.71, -782.416, 62.9859, 0, 0, 32.6, 0, 0, 80),
	(29, 1023.53, 461.95, 19.0528, 0, 0, 67.1, 0, 0, 100),
	(30, 1602.05, -1606.24, 27.7, 0, 0, -178, 0, 0, 120),
	(31, 2308.12, -2256.04, 12.3169, 0, 0, 134.7, 0, 0, 100),
	(32, 2870.49, -1645.61, 9.87687, 0, 0, 162.3, 0, 0, 100);
/*!40000 ALTER TABLE `speedcam` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.storage
CREATE TABLE IF NOT EXISTS `storage` (
  `ID` int(8) NOT NULL AUTO_INCREMENT,
  `PosX` float NOT NULL DEFAULT 0,
  `PosY` float NOT NULL DEFAULT 0,
  `PosZ` float NOT NULL DEFAULT 0,
  `Type` int(3) NOT NULL DEFAULT 0,
  `World` int(8) NOT NULL DEFAULT 0,
  `Interior` int(5) NOT NULL DEFAULT 0,
  `ExtraID` int(8) NOT NULL DEFAULT -1,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.storage: ~2 rows (approximately)
INSERT INTO `storage` (`ID`, `PosX`, `PosY`, `PosZ`, `Type`, `World`, `Interior`, `ExtraID`) VALUES
	(18, 2077.12, -2033.34, 13.5469, 1, 0, 0, -1),
	(22, 588.718, -1811.96, 6.37406, 2, 0, 0, 5);

-- Dumping structure for table s1130_localprime_samp.tags
CREATE TABLE IF NOT EXISTS `tags` (
  `ID` int(12) NOT NULL,
  `PosX` float NOT NULL DEFAULT 0,
  `PosY` float NOT NULL DEFAULT 0,
  `PosZ` float NOT NULL DEFAULT 0,
  `RotX` float NOT NULL DEFAULT 0,
  `RotY` float NOT NULL DEFAULT 0,
  `RotZ` float NOT NULL DEFAULT 0,
  `Font` varchar(24) NOT NULL DEFAULT 'Arial',
  `Text` varchar(64) NOT NULL DEFAULT 'None',
  `Size` int(3) NOT NULL DEFAULT 24,
  `Interior` int(4) NOT NULL DEFAULT -1,
  `World` int(4) NOT NULL DEFAULT -1,
  `Bold` int(2) NOT NULL DEFAULT 0,
  `Owner` int(6) NOT NULL DEFAULT -1,
  `Color` int(5) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table s1130_localprime_samp.tags: ~0 rows (approximately)
INSERT INTO `tags` (`ID`, `PosX`, `PosY`, `PosZ`, `RotX`, `RotY`, `RotZ`, `Font`, `Text`, `Size`, `Interior`, `World`, `Bold`, `Owner`, `Color`) VALUES
	(0, -355.81, -1412.48, 25.0816, 0, 0, 11.7938, 'Arial', 'jaer', 50, 0, 0, 0, 6, -1);

-- Dumping structure for table s1130_localprime_samp.toys
CREATE TABLE IF NOT EXISTS `toys` (
  `Id` int(10) NOT NULL AUTO_INCREMENT,
  `Owner` varchar(40) NOT NULL DEFAULT '',
  `Slot0_Model` int(8) NOT NULL DEFAULT 0,
  `Slot0_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot0_Hide` int(8) NOT NULL DEFAULT 0,
  `Slot0_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_Model` int(8) NOT NULL DEFAULT 0,
  `Slot1_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot1_Hide` int(8) NOT NULL DEFAULT 0,
  `Slot1_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_Model` int(8) NOT NULL DEFAULT 0,
  `Slot2_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot2_Hide` int(8) NOT NULL DEFAULT 0,
  `Slot2_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_Model` int(8) NOT NULL DEFAULT 0,
  `Slot3_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot3_Hide` int(8) NOT NULL DEFAULT 0,
  `Slot3_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_Model` int(8) NOT NULL DEFAULT 0,
  `Slot4_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot4_Hide` int(8) NOT NULL DEFAULT 0,
  `Slot4_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_Model` int(8) NOT NULL DEFAULT 0,
  `Slot5_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot5_Hide` int(8) NOT NULL DEFAULT 0,
  `Slot5_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `id` (`Owner`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.toys: 2 rows
/*!40000 ALTER TABLE `toys` DISABLE KEYS */;
INSERT INTO `toys` (`Id`, `Owner`, `Slot0_Model`, `Slot0_Bone`, `Slot0_Hide`, `Slot0_XPos`, `Slot0_YPos`, `Slot0_ZPos`, `Slot0_XRot`, `Slot0_YRot`, `Slot0_ZRot`, `Slot0_XScale`, `Slot0_YScale`, `Slot0_ZScale`, `Slot1_Model`, `Slot1_Bone`, `Slot1_Hide`, `Slot1_XPos`, `Slot1_YPos`, `Slot1_ZPos`, `Slot1_XRot`, `Slot1_YRot`, `Slot1_ZRot`, `Slot1_XScale`, `Slot1_YScale`, `Slot1_ZScale`, `Slot2_Model`, `Slot2_Bone`, `Slot2_Hide`, `Slot2_XPos`, `Slot2_YPos`, `Slot2_ZPos`, `Slot2_XRot`, `Slot2_YRot`, `Slot2_ZRot`, `Slot2_XScale`, `Slot2_YScale`, `Slot2_ZScale`, `Slot3_Model`, `Slot3_Bone`, `Slot3_Hide`, `Slot3_XPos`, `Slot3_YPos`, `Slot3_ZPos`, `Slot3_XRot`, `Slot3_YRot`, `Slot3_ZRot`, `Slot3_XScale`, `Slot3_YScale`, `Slot3_ZScale`, `Slot4_Model`, `Slot4_Bone`, `Slot4_Hide`, `Slot4_XPos`, `Slot4_YPos`, `Slot4_ZPos`, `Slot4_XRot`, `Slot4_YRot`, `Slot4_ZRot`, `Slot4_XScale`, `Slot4_YScale`, `Slot4_ZScale`, `Slot5_Model`, `Slot5_Bone`, `Slot5_Hide`, `Slot5_XPos`, `Slot5_YPos`, `Slot5_ZPos`, `Slot5_XRot`, `Slot5_YRot`, `Slot5_ZRot`, `Slot5_XScale`, `Slot5_YScale`, `Slot5_ZScale`) VALUES
	(1, 'Xeno_Tadasi', 19625, 2, 0, 0.005, 0.105, -0.001, -130.000, 1.200, 7.800, 1.000, 1.000, 1.000, 0, 1, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 1, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 1, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000),
	(2, 'Xeno_Gerad', 19064, 2, 0, 0.113, 0.022, 0.000, 96.600, 127.600, 3.300, 1.000, 1.000, 1.000, 19625, 2, 0, -0.021, 0.113, 0.005, -174.500, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 1, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 1, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000);
/*!40000 ALTER TABLE `toys` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.toysveh
CREATE TABLE IF NOT EXISTS `toysveh` (
  `Id` int(10) NOT NULL AUTO_INCREMENT,
  `Owner` varchar(40) NOT NULL DEFAULT '',
  `Slot0_Model` int(8) NOT NULL DEFAULT 0,
  `Slot0_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_Model` int(8) NOT NULL DEFAULT 0,
  `Slot1_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_Model` int(8) NOT NULL DEFAULT 0,
  `Slot2_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_Model` int(8) NOT NULL DEFAULT 0,
  `Slot3_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_Model` int(8) NOT NULL DEFAULT 0,
  `Slot4_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_Model` int(8) NOT NULL DEFAULT 0,
  `Slot5_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `id` (`Owner`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.toysveh: 2 rows
/*!40000 ALTER TABLE `toysveh` DISABLE KEYS */;
INSERT INTO `toysveh` (`Id`, `Owner`, `Slot0_Model`, `Slot0_XPos`, `Slot0_YPos`, `Slot0_ZPos`, `Slot0_XRot`, `Slot0_YRot`, `Slot0_ZRot`, `Slot1_Model`, `Slot1_XPos`, `Slot1_YPos`, `Slot1_ZPos`, `Slot1_XRot`, `Slot1_YRot`, `Slot1_ZRot`, `Slot2_Model`, `Slot2_XPos`, `Slot2_YPos`, `Slot2_ZPos`, `Slot2_XRot`, `Slot2_YRot`, `Slot2_ZRot`, `Slot3_Model`, `Slot3_XPos`, `Slot3_YPos`, `Slot3_ZPos`, `Slot3_XRot`, `Slot3_YRot`, `Slot3_ZRot`, `Slot4_Model`, `Slot4_XPos`, `Slot4_YPos`, `Slot4_ZPos`, `Slot4_XRot`, `Slot4_YRot`, `Slot4_ZRot`, `Slot5_Model`, `Slot5_XPos`, `Slot5_YPos`, `Slot5_ZPos`, `Slot5_XRot`, `Slot5_YRot`, `Slot5_ZRot`) VALUES
	(1, '2', 1001, 0.000, -2.500, 0.100, 0.000, 0.000, 0.000, 19314, 0.000, 0.300, 0.800, 45.000, -90.000, 0.000, 19419, 0.000, -0.100, 0.800, 0.000, 0.000, 0.000, 1001, 0.000, -2.500, 0.300, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000),
	(2, '1', 18646, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000);
/*!40000 ALTER TABLE `toysveh` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.trashmaster
CREATE TABLE IF NOT EXISTS `trashmaster` (
  `id` int(11) NOT NULL,
  `stock` int(11) NOT NULL DEFAULT 0,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posrx` float DEFAULT 0,
  `posry` float DEFAULT 0,
  `posrz` float DEFAULT 0,
  `interior` int(11) NOT NULL,
  `world` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.trashmaster: 33 rows
/*!40000 ALTER TABLE `trashmaster` DISABLE KEYS */;
INSERT INTO `trashmaster` (`id`, `stock`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `interior`, `world`) VALUES
	(0, 1, 1363.37, -1751.39, 13.2429, 0, 0, -90.7, 0, 0),
	(1, 1, 1710.54, -1802.91, 13.2569, 0, 0, -0.399998, 0, 0),
	(2, 1, 1830.22, -1824.57, 13.2981, 0, 0, -89.7, 0, 0),
	(3, 1, 2127.98, -1765.53, 13.2085, 0, 0, -91.7, 0, 0),
	(4, 1, 2280.46, -1722.16, 13.2469, 0, 0, 0.499998, 0, 0),
	(5, 1, 2204.41, -1968.98, 13.2769, 0, 0, 89.1, 0, 0),
	(6, 1, 1984.45, -1923.05, 13.2269, 0, 0, 0, 0, 0),
	(7, 1, 1812.33, -1920.79, 13.2531, 0, 0, 90, 0, 0),
	(8, 1, 1737.65, -1850.59, 13.1241, 0, 0, 0, 0, 0),
	(9, 1, 1554.44, -1704.49, 13.2869, 0, 0, 0, 0, 0),
	(10, 1, 1538.95, -1615.31, 13.2669, 0, 0, -91.3, 0, 0),
	(12, 1, 1975.05, -1893.48, 13.2569, 0, 0, 0, 0, 0),
	(13, 1, 1966.11, -1743.1, 13.2969, 0, 0, 0, 0, 0),
	(14, 1, 2138.71, -1487.23, 23.7244, 0, 0, -89.9, 0, 0),
	(15, 1, 2128.48, -1374.96, 23.6982, 0, 0, 0, 0, 0),
	(16, 1, 2713.41, -1125.39, 69.2681, 0, 0, 90.7, 0, 0),
	(17, 1, 2237.56, -1017.94, 58.434, 0, 7.3, -36.8, 0, 0),
	(18, 1, 2184.34, -1150.1, 24.1884, 0, 0, -89.7, 0, 0),
	(19, 1, 2440.4, -1559.67, 23.64, 0, 0, -90.3, 0, 0),
	(20, 1, 2541.46, -1483.74, 23.7187, 0, 0, 89.7, 0, 0),
	(21, 1, 2858.75, -1513.54, 10.7453, 0, 0, 78.5, 0, 0),
	(22, 1, 1678.32, -1881.65, 13.2659, 0, 0, -178.4, 0, 0),
	(23, 1, 1330.89, -1844.04, 13.2469, 0, 0, -6.3, 0, 0),
	(25, 1, 647.043, -1340.64, 13.1944, 0, 0, -90.3, 0, 0),
	(26, 1, 868.095, -1339.25, 13.1869, 0, 0, 89.8, 0, 0),
	(27, 1, 1525.79, -1450.22, 13.2169, 0, 0, -179.8, 0, 0),
	(28, 1, 2081.2, -1254.91, 23.6831, 0, 0, 90.6, 0, 0),
	(29, 1, 1541.7, -1151.93, 23.8181, 0, 0, 0, 0, 0),
	(30, 1, 1046.72, -1165.99, 23.538, 0, 0, 89.8, 0, 0),
	(31, 1, 1861.14, -1361.52, 13.2895, 0, 0, -89.9, 0, 0),
	(32, 1, 1428.14, -1022.31, 23.5581, 0, 0, 0, 0, 0),
	(33, 1, 1206.92, -1198.18, 20.0834, 0, 4.9, -89.6999, 0, 0),
	(34, 1, 832.516, -1336.64, 13.3069, 0, 0, 0, 0, 0);
/*!40000 ALTER TABLE `trashmaster` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.trees
CREATE TABLE IF NOT EXISTS `trees` (
  `id` int(11) NOT NULL,
  `posx` float DEFAULT NULL,
  `posy` float DEFAULT NULL,
  `posz` float DEFAULT NULL,
  `posrx` float DEFAULT NULL,
  `posry` float DEFAULT NULL,
  `posrz` float DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.trees: 51 rows
/*!40000 ALTER TABLE `trees` DISABLE KEYS */;
INSERT INTO `trees` (`id`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`) VALUES
	(16, -728.368, -2688.79, 87.7584, 0, 0, 0),
	(17, -755.911, -2645.77, 82.1198, 0, 0, 0),
	(18, -803.047, -2670.73, 87.8427, 0, 0, 0),
	(19, -804.388, -2674.93, 88.6293, 0, 0, 0),
	(20, -802.081, -2668.56, 87.156, 0, 0, 0),
	(21, -811.424, -2674.16, 90.4224, 0, 0, 0),
	(22, -809.648, -2667.9, 89.3789, 0, 0, 0),
	(23, -816.313, -2667.16, 90.6121, 0, 0, 0),
	(24, -857.24, -2569.42, 90.928, 0, 0, 0),
	(25, -814.815, -2330.2, 38.2684, 0, 0, 0),
	(26, -862.42, -2284.11, 25.1743, 0, 0, 0),
	(27, -729.853, -2264.4, 28.0405, 0, 0, 0),
	(28, -732.258, -2303.1, 35.4701, 0, 0, 0),
	(29, -781.662, -2206.1, 19.0109, 0, 0, 0),
	(30, -693.839, -2056.79, 21.7696, 0, 0, 0),
	(31, -714.997, -2110.65, 24.7368, 0, 0, 0),
	(32, -783.42, -2073.36, 16.2298, 0, 0, 0),
	(33, -775.931, -2106.01, 23.5836, 0, 0, 0),
	(34, -879.146, -2595.55, 92.6483, 0, 0, 0),
	(35, -638.262, -2100.03, 28.3524, 0, 0, 0),
	(36, -663.67, -2147.02, 23.9997, 0, 0, 0),
	(37, -878.877, -2605.61, 93.9239, 0, 0, 0),
	(38, -700.348, -2403.07, 55.6708, 0, 0, 0),
	(39, -864.153, -2602.65, 93.292, 0, 0, 0),
	(40, -853.141, -2598.64, 92.0366, 0, 0, 0),
	(41, -556.126, -2639.3, 149.022, 0, 0, 0),
	(42, -691.089, -2740.47, 96.2746, 0, 0, 0),
	(43, -797.985, -2532.12, 88.5981, 0, 0, 0),
	(44, -873.286, -2235.05, 26.797, 0, 0, 0),
	(45, -773.779, -1890.77, 6.36226, 0, 0, 0),
	(46, -808.778, -1928.06, 5.68809, 0, 0, 0),
	(47, -685.347, -1953.85, 18.262, 0, 0, 0),
	(48, -558.404, -2014.99, 49.0187, 0, 0, 0),
	(49, -549.86, -2050.9, 55.5491, 0, 0, 0),
	(50, -701.968, -2236.68, 19.7047, 0, 0, 0),
	(0, -721.124, -2458.28, 66.3121, 0, 0, 0),
	(1, -715.451, -2455.67, 66.2546, 0, 0, 0),
	(2, -709.535, -2454.53, 65.6647, 0, 0, 0),
	(3, -704.13, -2451.45, 65.3009, 0, 0, 0),
	(4, -718.012, -2467.66, 68.4166, 0, 0, 0),
	(5, -713.14, -2465.66, 68.5334, 0, 0, 0),
	(6, -700.174, -2460.89, 67.8149, 0, 0, 0),
	(7, -707.08, -2461.66, 68.3959, 0, 0, 0),
	(8, -693.467, -2458.13, 67.3936, 0, 0, 0),
	(9, -714.48, -2474.16, 68.6063, 0, 0, 0),
	(10, -707.91, -2478.52, 68.8341, 0, 0, 0),
	(11, -701.36, -2474.84, 68.4912, 0, 0, 0),
	(12, -700.166, -2467.98, 68.1166, 0, 0, 0),
	(13, -823.062, -2671.84, 93.1915, 0, 0, 0),
	(14, -789.213, -2668.98, 85.4511, 0, 0, 0),
	(15, -789.174, -2675.8, 85.2851, 0, 0, 0);
/*!40000 ALTER TABLE `trees` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.ucp
CREATE TABLE IF NOT EXISTS `ucp` (
  `reg_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `ucp_name` varchar(24) NOT NULL DEFAULT '',
  `ip` varchar(24) NOT NULL DEFAULT '',
  `password` varchar(255) NOT NULL DEFAULT '',
  `register` int(11) NOT NULL DEFAULT 0,
  `status` int(11) NOT NULL DEFAULT 0,
  `phone` varchar(30) NOT NULL DEFAULT '',
  `pin_code` int(11) NOT NULL DEFAULT 0,
  `discordid` varchar(30) NOT NULL DEFAULT '',
  `email` varchar(30) NOT NULL DEFAULT '',
  `reg_date` varchar(30) NOT NULL DEFAULT '',
  `last_login` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`reg_id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.ucp: 2 rows
/*!40000 ALTER TABLE `ucp` DISABLE KEYS */;
INSERT INTO `ucp` (`reg_id`, `ucp_name`, `ip`, `password`, `register`, `status`, `phone`, `pin_code`, `discordid`, `email`, `reg_date`, `last_login`) VALUES
	(1, 'Xeno', '', '$2a$12$zSdQTBj/IJE9.TBdoScNCe6ghf5z7LmiRhUBUx/9D232Cucz4nmmC', 1, 0, '', 0, '887808633717551195', 'xenoaja50@gmail.com', '', ''),
	(2, 'XenoX', '', '$2a$12$zSdQTBj/IJE9.TBdoScNCe6ghf5z7LmiRhUBUx/9D232Cucz4nmmC', 1, 0, '', 0, '', '', '', '');
/*!40000 ALTER TABLE `ucp` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.vehicle
CREATE TABLE IF NOT EXISTS `vehicle` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `owner` int(11) NOT NULL,
  `model` int(11) NOT NULL DEFAULT 0,
  `name` varchar(40) NOT NULL DEFAULT 'None',
  `color1` int(11) NOT NULL DEFAULT 0,
  `color2` int(11) NOT NULL DEFAULT 0,
  `paintjob` int(11) NOT NULL DEFAULT -1,
  `neon` int(11) NOT NULL DEFAULT 0,
  `locked` int(11) NOT NULL DEFAULT 0,
  `insu` int(11) NOT NULL DEFAULT 1,
  `claim` int(11) NOT NULL DEFAULT 0,
  `claim_time` bigint(15) NOT NULL DEFAULT 0,
  `plate` varchar(50) NOT NULL DEFAULT 'None',
  `plate_time` bigint(16) NOT NULL DEFAULT 0,
  `ticket` int(11) unsigned NOT NULL DEFAULT 0,
  `parkid` int(11) NOT NULL DEFAULT -1,
  `price` int(11) NOT NULL DEFAULT 200000,
  `health` float NOT NULL DEFAULT 1000,
  `fuel` int(11) NOT NULL DEFAULT 100,
  `x` float NOT NULL DEFAULT 0,
  `y` float NOT NULL DEFAULT 0,
  `z` float NOT NULL DEFAULT 0,
  `a` float NOT NULL DEFAULT 0,
  `int` int(11) NOT NULL DEFAULT 0,
  `vw` int(11) NOT NULL DEFAULT 0,
  `damage0` int(11) NOT NULL DEFAULT 0,
  `damage1` int(11) NOT NULL DEFAULT 0,
  `damage2` int(11) NOT NULL DEFAULT 0,
  `damage3` int(11) NOT NULL DEFAULT 0,
  `mod0` int(11) NOT NULL DEFAULT 0,
  `mod1` int(11) NOT NULL DEFAULT 0,
  `mod2` int(11) NOT NULL DEFAULT 0,
  `mod3` int(11) NOT NULL DEFAULT 0,
  `mod4` int(11) NOT NULL DEFAULT 0,
  `mod5` int(11) NOT NULL DEFAULT 0,
  `mod6` int(11) NOT NULL DEFAULT 0,
  `mod7` int(11) NOT NULL DEFAULT 0,
  `mod8` int(11) NOT NULL DEFAULT 0,
  `mod9` int(11) NOT NULL DEFAULT 0,
  `mod10` int(11) NOT NULL DEFAULT 0,
  `mod11` int(11) NOT NULL DEFAULT 0,
  `mod12` int(11) NOT NULL DEFAULT 0,
  `mod13` int(11) NOT NULL DEFAULT 0,
  `mod14` int(11) NOT NULL DEFAULT 0,
  `mod15` int(11) NOT NULL DEFAULT 0,
  `mod16` int(11) NOT NULL DEFAULT 0,
  `lumber` int(11) NOT NULL DEFAULT -1,
  `product` int(11) NOT NULL DEFAULT 0,
  `Weapon1` int(11) NOT NULL DEFAULT 0,
  `Ammo1` int(11) NOT NULL DEFAULT 0,
  `Weapon2` int(11) NOT NULL DEFAULT 0,
  `Ammo2` int(11) NOT NULL DEFAULT 0,
  `Weapon3` int(11) NOT NULL DEFAULT 0,
  `Ammo3` int(11) NOT NULL DEFAULT 0,
  `Weapon4` int(11) NOT NULL DEFAULT 0,
  `Ammo4` int(11) NOT NULL DEFAULT 0,
  `Weapon5` int(11) NOT NULL DEFAULT 0,
  `Ammo5` int(11) NOT NULL DEFAULT 0,
  `component` int(11) NOT NULL DEFAULT 0,
  `material` int(11) NOT NULL DEFAULT 0,
  `tembaga` int(11) NOT NULL DEFAULT 0,
  `besi` int(11) NOT NULL DEFAULT 0,
  `emas` int(11) NOT NULL DEFAULT 0,
  `berlian` int(11) NOT NULL DEFAULT 0,
  `seed` int(11) NOT NULL DEFAULT 0,
  `marijuana` int(11) NOT NULL DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `gasoil` int(11) NOT NULL DEFAULT 0,
  `rental` bigint(16) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.vehicle: 4 rows
/*!40000 ALTER TABLE `vehicle` DISABLE KEYS */;
INSERT INTO `vehicle` (`id`, `owner`, `model`, `name`, `color1`, `color2`, `paintjob`, `neon`, `locked`, `insu`, `claim`, `claim_time`, `plate`, `plate_time`, `ticket`, `parkid`, `price`, `health`, `fuel`, `x`, `y`, `z`, `a`, `int`, `vw`, `damage0`, `damage1`, `damage2`, `damage3`, `mod0`, `mod1`, `mod2`, `mod3`, `mod4`, `mod5`, `mod6`, `mod7`, `mod8`, `mod9`, `mod10`, `mod11`, `mod12`, `mod13`, `mod14`, `mod15`, `mod16`, `lumber`, `product`, `Weapon1`, `Ammo1`, `Weapon2`, `Ammo2`, `Weapon3`, `Ammo3`, `Weapon4`, `Ammo4`, `Weapon5`, `Ammo5`, `component`, `material`, `tembaga`, `besi`, `emas`, `berlian`, `seed`, `marijuana`, `money`, `gasoil`, `rental`) VALUES
	(1, 1, 522, 'NRG-500', 1, 1, -1, 0, 0, 3, 1, 1741862795, 'None', 0, 0, -1, 10000, 1410.95, 89, 639.61, -1363.78, 15.8081, 325.311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
	(2, 1, 422, 'Bobcat', 0, 0, -1, 18652, 0, 3, 0, 0, 'None', 0, 0, -1, 5000, 789.601, 94, 1685.63, -1472.86, 26.1145, 252.664, 0, 0, 36896818, 33751812, 5, 0, 0, 1010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
	(3, 1, 560, 'Sultan', 0, 0, 0, 18652, 0, 1, 1, 1741742543, 'None', 0, 0, -1, 60000, 799.129, 83, 196.982, -286.946, 3.50482, 89.6848, 0, 0, 3211312, 2, 4, 0, 1138, 1010, 1169, 1141, 1028, 0, 0, 0, 1032, 1026, 1027, 0, 1086, 0, 0, 1080, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
	(4, 3, 522, 'NRG-500', 1, 1, -1, 0, 0, 3, 0, 0, 'None', 0, 0, -1, 10000, 1929.6, 70, 2029.2, -1419.46, 17.1741, 30.2417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
/*!40000 ALTER TABLE `vehicle` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.vendingmachine
CREATE TABLE IF NOT EXISTS `vendingmachine` (
  `ID` int(11) NOT NULL,
  `owner` varchar(50) NOT NULL DEFAULT 'None',
  `price` int(11) NOT NULL DEFAULT 500000,
  `posx` float DEFAULT 0,
  `posy` float DEFAULT 0,
  `posz` float DEFAULT 0,
  `posrx` float DEFAULT 0,
  `posry` float DEFAULT 0,
  `posrz` float DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `drinkprice` int(11) NOT NULL DEFAULT 500,
  `product` int(11) NOT NULL DEFAULT 0,
  `visit` bigint(16) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.vendingmachine: 0 rows
/*!40000 ALTER TABLE `vendingmachine` DISABLE KEYS */;
/*!40000 ALTER TABLE `vendingmachine` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.vouchers
CREATE TABLE IF NOT EXISTS `vouchers` (
  `id` int(11) NOT NULL,
  `code` int(11) NOT NULL DEFAULT 0,
  `vip` int(11) NOT NULL DEFAULT 0,
  `vip_time` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  `admin` varchar(16) NOT NULL DEFAULT 'None',
  `donature` varchar(16) NOT NULL DEFAULT 'None',
  `claim` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.vouchers: 0 rows
/*!40000 ALTER TABLE `vouchers` DISABLE KEYS */;
/*!40000 ALTER TABLE `vouchers` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.weaponsettings
CREATE TABLE IF NOT EXISTS `weaponsettings` (
  `Owner` int(11) NOT NULL,
  `WeaponID` tinyint(4) NOT NULL,
  `PosX` float DEFAULT -0.116,
  `PosY` float DEFAULT 0.189,
  `PosZ` float DEFAULT 0.088,
  `RotX` float DEFAULT 0,
  `RotY` float DEFAULT 44.5,
  `RotZ` float DEFAULT 0,
  `Bone` tinyint(4) NOT NULL DEFAULT 1,
  `Hidden` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`Owner`,`WeaponID`),
  UNIQUE KEY `Owner` (`Owner`,`WeaponID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.weaponsettings: 2 rows
/*!40000 ALTER TABLE `weaponsettings` DISABLE KEYS */;
INSERT INTO `weaponsettings` (`Owner`, `WeaponID`, `PosX`, `PosY`, `PosZ`, `RotX`, `RotY`, `RotZ`, `Bone`, `Hidden`) VALUES
	(1, 24, -0.14, 0.178, -0.215, 100.4, 175.6, -4.6, 1, 0),
	(1, 25, -0.182, 0.186, 0.248, 16.8, -166, -14.2, 1, 0);
/*!40000 ALTER TABLE `weaponsettings` ENABLE KEYS */;

-- Dumping structure for table s1130_localprime_samp.workshop
CREATE TABLE IF NOT EXISTS `workshop` (
  `ID` int(11) NOT NULL,
  `name` varchar(50) NOT NULL DEFAULT 'None',
  `leader` varchar(50) NOT NULL DEFAULT 'None',
  `price` int(11) NOT NULL DEFAULT 500000,
  `status` int(11) NOT NULL DEFAULT 1,
  `extposx` float DEFAULT 0,
  `extposy` float DEFAULT 0,
  `extposz` float DEFAULT 0,
  `extposa` float DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `component` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- Dumping data for table s1130_localprime_samp.workshop: 1 rows
/*!40000 ALTER TABLE `workshop` DISABLE KEYS */;
INSERT INTO `workshop` (`ID`, `name`, `leader`, `price`, `status`, `extposx`, `extposy`, `extposz`, `extposa`, `money`, `component`) VALUES
	(0, 'Ws X tune', 'Xeno_Gerad', 1, 0, -82.4364, -1545.58, 2.94369, 65.1446, 0, 0);
/*!40000 ALTER TABLE `workshop` ENABLE KEYS */;

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
