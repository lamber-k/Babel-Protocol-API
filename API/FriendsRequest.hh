#ifndef FRIENDSREQUEST_H_
# define FRIENDSREQUEST_H_

#include	"ARequest.hh"
#include	"types.hh"

class	Protocol;

namespace	friends
{
    class	FriendsRequest : public ARequest
    {
	public:
	virtual ~FriendsRequest();

	virtual ARequest      *clone();
	virtual Protocol      &serialize(Protocol &)const;
	virtual Protocol      &unserialize(Protocol &);

	protected:
	FriendsRequest();
	FriendsRequest(const request::ID &);
    };

    namespace	client
    {
	class AskFriendRequest : public FriendsRequest
	{
	    public:
	    AskFriendRequest();
	    AskFriendRequest(const request::FromLen &, const request::From &,
			     const request::FromLen &, const request::From &);
	    AskFriendRequest(AskFriendRequest const&);
	    virtual ~AskFriendRequest();

	    public:
	    AskFriendRequest& operator=(AskFriendRequest const&);

	    ARequest      *clone();
	    Protocol      &serialize(Protocol &)const;
	    Protocol      &unserialize(Protocol &);

	    private:
	    request::FromLen		_fromLen;
	    request::From		_from;
	    request::FromLen		_toLen;
	    request::From		_to;
	};

	class DelFriendRequest : public FriendsRequest
	{
	    public:
	    DelFriendRequest();
	    DelFriendRequest(const request::FromLen &, const request::From &);
	    DelFriendRequest(DelFriendRequest const&);
	    virtual ~DelFriendRequest();

	    public:
	    DelFriendRequest& operator=(DelFriendRequest const&);

	    ARequest      *clone();
	    Protocol      &serialize(Protocol &)const;
	    Protocol      &unserialize(Protocol &);

	    private:
	    request::FromLen		_fromLen;
	    request::From		_from;
	};

	class AcceptRequest : public FriendsRequest
	{
	    public:
	    AcceptRequest(const request::FromLen &, const request::From &,
			  const request::FromLen &, const request::From &);
	    AcceptRequest(AcceptRequest const&);
	    virtual ~AcceptRequest();

	    public:
	    AcceptRequest& operator=(AcceptRequest const&);

	    ARequest      *clone();
	    Protocol      &serialize(Protocol &)const;
	    Protocol      &unserialize(Protocol &);

	    private:
	    request::FromLen		_fromLen;
	    request::From		_from;
	    request::FromLen		_toLen;
	    request::From		_to;
	};

	class RefuseRequest : public FriendsRequest
	{
	    public:
	    RefuseRequest(const request::FromLen &, const request::From &,
			  const request::FromLen &, const request::From &);
	    RefuseRequest(RefuseRequest const&);
	    virtual ~RefuseRequest();

	    public:
	    RefuseRequest& operator=(RefuseRequest const&);

	    ARequest      *clone();
	    Protocol      &serialize(Protocol &)const;
	    Protocol      &unserialize(Protocol &);

	    private:
	    request::FromLen		_fromLen;
	    request::From		_from;
	    request::FromLen		_toLen;
	    request::From		_to;
	};

	class ListRequest : public FriendsRequest
	{
	    public:
	    ListRequest();
	    ListRequest(ListRequest const&);
	    virtual ~ListRequest();

	    public:
	    ListRequest& operator=(ListRequest const&);

	    ARequest      *clone();
	};
    }

    namespace	server
    {
	class UpdateRequest : public FriendsRequest
	{
	    public:
	    UpdateRequest();
	    UpdateRequest(const request::UserNameLen &, const request::UserName &,
			  const request::Status &, const request::StatusDetailLen &,
			  const request::StatusDetail &);
	    UpdateRequest(UpdateRequest const&);
	    virtual ~UpdateRequest();

	    public:
	    UpdateRequest& operator=(UpdateRequest const&);

	    ARequest      *clone();
	    Protocol      &serialize(Protocol &)const;
	    Protocol      &unserialize(Protocol &);

	    const request::UserNameLen		&nameLen()const {return _nameLen;}
	    const request::UserName		&name()const {return _name;}
	    const request::Status		&status()const {return _status;}
	    const request::StatusDetailLen	&statusDetailLen()const {return _statusDetailLen;}
	    const request::StatusDetail		&statusDetail()const {return _statusDetail;}

	    private:
	    request::UserNameLen	_nameLen;
	    request::UserName		_name;
	    request::Status		_status;
	    request::StatusDetailLen	_statusDetailLen;
	    request::StatusDetail	_statusDetail;
	};
    }
}

#endif /* FRIENDSREQUEST_H_ */
