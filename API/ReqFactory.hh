#ifndef REQFACTORY_H_
# define REQFACTORY_H_

#include	<map>
#include	"types.hh"

class	Protocol;
class	ARequest;

class ReqFactory
{
    public:
    static ReqFactory		&getInstance();
    static ARequest		*consume(Protocol &proto, request::ID code);
    static void			product(Protocol &proto, const ARequest *req);

    private:
    ReqFactory();
    virtual ~ReqFactory();

    private:
    std::map<request::ID, ARequest *>	_factory;
};

#endif /* REQFACTORY_H_ */
