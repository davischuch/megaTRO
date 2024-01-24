#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c = 1, nameSize = 0, eusabo = 1;
char name[100], comp[] = { "eu sabo" };

int validBet(int bet) {
	int validBet = bet;

	while (validBet < 1 || validBet > 60) {
		printf("-> Digite uma dezena valida (entre 1 a 60): \n");
		scanf_s("%i", &validBet);
	}

	return validBet;
}

void randomizer(int b[], int bS, char n[], int nameSize) {
	int bets[10], numbers[6], corrects[6], sizeCorrects = 0;
	char name[100];
	srand(time(NULL));

	for (int i = 0; i < 6; i++) {
		numbers[i] = rand() % 61;
	}

	for (int i = 0; i < bS; i++) {
		for (int j = 0; j < 6; j++) {
			if (b[i] == numbers[j]) {
				corrects[i] = b[i];
				sizeCorrects++;
			}
		}
	}

	for (int i = 0; i < nameSize; i++) {
		name[i] = n[i];
	}

	switch (sizeCorrects) {
	case 4:
		printf("-> Parabens %.*s, voc? fez uma QUADRA _TR?\n\n", nameSize, name);

		break;
	case 5:
		printf("-> Parabens %.*s, voc? fez uma QUINA_TR?\n\n", nameSize, name);

		break;
	case 6:
		printf("-> Parabens %.*s, voc? fez uma SENA_TR?\n\n", nameSize, name);
		break;
	default:
		printf("-> Infelizmente voce so acertou %i, %.*s\n\n", sizeCorrects, nameSize, name);
		break;
	}
}

void bet() {
	int bets[10], betsS;

	do {
		printf("-> Digite o numero de dezenas (6 a 10): ");
		scanf_s("%i", &betsS);
	} while (betsS < 6 || betsS > 10);

	printf("-> Digite suas dezenas: ");
	for (int i = 0; i < betsS; i++) {
		scanf_s("%i", &bets[i]);
		bets[i] = validBet(bets[i]);
	}

	for (int i = 0; i < betsS; i++) {
		for (int j = 0; j < betsS; j++) {
			if (eusabo < 6) {
				if (i != j) {
					if (bets[i] == bets[j]) {
						while (bets[i] == bets[j]) {
							printf("-> Uma de suas dezenas esta repetida. Por favor, digite uma dezena valida (1 a 60): \n");
							scanf_s("%i", &bets[i]);
							bets[i] = validBet(bets[i]);
						}
						i = 0;
						j = -1;
					}
				}
			}
		}
	}

	for (int i = 0; i < betsS - 1; i++) {
		if (bets[i] > bets[i + 1]) {
			int aux = bets[i];
			bets[i] = bets[i + 1];
			bets[i + 1] = aux;
			i = -1;
		}
	}

	printf("-> Suas dezenas: \n");
	for (int i = 0; i < betsS; i++) {
		printf("%i. %i\n", i + 1, bets[i]);
	}
	printf("\n");

	randomizer(bets, betsS, name, nameSize);
}

