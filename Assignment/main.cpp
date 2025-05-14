#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <ranges>

using namespace std;

class Player {
public:
	Player() :id{}, score{}, num{} {}
	Player(const Player& other)  
		: name{other.name}, score{other.score}, id{other.id}, num{other.num}
	{
		p = std::make_unique<char[]>(num);
		memcpy(p.get(), other.p.get(), num);
	}
	Player& operator=(const Player& other) {
		if (this == &other)
			return *this;
		name = other.name;
		score = other.score;
		id = other.id;
		num = other.num;

		p.release();
		p = std::make_unique<char[]>(num);
		memcpy(p.get(), other.p.get(), num);

		return *this;
	}

	bool operator<(const Player& rhs) const {
		return id < rhs.id;
	}

	void sort() {
		std::sort(p.get(), p.get() + num);
	}

	// 'a'의 개수 리턴
	size_t CountA() {
		int cnt{};
		for (int i = 0; i < num; ++i) {
			if ('a' == p[i]) {
				++cnt;
			}
			else {
				// 이미 정렬되어있기 때문에 중단
				break;
			}
		}
		return cnt;
	}

	int GetScore() const { return score; }
	size_t GetID() const { return id; }
	string GetName() const { return name; }

	void write(ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}
	void read(istream& is) {
		is.read((char*)this, sizeof(Player));
		p.release();
		p = make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}

	friend ostream& operator<<(ostream& os, const Player& other) {
		os << "이름: " << other.name << ", 아이디: " << other.id << ", 점수: " << other.score
			<< ", 자원수: " << other.num << endl;
		os << "저장된 글자: ";
		for (int i = 0; i < other.num; ++i) {
			os << other.p[i];
		}
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
	ifstream in{ "2025 STL 과제 파일 - 2022180039", ios::binary };
	if (not in) {
		throw 2022180039;
	}

	// 1
	for (int i = 0; i < players.size(); ++i) {
		players[i].read(in);
	}
	cout << "마지막 player의 정보" << endl;
	cout << players.back() << endl;

	// 2
	cout << "가장 큰 점수를 가진 player\n" << *max_element(players.begin(), players.end()) << endl;
	//sort(players.begin(), players.end());
	//cout << players.back() << endl;

	double average = (double)accumulate(players.begin(), players.end(), 0, [](size_t sum, const Player& p) {
		return sum + p.GetScore();
		}) / players.size();
	cout << "score 평균 값: " << average << endl;
	cout << endl;

	// 3
	unordered_map<size_t, vector<Player>> equal_id;
	for (const Player& player : players) {
		equal_id[player.GetID()].push_back(player);
	}

	// 하나면 삭제
	for (auto it = equal_id.begin(); it != equal_id.end(); ) {
		if (it->second.size() == 1)
			it = equal_id.erase(it);
		else
			++it;
	}

	// 파일 출력
	/*ofstream out{ "같은아이디.txt" };
	for (const auto& [id, player] : equal_id) {
		for (const Player p : player) {
			out << "이름: " << p.GetName() << endl;
			out << "아이디: " << p.GetID() << endl;
		}
	}*/
	cout << "같은 아이디를 가진 객체의 개수: " << equal_id.size() << endl;
	cout << endl;

	// 4
	for (Player& player : players) {
		player.sort();
	}

	int cnt{};
	for (Player& player : players) {
		if (10 <= player.CountA()) {
			++cnt;
		}
	}

	cout << "'a'가 10글자 이상인 객체의 개수: " << cnt << endl;
	cout << endl;
}