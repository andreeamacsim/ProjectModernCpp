export module player;

import<string>;
import profile;
using game::Profile;
namespace game {

	export class Player
	{
	public:
		Player();
		Player(int id, std::string username, std::string password, std::string email);

		std::string getEmail()const;
		std::string getUsername()const;
		std::string getPassword()const;
		int getId() const;
		//Profile getProfile() const;


		void setId(int id);
		void setEmail(std::string email);
		void setUsername(std::string username);
		void setPassword(std::string password);
		void checkPassword(const std::string& password);
		void checkEmail(const std::string& email);
		void checkUsername(const std::string& username);
		bool isUsernameUnique(const std::string& username);

	private:
		int m_id;
		std::string m_email;
		std::string m_username;
		std::string m_password;
		//Profile m_playerProfile;

	};
}