void easteregg() {
	//int r = rand() % 1;
	int r = 1;
	switch (r) {
	case 1:
		printf("xxxxxxxxxxxxxxxxxxxxkkkxxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddd\n xxxxxxxxxxkkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n xxxxxkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxkkkkkkkkkkkkkkkkkkkkkkkkkxxxxkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n xxxxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxdoooddddxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxdddddxxxxxxdolccc::::ccldxxkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxdddolc:;,,,;;::clolc:;,,''''''',;coxxkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdolc:;,'.........'',::'.............',:oxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxdlc:;,''..............'..................':ldxxkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdlc:,''''....................................';cldxkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxo:;,'...'''......................................',;cdxkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdc,......'''''''....',;;;;;;;:::;;,'''...................',:oxkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxl,........''''''''',,,;;::::::c:::;,;;,'''.................'';lxkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko;'........''''''',,,,;;;:ccccllllcc:::;,,,',,'................',lxkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxc,''.......''''',,,;;;:c::ccllllllllc::c:;;;;,,,'.................,lxkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdc,'........'''',,,;;::cccccclllllllllcccc::::::;;,'''''.............,okkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:''.....''.''',,;;;;:cclllllllllllllllccccc::cc:::;;,,,,'''...........:dkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko;'......'''',,;::;::cclllllllllllllllllccclccclccc:::;;,,,'''...'......'cxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkl,...''''',,,,;:::::cccclllllllloollllloolllllcllllcc::;;;;,,,'''.''......;okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkl,....''',,;;;;::ccccccllllllllooooooloooooollllllllccc::;;;;;,,,''''......'cxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:'...'''',;;;:::ccccclllllllllloooooooooooooolllllllcccc:::;;;;;,,,''.......;dkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd;''.'..',;;:::::cccllllllllooooooooooooooooooollllllllccc:::;;;;;,,,''......,lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:'''..'',;;:::::ccclllllloooooooooooooooooooooooooollllccc:::;;;;;;,,''.....':xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxl,''..'',;;:::::ccllllloooooooodoodoooooooooooooooooollcccc::::;;;,,,,'...''';okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko,'...'',;:::::cclllllooooooooodddddddddooooooooooollllcccccc:::;;,,,,'...'',cdkOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko,...'',;:::::cclllllllolllllllooooooooooooooooollcccc::::::::::;;;,,,''..'.,okOOkOOOOOOkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd;..''',::::::ccccclllccc:::::cclloooooooooooolccc:;;;;;;;:::::::;;;,,,'....,okOOOOOOOOOOOOkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx:'.''';:::::ccccccccccccc::;;;::ccloooooooollc:;;;;;;::::::;;;;;;;;,,,''''.,okOOOOOOOOOOOOOOkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx:'.'',;:::::cc::::cccc::;;;;;;;;;;cllloollc:;,,;;,,,,,,,;;;;;;,,,;;;,;,'''':dkOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOkkOOxc'.'',;:c:::::;;;;,,'....,::;;::;,;cccloll:;,,;;;,;:;.....'',,,,,,;;;;;,'',lkOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOkOkd:''',:cccc:::;,,'',;,..':lc;;;:;;::ccloll:;,,;;;;:lc;'.,::,..',,;;;;;;,..,okOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOkOkxdc;,,;cccccc::;,,,,;::;;:cc:;;:::cc::clllc:;;;;;;;;:::;;;:;,,',,,;;:;;;,'':dOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOkdc:::::::cccccc:;;;;::;;;::::::::cllc:::cllc:;;::;;;;:;;;;;;;;;;;;;::::;;,,;;cdkOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOkOOOOxl::::cc::cccllccccc::::::::::::cclllc::cllllc:;::::;;;:::::;;;;;;::::::;;;;;:;cxOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOxlcc:cc::::cccccllccccccccccccllllllc:ccclllllc;;;:c:::::cc:::::::::::::;;;,;cccoOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOxlcc:cc:::::cccllllllllllllllloooolccccclooodol:;;;clccccccccccccc:::::;;;,,;cccokOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOkocc:ccc::::ccclllllllooooooooodolcccccclooodoc:;;;clollllllllllccc::::;;;,;;cc:oOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOkocccllc:::::ccclllllooooooooooddlccc;,,;:cccc;,;:::ldoooolllllcccc::::;;;;:::::dOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOxl:clll:::::ccclllllooooooodddoolcccc::;:::::;;cc::loooooollllccccc::;;;;;cc:;cxOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOkocclccc:::::ccllllllooooodddooollccccccllllc:::::ccloooooolllcccc::::;;;;::;;oOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOxl:cccc:::::ccllllllooooooooooolllccllloooolc:::::ccloooollllccc::::;;;;;;:;:dOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOxlcccc:::::ccccllllooooooooollcllllllooloollcc::::ccclllllllccc::::;;;;;;;;lkOO0OOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOxlccc::::::ccccllllooooollllccllloooolloolllccc::ccccllllllccc::::;;,,;:;:dOOO0OOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOxlccc:::::cccllllllooolllllllllllllccllccccccc:cccccccllllccc:::;;,;;;::lk00O0OOOOOOOOOOOOOOOOOOOOOOOOkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkOOOkOOOOOOOOOOOOOOOOOdc::;:::::cclllllloollllllccc:cccc:::::::c::::::clccclllcccc:::;;,,,;,;oO0O0000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOxolcc::::cccllllooollllc:::::::::::;;::::::::;;:cccclllcccc::;;;,,',:dO0000000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOxc::::ccclllloolllccccccccllllllllllccccc::::ccllllccc:::;;,,,:xO000000000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOd:;::ccccllllollllccccccclllllllllccccc:::::ccclllcc:::;;,,,,oO00000000000OOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOo:;::ccccclllllllllllccccccccc::::::cccccccccccllcc:::;,,,':k0000000000OOOOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOko;;;:cccccllllllllllllllllllllcccccllcccccccccccc:::;,,,,;d000000000000OOOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOko;;;::ccccccccccllllloolllllllllcccccccccc::::::::;,,,,,cO000000000000OOOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOkl;,;;::::cccccccllllllllooooooollccccc:::::::;;;;,,;;,,lO00000000000000OOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOd:;;,;;:::::::ccccccllllooooooollccc:::;;;;;;;,,',;;;,',cx00000000000000OOOOOOOOOOOOOOOOOOOkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOxc;;;,,,,;;;;;:::ccccllllllllllccc:::;;;;,,,,,'',;:;,'..',lk000000000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOkc::::;,,,,,,,,;;;::::cccccc::::::;;;;,,,,,,,'',;::;,'.'''';dO000000O0OOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOo;;::::;,,,,,,;;,,,;;;;;;;;;;;;;;;,,,,,;;;,,,',;::;;,..''''',cxOO0000OOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOx;',;:::::;,,,,,;;:::::::::::cc:::::;;;;;;,,,,,;:::;;'..''''''',;:clodxkOOOOOOOOOOOOOOOkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOkl,'',;::cc:;;,,,,,;;;:::cccccc:::::;;;;,,,,,,;:cc::;,...''''''''''...',,;clooxkkOOOOOkkOkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOkxl,''.';:::ccc::;;;;;;;;;;;;;::::;;;;;;;;;;;;;:ccccc:;'..'''''''''''''''''''''',;:cloxkkOOkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOkxolc;,,',,'',;::ccccc::::::::::::::::::::ccc::::::ccccccc:,...'''''''.''''''''''...''''''',;cloxxkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOkkdoc:;,''',,'','',;;::cccccc::::ccccccccccllllcccc::::ccccccc:;'....'''''..''''.''',,,'''''''''''''',;clodxkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdlc:,,,,,''''',,'','';;;:ccccccccccccccllllllllllccccc::ccccccc::,....''''''..''''''''''',,,,''',,'',,,,'''',;:ccl\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdlc:,',,,,,,''''''''',;,';;;:::cccccccccccccclllllllcccccccccccccc::;'....'''''''.''''''''.''''',,,,,,,,,,,,,'''',,'''\n kkkkkkkkkkkkkkkkkkkkkkkkkkkxol:;,'',,,,,',,',,,''''',,,,,;;:;:::cccccccccccclllllllllccccccccccccc::,.....',,'''''...'''''''''''''',,,,,,,,,,'',,,,,''\n kkkkkkkkkkkkkkkkkkkkkkkxdlc;'',',,,,,,,,;;,,,''''''''',;,,;::::::ccccccccccllllllllllllcccccllccc::;'....',,,,''''...''',,'''',,,'',,,,,'',,,'',,,,'''\n kkkkkkkkkkkkkkkkkkkxdlc;,',,,',,,,,,,,,,,,'''''''''''',,,,,,;;;:::ccllllllllllllllllllllllllcccc:::;.....',;,,','''..'''','''',,,,,,'',,,,,,,,,,,'''',\n kkkkkkkkkkkkkkkxdlc;,,,'',,;,,,,;,,,,,,,,''',,''''''',',;,,,'';:::ccclllllllllllllllllllllllcccc::;,...'''''',,,'''....'','''',,,,,'',,,,,,,,,,,'..'',\n kkkkkkkkkkkdoc:;,,,,,,,,,,,,,,,,,,,,,,,,,''','''''''''',;;;,,'',:::ccllllllllllloooolllllllllcc::;'''..'''...''''''''...''''.',,,',,,,,,,,,,,,,'...',,\n kkkkkkkdoc:,,,'',,,,,,,,',,,,,,,,,,,,,,,'''''',,,,''''',,;;;;,'',::cclllollllooooooooolllllllcc:;,.''..,'.'',,'..''''''..''''.',',,,,,,,,,,,,,,'..'',,\n kkkkdl:;,,'',,,,,,,,,,,,',,,,,,,,,,,,,,,,,''''',''','',,;,,'..,,'';::lllooooooooooooooooooool:,''..''''..'',,,'''.''''...'''''',,,,,,,,,,,,,,''..',,,,\n xdoc;,'',,'',,,,,,,;;;,,,,,,,,,,,,,,,,,,,,,,'''''''',,,,'...'',,'.'',;clooooooooooooooooool:,'''.''.'...',,,,'''''''''...'''''.';,,,,,,,,,,,,''..',,,,\n :;,',,,,,,,''',,,,,,,,,,,,,,',,,,,,,;,,,,,,,'''.'''''''...'''','....'',;cloddddddooddddol;''''''....''.'',,'''',''''''.....'''.',,,,,,,,,,,,'''',,,,,,\n '','',,,,,,,''',;,,,,,,,,,,'',,,,,;;,,,,;;,,,'''''',''...''''''''.....'',;:ccoddddddodl:'.'''.''..''''',,,,',,,,'',,'''''..'....,,,;,,,,,,,''.'',,,,,,\n '','',,,,,,,,'',,,,,,,;;,,,,,,,'',,,,,,,,,,,,,'''',,'.....'''''.','...',,,,',;cooooool;''''.'',,'''..',,,,,,,,'',,''''''''''''..',,;,,;,,,'''''',,,,,,\n '',,,,',,,,,,'','',,,,,,,,;;,,,,'',,'',,',,'',,,'''..'''''...''''''..'','''','':looooc,,,'..',,,,''.',,,,',,,,'',,'',''',,,',''.',;;;;,,,,''',,,,,,,,,\n");
		break;
	case 2:
		printf("------------------------------------===--------------------------------====\n");
		printf("------------------------=---==+==+*######**+===-----------------------=====\n");
		printf("-------------------------==*##%%%%%%%%%%%@@@@@%#+==------------------======\n");
		printf("------------------------=++*#%%%%@@@@%%%%%@@%##%#**=----------------=======\n");
		printf("-----------------------=+*####%%@@%%%%%%%%%########*+==-------------=======\n");
		printf("---------------------===+**+++++**###******************=-----------========\n");
		printf("---------------------=++++==-=====+++**+++++**++++++*#*+=----------========\n");
		printf("--------------------==-=+=====++++=+++*****+***+++++++#*==----=----========\n");
		printf("--------------------=--=========--=++++++++++++++++++++++=---=----=========\n");
		printf("---------------------=+++++======+++++++++++++++++++++++++---=--===========\n");
		printf("-------------------=-=+++====+++****************++++++**++=--=--===========\n");
		printf("-------------------==*++++*#%%@@@%%%###*##%%%%%%%%##****+==---=-===========\n");
		printf("-------------------++++*+#%%%%%%%@%%%%###%%%%@@@@@%%%#*##+=--==============\n");
		printf("----------------=++***##*%%@@@@@@@@@@%**#%%@@@@@@@@%###%#++=-==-===========\n");
		printf("----------------=@#**+****####%%@@@%%++++*%%@@@@%%%%%#****#%===============\n");
		printf("----------------=%**++++*+***####***+==+++*###%%%%%#*****#%#===============\n");
		printf("----------------=*%%+++=++*+====****+=-=+**##******+++***##+--=============\n");
		printf("----------------=+@*+++++==+++*##@#++==+++*#%%##**++++***##+-==============\n");
		printf("----------------=++*+++++++**##%%@++**###***#@%%###********+===============\n");
		printf("----------------==++++**+**##%%%%%%@%%%%%%@@%%%%%%###*****+================\n");
		printf("----------------===++++***##%%%%####%%@%%%%##%%%%%%####***+================\n");
		printf("---=----======---=+*+++***##%%%#*###%%%%%%%###%%%%%#####**+================\n");
		printf("================---=+*****##%%%%@@%%#%#%%#%%@@@@%%%####**+=================\n");
		printf("=================-===******#%%%##%%%%%%%%%%#####%%%#####*==================\n");
		printf("=====================+***###%##***###%%%%%%#######%#####===================\n");
		printf("===================-===*######******#########**#######*====================\n");
		printf("===================-====*#%%%#****+***#####*****#%%%%+=====================\n");
		printf("=========================*#%%%##***##############%%%=======================\n");
		printf("========================***#%##%%%%%%%%%%%%%%%%%#%##*======================\n");
		printf("=======================%@#*####%%%%%%%%%%%%%%%%%%%#%@%=====================\n");
		printf("====================+#%%@%**#%%%%%%%%%%%%%%%%%%%%#%@@@@*===================\n");
		printf("===============**#%%%%%@@@##*##%%%%%%%%%%%%%%%%%%@@@@@@@@#*++==============\n");
		printf("=========+*#*###@@@%%%@@@@@%####%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@%##+=========\n");
		printf("==+++**#%@@%%@#**@@%%@@@@@@@%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@%--**##%%###++===\n");
		printf("+**+++--+***+::.=@@@@@@@@@@@@@@@@%%%%%@@@@@@@@@@@@@@@@@@@@@=::::::::::--===\n");
		printf(".....::---:::::.+@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%##%@@@%#*-::::::---::-:::\n");
		printf("::::::--::::::::+@@@@@%%%%%%@@@@@@@@@@@@@@@@@@@@@%###**++=-:::::::---------\n");
		break;
	default:
		break;
	}
}

