#ifndef PERSOREQUEST_H_
# define PERSOREQUEST_H_

#include	"ARequest.hh"
#include	"types.hh"

class	Protocol;

namespace	perso
{
    class PersoRequest : public ARequest
    {
	public:
	virtual ~PersoRequest();

	virtual ARequest	*clone();
	virtual Protocol	&serialize(Protocol &)const;
	virtual Protocol	&unserialize(Protocol &);

	protected:
	PersoRequest();
	PersoRequest(const request::ID &);
    };

    namespace	client
    {
	class PrivacyModeRequest : public PersoRequest
	{
	    public:
	    PrivacyModeRequest();
	    PrivacyModeRequest(const request::Privacy &);
	    PrivacyModeRequest(PrivacyModeRequest const&);
	    virtual ~PrivacyModeRequest();

	    public:
	    PrivacyModeRequest& operator=(PrivacyModeRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::Privacy	_privacy;
	};

	class StatusRequest : public PersoRequest
	{
	    public:
	    StatusRequest();
	    StatusRequest(const request::Status &, const request::StatusDetailLen &,
			  const request::StatusDetail &);
	    StatusRequest(StatusRequest const&);
	    virtual ~StatusRequest();

	    public:
	    StatusRequest& operator=(StatusRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::Status		_status;
	    request::StatusDetailLen	_statusLen;
	    request::StatusDetail	_statusDetail;
	};

	class MissedCallsRequest : public PersoRequest
	{
	    public:
	    MissedCallsRequest();
	    MissedCallsRequest(MissedCallsRequest const&);
	    virtual ~MissedCallsRequest();

	    public:
	    MissedCallsRequest& operator=(MissedCallsRequest const&);

	    ARequest	*clone();
	};

	class GetMissedRequest : public PersoRequest
	{
	    public:
	    GetMissedRequest();
	    GetMissedRequest(const request::IdxAnswer &);
	    GetMissedRequest(GetMissedRequest const&);
	    virtual ~GetMissedRequest();

	    public:
	    GetMissedRequest& operator=(GetMissedRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::IdxAnswer		_idxAnswer;
	};

	class DelMissedRequest : public PersoRequest
	{
	    public:
	    DelMissedRequest();
	    DelMissedRequest(const request::IdxAnswer &);
	    DelMissedRequest(DelMissedRequest const&);
	    virtual ~DelMissedRequest();

	    public:
	    DelMissedRequest& operator=(DelMissedRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::IdxAnswer		_idxAnswer;
	};

	class SetAutoAnswerRequest : public PersoRequest
	{
	    public:
	    SetAutoAnswerRequest();
	    SetAutoAnswerRequest(const request::AnswerLen &, const request::Answer &);
	    SetAutoAnswerRequest(SetAutoAnswerRequest const&);
	    virtual ~SetAutoAnswerRequest();

	    public:
	    SetAutoAnswerRequest& operator=(SetAutoAnswerRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::Answer	_answer;
	    request::AnswerLen	_answerLen;
	};

	class UnsetAutoAnswerRequest : public PersoRequest
	{
	    public:
	    UnsetAutoAnswerRequest();
	    UnsetAutoAnswerRequest(UnsetAutoAnswerRequest const&);
	    virtual ~UnsetAutoAnswerRequest();

	    public:
	    UnsetAutoAnswerRequest& operator=(UnsetAutoAnswerRequest const&);

	    ARequest	*clone();
	};
    }

    namespace	server
    {
	class GetMissedRequest : public PersoRequest
	{
	    public:
	    GetMissedRequest();
	    GetMissedRequest(const request::IdxAnswer &, const request::FromLen &,
			     const request::From &, const request::SinceWhen &);
	    GetMissedRequest(GetMissedRequest const&);
	    virtual ~GetMissedRequest();

	    public:
	    GetMissedRequest& operator=(GetMissedRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::IdxAnswer		_idxAnswer;
	    request::FromLen		_fromLen;
	    request::From		_from;
	    request::SinceWhen		_sinceWhen;
	};

	class AutoAnswerRequest : public PersoRequest
	{
	    public:
	    AutoAnswerRequest();
	    AutoAnswerRequest(const request::AnswerLen &, const request::Answer &,
			      const request::FromLen &, const request::From &);
	    AutoAnswerRequest(AutoAnswerRequest const&);
	    virtual ~AutoAnswerRequest();

	    public:
	    AutoAnswerRequest& operator=(AutoAnswerRequest const&);

	    ARequest	*clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::AnswerLen		_answerLen;
	    request::Answer		_answer;
	    request::FromLen		_fromLen;
	    request::From		_from;
	};
    }
}

#endif /* PERSOREQUEST_H_ */
