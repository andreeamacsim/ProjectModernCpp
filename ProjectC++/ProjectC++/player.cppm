module;
import<string>;
import profile;


export module player;

export class Player 
{
public:
	Player();
	Player(std::string email,std::string username, std::string password, Profile playerProfile);

	std::string getEmail()const;
	std::string getUsername()const;
	std::string getPassword()const;
	Profile getProfile() const;


	void setEmail(std::string email);
	void setUsername(std::string username);
	void setPassword(std::string password);
	void checkPassword(const std::string& password);
	void checkEmail(const std::string& email);
	void checkUsername(const std::string& username);
	bool isUsernameUnique(const std::string& username);

private:
	std::string m_email;
	std::string m_username;
	std::string m_password;
	Profile m_playerProfile;

};