#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <array>

using namespace std;

class Player {
public:
	void write(ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}
	void read(istream& is) {
		/*1번 객체 이름 : tbgkdyf, 아이디 : 1585002, 점수 : 225936740, 자원수 : 482
		2번 객체 이름 : ebodemiipwcovky, 아이디 : 960538, 점수 : 353919937, 자원수 : 231
		3번 객체 이름 : bupee, 아이디 : 250535, 점수 : 275456330, 자원수 : 16
		4번 객체 이름 : bwdgnvrstnxo, 아이디 : 2221181, 점수 : 22271892, 자원수 : 269
		5번 객체 이름 : hnln, 아이디 : 550535, 점수 : 276748627, 자원수 : 245
		6번 객체 이름 : dvrlgaiqnnmtqe, 아이디 : 2296425, 점수 : 226278669, 자원수 : 426
		7번 객체 이름 : rnfsutjmxth, 아이디 : 1699554, 점수 : 205153856, 자원수 : 32
		8번 객체 이름 : hqqkntxtbcuxu, 아이디 : 1956483, 점수 : 278670016, 자원수 : 282
		9번 객체 이름 : vcoyimkqeyohal, 아이디 : 2012612, 점수 : 380493315, 자원수 : 358*/

		is.read((char*)this, sizeof(Player));
		p = make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}

	friend ostream& operator<<(ostream& os, const Player& other) {
		os << "이름: " << other.name << ", 아이디: " << other.id << ", 점수: " << other.score
			<< ", 자원수: " << other.num << endl;
		os << "저장된 글자: ";
		/*for (int i = 0; i < other.num; ++i) {
			os << other.p[i];
		}*/
		os << endl;
		return os;
	}
private:
	string name; // 이름, 길이[3, 15],  ['a', 'z']로만 구성
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	unique_ptr<char[]> p; // free store에 확보한 메모리
};


array<Player, 2'500'000> players;

int main()
{
	ifstream in{ "2025 STL 과제 파일 - 2022180039", ios::binary};
	if (not in) {
		throw 2022180039;
	}

	for (int i = 0; i < players.size(); ++i) {
		players[i].read(in);
	}

	for (const Player& player : players) {
		cout << player << endl;
	}
}