 /**
  * Snowman header
  * CPP course, Ariel University
  * For more documentation visit: 
  * https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */
 
#include <iostream>
#include <string>
using namespace std;

namespace ariel{
	std::string snowman(int num);
	const int CorrectNumbers[] ={
		11111111,11111112,11111113,11111114,11111121,11111122,11111123,11111124,11111131,11111132,
		11111133,11111134,11111141,11111142,11111143,11111144,11111211,11111212,11111213,21223422,
		21223423,21223424,21223431,21223432,21223433,21223434,21223441,21223442,21223443,21223444,
		21224111,21224112,21224113,21224114,21224121,21224122,21224123,21224124,21224131,21224132,
		21224133,21224134,21224141,21224142,21224143,21224144,21224211,21224212,21224213,21224214,
		21224221,21224222,21224223,21224224,21224231,21224232,21224233,21224234,21224241,21224242,
		21224243,21224244,21224311,21224312,21224313,21224314,21224321,21224322,21224323,21224324,
		21224331,21224332,21224333,21224334,21224341,32133111,32133112,32133113,32133114,32133121,
		32133122,32133123,32133124,32133131,32133132,32133133,32133134,32133141,32133142,32133143,
		32133144,32133211,32133212,32133213,32133214,32133221,42244222,42244223,42244224,42244231,
		42244232,42244233,42244234,42244241,42244242,42244243,42244244,42244311,42244312,42244313,
		42244314,42244321,42244322,42244323,42244324,42244331,42244332,42244333,42244334};
    
	const int IncorrectNumbers[] ={
		23713926,23713927,23713928,23713929,23713930,23713931,23713932,23713933,23713934,23713935,23713936,
		23713937,23713938,23713939,23713940,23713941,23713942,23713943,23713944,23713945,23713946,23713947,
		23713952,23713953,23713954,23713955,23713956,23713957,23713958,23713959,23713960,23713961,23713962,
		23713967,23713968,23713969,23713970,23713971,23713972,23713973,23713974,23713975,23713976,23713977,
		23713982,23713983,23713984,23713985,23713986,23713987,23713988,23713989,23713990,23713991,23713992,
		23713997,23713998,23713999,23714000,23714001,23714002,23714003,23714004,23714005,23714006,23714007,
		23714012,23714013,23714014,23714015,23714016,23714017,11192352,11192353,11192354,11192355,11192356,
		11192361,11192362,11192363,11192364,11192365,11192366,11192367,11192368,11192369,11192370,11192371,
		11192376,11192377,11192378,11192379,11192380,11192381,11192382,11192383,11192384,11192385,11192386,
		11192391,11192392,11192393,11192394,11192395,11192396,11192397,11192398,11192399,11192400,11192401,
		11192406,11192407,11192408,11192409,11192410,11192411,11192412,11192413,11192414,11192415,11192416,
		11192421,11192422,11192423,11192424,11192425,11192426,11192427,11192428,11192429,11192430,11192431,
		11192436,11192437,11192438,11192439,11192440,11192441,11192442,11192443,11192444,11192445,11192446,
		11192451,11192452,11192453,11192454,11192455,11192456,11192457,11192458,11192459,11192460};

