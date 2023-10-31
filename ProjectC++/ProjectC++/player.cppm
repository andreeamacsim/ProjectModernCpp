module;
import<string>;
import "Profile.h";


export module player;

export class Player 
{
public:
	Player();
	Player(std::string username, std::string password, Profile playerProfile);

	std::string getUsername();
	std::string getPassword();
	Profile getProfile();


	void setUsername(std::string username);
	void setPassword(std::string password);

private:
	std::string m_username;
	std::string m_password;
	Profile m_playerProfile;

};