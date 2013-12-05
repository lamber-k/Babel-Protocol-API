#ifndef         PROTOCOL_H_
# define        PROTOCOL_H_

# include       <string>
# include       <deque>
# include       <vector>
# include       "ARequest.hh"
# include       "types.hh"
# include       "RequestCode.hh"

#if defined(WIN32) && defined(PROTOCOL_API)
extern template class __declspec(dllimport) std::vector<Ruint8>;
#endif
class Protocol
{
    public:
    class ConstructRequest : public std::exception
    {
	public:
	virtual const char  *what() const throw();
	ConstructRequest(const std::string &) throw();
	ConstructRequest(const ConstructRequest &) throw();
	virtual ~ConstructRequest() throw();

	public:
	ConstructRequest& operator=(ConstructRequest const&) throw();

	private:
	std::string         _what;
    };

    public:
    typedef Ruint8                        Byte;
    typedef std::deque<Byte>              container_type;
    typedef container_type::size_type     size_type;

    public:
    Protocol&	operator<<(const Rint8);
    Protocol&	operator<<(const Rint32);
    Protocol&	operator<<(const Rint16);
    Protocol&	operator<<(const Ruint8);
    Protocol&	operator<<(const Ruint32);
    Protocol&	operator<<(const Ruint16);
    Protocol&	operator<<(const Rdouble);
    Protocol&	operator<<(const Rfloat);
    Protocol&	operator<<(const Rint8*);
    Protocol&	operator<<(const std::string &);

    Protocol&	operator>>(Rint8 &);
    Protocol&	operator>>(Rint32 &);
    Protocol&	operator>>(Rint16 &);
    Protocol&	operator>>(Ruint8 &);
    Protocol&	operator>>(Ruint32 &);
    Protocol&	operator>>(Ruint16 &);
    Protocol&	operator>>(Rdouble &);
    Protocol&	operator>>(Rfloat &);
    Protocol&	operator>>(Rint8*);
    Protocol&	operator>>(std::string &);

    public:
    Protocol();
    virtual ~Protocol();

    public:
    template <typename T>
    T             push(const T, size_type count);
    std::string   push(const std::string &, size_type count);

    template <typename T>
    T             &pop(T&);
    std::string   &pop(std::string &, size_type count);

    public:
    Rbool         empty() const;
    Ruint32       size() const;
    Byte          *data();

    public:
    static ARequest               *consume(std::vector<Byte> &, int &);
    static std::vector<Byte>      product(const ARequest &);

    private:
    Protocol(Protocol const&);
    Protocol& operator=(Protocol const&);

    private:
    std::deque<Byte>      _container;
    Byte                  *_data;
};
