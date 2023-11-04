module;
import<string>;
import profile;


export module player;

export class Player 
{
public:
	Player();
	Player(std::string username, std::string password, Profile playerProfile);

	std::string getUsername()const;
	std::string getPassword()const;
	Profile getProfile() const;


	void setUsername(std::string username);
	void setPassword(std::string password);

private:
	std::string m_username;
	std::string m_password;
	Profile m_playerProfile;

};