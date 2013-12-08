#ifndef AUTHREQUEST_H_
# define AUTHREQUEST_H_

#include	"ARequest.hh"
#include	"types.hh"

class	Protocol;

namespace	auth
{
    class AuthRequest : public ARequest
    {
	public:
	virtual ~AuthRequest();

	public:
	virtual ARequest      *clone();
	virtual Protocol      &serialize(Protocol &)const;
	virtual Protocol      &unserialize(Protocol &);

	protected:
	AuthRequest();
	AuthRequest(const request::ID &);
    };

    class NewClientRequest : public AuthRequest
    {
	public:
	NewClientRequest();
	NewClientRequest(const request::UserNameLen &, const request::UserName &,
			 const request::PasswordType &, const request::Privacy &);
	NewClientRequest(NewClientRequest const&);
	virtual ~NewClientRequest();

	public:
	NewClientRequest& operator=(NewClientRequest const&);

	ARequest      *clone();
	Protocol      &serialize(Protocol &)const;
	Protocol      &unserialize(Protocol &);

	const request::UserNameLen	&nameLen()const {return _nameLen;}
	const request::UserName		&name()const {return _name;}
	const request::PasswordType	&passwd()const {return _passwd;}
	const request::Privacy		&privacy()const {return _privacy;}

	private:
	request::UserNameLen	_nameLen;
	request::UserName		_name;
	request::PasswordType	_passwd;
	request::Privacy		_privacy;
    };

    class DelClientRequest : public AuthRequest
    {
	public:
	DelClientRequest();
	DelClientRequest(const request::UserNameLen &, const request::UserName &,
			 const request::PasswordType &);
	DelClientRequest(DelClientRequest const&);
	virtual ~DelClientRequest();

	public:
	DelClientRequest& operator=(DelClientRequest const&);

	ARequest      *clone();
	Protocol      &serialize(Protocol &)const;
	Protocol      &unserialize(Protocol &);

	const request::UserNameLen	&nameLen()const {return _nameLen;}
	const request::UserName		&name()const {return _name;}
	const request::PasswordType	&passwd()const {return _passwd;}

	private:
	request::UserNameLen	_nameLen;
	request::UserName		_name;
	request::PasswordType	_passwd;
    };

    class ModifyClientRequest : public AuthRequest
    {
	public:
	ModifyClientRequest();
	ModifyClientRequest(const request::UserNameLen &, const request::UserName &,
			    const request::PasswordType &, const request::PasswordType &);
	ModifyClientRequest(ModifyClientRequest const&);
	virtual ~ModifyClientRequest();

	public:
	ModifyClientRequest& operator=(ModifyClientRequest const&);

	ARequest      *clone();
	Protocol      &serialize(Protocol &)const;
	Protocol      &unserialize(Protocol &);

	const request::UserNameLen	&nameLen()const {return _nameLen;}
	const request::UserName		&name()const {return _name;}
	const request::PasswordType	&oldPasswd()const {return _oldPasswd;}
	const request::PasswordType	&newPasswd()const {return _newPasswd;}

	private:
	request::UserNameLen	_nameLen;
	request::UserName	_name;
	request::PasswordType	_oldPasswd;
	request::PasswordType	_newPasswd;
    };

    class ConnectRequest : public AuthRequest
    {
	public:
	ConnectRequest();
	ConnectRequest(const request::UserNameLen &, const request::UserName &,
		       const request::PasswordType &);
	ConnectRequest(ConnectRequest const&);
	virtual ~ConnectRequest();

	public:
	ConnectRequest& operator=(ConnectRequest const&);

	ARequest      *clone();
	Protocol      &serialize(Protocol &)const;
	Protocol      &unserialize(Protocol &);

	const request::UserNameLen	&nameLen()const {return _nameLen;}
	const request::UserName		&name()const {return _name;}
	const request::PasswordType	&passwd()const {return _passwd;}

	private:
	request::UserNameLen	_nameLen;
	request::UserName	_name;
	request::PasswordType	_passwd;
    };

    class DisconnectRequest : public AuthRequest
    {
	public:
	DisconnectRequest();
	DisconnectRequest(DisconnectRequest const&);
	virtual ~DisconnectRequest();

	public:
	DisconnectRequest& operator=(DisconnectRequest const&);

	ARequest      *clone();
    };
}

#endif /* AUTHREQUEST_H_ */
