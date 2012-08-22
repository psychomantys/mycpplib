/* soapSentidoDaVidaProxy.h
   Generated by gSOAP 2.7.9l from sentido_da_vida.wsdl.hpp
   Copyright(C) 2000-2007, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapSentidoDaVidaProxy_H
#define soapSentidoDaVidaProxy_H
#include "soapH.h"
class SentidoDaVida
{   public:
	/// Runtime engine context allocated in constructor
	struct soap *soap;
	/// Endpoint URL of service 'SentidoDaVida' (change as needed)
	const char *endpoint;
	/// Constructor allocates soap engine context, sets default endpoint URL, and sets namespace mapping table
	SentidoDaVida()
	{ soap = soap_new(); endpoint = "http://localhost:50000/ws_test"; if (soap && !soap->namespaces) { static const struct Namespace namespaces[] = 
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns", "urn:SentidoDaVida", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap->namespaces = namespaces; } };
	/// Destructor frees deserialized data and soap engine context
	virtual ~SentidoDaVida() { if (soap) { soap_destroy(soap); soap_end(soap); soap_free(soap); } };
	/// Invoke 'SentidoDaVida' of service 'SentidoDaVida' and return error code (or SOAP_OK)
	virtual int ns__SentidoDaVida(double &result) { return soap ? soap_call_ns__SentidoDaVida(soap, endpoint, NULL, result) : SOAP_EOM; };
};
#endif