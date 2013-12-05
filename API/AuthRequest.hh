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

	private:
	request::UserNameLen	_nameLen;
	request::UserName		_name;
	request::PasswordType	_oldpasswd;
	request::PasswordType	_newpasswd;
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

	private:
	request::UserNameLen	_nameLen;
	request::UserName		_name;
	request::PasswordType	_passwd;
    };

    class DiconnectRequest : public AuthRequest
    {
	public:
	DiconnectRequest();
	DiconnectRequest(DiconnectRequest const&);
	virtual ~DiconnectRequest();

	public:
	DiconnectRequest& operator=(DiconnectRequest const&);

	ARequest      *clone();
    };
}

#endif /* AUTHREQUEST_H_ */
