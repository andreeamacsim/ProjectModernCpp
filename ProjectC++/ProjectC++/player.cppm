export module player;

import<string>;
import profile;
import PointsModule;
using game::Profile;
namespace game {

	export class Player
	{
	public:
		bool operator<(const Player& other) const {
			return m_username < other.m_username;
		}

		bool operator==(const Player& other) const {
			return m_username == other.m_username;
		}
		bool operator!=(const Player& other) const {
			return !(*this == other);
		}
		Player();
		Player(int16_t id, std::string username, std::string password, std::string email);

		std::string getEmail()const;
		std::string getUsername()const;
		std::string getPassword()const;
		int16_t getId() const;
		bool getGuessedWord();

		void setGuessedWord(bool guessedWord);
		void setId(int16_t id);
		void setEmail(std::string email);
		void setUsername(std::string username);
		void setPassword(std::string password);
		void checkPassword(const std::string& password);
		void checkEmail(const std::string& email);
		void checkUsername(const std::string& username);
		Points& getPointsObject();
		

	private:
		int16_t m_id;
		Points m_points;
		std::string m_email;
		std::string m_username;
		std::string m_password;
		bool m_guessedWord;
		

	};
}