	const int NegativeNumbers[] ={
		-11112314,-11112313,-11112312,-11112311,-11112244,-11112243,-11112242,-11112241,-11112234,-11112233,-11112232,-11112231,
		-11112224,-11112223,-11112222,-11112221,-11112214,-11112213,-11112212,-11112211,-11112144,-11112143,-11112142,-11112141,
		-11112134,-11112133,-11112132,-11112131,-11112124,-11112123,-11112122,-11112121,-11112114,-11112113,-11112112,-11112111,
		-11111444,-11111443,-11111442,-11111441,-11111434,-11111433,-11111432,-11111431,-11111424,-11111423,-11111422,-11111421,
		-11111414,-11111413,-11111412,-11111411,-11111344,-11111343,-11111342,-11111341,-11111334,-11111333,-11111332,-11111331,
		-11111324,-11111323,-11111322,-11111321,-11111314,-11111313,-11111312,-11111311,-11111244,-11111243,-11111242,-11111241,
		-11111234,-11111233,-11111232,-11111231,-11111224,-11111223,-11111222,-11111221,-11111214,-11111213,-11111212,-11111211,
		-24314333,-24314332,-24314331,-24314324,-24314323,-24314322,-24314321,-24314314,-24314313,-24314312,-24314311,-24314244,
		-24314243,-24314242,-24314241,-24314234,-24314233,-24314232,-24314231,-24314224,-24314223,-24314222,-24314221,-24314214,
		-24314213,-24314212,-24314211,-24314144,-24314143,-24314142,-24314141,-24314134,-24314133,-24314132,-24314131,-24314124,
		-24314123,-24314122,-24314121,-24314114,-24314113,-24314112,-24314111,-24313444,-24313443,-24313442,-24313441,-24313434,
		-24313433,-24313432,-24313431,-24313424,-24313423,-24313422,-24313421,-24313414,-24313413,-24313412,-24313411,-24313344,
		-24313343,-24313342,-24313341,-24313334,-24313333,-24313332,-44444444,-44444443,-44444442,-44444441,-44444434,-44444433,
		-44444432,-44444431,-44444424,-44444423,-44444422,-44444421,-44444414,-44444413,-44444412,-44444411,-44444344,-44444343,
		-44444342,-44444341,-44444334,-44444333,-44444332,-44444331,-44444324,-44444323,-44444322,-44444321,-44444314,-44444313,
		-44444312,-44444311,-44444244,-44444243,-44444242,-44444241,-44444234,-44444233,-44444232,-44444231,-44444224,-44444223,
		-44444222,-44444221,-44444214,-44444213,-44444212,-44444211,-44444144,-44444143,-44444142,-44444141};

	const int smallerThan8Characters[] ={
		1,8,15,22,29,36,43,50,57,64,71,78,85,92,99,106,113,120,127,134,141,148,155,162,169,176,183,190,197,204,211,218,225,232,
		239,246,253,260,267,274,281,288,295,302,309,316,323,330,337,344,351,358,365,372,379,386,393,400,407,414,421,428,435,442,
		449,456,463,470,477,484,491,498,505,512,519,526,533,540,547,554,561,568,575,582,589,596,603,610,617,624,631,638,645,652,
		659,666,673,680,687,694,701,708,715,722,729,736,743,750,757,764,771,778,785,792,799,806,813,820,827,834,841,848,855,862,
		869,876,883,890,897,904,911,918,925,932,939,946,953,960,967,974,981,988,995,1002,1009,1016,1023,1030,1037,1044,1051,1058,
		1065,1072,1079,1086,1093,1100,1107,1114,1121,1128,1135,1142,1149,1156,1163,1170,1177,1184,1191,1198,1205,1212,1219,1226,
		1233,1240,1247,1254,1261,1268,1275,1282,1289,1296,1303,1310,1317,1324,1331,1338,1345,1352,1359,1366,1373,1380,1387,1394,
		1401,1408,1415,1422,1429,1436,1443,1450,1457,1464,1471,1478,1485,1492,1499,1506,1513,1520,1527,1534,1541,1548,1555,1562,
		1569,1576,1583,1590,1597,1604,1611,1618,1625,1632,1639,1646,1653,1660,1667,1674,1681,1688,1695,1702,1709,1716,1723,1730,
		1737,9998934,9998941,9998948,9998955,9998962,9998969,9998976,9998983,9998990,9998997,9999004,9999011, 9999018,9999025,
		9999032,9999039,9999046,9999053,9999060,9999067,9999074,9999081,9999088,9999095,9999102,9999109,9999116,9999123,9999130,
		9999137,9999144,9999151,9999158,9999165,9999172,9999179,9999186,9999193,9999200,9999207,9999214,9999221,9999228,9999235,
		9999242,9999249,9999256,9999263,9999270,9999277,9999284,9999291,9999298,9999305,9999312,9999319,9999326,9999333,9999340,
		9999347,9999354,9999361,9999368,9999375,9999382,9999389,9999396,9999403,9999410,9999417,9999424,9999431,9999438,9999445,
		9999452,9999459,9999466,9999473,9999480,9999487,9999494,9999501,9999508,9999515,9999522,9999529,9999536,9999543,9999550,
		9999557,9999564,9999571,9999578,9999585,9999592,9999599,9999606,9999613,9999620,9999627,9999634,9999641,9999648,9999655,
		9999662,9999669,9999676,9999683,9999690,9999697,9999704,9999711,9999718,9999725,9999732,9999739,9999746,9999753,9999760,
		9999767,9999774,9999781,9999788,9999795,9999802,9999809,9999816,9999823,9999830,9999837,9999844,9999851,9999858,9999865,
		9999872,9999879,9999886,9999893,9999900,9999907,9999914,9999921,9999928};

