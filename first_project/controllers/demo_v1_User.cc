#include "demo_v1_User.h"

using namespace demo::v1;

// Add definition of your processing function here

void User::login(const HttpRequestPtr &req,
    std::function <void (const HttpRequestPtr &)> &&callback,
    std::string &&userId,
    const std::string &password

    )
{
  LOG_DEBUG<<"User "<<userId<<" login";
  Json::Value ret;
  ret["result"]="ok";
  ret["token"]=drogon::utils::getUuid();
  auto resp=HttpResponse::newHttpJsonResponse(ret);
  callback(resp);
}

void User::getInfo(const HttpRequestPtr &req,
    std::function<void(const HttpRequestPtr &)> &&callback,
    std::string userId,
    const std::string &token
          ) const
{
  LOG_DEBUG<<"User "<<userId<<" get his information";
  Json::Value ret;
  re["result"]="ok";
  ret["user_name"]="Jack";
  ret["user_id"]=userId;
  ret["gender"]=1;
  auto resp=HttpResponse::newHttpJsonResponse(ret);
  callback(resp);
}
