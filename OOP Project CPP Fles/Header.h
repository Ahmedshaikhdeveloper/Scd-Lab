#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class player {       
protected:
	string name;
	int shirt;
	double average;
	int ranking[3];
	int totalruns;
	int experience;
	int wickets;
public:
	
	 void addplayer(player**players,int playerpostion,int i,string playername);
	 void removeplayer(player** players,string playername);
	 bool searchplayer(player**player,string playername);
	 void updateplayer(player** player,string playername);
	 void getplayer(ifstream& teamfile, player** players, int& i, int& j);
	 void displayplayer(player** players, int& i, int& j);
	 void updateworldrecord(player** players, int& i, string& mostruns, string& mostsixes, string& mostfours, string& mostcenturies, string& highestaverage, string& mostwickets);
	 void updateplayerranking(player** players,int i);
};
class team :public player {
protected:
	string name;
	int ranking[3];
	int noplayers;
	int won;
	int lost;
	string captain;
	string coach;
	string adminusername;
	int password;
public:
	team() {
		adminusername = "1";
		password = 1;
	}

	void getteams(ifstream& teamfile, team teams[], int& i);
	void addplayer();
	void removeplayer();
	bool searchplayer();
	void updateplayer();
	void displaymatches();
	void updateteamranking(team teams[], int i);

	
	void updatecaptain(team teams[],int& i );
	void updatecoach(team teams[],int &i);
	void displayteam(team teams[], int& i);
	string getusername() {
		return adminusername;
	}
	int getpass() {
		return password;
	}
	string getname(int i) {
		if (i == 0) {
			return "Pakistan";
		}
		if (i == 1) {
			return "India";
		}
		if (i == 2) {
			return "England";
		}
		if (i == 3) {
			return "Austrailia";
		}
		if (i == 4) {
			return "S.Africa";
		}
		if (i == 5) {
			return "Srilanka";
		}
		if (i == 6) {
			return "Bangladesh";
		}
		if (i == 7) {
			return "Windies";
		}
		if (i == 8) {
			return "Afganistan";
		}
		if (i == 7) {
			return "NewZealand";
		}
	
	}

};
class match {
protected:
	string team1;
	string team2;
	string date;
	string venue;
	string matchtype;
	string tournamentname;
	string commentators;
	string umpires;
	string matchstatus;
public:
	string conductmatch(string,string,string,string,string,string);
	string conductquick(string, string);
	void checkteam(string, string);
	void schedulematch();
	

	void displayupcomingmatches();
	void displayrecentmatches();
	void settteam(string a,string b);
	void setschedule(string d, string v, string u, string c, string m);
	void settournament(string d, string v, string u, string c, string m,string t);
	

};
void updateworldrecord(player **players,int& i, string& mostruns, string& mostsixes, string& mostfours, string& mostcenturies, string& highestaverage, string& mostwickets);
void starting(); 
void login();
void add();
void found();
void remove();
void update();
void captain();
void coach();
void t1();
void t2();
void t3();
void t4();
void t5();
void t6();
void t7();
void t8();
void t9();
void t10();
void m1();
void m2();
void m3();
void m4();
void m5();
void m6();
void m7();
void m8();
void m9();
void m10();
void pwon();
void iwon();
void ewon();
void swon();
void sawon();
void afwon();
void wwon();
void bwon();
void awon();
void nwon();
void pa();
void pi();
void pe();
void pb();
void paf();
void pw();
void psl();
void psa();
void pn();

void ea();
void eaf();
void eb();
void ei();
void en();
void es();
void esa();
void ew();

void ia();
void iaf();
void ib();
void in();
void is();
void isa();
void iw();

void aaf();
void ab();
void as();
void an();
void asa();
void aw();

void naf();
void nb();
void ns();
void nsa();
void nw();

void waf();
void wb();
void ws();
void wsa();

void saf();
void sb();
void ssa();

void baf();
void bsa();

void asa();