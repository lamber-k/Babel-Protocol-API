#ifndef CHATREQUEST_H_
# define CHATREQUEST_H_

#include	"ARequest.hh"
#include	"types.hh"

class	Protocol;

namespace	Chat
{
    namespace	client
    {
	class MessageRequest : public ARequest
	{
	    public:
	    MessageRequest();
	    MessageRequest(MessageRequest const&);
	    virtual ~MessageRequest();

	    public:
	    MessageRequest& operator=(MessageRequest const&);

	    ARequest	&clone();
	    Protocol	&serialize(Protocol &)const;
	    Protocol	&unserialize(Protocol &);

	    private:
	    request::FromLen	_fromLen;
	    request::From	_from;
	    request::FromLen	_toLen;
	    request::From	_to;
	    request::SinceWhen	_time;
	    request::MsgLen	_msgLen;
	    request::Msg	_msg;
	};
    }
}

#endif /* CHATREQUEST_H_ */
