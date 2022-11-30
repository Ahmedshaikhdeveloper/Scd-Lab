#include "Header.h"
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iomanip>
using namespace std;
using namespace sf;
void starting() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("start.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);
		
		window.display();
	}
}
void team::getteams(ifstream& teamfile, team teams[], int& i) {


	teamfile >> teams[i].name >> teams[i].ranking[0] >> teams[i].ranking[1] >> teams[i].ranking[2] >> teams[i].noplayers >> teams[i].won >> teams[i].lost >> teams[i].captain >> teams[i].coach;

}
void player::getplayer(ifstream& playerfile, player **players, int& i, int& j) {
	playerfile >> players[i][j].name >> players[i][j].shirt >> players[i][j].average >> players[i][j].ranking[0] >> players[i][j].ranking[1] >> players[i][j].ranking[2] >> players[i][j].totalruns >> players[i][j].experience >> players[i][j].wickets;
}
void team::displayteam(team teams[], int& i) {

	cout << left << setw(30);
	cout << left << setw(30) << teams[i].name << " " << teams[i].ranking[0] << "    " << teams[i].ranking[1] << "   " << teams[i].ranking[2] << "    " << teams[i].noplayers << "     " << teams[i].won << "     " << teams[i].lost << "              " << teams[i].captain << "          " << teams[i].coach << endl;

}
void player::displayplayer(player** player, int& i, int& j) {

	cout << left << setw(30)<< player[i][j].name << " "<<player[i][j].shirt<<"  "<<player[i][j].average <<"  "<< player[i][j].ranking[0] << "    " << player[i][j].ranking[1] << "   " << player[i][j].ranking[2] << "    " << player[i][j].totalruns << "     " << player[i][j].experience << "     " << player[i][j].wickets << "              " << endl;

}
void player::addplayer(player** player,int playerposition, int i,string playername) {
	player[i][playerposition].name = playername;
}
bool player ::searchplayer(player** players, string playername) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			if (playername == players[i][j].name) {
				return true;
			}
		}
	}
}
void player ::removeplayer(player** players, string playername) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			if (playername == players[i][j].name) {
				players[i][j].name ="-";
				players[i][j].shirt = 0;
				players[i][j].average = 0;
				players[i][j].ranking[0] = 0;
				players[i][j].ranking[1] = 0;
				players[i][j].ranking[2] = 0;
				players[i][j].totalruns = 0;
				players[i][j].experience = 0;
				players[i][j].wickets = 0;
			}
		}
	}
}
void player::updateplayer(player** players, string playername) {
	int shirt, avg, r1, r2, r3, run, exp, wic;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			if (playername == players[i][j].name) {
				cout << "\nplease enter his new shirt number: ";
				cin >> shirt;
				cout << "player new average: ";
				cin >> avg;
				cout << "player rank in t20: ";
				cin >> r1;
				cout << "player rank in odi: ";
				cin >> r2;
				cout << "player rank in test: ";
				cin >> r3;
				cout << "the total runs " << playername << " has made yet: ";
				cin >> run;
				cout << "enter how many matches has " << playername << " played yet: ";
				cin >> exp;
				cout << "enter total wickets he had taken in his career: ";
				cin >> wic;
				players[i][j].shirt = shirt;
				players[i][j].average = avg;
				players[i][j].ranking[0] = r1;
				players[i][j].ranking[1] = r2;
				players[i][j].ranking[2] = r3;
				players[i][j].totalruns = run;
				players[i][j].experience = exp;
				players[i][j].wickets = wic;
			}
		}
	}
}
void team::updatecaptain(team teams[],int& i) {
	string newcaptain;
	cout << "please enter the new captain: ";
	cin >> newcaptain;
	teams[i].captain = newcaptain;
}
void team::updatecoach(team teams[], int& i) 
{
	string newcoach;
	cout << "please enter the new couch: ";
	cin >> newcoach;
	teams[i].coach = newcoach;
}
void match::settteam(string a, string b) {
	team1 = a;
	team2 = b;
}
void match:: setschedule(string d, string v, string u, string c, string m) {
	date = d;
	 venue=v;
	matchtype=m;
	 commentators=c;
	 umpires=c;
}
void match::settournament(string d, string v, string u, string c, string m,string t) {
	date = d;
	venue = v;
	matchtype = m;
	commentators = c;
	umpires = c;
}
string match ::conductmatch(string a, string b, string c, string d,string e,string f){
	srand(time(NULL));
	int i = rand() % 6 + 1;
	if (i == 1) {
		if (a == "Pakistan") {
			pwon();
		}
		if (a == "India") {
			iwon();
		}
		if (a == "England") {
			ewon();
		}
		if (a == "Australia") {
			awon();
		}
		if (a == "Afganistan") {
			afwon();
		}
		if (a == "Windies") {
			wwon();
		}
		if (a == "NewZealand") {
			nwon();
		}
		if (a == "Srilanka") {
			swon();
		}
		if (a == "Bangladesh") {
			bwon();
		}
		if (a == "S.Africa") {
			sawon();
		}
		return a;
		
	}
	else if (i == 2) {
		if (b == "Pakistan") {
			pwon();
		}
		if (b == "India") {
			iwon();
		}
		if (b== "England") {
			ewon();
		}
		if (b == "Australia") {
			awon();
		}
		if (b == "Afganistan") {
			afwon();
		}
		if (b == "Windies") {
			wwon();
		}
		if (b == "NewZealand") {
			nwon();
		}
		if (b == "Srilanka") {
			swon();
		}
		if (b == "Bangladesh") {
			bwon();
		}
		if (b == "S.Africa") {
			sawon();
		}
		return b;
	}
	else if (i == 3) {
		if (c == "Pakistan") {
			pwon();
		}
		if (c == "India") {
			iwon();
		}
		if (c == "England") {
			ewon();
		}
		if (c == "Australia") {
			awon();
		}
		if (c == "Afganistan") {
			afwon();
		}
		if (c == "Windies") {
			wwon();
		}
		if (c == "NewZealand") {
			nwon();
		}
		if (c == "Srilanka") {
			swon();
		}
		if (c == "Bangladesh") {
			bwon();
		}
		if (c == "S.Africa") {
			sawon();
		}
		return c;
	}
	else if (i == 4) {
	if (d == "Pakistan") {
		pwon();
	}
	if (d == "India") {
		iwon();
	}
	if (d== "England") {
		ewon();
	}
	if (d== "Australia") {
		awon();
	}
	if (b == "Afganistan") {
		afwon();
	}
	if (d == "Windies") {
		wwon();
	}
	if (d== "NewZealand") {
		nwon();
	}
	if (d== "Srilanka") {
		swon();
	}
	if (d== "Bangladesh") {
		bwon();
	}
	if (d== "S.Africa") {
		sawon();
	}
		return d;
	}
	else if (i == 5) {
	if (e == "Pakistan") {
		pwon();
	}
	if (e == "India") {
		iwon();
	}
	if (e == "England") {
		ewon();
	}
	if (e== "Australia") {
		awon();
	}
	if (e == "Afganistan") {
		afwon();
	}
	if (e== "Windies") {
		wwon();
	}
	if (e == "NewZealand") {
		nwon();
	}
	if (e == "Srilanka") {
		swon();
	}
	if (e == "Bangladesh") {
		bwon();
	}
	if (e == "S.Africa") {
		sawon();
	}
		return e;
	}
	else if (i == 6) {
	if (f == "Pakistan") {
		pwon();
	}
	if (f == "India") {
		iwon();
	}
	if (f == "England") {
		ewon();
	}
	if (f == "Australia") {
		awon();
	}
	if (f == "Afganistan") {
		afwon();
	}
	if (f == "Windies") {
		wwon();
	}
	if (f == "NewZealand") {
		nwon();
	}
	if (f == "Srilanka") {
		swon();
	}
	if (f == "Bangladesh") {
		bwon();
	}
	if (f == "S.Africa") {
		sawon();
	}
		return f;
	}
}
string match::conductquick(string a, string b) {
	srand(time(NULL));
	date = "12 july";
	if (b == "England") {
		venue = "Lords";
	}
	matchtype = "odi";
	commentators = "danny morrison";
	umpires = "Aleem dar";
	int i = rand() % 2 + 1;
	if (i == 1) {
		return a;
	}
	else if (i == 2) {
		return b;
	}
}
void match::checkteam(string a, string b) {
	if (a == "Pakistan" && b == "Inida"||a=="India"&&b=="Pakistan") {
		pi();
	}
	else if (a == "Pakistan" && b == "England"||a=="England"&&b=="Pakistan") {
		pe();
	}
	else if (a == "Pakistan" && b == "Australia"||a=="Australia"&&b=="Pakistan") {
		pa();
	}
	else if (a == "Pakistan" && b == "NewZealand"||a=="NewZealan"&&b=="Pakistan") {
		pn();
	}
	else if (a == "Pakistan" && b == "Afganistan"||a=="Afganistan"&&b=="Pakistan") {
		pa();
	}
	else if (a == "Pakistan" && b == "Srilanka"||a=="Srilanka"&&b=="Pakistan") {
		psl();
	}
	else if (a == "Pakistan" && b == "Bangladesh"||a=="Bangladesh"&&b=="Pakistan") {
		pb();
	}
	else if (a == "Pakistan" && b == "S.Africa"||a=="S.Africa"&&b=="Pakistan") {
		psa();
	}
	else if (a == "Pakistan" && b == "Windies"||a=="Windies"&&b=="Pakistan") {
		pw();
	}
	else if (a == "England" && b == "India" || a == "India"&&b=="England") {
		ei();
	}
	else if (a == "England" && b == "Australia" || a == "Australia"&&b=="England") {
		ea();
	}
	else if (a == "England" && b == "Newzealand" || a == "NewZealand" && b == "England") {
		en();
	}
	else if (a == "England" && b == "Bangladesh" || a == "Bangladesh" && b == "England") {
		eb();
	}
	else if (a == "England" && b == "Srilanka" || a == "Srilanka" && b == "England") {
		es();
	}
	else if (a == "England" && b == "S.Africa" || a == "S.Africa" && b == "England") {
		esa();
	}
	else if (a == "England" && b == "Windies" || a == "Windies" && b == "England") {
		ew();
	}
	else if (a == "England" && b == "Afganistan" || a == "Afganistan" && b == "England") {
		eaf();
	}
	else if (a == "India" && b == "Australia" || a == "Australia" && b == "India") {
		ia();
	}
	else if (a == "India" && b == "NewZealand" || a == "NewZealand" && b == "India") {
		in();
	}
	else if (a == "India" && b == "Windies" || a == "Windies" && b == "India") {
		iw();
	}
	else if (a == "India" && b == "Srilanka" || a == "Srilanka" && b == "India") {
		is();
	}
	else if (a == "India" && b == "Bangladesh" || a == "Bangladesh" && b == "India") {
		ib();
	}
	else if (a == "India" && b == "S.Africa" || a == "S.Africa" && b == "India") {
		is();
	}
	else if (a == "India" && b == "Afganistan" || a == "Afganistan" && b == "India") {
		iaf();
	}
	
	else if (a == "Australia" && b == "NewZealand" || a == "NewZealand" && b == "Australia") {
		an();
	}
	else if (a == "Australia" && b == "Windies" || a == "Windies" && b == "Australia") {
		aw();
	}
	else if (a == "Australia" && b == "Srilanka" || a == "Srilanka" && b == "Australia") {
		as();
	}
	else if (a == "Australia" && b == "Bangladesh" || a == "Bangladesh" && b == "Australia") {
		ab();
	}
	else if (a == "Australia" && b == "S.Africa" || a == "S.Africa" && b == "Australia") {
		as();
	}
	else if (a == "Australia" && b == "Afganistan" || a == "Afganistan" && b == "Australia") {
		aaf();
	}
	else if (a == "NewZealand" && b == "Windies" || a == "Windies" && b == "NewZaland") {
		nw();
	}
	else if (a == "NewZealand" && b == "Srilanka" || a == "Srilanka" && b == "NewZaland") {
		ns();
	}
	else if (a == "NewZealand" && b == "Bangladesh" || a == "Bangladesh" && b == "NewZaland") {
		ns();
	}
	else if (a == "NewZealand" && b == "S.Africa" || a == "S.Africa" && b == "NewZaland") {
		nsa();
	}
	else if (a == "NewZealand" && b == "Afganistan" || a == "Afganistan" && b == "NewZaland") {
		naf();
	}
	else if (a == "Windies" && b == "Srilanka" || a == "" && b == "Srilanka") {
		ws();
	}
	else if (a == "Windies" && b == "Bangladesh" || a == "Bangladesh" && b == "Windies") {
		wb();
	}
	else if (a == "Windies" && b == "Afganistan" || a == "Afganistan" && b == "Windies") {
		waf();
	}
	else if (a == "Srilanka" && b == "Bangladesh" || a == "Bangladesh" && b == "Srilanka") {
		sb();
	}
	else if (a == "Srilanka" && b == "Afganistan" || a == "Afganistan" && b == "Srilanka") {
		saf();
	}
	else if (a == "Srilanka" && b == "S.Africa" || a == "S.Africa" && b == "Srilanka") {
		ssa();
	}
	else if (a == "Banlgadesh" && b == "Afganistan" || a == "Afganistan" && b == "Bangladesh") {
		baf();
	}
	else if (a == "Banlgadesh" && b == "S.Africa" || a == "S.Africa" && b == "Bangladesh") {
		bsa();
	}
	else if (a == "Afganistan" && b == "S.Africa" || a == "S.Africa" && b == "Afganistan") {
		asa();
	}

}
void player::updateworldrecord(player **players,int& i, string& mostruns, string& mostsixes, string& mostfours, string& mostcenturies, string& highestaverage, string& mostwickets) {
	 mostruns=players[i][0].name;
	 mostsixes = players[i][3].name;
	 mostfours = players[i][1].name;
	 mostcenturies = mostruns;
	 highestaverage = mostruns;
	 mostwickets = players[i][10].name;

}
void team::updateteamranking(team teams[],int i) {
	teams[i].ranking[1]++;
}
void player::updateplayerranking(player** players,int i) {
	for (int j = 0; j < 11; j++) {
		players[i][j].ranking[1]++;
	}
}
void login() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("login.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void add() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("add.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void found() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("found.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void remove() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("remove.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void update() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("update.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void captain() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("captain.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void coach() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("coach.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t1() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t1.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t2() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t2.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t3() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t3.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t4() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t4.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t5() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t5.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t6() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t6.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t7() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t7.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t8() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t8.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t9() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t9.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void t10() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("t10.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m1() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m1.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m2() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m2.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m3() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m3.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m4() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m4.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m5() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m5.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m6() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m6.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m7() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m7.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m8() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m8.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m9() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m9.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void m10() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("m10.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pwon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pwon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void iwon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("iwon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ewon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ewon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void awon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("awon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void afwon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("afwon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void nwon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("nwon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void bwon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("bwon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void swon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("swon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void sawon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("sawon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void wwon() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("wwon.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pa(){
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pi() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pi.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pe(){
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pe.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pb(){
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pb.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void paf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("paf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pw() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pw.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void psl() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("psl.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void psa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("psa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void pn() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("pn.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}

}

void ea() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ea.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void eaf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("eaf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void eb() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("eb.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ei() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ei.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void en() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("en.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void es() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("es.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void esa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("esa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ew() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ew.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void ia() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ia.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void iaf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("iaf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ib() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ib.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void in() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("in.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void is() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("is.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void isa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("isa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void iw() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("iw.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void aaf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("aaf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ab() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ab.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void as() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("as.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void an() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("an.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void aw() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("aw.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void naf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("naf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void nb() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("nb.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ns() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ns.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void nsa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("nsa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void nw() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("nw.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void waf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("waf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void wb() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("wb.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ws() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ws.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void wsa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("wsa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void saf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("saf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void sb() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("sb.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void ssa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("ssa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void baf() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("baf.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}
void bsa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("bsa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void asa() {
	RenderWindow window(VideoMode(800, 750), "SFML works!");

	RectangleShape sound_Button(Vector2f(800.0f, 750.0f));
	sound_Button.setPosition(10.0, 20.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("asa.png");
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}