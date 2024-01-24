#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <Windows.h>

int row, col, c = 1, nameSize = 0, eusabo = 1, salber = 0, traps = 0, jb = 0, certos[10];
char name[100], sauber[] = { "aeromodelismo" }, trapezio[] = { "o vo" }, bair[] = { "regras do chefe" };

void printNums() {
	getyx(stdscr, row, col);
	move(row + 1, (COLS / 2) - 25);
	printw("-> ");
	for (int i = 0; i < 10; i++) {
		if (certos[i] != 0) {
			printw("%i ", certos[i]);
		}
	}
}

void end() {
	clear();
	flash();
	mvprintw((LINES / 2) - 7, (COLS / 2) - 32, "----------------- Obrigado por participar da ------------------       ");
	mvprintw((LINES / 2) - 6, (COLS / 2) - 32, "   _____                              ___________                     ");
	mvprintw((LINES / 2) - 5, (COLS / 2) - 32, "  /     \\   ____   _________          \\__    ___/______  ____       ");
	mvprintw((LINES / 2) - 4, (COLS / 2) - 32, " /  \\ /  \\_/ __ \\ / ___\\__  \\    ______ |    |  \\_  __ \\/  _ \\");
	mvprintw((LINES / 2) - 3, (COLS / 2) - 32, "/    Y    \\  ___// /_/  > __ \\_ /_____/ |    |   |  | \\(  <_> )    ");
	mvprintw((LINES / 2) - 2, (COLS / 2) - 32, "\\____|__  /\\___  >___  (____  /         |____|   |__|   \\____/     ");
	mvprintw((LINES / 2) - 1, (COLS / 2) - 32, "        \\/     \\/_____/     \\/                                     ");
	mvprintw((LINES / 2), (COLS / 2) - 32, "---------------------------------------------------------------       ");
	getch();
	endwin();
}

void clearTerminal() {
	getyx(stdscr, row, col);
	if (row >= (LINES - 2)) {
		clear();
		move(2, (COLS / 2) - 37);
	}
}

