#ifndef CALLREQUEST_H_
# define CALLREQUEST_H_

#include	"ARequest.hh"
#include	"types.hh"

namespace	call
{
    class CallRequest
    {
	public:
	virtual ~Callrequest();

	virtual ARequest	*clone();
	virtual Protocol	&serialize(Protocol &)const;
	virtual Protocol	&unserialize(Protocol &);

	protected:
	CallRequest();
	CallRequest(const request::ID &);
    };

    namespace	client
    {
	class CallsRequest : public CallRequest
	{
	    public:
	    CallsRequest();
	    CallsRequest(const request::Options &,
			 const request::FromLen &, const request::From &,
			 const request::FromLen &, const request::From &);
	    CallsRequest(CallsRequest const&);
	    virtual ~CallsRequest();

	    public:
	    CallsRequest& operator=(CallsRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    protected:
	    request::Options	_option;
	    request::FromLen	_fromLen;
	    request::From	_from;
	    request::FromLen	_toLen;
	    request::From	_to;
	};

	class AcceptRequest : public CallRequest
	{
	    public:
	    AcceptRequest();
	    AcceptRequest(const request::FromLen &, const request::From &,
			  const request::FromLen &, const request::From &);
	    AcceptRequest(AcceptRequest const&);
	    virtual ~AcceptRequest();

	    public:
	    AcceptRequest& operator=(AcceptRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    protected:
	    request::FromLen	_fromLen;
	    request::From	_from;
	    request::FromLen	_toLen;
	    request::From	_to;
	};

	class RefuseRequest : public CallRequest
	{
	    public:
	    RefuseRequest();
	    RefuseRequest(const request::FromLen &, const request::From &,
			  const request::FromLen &, const request::From &);
	    RefuseRequest(RefuseRequest const&);
	    virtual ~RefuseRequest();

	    public:
	    RefuseRequest& operator=(RefuseRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    protected:
	    request::FromLen	_fromLen;
	    request::From	_from;
	    request::FromLen	_toLen;
	    request::From	_to;
	};

	class HangUpRequest : public CallRequest
	{
	    public:
	    HangUpRequest();
	    HangUpRequest(const request::FromLen &, const request::From &,
			  const request::FromLen &, const request::From &);
	    HangUpRequest(HangUpRequest const&);
	    virtual ~HangUpRequest();

	    public:
	    HangUpRequest& operator=(HangUpRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    protected:
	    request::FromLen	_fromLen;
	    request::From	_from;
	    request::FromLen	_toLen;
	    request::From	_to;
	};

    }

    namespace	server
    {
	class TimeoutRequest : public CallRequest
	{
	    public:
	    TimeoutRequest();
	    TimeoutRequest(TimeoutRequest const&);
	    virtual ~TimeoutRequest();

	    public:
	    TimeoutRequest& operator=(TimeoutRequest const&);

	    ARequest	*clone();
	};

	class CallsRequest : public CallRequest
	{
	    public:
	    CallsRequest();
	    CallsRequest(const request::IP &, const request::Port &);
	    CallsRequest(CallsRequest const&);
	    virtual ~CallsRequest();

	    public:
	    CallsRequest& operator=(CallsRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    protected:
	    request::IP		_ip;
	    request::Port	_port;
	};
    }
}

#endif /* CALLREQUEST_H_ */