char* teste() {
	return "teste";
}

int main() {
	int o;
	char option;
	char testee[10];

	printf("=========================--- Bem vindo a: ---==============================    \n");
	printf(" /$$      /$$                                    /$$$$$$$$                     \n");
	printf("| $$$    /$$$                                   |__  $$__/                     \n");
	printf("| $$$$  /$$$$  /$$$$$$   /$$$$$$   /$$$$$$         | $$  /$$$$$$   /$$$$$$     \n");
	printf("| $$ $$/$$ $$ /$$__  $$ /$$__  $$ |____  $$ /$$$$$$| $$ /$$__  $$ /$$__  $$    \n");
	printf("| $$  $$$| $$| $$$$$$$$| $$  \\ $$  /$$$$$$$|______/| $$| $$  \\__/| $$  \\ $$ \n");
	printf("| $$\\  $ | $$| $$_____/| $$  | $$ /$$__  $$        | $$| $$      | $$  | $$   \n");
	printf("| $$ \\/  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$        | $$| $$      |  $$$$$$/   \n");
	printf("|__/     |__/ \\_______/ \\____  $$ \\_______/        |__/|__/       \\______/ \n");
	printf("                        /$$  \\ $$                                             \n");
	printf("                       |  $$$$$$/                                              \n");
	printf("                        \\______/                                              \n");
	printf("===========================================================================  \n\n");

	printf("%s", teste());

	printf("-> Digite seu nome: ");
	gets_s(name, 100);

	for (int i = 0; name[i] != '\0'; i++) {
		nameSize++;
	}

	eusabo = strcmp(name, comp);

	do {
		bet();

		if (eusabo == 0) {
			do {
				printf("-> Fazer nova aposta (N)\n");
				printf("-> Encerrar programa (Esc)\n");
				printf("-> ? (?)\n\n");

				option = getch();
				o = option;
			} while (o != 27 && o != 78 && o != 110 && o != 63);

			if (o == 27) {
				c = 0;
				system("cls");
				printf("----------------- Obrigado por participar da ------------------       \n");
				printf("   _____                              ___________                     \n");
				printf("  /     \\   ____   _________          \\__    ___/______  ____       \n");
				printf(" /  \\ /  \\_/ __ \\ / ___\\__  \\    ______ |    |  \\_  __ \\/  _ \\\n");
				printf("/    Y    \\  ___// /_/  > __ \\_ /_____/ |    |   |  | \\(  <_> )    \n");
				printf("\\____|__  /\\___  >___  (____  /         |____|   |__|   \\____/     \n");
				printf("        \\/     \\/_____/     \\/                                     \n");
				printf("---------------------------------------------------------------       \n");
			}
			else if (o == 63) {
				c = 0;
				system("cls");
				easteregg();
			}
		}
		else {
			do {
				printf("-> Fazer nova aposta (N)\n");
				printf("-> Encerrar programa (Esc)\n\n");

				option = getch();
				o = option;
			} while (o != 27 && o != 78 && o != 110);

			if (o == 27) {
				c = 0;
				system("cls");
				printf("----------------- Obrigado por participar da ------------------       \n");
				printf("   _____                              ___________                     \n");
				printf("  /     \\   ____   _________          \\__    ___/______  ____       \n");
				printf(" /  \\ /  \\_/ __ \\ / ___\\__  \\    ______ |    |  \\_  __ \\/  _ \\\n");
				printf("/    Y    \\  ___// /_/  > __ \\_ /_____/ |    |   |  | \\(  <_> )    \n");
				printf("\\____|__  /\\___  >___  (____  /         |____|   |__|   \\____/     \n");
				printf("        \\/     \\/_____/     \\/                                     \n");
				printf("---------------------------------------------------------------       \n");
			}
		}

	} while (c == 1);
}