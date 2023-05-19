/*
** Lua binding: AresZMQ
** Generated automatically by tolua++-1.0.93-lua53 on Fri May 19 11:38:22 2023.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_AresZMQ_open (lua_State* tolua_S);

#include "ZmqContext.h"
#include "ZmqMessageRouter.h"
#include "ZmqPoller.h"
#include "ZmqSocket.h"
#include "ZmqTimer.h"
#include "ZmqMonitor.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ZmqMessageRouter (lua_State* tolua_S)
{
 ZmqMessageRouter* self = (ZmqMessageRouter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ZmqMonitor (lua_State* tolua_S)
{
 ZmqMonitor* self = (ZmqMonitor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ZmqTimer (lua_State* tolua_S)
{
 ZmqTimer* self = (ZmqTimer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ZmqSocket (lua_State* tolua_S)
{
 ZmqSocket* self = (ZmqSocket*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ZmqPoller (lua_State* tolua_S)
{
 ZmqPoller* self = (ZmqPoller*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ZmqMonitor");
 tolua_usertype(tolua_S,"QObject");
 tolua_usertype(tolua_S,"ZmqMessageRouter");
 tolua_usertype(tolua_S,"ZmqPoller");
 tolua_usertype(tolua_S,"ZmqSocket");
 tolua_usertype(tolua_S,"ZmqTimer");
 tolua_usertype(tolua_S,"ZmqContext");
 tolua_usertype(tolua_S,"zmq::context_t");
}

/* method: getSingleton of class  ZmqContext */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqContext_getSingleton00
static int tolua_AresZMQ_ZmqContext_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ZmqContext* tolua_ret = (ZmqContext*)  ZmqContext::getSingleton();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqContext");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteSingleton of class  ZmqContext */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqContext_deleteSingleton00
static int tolua_AresZMQ_ZmqContext_deleteSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ZmqContext::deleteSingleton();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getContext of class  ZmqContext */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqContext_getContext00
static int tolua_AresZMQ_ZmqContext_getContext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ZmqContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ZmqContext* self = (const ZmqContext*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContext'", NULL);
#endif
  {
   zmq::context_t* tolua_ret = (zmq::context_t*)  self->getContext();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"zmq::context_t");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContext'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setctxopt of class  ZmqContext */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqContext_setctxopt00
static int tolua_AresZMQ_ZmqContext_setctxopt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqContext",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* self = (ZmqContext*)  tolua_tousertype(tolua_S,1,0);
  int option = ((int)  tolua_tonumber(tolua_S,2,0));
  int optval = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setctxopt'", NULL);
#endif
  {
   self->setctxopt(option,optval);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setctxopt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createUuid of class  ZmqContext */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqContext_createUuid00
static int tolua_AresZMQ_ZmqContext_createUuid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  ZmqContext::createUuid();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createUuid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ZmqMessageRouter */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMessageRouter_new00
static int tolua_AresZMQ_ZmqMessageRouter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqMessageRouter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* context = ((ZmqContext*)  tolua_tousertype(tolua_S,2,0));
  {
   ZmqMessageRouter* tolua_ret = (ZmqMessageRouter*)  Mtolua_new((ZmqMessageRouter)(context));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqMessageRouter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ZmqMessageRouter */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMessageRouter_new00_local
static int tolua_AresZMQ_ZmqMessageRouter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqMessageRouter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* context = ((ZmqContext*)  tolua_tousertype(tolua_S,2,0));
  {
   ZmqMessageRouter* tolua_ret = (ZmqMessageRouter*)  Mtolua_new((ZmqMessageRouter)(context));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqMessageRouter");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bind of class  ZmqMessageRouter */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMessageRouter_bind00
static int tolua_AresZMQ_ZmqMessageRouter_bind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqMessageRouter",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqMessageRouter* self = (ZmqMessageRouter*)  tolua_tousertype(tolua_S,1,0);
  const char* addr = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bind'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->bind(addr);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  ZmqMessageRouter */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMessageRouter_start00
static int tolua_AresZMQ_ZmqMessageRouter_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqMessageRouter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqMessageRouter* self = (ZmqMessageRouter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ZmqPoller */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqPoller_new00
static int tolua_AresZMQ_ZmqPoller_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqPoller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ZmqPoller* tolua_ret = (ZmqPoller*)  Mtolua_new((ZmqPoller)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqPoller");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ZmqPoller */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqPoller_new00_local
static int tolua_AresZMQ_ZmqPoller_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqPoller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ZmqPoller* tolua_ret = (ZmqPoller*)  Mtolua_new((ZmqPoller)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqPoller");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ZmqPoller */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqPoller_delete00
static int tolua_AresZMQ_ZmqPoller_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqPoller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqPoller* self = (ZmqPoller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  ZmqPoller */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqPoller_add00
static int tolua_AresZMQ_ZmqPoller_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqPoller",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqPoller* self = (ZmqPoller*)  tolua_tousertype(tolua_S,1,0);
  ZmqSocket* socket = ((ZmqSocket*)  tolua_tousertype(tolua_S,2,0));
  short event = ((short)  tolua_tonumber(tolua_S,3,ZMQ_POLLIN));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(socket,event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: poll of class  ZmqPoller */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqPoller_poll00
static int tolua_AresZMQ_ZmqPoller_poll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqPoller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqPoller* self = (ZmqPoller*)  tolua_tousertype(tolua_S,1,0);
  long timeout = ((long)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'poll'", NULL);
#endif
  {
   int tolua_ret = (int)  self->poll(timeout);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'poll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: has_in of class  ZmqPoller */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqPoller_has_in00
static int tolua_AresZMQ_ZmqPoller_has_in00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqPoller",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqPoller* self = (ZmqPoller*)  tolua_tousertype(tolua_S,1,0);
  ZmqSocket* socket = ((ZmqSocket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'has_in'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->has_in(socket);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'has_in'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_new00
static int tolua_AresZMQ_ZmqSocket_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqContext",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* context = ((ZmqContext*)  tolua_tousertype(tolua_S,2,0));
  int socket_type = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ZmqSocket* tolua_ret = (ZmqSocket*)  Mtolua_new((ZmqSocket)(context,socket_type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqSocket");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_new00_local
static int tolua_AresZMQ_ZmqSocket_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqContext",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* context = ((ZmqContext*)  tolua_tousertype(tolua_S,2,0));
  int socket_type = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ZmqSocket* tolua_ret = (ZmqSocket*)  Mtolua_new((ZmqSocket)(context,socket_type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqSocket");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_delete00
static int tolua_AresZMQ_ZmqSocket_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bind of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_bind00
static int tolua_AresZMQ_ZmqSocket_bind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* addr = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bind'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->bind(addr);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connect of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_connect00
static int tolua_AresZMQ_ZmqSocket_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* addr = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->connect(addr);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSockoptInt of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_setSockoptInt00
static int tolua_AresZMQ_ZmqSocket_setSockoptInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  int option = ((int)  tolua_tonumber(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSockoptInt'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSockoptInt(option,value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSockoptInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSockoptString of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_setSockoptString00
static int tolua_AresZMQ_ZmqSocket_setSockoptString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  int option = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSockoptString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSockoptString(option,value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSockoptString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSockoptString of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_getSockoptString00
static int tolua_AresZMQ_ZmqSocket_getSockoptString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
  int option = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSockoptString'", NULL);
#endif
  {
   self->getSockoptString(L,option);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSockoptString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSockoptInt of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_getSockoptInt00
static int tolua_AresZMQ_ZmqSocket_getSockoptInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  int option = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSockoptInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getSockoptInt(option);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSockoptInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_send00
static int tolua_AresZMQ_ZmqSocket_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
  int send_flags = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send(msg,send_flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendBySize of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_sendBySize00
static int tolua_AresZMQ_ZmqSocket_sendBySize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int size = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  int send_flags = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendBySize'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->sendBySize(msg,size,send_flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendBySize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_recv00
static int tolua_AresZMQ_ZmqSocket_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
  int recv_flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'", NULL);
#endif
  {
   self->recv(L,recv_flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recvAndWait of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_recvAndWait00
static int tolua_AresZMQ_ZmqSocket_recvAndWait00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
  long timeout = ((long)  tolua_tonumber(tolua_S,2,-1));
  int recv_flags = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recvAndWait'", NULL);
#endif
  {
   self->recvAndWait(L,timeout,recv_flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recvAndWait'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recvMultiMessage of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_recvMultiMessage00
static int tolua_AresZMQ_ZmqSocket_recvMultiMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
  int recv_flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recvMultiMessage'", NULL);
#endif
  {
   self->recvMultiMessage(L,recv_flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recvMultiMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recvMultiMessageAndWait of class  ZmqSocket */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqSocket_recvMultiMessageAndWait00
static int tolua_AresZMQ_ZmqSocket_recvMultiMessageAndWait00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqSocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqSocket* self = (ZmqSocket*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
  long timeout = ((long)  tolua_tonumber(tolua_S,2,-1));
  int recv_flags = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recvMultiMessageAndWait'", NULL);
#endif
  {
   self->recvMultiMessageAndWait(L,timeout,recv_flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recvMultiMessageAndWait'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ZmqTimer */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqTimer_new00
static int tolua_AresZMQ_ZmqTimer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqTimer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqContext",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* context = ((ZmqContext*)  tolua_tousertype(tolua_S,2,0));
  int socket_type = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ZmqTimer* tolua_ret = (ZmqTimer*)  Mtolua_new((ZmqTimer)(context,socket_type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqTimer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ZmqTimer */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqTimer_new00_local
static int tolua_AresZMQ_ZmqTimer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqTimer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqContext",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqContext* context = ((ZmqContext*)  tolua_tousertype(tolua_S,2,0));
  int socket_type = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ZmqTimer* tolua_ret = (ZmqTimer*)  Mtolua_new((ZmqTimer)(context,socket_type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqTimer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ZmqTimer */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqTimer_delete00
static int tolua_AresZMQ_ZmqTimer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqTimer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqTimer* self = (ZmqTimer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startTimer of class  ZmqTimer */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqTimer_startTimer00
static int tolua_AresZMQ_ZmqTimer_startTimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqTimer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqTimer* self = (ZmqTimer*)  tolua_tousertype(tolua_S,1,0);
  int interval = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* addr = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startTimer'", NULL);
#endif
  {
   self->startTimer(interval,addr);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ZmqMonitor */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMonitor_new00
static int tolua_AresZMQ_ZmqMonitor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqMonitor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ZmqMonitor* tolua_ret = (ZmqMonitor*)  Mtolua_new((ZmqMonitor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqMonitor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ZmqMonitor */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMonitor_new00_local
static int tolua_AresZMQ_ZmqMonitor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ZmqMonitor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ZmqMonitor* tolua_ret = (ZmqMonitor*)  Mtolua_new((ZmqMonitor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqMonitor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ZmqMonitor */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMonitor_delete00
static int tolua_AresZMQ_ZmqMonitor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqMonitor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqMonitor* self = (ZmqMonitor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  ZmqMonitor */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMonitor_init00
static int tolua_AresZMQ_ZmqMonitor_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqMonitor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ZmqSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqMonitor* self = (ZmqMonitor*)  tolua_tousertype(tolua_S,1,0);
  ZmqSocket* socket = ((ZmqSocket*)  tolua_tousertype(tolua_S,2,0));
  const char* address = ((const char*)  tolua_tostring(tolua_S,3,0));
  int events = ((int)  tolua_tonumber(tolua_S,4,ZMQ_EVENT_ALL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   ZmqSocket* tolua_ret = (ZmqSocket*)  self->init(socket,address,events);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ZmqSocket");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  ZmqMonitor */
#ifndef TOLUA_DISABLE_tolua_AresZMQ_ZmqMonitor_recv00
static int tolua_AresZMQ_ZmqMonitor_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ZmqMonitor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZmqMonitor* self = (ZmqMonitor*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'", NULL);
#endif
  {
   self->recv(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AresZMQ_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"ZmqContext","ZmqContext","",NULL);
  tolua_beginmodule(tolua_S,"ZmqContext");
   tolua_function(tolua_S,"getSingleton",tolua_AresZMQ_ZmqContext_getSingleton00);
   tolua_function(tolua_S,"deleteSingleton",tolua_AresZMQ_ZmqContext_deleteSingleton00);
   tolua_function(tolua_S,"getContext",tolua_AresZMQ_ZmqContext_getContext00);
   tolua_function(tolua_S,"setctxopt",tolua_AresZMQ_ZmqContext_setctxopt00);
   tolua_function(tolua_S,"createUuid",tolua_AresZMQ_ZmqContext_createUuid00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ZmqMessageRouter","ZmqMessageRouter","",tolua_collect_ZmqMessageRouter);
  #else
  tolua_cclass(tolua_S,"ZmqMessageRouter","ZmqMessageRouter","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ZmqMessageRouter");
   tolua_function(tolua_S,"new",tolua_AresZMQ_ZmqMessageRouter_new00);
   tolua_function(tolua_S,"new_local",tolua_AresZMQ_ZmqMessageRouter_new00_local);
   tolua_function(tolua_S,".call",tolua_AresZMQ_ZmqMessageRouter_new00_local);
   tolua_function(tolua_S,"bind",tolua_AresZMQ_ZmqMessageRouter_bind00);
   tolua_function(tolua_S,"start",tolua_AresZMQ_ZmqMessageRouter_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ZmqPoller","ZmqPoller","",tolua_collect_ZmqPoller);
  #else
  tolua_cclass(tolua_S,"ZmqPoller","ZmqPoller","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ZmqPoller");
   tolua_function(tolua_S,"new",tolua_AresZMQ_ZmqPoller_new00);
   tolua_function(tolua_S,"new_local",tolua_AresZMQ_ZmqPoller_new00_local);
   tolua_function(tolua_S,".call",tolua_AresZMQ_ZmqPoller_new00_local);
   tolua_function(tolua_S,"delete",tolua_AresZMQ_ZmqPoller_delete00);
   tolua_function(tolua_S,"add",tolua_AresZMQ_ZmqPoller_add00);
   tolua_function(tolua_S,"poll",tolua_AresZMQ_ZmqPoller_poll00);
   tolua_function(tolua_S,"has_in",tolua_AresZMQ_ZmqPoller_has_in00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ZmqSocket","ZmqSocket","",tolua_collect_ZmqSocket);
  #else
  tolua_cclass(tolua_S,"ZmqSocket","ZmqSocket","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ZmqSocket");
   tolua_function(tolua_S,"new",tolua_AresZMQ_ZmqSocket_new00);
   tolua_function(tolua_S,"new_local",tolua_AresZMQ_ZmqSocket_new00_local);
   tolua_function(tolua_S,".call",tolua_AresZMQ_ZmqSocket_new00_local);
   tolua_function(tolua_S,"delete",tolua_AresZMQ_ZmqSocket_delete00);
   tolua_function(tolua_S,"bind",tolua_AresZMQ_ZmqSocket_bind00);
   tolua_function(tolua_S,"connect",tolua_AresZMQ_ZmqSocket_connect00);
   tolua_function(tolua_S,"setSockoptInt",tolua_AresZMQ_ZmqSocket_setSockoptInt00);
   tolua_function(tolua_S,"setSockoptString",tolua_AresZMQ_ZmqSocket_setSockoptString00);
   tolua_function(tolua_S,"getSockoptString",tolua_AresZMQ_ZmqSocket_getSockoptString00);
   tolua_function(tolua_S,"getSockoptInt",tolua_AresZMQ_ZmqSocket_getSockoptInt00);
   tolua_function(tolua_S,"send",tolua_AresZMQ_ZmqSocket_send00);
   tolua_function(tolua_S,"sendBySize",tolua_AresZMQ_ZmqSocket_sendBySize00);
   tolua_function(tolua_S,"recv",tolua_AresZMQ_ZmqSocket_recv00);
   tolua_function(tolua_S,"recvAndWait",tolua_AresZMQ_ZmqSocket_recvAndWait00);
   tolua_function(tolua_S,"recvMultiMessage",tolua_AresZMQ_ZmqSocket_recvMultiMessage00);
   tolua_function(tolua_S,"recvMultiMessageAndWait",tolua_AresZMQ_ZmqSocket_recvMultiMessageAndWait00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ZmqTimer","ZmqTimer","QObject",tolua_collect_ZmqTimer);
  #else
  tolua_cclass(tolua_S,"ZmqTimer","ZmqTimer","QObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ZmqTimer");
   tolua_function(tolua_S,"new",tolua_AresZMQ_ZmqTimer_new00);
   tolua_function(tolua_S,"new_local",tolua_AresZMQ_ZmqTimer_new00_local);
   tolua_function(tolua_S,".call",tolua_AresZMQ_ZmqTimer_new00_local);
   tolua_function(tolua_S,"delete",tolua_AresZMQ_ZmqTimer_delete00);
   tolua_function(tolua_S,"startTimer",tolua_AresZMQ_ZmqTimer_startTimer00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ZmqMonitor","ZmqMonitor","",tolua_collect_ZmqMonitor);
  #else
  tolua_cclass(tolua_S,"ZmqMonitor","ZmqMonitor","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ZmqMonitor");
   tolua_function(tolua_S,"new",tolua_AresZMQ_ZmqMonitor_new00);
   tolua_function(tolua_S,"new_local",tolua_AresZMQ_ZmqMonitor_new00_local);
   tolua_function(tolua_S,".call",tolua_AresZMQ_ZmqMonitor_new00_local);
   tolua_function(tolua_S,"delete",tolua_AresZMQ_ZmqMonitor_delete00);
   tolua_function(tolua_S,"init",tolua_AresZMQ_ZmqMonitor_init00);
   tolua_function(tolua_S,"recv",tolua_AresZMQ_ZmqMonitor_recv00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AresZMQ (lua_State* tolua_S) {
 return tolua_AresZMQ_open(tolua_S);
};
#endif

