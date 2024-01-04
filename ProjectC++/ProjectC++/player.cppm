export module player;

import<string>;
import profile;
using game::Profile;
namespace game {

	export class Player
	{
	public:
		Player();
		Player(uint16_t id, std::string username, std::string password, std::string email);

		std::string getEmail()const;
		std::string getUsername()const;
		std::string getPassword()const;
		uint16_t getId() const;


		void setId(uint16_t id);
		void setEmail(std::string email);
		void setUsername(std::string username);
		void setPassword(std::string password);
		void checkPassword(const std::string& password);
		void checkEmail(const std::string& email);
		void checkUsername(const std::string& username);
		bool isUsernameUnique(const std::string& username);

	private:
		uint16_t m_id;
		std::string m_email;
		std::string m_username;
		std::string m_password;

	};
}