	const int biggerThan8Characters[] ={
		114059811,114059818,114059825,114059832,114059839,114059846,114059853,114059860,114059867,114059874,114059881,114059888,
		114059895,114059902,114059909,114059916,114059923,114059930,114059937,114059944,114059951,114059958,114059965,114059972,
		114059979,114059986,114059993,114060000,114060007,114060014,114060021,114060028,114060035,114060042,114060049,114060056,
		114060063,114060070,114060077,114060084,114060091,114060098,114060105,114060112,114060119,114060126,114060133,114060140,
		114060147,114060154,114060161,114060168,114060175,114060182,114060189,114060196,114060203,114060210,114060217,114060224,
		114060231,114060238,114060245,114060252,114060259,114060266,114060273,114060280,114060287,114060294,114060301,114060308,
		114060315,114060322,114060329,114060336,114060343,114060350,114060357,114060364,114060371,114060378,113386523,113386530,
		113386537,113386544,113386551,113386558,113386565,113386572,113386579,113386586,113386593,113386600,113386607,113386614,
		113386621,113386628,113386635,113386642,113386649,113386656,113386663,113386670,113386677,113386684,113386691,113386698,
		113386705,113386712,113386719,113386726,113386733,113386740,113386747,113386754,113386761,113386768,113386775,113386782,
		113386789,113386796,113386803,113386810,113386817,113386824,113386831,113386838,113386845,113386852,113386859,113386866,
		113386873,113386880,113386887,113386894,113386901,113386908,113386915,113386922,113386929,113386936,113386943,113386950,
		113386957,113386964,113386971,113386978,113386985,113386992,113386999,113387006,113387013,113387020,113387027,113387034,
		113387041,113387048,113387055,113387062,113387069,113387076,113387083,113387090,113387097,113387104,113387111,113387118,
		113387125,113387132,113387139,113387146,113387153,113387160,113387167,113387174,113387181,113387188,113387195,113387202,
		113387209,113387216,113387223,113387230,113387237,113387244,113387251,113387258,113387265,113387272,113387279,113387286,
		113387293,113387300,113387307,113387314,113387321,113387328,113387335,113387342,113387349,113387356,113387363,113387370,
		113387377,113387384,113387391,113387398,113387405,113387412,113387419,113387426,113387433,113387440,113387447,113387454,
		113387461,113387468,113387475,113387482,113387489,113387496,113387503,113387510,113387517,113387524,113387531,113387538,
		113387545,113387552,113387559,113387566,113387573,113387580,113387587,113387594,113387601,113387608,113387615,113387622,
		113387629,113387636,113387643,113387650,113387657,113387664,113387687};

const string snowMan2[] = {
    "_===_(.,.)<(:)>(:)",
    "_===_(.,.)<(:)>(\"\")",
    "_===_(.,.)<(:)>(___)",
    "_===_(.,.)<(:)>()",
    "_===_(.,.)<(][)>(:)",
    "_===_(.,.)<(][)>(\"\")",
    "_===_(.,.)<(][)>(___)",
    "_===_(.,.)<(][)>()",
    "_===_(.,.)<(><)>(:)",
    "_===_(.,.)<(><)>(\"\")",
    "_===_(.,.)<(><)>(___)",
    "_===_(.,.)<(><)>()",
    "_===_(.,.)<()>(:)",
    "_===_(.,.)<()>(\"\")",
    "_===_(.,.)<()>(___)",
    "_===_(.,.)<()>()",
    "_===_(.,.)/<(:)(:)",
    "_===_(.,.)/<(:)(\"\")",
    "_===_(.,.)/<(:)(___)",
    "___.....(o,o)/(][)(\"\")",
    "___.....(o,o)/(][)(___)",
    "___.....(o,o)/(][)()",
    "___.....(o,o)/(><)(:)",
    "___.....(o,o)/(><)(\"\")",
    "___.....(o,o)/(><)(___)",
    "___.....(o,o)/(><)()",
    "___.....(o,o)/()(:)",
    "___.....(o,o)/()(\"\")",
    "___.....(o,o)/()(___)",
    "___.....(o,o)/()()",
    "___.....(o,o)(:)>(:)",
    "___.....(o,o)(:)>(\"\")",
    "___.....(o,o)(:)>(___)",
    "___.....(o,o)(:)>()",
    "___.....(o,o)(][)>(:)",
    "___.....(o,o)(][)>(\"\")",
    "___.....(o,o)(][)>(___)",
    "___.....(o,o)(][)>()",
    "___.....(o,o)(><)>(:)",
    "___.....(o,o)(><)>(\"\")",
    "___.....(o,o)(><)>(___)",
    "___.....(o,o)(><)>()",
    "___.....(o,o)()>(:)",
    "___.....(o,o)()>(\"\")",
    "___.....(o,o)()>(___)",
    "___.....(o,o)()>()",
    "___.....(o,o)/(:)(:)",
    "___.....(o,o)/(:)(\"\")",
    "___.....(o,o)/(:)(___)",
    "___.....(o,o)/(:)()",
    "___.....(o,o)/(][)(:)",
    "___.....(o,o)/(][)(\"\")",
    "___.....(o,o)/(][)(___)",
    "___.....(o,o)/(][)()",
    "___.....(o,o)/(><)(:)",
    "___.....(o,o)/(><)(\"\")",
    "___.....(o,o)/(><)(___)",
    "___.....(o,o)/(><)()",
    "___.....(o,o)/()(:)",
    "___.....(o,o)/()(\"\")",
    "___.....(o,o)/()(___)",
    "___.....(o,o)/()()",
    "___.....(o,o)(:)\\(:)",
    "___.....(o,o)(:)\\(\"\")",
    "___.....(o,o)(:)\\(___)",
    "___.....(o,o)(:)\\()",
    "___.....(o,o)(][)\\(:)",
    "___.....(o,o)(][)\\(\"\")",
    "___.....(o,o)(][)\\(___)",
    "___.....(o,o)(][)\\()",
    "___.....(o,o)(><)\\(:)",
    "___.....(o,o)(><)\\(\"\")",
    "___.....(o,o)(><)\\(___)",
    "___.....(o,o)(><)\\()",
    "___.....(o,o)()\\(:)",
    "_/_\\(..O)/(:)>(:)",
    "_/_\\(..O)/(:)>(\"\")",
    "_/_\\(..O)/(:)>(___)",
    "_/_\\(..O)/(:)>()",
    "_/_\\(..O)/(][)>(:)",
    "_/_\\(..O)/(][)>(\"\")",
    "_/_\\(..O)/(][)>(___)",
    "_/_\\(..O)/(][)>()",
    "_/_\\(..O)/(><)>(:)",
    "_/_\\(..O)/(><)>(\"\")",
    "_/_\\(..O)/(><)>(___)",
    "_/_\\(..O)/(><)>()",
    "_/_\\(..O)/()>(:)",
    "_/_\\(..O)/()>(\"\")",
    "_/_\\(..O)/()>(___)",
    "_/_\\(..O)/()>()",
    "_/_\\(..O)//(:)(:)",
    "_/_\\(..O)//(:)(\"\")",
    "_/_\\(..O)//(:)(___)",
    "_/_\\(..O)//(:)()",
    "_/_\\(..O)//(][)(:)",
    "___(_*_)(o.-)/(][)(\"\")",
    "___(_*_)(o.-)/(][)(___)",
    "___(_*_)(o.-)/(][)()",
    "___(_*_)(o.-)/(><)(:)",
    "___(_*_)(o.-)/(><)(\"\")",
    "___(_*_)(o.-)/(><)(___)",
    "___(_*_)(o.-)/(><)()",
    "___(_*_)(o.-)/()(:)",
    "___(_*_)(o.-)/()(\"\")",
    "___(_*_)(o.-)/()(___)",
    "___(_*_)(o.-)/()()",
    "___(_*_)(o.-)(:)\\(:)",
    "___(_*_)(o.-)(:)\\(\"\")",
    "___(_*_)(o.-)(:)\\(___)",
    "___(_*_)(o.-)(:)\\()",
    "___(_*_)(o.-)(][)\\(:)",
    "___(_*_)(o.-)(][)\\(\"\")",
    "___(_*_)(o.-)(][)\\(___)",
    "___(_*_)(o.-)(][)\\()",
    "___(_*_)(o.-)(><)\\(:)",
    "___(_*_)(o.-)(><)\\(\"\")",
    "___(_*_)(o.-)(><)\\(___)",
    "___(_*_)(o.-)(><)\\()"};
}


