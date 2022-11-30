#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <iomanip>
#include "Header.h"
using namespace std;
using namespace sf;
int main() {
	starting();
	team teams [10];
	ifstream teamfile;
	teamfile.open("teams.txt");
	for (int i = 0; i < 10; i++) {
		teams[i].getteams(teamfile, teams, i);
	}
	
	player** players= new player * [10];
	for (int i = 0; i < 10; i++) {
		players[i] = new player [15];
	}
	ifstream playerfile;
	playerfile.open("players.txt");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			players[i][j].getplayer(playerfile, players, i, j);
		}
	}
	string id;
	int pass;
	cout << "*******************************************************************************\n";
	cout << "******************************* C R I C B U Z Z *******************************\n\n";

	cout << "please enter ID and password to coontinue: ";
	cin >> id;
	cout << "\nenter password: ";
	cin >> pass;
	if (pass == teams[0].getpass() && id == teams[0].getusername()) {
		cout << "you have logged in sucsessfully\n";
		login();
		bool appexit = true;
		while (appexit == true) {
			bool flag = false;
			while (flag == false) {
				int choice;
				string teamname, playername;
				cout << "what do you want to do!\n\t\t\t1 add player \n\t\t\t2 search player \n\t\t\t3 remove player\n\t\t\t4 update player\n\t\t\t5 update captain\n\t\t\t6 update coach\n\t\t\t7 display team\n\t\t\t0 Do nothing !\n";
				cin >> choice;
				int playerposition = 12;
				switch (choice) {
				case 1: {
					cout << "which team ?\n";
					cin >> teamname;
					for (int i = 0; i < 10; i++) {
						if (teams[i].getname(i) == teamname) {
							cout << "please enter player name\n";
							cin >> playername;
							players[i][playerposition].addplayer(players, playerposition, i, playername);
							add();
							cout << playername << " is added in " << teams[i].getname(i) << " team\n";
						}
					}
					break;
				}
				case 2: {
					cout << "please enter the player name for search\n";
					cin >> playername;
					if (players[0][0].searchplayer(players, playername) == true) {
						cout << "player found !!";
						found();
					}
					else cout << "player not found !!\n";
					break;
				}
				case 3: {
					cout << "please enter the player you want to remove\n";
					cin >> playername;
					if (players[0][0].searchplayer(players, playername) == true) {
						cout << "player found !!\n";
						found();
						players[0][0].removeplayer(players, playername);
						remove();
						cout << "player removed success\n";
					}
					else cout << "player not found !!\n";
					break;
				}
				case 4:
				{
					cout << "please enter the name of the player you want to update his stats\n";
					cin >> playername;
					if (players[0][0].searchplayer(players, playername) == true) {
						cout << "player found !!\n";
						found();
						players[0][0].updateplayer(players, playername);
						update();
					}
					else cout << "player not found\n";
					break;
				}
				case 5: {
					cout << "From which team you want to update captain: ";
					cin >> teamname;
					for (int i = 0; i < 10; i++) {
						if (teams[i].getname(i) == teamname) {
							teams[i].updatecaptain(teams, i);
							cout << "captain of " << teamname << " updated successfuly\n";
							captain();
						}

					}
					break;
				}
				case 6: {
					cout << "From which team you want to update coach: ";
					cin >> teamname;
					for (int i = 0; i < 10; i++) {
						if (teams[i].getname(i) == teamname) {
							teams[i].updatecoach(teams, i);
							cout << "couch of " << teamname << " updated successfuly\n";
							coach();
						}

					}
					break;
				}
				case 7: {
					int tchoice;
					cout << "please enter which team you want to see\n1 pakistan\t\t\t\t2 India\n3 England\t\t\t\t4 NewZealand\n5 Australia\t\t\t\t6 Sri Lanka\n7 South Africa \t\t\t\t8 Bangladesh\n9 Afghanistan\t\t\t\t10 Windies\n";
					cin >> tchoice;
					if (tchoice == 1) {
						t1();
					}
					else if (tchoice == 2) {
						t2();
					}
					else if (tchoice == 3) {
						t3();
					}
					else if (tchoice == 4) {
						t4();
					}
					else if (tchoice == 5) {
						t5();
					}
					else if (tchoice == 6) {
						t6();
					}
					else if (tchoice == 7) {
						t7();
					}
					else if (tchoice == 8) {
						t8();
					}
					else if (tchoice == 9) {
						t9();
					}
					else if (tchoice == 10) {
						t10();
					}

					else cout << "wrong input\n";
					break;
				}
				case 8: {

				}
				case 0: {
					flag = true;
				}


				}
				int loop;
				cout << "Enter 1 if you want to do anything else before moving forward\nenter any kry to move forward\n";
				cin >> loop;
				if (loop != 1) {
					flag = true;
				}
			}
			match single, tournament[3];
			string mostruns, mostsixes, mostfours, mostcenturies, highestaverage, beststrikerate, mostwickets;
			int highestscore;
			int choice;
			string teama, teamb, teamc, teamd, teame, teamf, date, venue, umpire, commentator, matchtype;
			cout << "Cricbuzz allows many features for the user like :-\n\t1. conduct match\n\t2. display upcoming matches and recent matches\n\twhat do you want to do press respected input\n ";
			cin >> choice;
			switch (choice) {
			case 1: {
				int conduct;
				cout << "Dear user!\n\tDo you want to conduct an already schedule match or schedule a new match?\npress 1 or conduct or press 2 for schedule\n";
				cin >> conduct;
				if (conduct == 1) {
					int quickchoice;
					cout << "you have choosen to conduct match\n";
					cout << "1. Paistan vs England in england\n";
					cout << "2. SriLanka vs India in India\n";
					cout << "3. Australia vs NewZealand\n";
					cout << "4. West Indies vs Australia\n";
					cout << "5. England vs Srilanka\n";
					cin >> quickchoice;
					switch (quickchoice) {
					case 1: {
						pe();
						cout << "match has been done ";
						string an = single.conductquick("Pakistan", "England");
						cout << single.conductquick("Pakistan", "England") << " won the match\n";
						if (single.conductquick("Pakistan", "England") == "Pakistan") {
							pwon();
						}
						else ewon();
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "Team ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}


						break;
					}
					case 2: {
						is();
						string an = single.conductquick("Srilanka", "India");
						cout << "match has been done ";
						cout << single.conductquick("Srilanka", "India") << " won the match\n";
						if (single.conductquick("Srilanka", "India") == "India") {
							iwon();
						}
						else swon();
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "Team ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}
						break;
					}
					case 3: {
						an();
						string an = single.conductquick("Australia", "NewZealand");
						cout << "match has been done ";
						cout << single.conductquick("Australia", "NewZealand") << " won the match\n";
						if (single.conductquick("Australia", "NewZealand") == "Australia") {
							awon();
						}
						else nwon();
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "Team ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}
						break;
					}
					case 4: {
						aw();
						string an = single.conductquick("Windies", "Australia");
						cout << "match has been done ";
						cout << single.conductquick("Windies", "Australia") << " won the match\n";
						if (single.conductquick("Windies", "Australia") == "Windies") {
							wwon();
						}
						else awon();
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "Team ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}
						break;
					}
					case 5: {
						es();
						string an = single.conductquick("England", "Srilanka");
						cout << "match has been done ";
						cout << single.conductquick("England", "Srilanka") << " won the match\n";
						if (single.conductquick("England", "Srilanka") == "England") {
							ewon();
						}
						else swon();
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "Team ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}
						break;
					}
					}
				}
				if (conduct == 2) {
					int type;
					cout << "please enter 1 if you want to schedule a quick match\nplease enter 2 for the whole tournament\n ";
					cin >> type;
					if (type == 1) {
						cout << "please enter team 1: ";
						cin >> teama;
						cout << "\nplease enter team 2: ";
						cin >> teamb;
						single.settteam(teama, teamb);
						cout << "\nplease enter the date: ";
						cin >> date;
						cout << "\nplease enter venue\navailavble venues are LORDS (england),MCG (austrailia),chinnaswami (india): ";
						cin >> venue;
						cout << "\nplease enter umpire name for the (ICC ELITE PANEL REQUIRED): ";
						cin >> umpire;
						cout << "\nplease enter the name of commentator: ";
						cin >> commentator;
						cout << "\nplease enter match type ...t20...ODI...TEST: ";
						cin >> matchtype;
						single.checkteam(teama, teamb);
						single.setschedule(date, venue, umpire, commentator, matchtype);
						string an = single.conductquick(teama, teamb);
						cout << "match has been done ";
						cout << single.conductquick(teama, teamb) << " won the match\n";
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "Team ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}
					}
					else if (type == 2) {
						string ta, tb;
						cout << "you have selected a tournament\m";
						cout << "enter team 1: ";
						cin >> ta;
						cout << "enter team 2: ";
						cin >> tb;
						tournament[0].settteam(teama, teamb);
						cout << "enter team 3: ";
						cin >> teamc;
						cout << "enter team 4: ";
						cin >> teamd;
						tournament[1].settteam(teamc, teamd);
						cout << "enter team 5: ";
						cin >> teame;
						cout << "enter team 6: ";
						cin >> teamf;
						tournament[2].settteam(teame, teamf);
						single.checkteam(ta, tb);
						single.checkteam(teamc, teamd);
						single.checkteam(teame, teamf);
						tournament[0].settournament("9 june 2020", "Lords", "Aleem Dar", "Ramiz Raja", "ODI", "world_cup");
						tournament[1].settournament("10 june 2020", "MCG", "Tony Hill", "Sanghakara", "ODI", "world_cup");
						tournament[2].settournament("12 june 2020", "Chinnaswami", "Wilson", "Dany", "ODI", "world_cup");
						cout << tournament[0].conductmatch(teama, teamb, teamc, teamd, teame, teamf) << " have won the tournament they are champions!!\n";
						string an = tournament[0].conductmatch(teama, teamb, teamc, teamd, teame, teamf);
						for (int i = 0; i < 10; i++) {
							if (teams[i].getname(i) == an) {
								players[0][0].updateworldrecord(players, i, mostruns, mostsixes, mostfours, mostcenturies, highestaverage, mostwickets);
								cout << "most runs: " << mostruns << endl;
								cout << "Most sixes: " << mostsixes << endl;
								cout << "Most fours: " << mostfours << endl;
								cout << "Most centuries: " << mostruns << endl;
								cout << "Highest average: " << mostruns << endl;
								cout << "Most wickets: " << mostwickets << endl;
								teams[i].updateteamranking(teams, i);
								cout << "\nTeam ranking has been updated! \n";
								players[i][0].updateplayerranking(players, i);
								cout << "player ranking has been updated!\n";
							}
						}
					}
				}
				break;
			}
			case 2: {
				int tchoice;
				cout << "please enter which team schedule you want to see\n1 pakistan\t\t\t\t2 India\n3 England\t\t\t\t4 NewZealand\n5 Australia\t\t\t\t6 Sri Lanka\n7 South Africa \t\t\t\t8 Bangladesh\n9 Afghanistan\t\t\t\t10 Windies\n";
				cin >> tchoice;
				if (tchoice == 1) {
					m1();
				}
				else if (tchoice == 2) {
					m2();
				}
				else if (tchoice == 3) {
					m3();
				}
				else if (tchoice == 4) {
					m4();
				}
				else if (tchoice == 5) {
					m5();
				}
				else if (tchoice == 6) {
					m6();
				}
				else if (tchoice == 7) {
					m7();
				}
				else if (tchoice == 8) {
					m8();
				}
				else if (tchoice == 9) {
					m9();
				}
				else if (tchoice == 10) {
					m10();
				}

				else cout << "wrong input\n";


			}
				  break;
			}
			int Exit;
			cout << "Do you want to stay at the app? press 1\npress any key to exit!\n ";
			cin >> Exit;
			if (Exit != 1) {
				return false;
			}

		}
	}
	
	return 0;
}