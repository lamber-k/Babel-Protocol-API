#ifndef REQUESTCODE_H_
# define REQUESTCODE_H_

/**
 *
 *	\file	RequestCode.hh
 *	List of all request code
 *
 */

# include	"types.hh"

/** request Namespace */
namespace request
{
  /** Server codes */
  namespace server
  {
    static const ID OK =		1000; /**< Everything went fine */
    static const ID BAD_REQ =		1001; /**< Bad Request */
    static const ID FORBIDDEN =		1002; /**< You send a forbidden request due to the context */
    static const ID NOT_IMPLEMENTED =	1003; /**< Request not implemented */
    static const ID NO_CONTENT =	1004; /**< Request don't have */
    static const ID PARTIAL_CONTENT =	1005; /**< Request have partial content */
    static const ID NO_SLOTS =		1006; /**< No more slots available */

      namespace perso
      {
	  static const ID  MISSED_CALLS =	1200;
	  static const ID  GET_MISSED =		1201;
	  static const ID  AUTO_ANSWER =	1203;
      }

      namespace friends
      {
	  static const ID UPDATE =	1300;
      }

      namespace call
      {
	  static const ID TIMEOUT =	1400;
	  static const ID CALL =	1401;
      }

      namespace chat
      {
	  static const ID MESSAGE =	1500;
      }
  }
  namespace client
  {
      namespace auth
      {
	  static const ID NEW =		0100;
	  static const ID DELETE =	0101;
	  static const ID MODIFY =	0102;
	  static const ID CONNECT =	0103;
	  static const ID DISCONNECT =	0104;
      }

      namespace perso
      {
	  static const ID PRIVACY_MODE =	0200;
	  static const ID STATUS =		0201;
	  static const ID MISSED_CALLS =	0202;
	  static const ID GET_MISSED =		0203;
	  static const ID DEL_MISSED =		0204;
	  static const ID SET_AUTO_ANSWER =	0205;
	  static const ID UNSET_AUTO_ANSWER =	0206;
      }

      namespace friends
      {
	  static const ID REQUEST =	0300;
	  static const ID DEL_FRIEND =	0301;
	  static const ID ACCEPT =	0302;
	  static const ID REFUSE =	0303;
	  static const ID LIST =	0304;
      }

      namespace call
      {
	  static const ID CALL =	0400;
	  static const ID ACCEPT =	0401;
	  static const ID REFUSE =	0402;
	  static const ID HANG_UP =	0403;
      }

      namespace chat
      {
	  static const ID MESSAGE =	0500;
      }
  }
}

#endif /* REQUESTCODE_H_ */