int validBet(int bet) {
	int validBet = bet;

	while (validBet < 1 || validBet > 60) {
		getyx(stdscr, row, col);
		move(row, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Digite uma dezena valida (entre 1 a 60): ");
		scanw("%i", &validBet);
	}

	return validBet;
}

void randomizer(int b[], int bS, char n[], int nameSize) {
	int bets[10], numbers[6], corrects[6], sizeCorrects = 0;
	char name[100];
	srand(time(NULL));

	for (int i = 0; i < 6; i++) {
		numbers[i] = rand() % 60 + 1;
		for (int j = 0; j < i; j++) {
			if (numbers[i] == numbers[j]) {
				i--;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		certos[i] = 0;
	}

	for (int i = 0; i < bS; i++) {
		for (int j = 0; j < 6; j++) {
			if (b[i] == numbers[j]) {
				corrects[i] = b[i];
				certos[i] = b[i];
				sizeCorrects++;
			}
		}
	}

	getyx(stdscr, row, col);
	move(row + 2, (COLS / 2) - 37);
	printw("-> Dezenas sorteadas:");
	for (int i = 0; i < 6; i++) {
		getyx(stdscr, row, col);
		move(row + 1, (COLS / 2) - 25);
		printw("%i. %i", i + 1, numbers[i]);
	}

	for (int i = 0; i < nameSize; i++) {
		name[i] = n[i];
	}

	switch (sizeCorrects) {
	case 0:
		getyx(stdscr, row, col);
		move(row + 2, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Infelizmente voce nao acertou nenhuma, %.*s", nameSize, name);
		break;
	case 4:
		getyx(stdscr, row, col);
		move(row + 2, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Parabens %.*s, você fez uma QUADRA _TRÔ", nameSize, name);
		printNums();
		break;
	case 5:
		getyx(stdscr, row, col);
		move(row + 2, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Parabens %.*s, você fez uma QUINA_TRÔ", nameSize, name);
		printNums();
		break;
	case 6:
		getyx(stdscr, row, col);
		move(row + 2, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Parabens %.*s, você fez uma SENA_TRÔ", nameSize, name);
		printNums();
		break;
	default:
		getyx(stdscr, row, col);
		move(row + 2, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Infelizmente voce so acertou %i, %.*s", sizeCorrects, nameSize, name);
		printNums();
		break;
	}
}

void bet() {
	int bets[10], betsS;

	do {
		clear();
		getyx(stdscr, row, col);
		move(2, (COLS / 2) - 37);
		printw("-> Digite o numero de dezenas (6 a 10): ");
		scanw("%i", &betsS);
	} while (betsS < 6 || betsS > 10);

	for (int i = 0; i < betsS; i++) {
		getyx(stdscr, row, col);
		move(row, (COLS / 2) - 37);
		clearTerminal();
		printw("-> Digite suas dezenas: ");
		scanw("%i", &bets[i]);

		bets[i] = validBet(bets[i]);

		for (int j = 0; j < betsS; j++) {
			if (i != j) {
				if (bets[i] == bets[j]) {
					i--;
					j = 1;

					getyx(stdscr, row, col);
					move(row + 1, (COLS / 2) - 37);
					clearTerminal();
					printw("-> Uma de suas dezenas esta repetida. Por favor, digite uma dezena valida \n");
					break;
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

	clear();
	move(2, (COLS / 2) - 37);

	printw("-> Suas dezenas:");
	for (int i = 0; i < betsS; i++) {
		getyx(stdscr, row, col);
		move(row + 1, (COLS / 2) - 25);
		printw("%i. %i", i + 1, bets[i]);
	}

	randomizer(bets, betsS, name, nameSize);
}

void easteregg() {
	endwin();
	system("color 02");
	if (salber == 1) {
		printf("xxxxxxxxxxxxxxxxxxxxkkkxxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddd\n xxxxxxxxxxkkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n xxxxxkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxkkkkkkkkkkkkkkkkkkkkkkkkkxxxxkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n xxxxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxdoooddddxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxdddddxxxxxxdolccc::::ccldxxkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxdddolc:;,,,;;::clolc:;,,''''''',;coxxkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdolc:;,'.........'',::'.............',:oxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxdlc:;,''..............'..................':ldxxkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdlc:,''''....................................';cldxkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxo:;,'...'''......................................',;cdxkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdc,......'''''''....',;;;;;;;:::;;,'''...................',:oxkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxl,........''''''''',,,;;::::::c:::;,;;,'''.................'';lxkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko;'........''''''',,,,;;;:ccccllllcc:::;,,,',,'................',lxkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxc,''.......''''',,,;;;:c::ccllllllllc::c:;;;;,,,'.................,lxkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdc,'........'''',,,;;::cccccclllllllllcccc::::::;;,'''''.............,okkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:''.....''.''',,;;;;:cclllllllllllllllccccc::cc:::;;,,,,'''...........:dkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko;'......'''',,;::;::cclllllllllllllllllccclccclccc:::;;,,,'''...'......'cxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkl,...''''',,,,;:::::cccclllllllloollllloolllllcllllcc::;;;;,,,'''.''......;okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkl,....''',,;;;;::ccccccllllllllooooooloooooollllllllccc::;;;;;,,,''''......'cxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:'...'''',;;;:::ccccclllllllllloooooooooooooolllllllcccc:::;;;;;,,,''.......;dkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd;''.'..',;;:::::cccllllllllooooooooooooooooooollllllllccc:::;;;;;,,,''......,lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:'''..'',;;:::::ccclllllloooooooooooooooooooooooooollllccc:::;;;;;;,,''.....':xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxl,''..'',;;:::::ccllllloooooooodoodoooooooooooooooooollcccc::::;;;,,,,'...''';okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko,'...'',;:::::cclllllooooooooodddddddddooooooooooollllcccccc:::;;,,,,'...'',cdkOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko,...'',;:::::cclllllllolllllllooooooooooooooooollcccc::::::::::;;;,,,''..'.,okOOkOOOOOOkkkkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd;..''',::::::ccccclllccc:::::cclloooooooooooolccc:;;;;;;;:::::::;;;,,,'....,okOOOOOOOOOOOOkkkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx:'.''';:::::ccccccccccccc::;;;::ccloooooooollc:;;;;;;::::::;;;;;;;;,,,''''.,okOOOOOOOOOOOOOOkkkkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx:'.'',;:::::cc::::cccc::;;;;;;;;;;cllloollc:;,,;;,,,,,,,;;;;;;,,,;;;,;,'''':dkOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOkkOOxc'.'',;:c:::::;;;;,,'....,::;;::;,;cccloll:;,,;;;,;:;.....'',,,,,,;;;;;,'',lkOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOkOkd:''',:cccc:::;,,'',;,..':lc;;;:;;::ccloll:;,,;;;;:lc;'.,::,..',,;;;;;;,..,okOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOkOkxdc;,,;cccccc::;,,,,;::;;:cc:;;:::cc::clllc:;;;;;;;;:::;;;:;,,',,,;;:;;;,'':dOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOkdc:::::::cccccc:;;;;::;;;::::::::cllc:::cllc:;;::;;;;:;;;;;;;;;;;;;::::;;,,;;cdkOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOkOOOOxl::::cc::cccllccccc::::::::::::cclllc::cllllc:;::::;;;:::::;;;;;;::::::;;;;;:;cxOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOxlcc:cc::::cccccllccccccccccccllllllc:ccclllllc;;;:c:::::cc:::::::::::::;;;,;cccoOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOxlcc:cc:::::cccllllllllllllllloooolccccclooodol:;;;clccccccccccccc:::::;;;,,;cccokOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOkocc:ccc::::ccclllllllooooooooodolcccccclooodoc:;;;clollllllllllccc::::;;;,;;cc:oOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOkocccllc:::::ccclllllooooooooooddlccc;,,;:cccc;,;:::ldoooolllllcccc::::;;;;:::::dOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOxl:clll:::::ccclllllooooooodddoolcccc::;:::::;;cc::loooooollllccccc::;;;;;cc:;cxOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOkocclccc:::::ccllllllooooodddooollccccccllllc:::::ccloooooolllcccc::::;;;;::;;oOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOxl:cccc:::::ccllllllooooooooooolllccllloooolc:::::ccloooollllccc::::;;;;;;:;:dOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOxlcccc:::::ccccllllooooooooollcllllllooloollcc::::ccclllllllccc::::;;;;;;;;lkOO0OOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOxlccc::::::ccccllllooooollllccllloooolloolllccc::ccccllllllccc::::;;,,;:;:dOOO0OOOOOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOxlccc:::::cccllllllooolllllllllllllccllccccccc:cccccccllllccc:::;;,;;;::lk00O0OOOOOOOOOOOOOOOOOOOOOOOOkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkOOOkOOOOOOOOOOOOOOOOOdc::;:::::cclllllloollllllccc:cccc:::::::c::::::clccclllcccc:::;;,,,;,;oO0O0000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOxolcc::::cccllllooollllc:::::::::::;;::::::::;;:cccclllcccc::;;;,,',:dO0000000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOxc::::ccclllloolllccccccccllllllllllccccc::::ccllllccc:::;;,,,:xO000000000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOd:;::ccccllllollllccccccclllllllllccccc:::::ccclllcc:::;;,,,,oO00000000000OOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOo:;::ccccclllllllllllccccccccc::::::cccccccccccllcc:::;,,,':k0000000000OOOOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOko;;;:cccccllllllllllllllllllllcccccllcccccccccccc:::;,,,,;d000000000000OOOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOko;;;::ccccccccccllllloolllllllllcccccccccc::::::::;,,,,,cO000000000000OOOOOOOOOOOOOOOOOOOOOOOOkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOkl;,;;::::cccccccllllllllooooooollccccc:::::::;;;;,,;;,,lO00000000000000OOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOd:;;,;;:::::::ccccccllllooooooollccc:::;;;;;;;,,',;;;,',cx00000000000000OOOOOOOOOOOOOOOOOOOkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOxc;;;,,,,;;;;;:::ccccllllllllllccc:::;;;;,,,,,'',;:;,'..',lk000000000OOOOOOOOOOOOOOOOOOOOOOOkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOkc::::;,,,,,,,,;;;::::cccccc::::::;;;;,,,,,,,'',;::;,'.'''';dO000000O0OOOOOOOOOOOOOOOOOOOOkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOo;;::::;,,,,,,;;,,,;;;;;;;;;;;;;;;,,,,,;;;,,,',;::;;,..''''',cxOO0000OOOOOOOOOOOOOOOOOOOkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOx;',;:::::;,,,,,;;:::::::::::cc:::::;;;;;;,,,,,;:::;;'..''''''',;:clodxkOOOOOOOOOOOOOOOkkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOkl,'',;::cc:;;,,,,,;;;:::cccccc:::::;;;;,,,,,,;:cc::;,...''''''''''...',,;clooxkkOOOOOkkOkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOkxl,''.';:::ccc::;;;;;;;;;;;;;::::;;;;;;;;;;;;;:ccccc:;'..'''''''''''''''''''''',;:cloxkkOOkkkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOOOOkxolc;,,',,'',;::ccccc::::::::::::::::::::ccc::::::ccccccc:,...'''''''.''''''''''...''''''',;cloxxkkkkkkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOOkkdoc:;,''',,'','',;;::cccccc::::ccccccccccllllcccc::::ccccccc:;'....'''''..''''.''',,,'''''''''''''',;clodxkkkk\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdlc:,,,,,''''',,'','';;;:ccccccccccccccllllllllllccccc::ccccccc::,....''''''..''''''''''',,,,''',,'',,,,'''',;:ccl\n kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdlc:,',,,,,,''''''''',;,';;;:::cccccccccccccclllllllcccccccccccccc::;'....'''''''.''''''''.''''',,,,,,,,,,,,,'''',,'''\n kkkkkkkkkkkkkkkkkkkkkkkkkkkxol:;,'',,,,,',,',,,''''',,,,,;;:;:::cccccccccccclllllllllccccccccccccc::,.....',,'''''...'''''''''''''',,,,,,,,,,'',,,,,''\n kkkkkkkkkkkkkkkkkkkkkkkxdlc;'',',,,,,,,,;;,,,''''''''',;,,;::::::ccccccccccllllllllllllcccccllccc::;'....',,,,''''...''',,'''',,,'',,,,,'',,,'',,,,'''\n kkkkkkkkkkkkkkkkkkkxdlc;,',,,',,,,,,,,,,,,'''''''''''',,,,,,;;;:::ccllllllllllllllllllllllllcccc:::;.....',;,,','''..'''','''',,,,,,'',,,,,,,,,,,'''',\n kkkkkkkkkkkkkkkxdlc;,,,'',,;,,,,;,,,,,,,,''',,''''''',',;,,,'';:::ccclllllllllllllllllllllllcccc::;,...'''''',,,'''....'','''',,,,,'',,,,,,,,,,,'..'',\n kkkkkkkkkkkdoc:;,,,,,,,,,,,,,,,,,,,,,,,,,''','''''''''',;;;,,'',:::ccllllllllllloooolllllllllcc::;'''..'''...''''''''...''''.',,,',,,,,,,,,,,,,'...',,\n kkkkkkkdoc:,,,'',,,,,,,,',,,,,,,,,,,,,,,'''''',,,,''''',,;;;;,'',::cclllollllooooooooolllllllcc:;,.''..,'.'',,'..''''''..''''.',',,,,,,,,,,,,,,'..'',,\n kkkkdl:;,,'',,,,,,,,,,,,',,,,,,,,,,,,,,,,,''''',''','',,;,,'..,,'';::lllooooooooooooooooooool:,''..''''..'',,,'''.''''...'''''',,,,,,,,,,,,,,''..',,,,\n xdoc;,'',,'',,,,,,,;;;,,,,,,,,,,,,,,,,,,,,,,'''''''',,,,'...'',,'.'',;clooooooooooooooooool:,'''.''.'...',,,,'''''''''...'''''.';,,,,,,,,,,,,''..',,,,\n :;,',,,,,,,''',,,,,,,,,,,,,,',,,,,,,;,,,,,,,'''.'''''''...'''','....'',;cloddddddooddddol;''''''....''.'',,'''',''''''.....'''.',,,,,,,,,,,,'''',,,,,,\n '','',,,,,,,''',;,,,,,,,,,,'',,,,,;;,,,,;;,,,'''''',''...''''''''.....'',;:ccoddddddodl:'.'''.''..''''',,,,',,,,'',,'''''..'....,,,;,,,,,,,''.'',,,,,,\n '','',,,,,,,,'',,,,,,,;;,,,,,,,'',,,,,,,,,,,,,'''',,'.....'''''.','...',,,,',;cooooool;''''.'',,'''..',,,,,,,,'',,''''''''''''..',,;,,;,,,'''''',,,,,,\n '',,,,',,,,,,'','',,,,,,,,;;,,,,'',,'',,',,'',,,'''..'''''...''''''..'','''','':looooc,,,'..',,,,''.',,,,',,,,'',,'',''',,,',''.',;;;;,,,,''',,,,,,,,,\n");
	}
	if (traps == 1) {
		printf("                                             AAgAAAAAAAAA                                           \n");
		printf("                                     hAAAAAAAAIAje0eXAAAAAAAAAT                                     \n");
		printf("                                      FATAL RAAAAAAAAAAAAAAYAAAAA                                   \n");
		printf("                                     yZA2AAAAAAAAAA1AAO GAAA  vAoy                                  \n");
		printf("                                  qAAAAAAAAAAAHAFQDAVILAAAAMHAWeLAAA                                \n");
		printf("                                  hAAoyUjPAAAAAAAAAAQ76j  zRCSJA3AAAAj                              \n");
		printf("                                                                     2y A                           \n");
		printf("                                                                      AAR                           \n");
		printf("                                                      yvu    w          AA                          \n");
		printf("                                                y     zxux                                          \n");
		printf("                                                                                                    \n");
		printf("                                                                     qqz                            \n");
		printf("                                                                                                    \n");
		printf("                                                april2b                 GA                          \n");
		printf("                                     AAAAAAAAAAAAAN3iOFAAAAAAAAAAAA                                 \n");
		printf("                            v      AAAAAAAAAAAROAAAi vJAAM3AAAAAAAAMAAA                             \n");
		printf("                                 GA0s    y3PAA9b1AAAAVrAR4k2AAAA9XAAAAAA AAA                        \n");
		printf("                             AAA AAABAAAAAAAAAAA8A1   AA3RAAAAAAAAGH  qZ AAA                        \n");
		printf("                       A    xrqCeAAAAAAAAAAAAAAAAAA l AAAAAAAAAAAAAAAAAARAt                         \n");
		printf("                       AAr               gsDAAAAA       AANAAAIw     AAS   MGAAA                    \n");
		printf("                       A        v   AAAAAAAAA              AAAAAAAAAAw      GAA1                    \n");
		printf("                       3ZAA      xv                      3    vAAAAA5       AAA                     \n");
		printf("                        AAf u      p        AR           7AAr            ls AAR                     \n");
		printf("                        AA          u     AAAAA          AAAAAA7            AAA                     \n");
		printf("                        Mk             s6AACA              APHAACPo     XVt  A                      \n");
		printf("                                    zhUAAAPPAZ C WAAAAAAA58APPODAAAAAfwxx  k                        \n");
		printf("                             zx  y  s9AAJPPLAAAAAAAU4PAAAAACPPPPMEAACY9qaa9a                        \n");
		printf("                                   hAAANPKAAAAAAIBAAAASPMEAAALPPPPPJAAATQTy h                       \n");
		printf("                         um     1giYAAOPMAA     uR685WSPM0  7AKPPPPOIAW 3nj V                       \n");
		printf("                            z      eADPMCP    6PAHPPPPOOLDA1 wYTRPPLORl AIW4A                       \n");
		printf("                            u       BANLd 6AAAAAIAAAJSPYRUVDAM538TPEOHJTPw 3                        \n");
		printf("                                 qkzPALTIAAAABcV w  ABRYEAFHAAAAATPEqpq   ri                        \n");
		printf("                                    aAJFAADAAAAAAAAJSQPIRUQOHDAELRPHAAX RAAq                        \n");
		printf("                              b  t   AAAF         MPPPPPPPKm    AAMLAlxcgA                          \n");
		printf("                              A xUQmNAFx   AAAAAAAAAHGBAAAAAAA1ozJEFWNTAKA                          \n");
		printf("                               AAAEIy5HQ         SAAAAABDYevvb07 AA1nNAAw                           \n");
		printf("                                AAAMTbcL                         jWQAAA                             \n");
		printf("                                  AAAAAAm         pcpNKOIUbjt   VACGAA                              \n");
		printf("                                  8AAAAAAAw   aAAAAAAAAAAAAAAAAACAMAA                               \n");
		printf("                                   RAif9AAAAAAAAAMPPPPPPPPLGCCIKL7XAS                               \n");
		printf("                                AT  AP2o5fUBHLNPPPPPPPPPPPPPPPPPNHARRAA                             \n");
		printf("                               AAAv  ANfdag3NPPPPPPPPPPPPPPPPPPPNCb EAAA                            \n");
		printf("                             AAAAA   8AAAADINPPPPPPPPPPPPPPPPPPNLU aAAAAA                           \n");
		printf("                          AAAAFODAA   xAAAHPPPPPPPPPPPPPPPPPOJCAUMjAAAAAAAA                         \n");
		printf("                    AAAAAAAAFFGNGAAA    w2AGPPPPPPPPPPPPPPPPOVv  xAAAAAAAAAAAAA                     \n");
		printf("               At9Cc AAACGFFFHFEKAAAAAO   yDPPPPPPPPPPPPPPPPSY5mAAAAAAAAAAAAAAAAAAAA                \n");
		printf("            AAAAAAAAAAAAIHFFGDADIHAAAKMAAY4BPPPPPPPPPQQQSYakv2AAAAAAAAAAAAAAAAf 3AAAAAAAA           \n");
		printf("     HAAAAAAAAAAAAA    AIHFGIHILTQJAAAAClb85YTRPQSVXZ2Wal8NAAAAAAAAAAAAAAABFGA        7AAAAAAA      \n");
		printf(" AAAAAA     AAAAA      AKHGIFEDBAAAAAAAAAAAYakurpf41UZWMAAAAAAAAAAAAAAAAAAAAAAA                     \n");
		printf("                      IAPGIJPAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                      \n");
	}
}

int main() {
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	start_color();

	curs_set(0);
	resize_term(300, 100); //row: 29; col: 121
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));

	move((LINES / 2) - 1, (COLS / 2) - 4);

	char* intro = "MEGA TRO";
	for (int i = 0; i < 8; i++) {
		char curr = intro[i];
		addch(curr);
		Sleep(200);
		refresh();
	}

	Sleep(1800);
	flash();
	clear();

	mvprintw((LINES / 2) - 12, (COLS / 2) - 37, "=========================--- Bem vindo a: ---==============================    ");
	mvprintw((LINES / 2) - 11, (COLS / 2) - 37, " /$$      /$$                                    /$$$$$$$$                     ");
	mvprintw((LINES / 2) - 10, (COLS / 2) - 37, "| $$$    /$$$                                   |__  $$__/                     ");
	mvprintw((LINES / 2) - 9, (COLS / 2) - 37, "| $$$$  /$$$$  /$$$$$$   /$$$$$$   /$$$$$$         | $$  /$$$$$$   /$$$$$$     ");
	mvprintw((LINES / 2) - 8, (COLS / 2) - 37, "| $$ $$/$$ $$ /$$__  $$ /$$__  $$ |____  $$ /$$$$$$| $$ /$$__  $$ /$$__  $$    ");
	mvprintw((LINES / 2) - 7, (COLS / 2) - 37, "| $$  $$$| $$| $$$$$$$$| $$  \\ $$  /$$$$$$$|______/| $$| $$  \\__/| $$  \\ $$");
	mvprintw((LINES / 2) - 6, (COLS / 2) - 37, "| $$\\  $ | $$| $$_____/| $$  | $$ /$$__  $$        | $$| $$      | $$  | $$   ");
	mvprintw((LINES / 2) - 5, (COLS / 2) - 37, "| $$ \\/  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$        | $$| $$      |  $$$$$$/   ");
	mvprintw((LINES / 2) - 4, (COLS / 2) - 37, "|__/     |__/ \\_______/ \\____  $$ \\_______/        |__/|__/       \\______/ ");
	mvprintw((LINES / 2) - 3, (COLS / 2) - 37, "                        /$$  \\ $$                                             ");
	mvprintw((LINES / 2) - 2, (COLS / 2) - 37, "                       |  $$$$$$/                                              ");
	mvprintw((LINES / 2) - 1, (COLS / 2) - 37, "                        \\______/                                              ");
	mvprintw((LINES / 2), (COLS / 2) - 37, "===========================================================================    ");

	int o;
	char option;

	do {
		mvprintw((LINES / 2) + 3, (COLS / 2) - 14, "     -> NOVO JOGO (N)      ");
		mvprintw((LINES / 2) + 5, (COLS / 2) - 14, "-> Encerrar programa (Esc) ");

		option = getch();
		o = option;
	} while (o != 27 && o != 78 && o != 110);

	if (o == 27) {
		end();
	}
	else if (o == 27 || o == 110) {
		clear();
		mvprintw((LINES / 2) - 1, (COLS / 2) - 20, "-> Digite seu nome: ");
		curs_set(1);
		echo();
		refresh();
		getstr(name, 100);

		for (int i = 0; name[i] != '\0'; i++) {
			nameSize++;
		}

		eusabo = strcmp(name, sauber);
		if (eusabo == 0) {
			salber = 1;
		}
		if (eusabo == 1) {
			eusabo = strcmp(name, trapezio);
			if (eusabo == 0) {
				traps = 1;
			}
		}
		if (eusabo == 1) {
			eusabo = strcmp(name, bair);
			if (eusabo == 0) {
				jb = 1;
			}
		}

		do {
			echo();
			bet();

			if (eusabo == 0) {
				do {
					noecho();
					getyx(stdscr, row, col);
					move(row + 2, (COLS / 2) - 37);
					clearTerminal();
					printw("-> Fazer nova aposta (N)");
					getyx(stdscr, row, col);
					move(row + 1, (COLS / 2) - 37);
					printw("-> Encerrar programa (Esc)");
					getyx(stdscr, row, col);
					move(row + 1, (COLS / 2) - 37);
					printw("-> ? (?)");

					option = getch();
					o = option;
				} while (o != 27 && o != 78 && o != 110 && o != 63);

				if (o == 27) {
					c = 0;
					end();
				}
				else if (o == 63) {
					c = 0;
					clear();
					easteregg();
				}
			}
			else {
				do {
					noecho();
					getyx(stdscr, row, col);
					move(row + 2, (COLS / 2) - 37);
					clearTerminal();
					printw("-> Fazer nova aposta (N)");
					getyx(stdscr, row, col);
					move(row + 1, (COLS / 2) - 37);
					printw("-> Encerrar programa (Esc)");

					option = getch();
					o = option;
				} while (o != 27 && o != 78 && o != 110);

				if (o == 27) {
					c = 0;
					end();
				}
			}

		} while (c == 1);
	}
};